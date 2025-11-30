/***************************************************************************//**
* \file capsense_ADC_Centroid_LL.c
* \version 7.10
*
* \brief
*   This file provides the source code for the centroid calculation methods
*   of the Component.
*
* \see capsense_ADC v7.10 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2019), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#include "cytypes.h"
#include "CyLib.h"
#include "capsense_ADC_Centroid_LL.h"
#include "capsense_ADC_Configuration.h"
#include "capsense_ADC_Structure.h"
#include "capsense_ADC_Filter.h"

/*******************************************************************************
* Local definition
*******************************************************************************/
#if capsense_ADC_CSX_TOUCHPAD_WIDGET_EN
    #define capsense_ADC_CSX_TOUCHPAD_BUFFER_SIZE \
            (((capsense_ADC_CSX_MAX_LOCAL_PEAKS + 3u) * sizeof(int8)) +                                 /* fingerPosIndex */      \
            (capsense_ADC_CSX_MAX_LOCAL_PEAKS * capsense_ADC_CSX_MAX_LOCAL_PEAKS * sizeof(int32)) + /* distanceMap */         \
            (capsense_ADC_CSX_MAX_LOCAL_PEAKS * sizeof(int32)) +                                        /* int32 mins       [] */ \
            (capsense_ADC_CSX_MAX_LOCAL_PEAKS * sizeof(int8)) +                                         /* int8  links      [] */ \
            (capsense_ADC_CSX_MAX_LOCAL_PEAKS * sizeof(int8)) +                                         /* int8  visited    [] */ \
            (capsense_ADC_CSX_MAX_LOCAL_PEAKS * sizeof(int8)))                                          /* int8  markIndices[] */

    #define capsense_ADC_CSX_TOUCHPAD_FT_ON_FAIL                (0x81u)
    #define capsense_ADC_CSX_TOUCHPAD_TOUCH_ABSENT_ID           (0x82u)
    #define capsense_ADC_CSX_TOUCHPAD_DEBOUNCE_ENABLE           (0u)
    #define capsense_ADC_CSX_TOUCHPAD_TOUCH_MIN_ID              (0u)
    #define capsense_ADC_CSX_TOUCHPAD_TOUCH_MAX_ID              (capsense_ADC_CSX_MAX_LOCAL_PEAKS - 1u)
    #define capsense_ADC_CSX_TOUCHPAD_INT32                     (0x7FFFFFFFu)
    #define capsense_ADC_CSX_TOUCHPAD_TOUCH_DOWN                (0x80u)
    #define capsense_ADC_CSX_TOUCHPAD_LIFT_OFF                  (0x40u)
    #define capsense_ADC_CSX_TOUCHPAD_DEBOUNCE_MASK             (0x3Fu)
    #define capsense_ADC_CSX_TOUCHPAD_POSITION_NONE             (0xFFFFu)
    #define capsense_ADC_CSX_TOUCHPAD_Z_SHIFT                   (0x04u)
    #define capsense_ADC_CSX_TOUCHPAD_PADDING                   (3Lu)
    #define capsense_ADC_CSX_TOUCHPAD_CENTROID_LENGTH           (3u)
    #define capsense_ADC_CSX_TOUCHPAD_CENTROID_PREVIOUS         (0u)
    #define capsense_ADC_CSX_TOUCHPAD_CENTROID_CENTER           (1u)
    #define capsense_ADC_CSX_TOUCHPAD_CENTROID_NEXT             (2u)

#endif /* capsense_ADC_CSX_TOUCHPAD_WIDGET_EN */

/*******************************************************************************
* Static variables definition
*******************************************************************************/
#if ((capsense_ADC_ENABLE == capsense_ADC_CENTROID_3X3_CSD_EN) || \
     (capsense_ADC_ENABLE  == capsense_ADC_SLIDER_WIDGET_EN))
    static uint8 localMax[capsense_ADC_NUM_CENTROIDS];
    static capsense_ADC_THRESHOLD_TYPE localDiffArray[capsense_ADC_NUM_CENTROIDS][3u];
    static uint8 localMaxIndex;
#endif

#if ( 0u !=capsense_ADC_CSX_TOUCHPAD_WIDGET_EN)
    static capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT newTouches;
    static capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrNewTouches = &newTouches;
    static uint8 newActiveIDs = 0u;
    static uint8 oldActiveIDs = 0u;

    typedef int32 capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP[capsense_ADC_CSX_MAX_LOCAL_PEAKS];
#endif /* ( 0u !=capsense_ADC_CSX_TOUCHPAD_WIDGET_EN) */

/*******************************************************************************
* API Prototypes
*******************************************************************************/
#if (((capsense_ADC_ENABLE == capsense_ADC_CENTROID_3X3_CSD_EN) || \
      (capsense_ADC_ENABLE  == capsense_ADC_SLIDER_WIDGET_EN)) && \
      (capsense_ADC_ENABLE == capsense_ADC_4PTS_LOCAL_MAX_EN))
static void capsense_ADC_SaveLocalMax(capsense_ADC_RAM_SNS_STRUCT ptrSns[],
                                                  uint32 snsCount, uint32 fingerThreshold, uint32 snsIndex);
#endif

#if (0u !=capsense_ADC_CSX_TOUCHPAD_WIDGET_EN)
    static void capsense_ADC_TransferTouch(uint32 newIndex, uint32 oldIndex, capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches);
    static void capsense_ADC_NewTouch(uint32 newIndex, uint8 onDebounce, uint16 fingerOnThreshold);
    CY_INLINE static uint8 capsense_ADC_GetLowestId(uint16 idMask);
    static uint32 capsense_ADC_CalcDistance(uint32 newIndex, uint32 oldIndex, capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches);
    static void capsense_ADC_Hungarian(uint8 rowCount, uint8 colCount, int8 *fingerPosIndex,
                                           capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP *distanceMap);
    static void capsense_ADC_FillDistanceMap(capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP *distanceMap,
                                                 capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches);
    CY_INLINE static void capsense_ADC_TouchDownDebounce(void);
    CY_INLINE static void capsense_ADC_SortByAge(void);
    static void capsense_ADC_CopyTouchRecord(capsense_ADC_CSX_TOUCHPAD_PEAK_STRUCT *destination,
                                                           capsense_ADC_CSX_TOUCHPAD_PEAK_STRUCT *source);
    #if (0u != capsense_ADC_OFF_DEBOUNCE_EN)
    CY_INLINE static void capsense_ADC_LiftOffDebounce(uint8 offDebounce,
                                                           capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches);
    #endif /* (0u != capsense_ADC_OFF_DEBOUNCE_EN) */
#endif /* (0u !=capsense_ADC_CSX_TOUCHPAD_WIDGET_EN) */

#if ((capsense_ADC_ENABLE == capsense_ADC_CENTROID_3X3_CSD_EN) || \
     (capsense_ADC_ENABLE  == capsense_ADC_SLIDER_WIDGET_EN))
#if (capsense_ADC_ENABLE == capsense_ADC_4PTS_LOCAL_MAX_EN)
/*******************************************************************************
* Function Name: capsense_ADC_DpFindLocalMaxSd4pts
****************************************************************************//**
*
* \brief
*   Finds the maximum in the widget differences and prepares array with maximum difference
*   and it's neighbour differences in Legacy mode (only one touch can be found).
*   Finds the maxima in the widget differences and prepares arrays with maxima difference
*   and theirs neighbour differences in Multi-Touch mode (maximum three touches can be found).
*   This API is used in conjunction with capsense_ADC_DpCalcLinearCentroid or
*   capsense_ADC__DpCalcRadialCentroid, because they use shared static data: localMax[],
*   localDiffArray[][3u], localMaxIndex.
*
* \details
*   The localMax[] is used to store the index of the maximum/maxima.
*   The localDiffArray[][] is used to store values of the maximum/maxima and neighbour differences.
*   The localMaxIndex is used to store the number of maxima have been actually found.
*   The used finding method checks for 4 points : current, next, previous and before previous
*   sensor's position. Depends on these points differences it chooses the previous or before
*   previous position. For radial sliders an closed character of a widget is taken into the account.
*
* \param ptrFlashWdgt
*   The pointer to the the widget flash structure.
*
* \param ptrSns
*   The pointer to the the first sensor.
*
* \param snsCount
*   The total sensor number in the widget.
*
* \param fingerThreshold
*   The finger threshold in the widget.
*
* \return Returns the number of maxima found.
*
*******************************************************************************/
uint32 capsense_ADC_DpFindLocalMaxSd4pts(capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt,
                                              capsense_ADC_RAM_SNS_STRUCT ptrSns[],
                                              uint32 snsCount, uint32 fingerThreshold)
{
    uint32 i;
    capsense_ADC_RAM_SNS_STRUCT *localPtrSns = ptrSns;
    localMaxIndex = 0u;
    int32 slope0 = 0;
    int32 slope1 = (int32)localPtrSns[0].diff;
    int32 slope2 = 0;
    int32 slopeLast = -(int32)localPtrSns[snsCount - 1u].diff;

    #if (0u != capsense_ADC_TOTAL_RADIAL_SLIDERS)
        if ((capsense_ADC_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType == capsense_ADC_WD_RADIAL_SLIDER_E)
        {
            slope1 = (int32)localPtrSns[0].diff - (int32)localPtrSns[snsCount - 1u].diff;
            slope2 = (int32)localPtrSns[snsCount - 1u].diff - (int32)localPtrSns[snsCount - 2u].diff;
            slopeLast = slope1;
        }
    #else
        /* Typecast the parameter to avoid a compiler warning */
        (void) ptrFlashWdgt;
    #endif

    /* Search local maxima for sensorId from 0 to snsCount - 1 */
    for (i = 0uL; i < snsCount; i++ )
    {
        /* Check for the last sensor */
        if ((snsCount - 1uL) == i)
        {
            slope0 = slopeLast;
        }
        else
        {
            slope0 = (int32)localPtrSns[i + 1u].diff - (int32)localPtrSns[i].diff;
        }

        if(0 > slope0)
        {
            if(0 < slope1)
            {
                capsense_ADC_SaveLocalMax(ptrSns, snsCount, fingerThreshold, i);
            }
            else
            {
                if(0 == slope1)
                {
                    if(0 == slope2)
                    {
                        capsense_ADC_SaveLocalMax(ptrSns, snsCount, fingerThreshold, (i - 1uL));
                    }
                    else
                    {
                        if (0 < slope2)
                        {
                            if (slope2 > (-slope0))
                            {
                                capsense_ADC_SaveLocalMax(ptrSns, snsCount, fingerThreshold, i);
                            }
                            else
                            {
                                capsense_ADC_SaveLocalMax(ptrSns, snsCount, fingerThreshold, (i - 1uL));
                            }
                        }
                    }
                }
            }
            if (localMaxIndex >= capsense_ADC_NUM_CENTROIDS)
            {
                break;
            }
        }
        slope2 = slope1;
        slope1 = slope0;
    }

    return (uint32)(localMaxIndex);
}

/*******************************************************************************
* Function Name: capsense_ADC_SaveLocalMax
****************************************************************************//**
*
* \brief
*   Stores a found local maximum in the arrays.
*
* \details
*   Stores a found local maximum in the localMax array if the difference is greater
*   than a finger threshold. Prepares arrays with maximum neighbour differences for
*   position calculations.
*
* \param *ptrSns
*   A pointer to sensor RAM structure of a found local maximum.
*
* \param snsCount
*   The total sensor number in the widget.
*
* \param fingerThreshold
*   A fingerThreshold to compare with a sensor difference.
*
* \param snsIndex
*   An index of a sensor with a found local maximum.
*
*******************************************************************************/
static void capsense_ADC_SaveLocalMax(capsense_ADC_RAM_SNS_STRUCT ptrSns[],
                                                    uint32 snsCount, uint32 fingerThreshold, uint32 snsIndex)
{
    capsense_ADC_THRESHOLD_TYPE currentDiff = ptrSns[snsIndex].diff;

    if (currentDiff > fingerThreshold)
    {
        /* Store found Peak */
        localMax[localMaxIndex] = (uint8)snsIndex;
        localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS] = currentDiff;

        /* Store neighbour differences */
        if (snsIndex == 0u)
        {
            localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS_PREV] = ptrSns[snsCount - 1u].diff;
            localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[snsIndex + 1u].diff;
        }
        else if (snsIndex == (snsCount - 1u))
        {
            localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS_PREV] = ptrSns[snsIndex - 1u].diff;
            localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[0u].diff;
        }
        else
        {
            localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS_PREV] = ptrSns[snsIndex - 1u].diff;
            localDiffArray[localMaxIndex][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[snsIndex + 1u].diff;
        }

        localMaxIndex++;
    }
}
#else /* (capsense_ADC_ENABLE == capsense_ADC_4PTS_LOCAL_MAX_EN) */

/*******************************************************************************
* Function Name: capsense_ADC_DpFindLocalMaxSd
****************************************************************************//**
*
* \brief
*   Finds the maximum in the widget differences and prepares array with maximum difference
*   and it's neighbour differences in Legacy mode (only one touch can be found).
*   Finds the maxima in the widget differences and prepares arrays with maxima difference
*   and theirs neighbour differences in Multi-Touch mode (maximum three touches can be found).
*   This API is used in conjunction with capsense_ADC_DpCalcLinearCentroid or
*   capsense_ADC__DpCalcRadialCentroid, because they use shared static data: localMax[],
*   localDiffArray[][3u], localMaxIndex.
*
* \details
*   The localMax[] is used to store the index of the maximum/maxima.
*   The localDiffArray[][] is used to store values of the maximum/maxima and neighbour differences.
*   The localMaxIndex is used to store the number of maxima have been actually found.
*
* \param ptrSns The pointer to the first sensor.
* \param snsCount The total sensor number in the widget.
* \param fingerThreshold The finger threshold in the widget.
*
* \return Returns the number of maxima found.
*
*******************************************************************************/
uint32 capsense_ADC_DpFindLocalMaxSd(capsense_ADC_RAM_SNS_STRUCT ptrSns[], uint32 snsCount,
                                                                                   uint32 fingerThreshold)
{
    uint32 i;
    uint32 sensorId;

    #if (capsense_ADC_NUM_CENTROIDS == 0x01u)
        capsense_ADC_RAM_SNS_STRUCT *localPtrSns = ptrSns;
        capsense_ADC_THRESHOLD_TYPE temp = 0u;
    #endif

    localMaxIndex = 0u;

    #if (capsense_ADC_NUM_CENTROIDS == 0x01u)
        for (sensorId = 0u; sensorId < snsCount; sensorId++)
        {
            if ((localPtrSns->diff > fingerThreshold) && (localPtrSns->diff > temp))
            {
                localMax[0u] = LO8(sensorId);
                temp = localPtrSns->diff;
                localMaxIndex = 1u;
            }
            localPtrSns++;
        }
    #else /* (capsense_ADC_NUM_CENTROIDS == 0x01u) */

        if ((ptrSns[0u].diff > fingerThreshold) && (ptrSns[0u].diff >= ptrSns[1u].diff))
        {
            localMax[localMaxIndex] = 0u;
            localMaxIndex = 1u;
        }

        if ((ptrSns[snsCount - 1u].diff > fingerThreshold) && (ptrSns[snsCount - 1u].diff > ptrSns[snsCount - 2u].diff))
        {
            localMax[localMaxIndex] = (uint8)(snsCount - 1u);
            localMaxIndex++;
        }

        #if (capsense_ADC_NUM_CENTROIDS == 0x02u)
            if (localMaxIndex < capsense_ADC_NUM_CENTROIDS)
            {
        #endif /* (capsense_ADC_NUM_CENTROIDS == 0x02u) */
                for (sensorId = 1u; sensorId < (snsCount - 1u); sensorId++)
                {
                    if ((ptrSns[sensorId].diff > fingerThreshold) && (ptrSns[sensorId].diff >= ptrSns[sensorId + 1u].diff))
                    {
                        if (ptrSns[sensorId].diff > ptrSns[sensorId - 1u].diff)
                        {
                            localMax[localMaxIndex] = (uint8)sensorId;
                            localMaxIndex++;

                            if (localMaxIndex >= capsense_ADC_NUM_CENTROIDS)
                            {
                                break;
                            }
                        }
                    }
                }
        #if (capsense_ADC_NUM_CENTROIDS == 0x02u)
            }
        #endif /* (capsense_ADC_NUM_CENTROIDS == 0x02u) */
    #endif /* #if (capsense_ADC_NUM_CENTROIDS == 0x01u) */

    if (localMaxIndex != 0u)
    {
        /* Prepare single-dimension centroid calculation array */
        for (i = 0u; i < localMaxIndex; i++)
        {
             localDiffArray[i][capsense_ADC_CENTROID_POS] = ptrSns[localMax[i]].diff;

            if (localMax[i] == 0u)
            {
                localDiffArray[i][capsense_ADC_CENTROID_POS_PREV] = ptrSns[snsCount - 1u].diff;
                localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[localMax[i] + 1u].diff;
            }
            else if (localMax[i] == ((uint8)(snsCount - 1u)))
            {
                localDiffArray[i][capsense_ADC_CENTROID_POS_PREV] = ptrSns[localMax[i] - 1u].diff;
                localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[0u].diff;
            }
            else
            {
                localDiffArray[i][capsense_ADC_CENTROID_POS_PREV] = ptrSns[localMax[i] - 1u].diff;
                localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[localMax[i] + 1u].diff;
            }
        }
    }
    /* Return status to check if at least one maximum has been found */
    return (uint32)(localMaxIndex);
}
#endif /* (capsense_ADC_ENABLE == capsense_ADC_4PTS_LOCAL_MAX_EN) */
#endif /* ((capsense_ADC_ENABLE == capsense_ADC_CENTROID_3X3_CSD_EN) || \
          (capsense_ADC_ENABLE  == capsense_ADC_SLIDER_WIDGET_EN)) */

#if capsense_ADC_TOTAL_DIPLEXED_SLIDERS
/*******************************************************************************
* Function Name: capsense_ADC_DpFindLocalMaxDiplex
****************************************************************************//**
*
* \brief
*   Finds the maximum in the widget differences. Used only for diplexed linear slider.
*
* \details
*   The localMax[] is used to store the index of the maximum/maxima.
*   The localDiffArray[][] is used to store values of the maximum/maxima and neighbour differences.
*   The localMaxIndex is used to store the number of maxima have been actually found.
*
* \param ptrSns The pointer to the first sensor.
* \param snsCount The total sensor number in the widget.
* \param diplexTable The pointer to the diplex table.
* \param fingerThreshold The finger threshold in the widget.
*
* \return Returns the number of maxima found.
*
*******************************************************************************/
uint32 capsense_ADC_DpFindLocalMaxDiplex(
                        capsense_ADC_RAM_SNS_STRUCT ptrSns[],
                        uint32 snsCount,
                        uint8 const diplexTable[],
                        uint32 fingerThreshold)
{
    uint32 sensorId;
    uint32 diplexSensorId;

    uint32 biggestStartPos = 0u;
    uint32 biggestSize = 0u;
    uint32 curStartPos = 0u;
    uint32 curSize = 0u;
    capsense_ADC_THRESHOLD_TYPE temp = 0u;

    localMaxIndex = 0u;

    for (sensorId = 0u; sensorId < (snsCount << 1u); sensorId++)
    {
        diplexSensorId = diplexTable[sensorId];

        if (ptrSns[diplexSensorId].diff > fingerThreshold)
        {
            if (0u == curSize)
            {
                curStartPos = sensorId;
            }

            curSize++;
        }
        else
        {
            if (curSize > biggestSize)
            {
                biggestSize = curSize;
                biggestStartPos = curStartPos;
            }
            curSize = 0u;
        }
    }

    if (curSize > biggestSize)
    {
        biggestSize = curSize;
        biggestStartPos = curStartPos;
    }

    if (biggestSize >= capsense_ADC_CENTROID_DIPLEX_SECTION_LENGTH)
    {
        for (sensorId = biggestStartPos; sensorId < (biggestStartPos + biggestSize); sensorId++)
        {
            diplexSensorId = diplexTable[sensorId];

            if (ptrSns[diplexSensorId].diff > temp)
            {
                localMax[0u] = LO8(sensorId);
                temp = ptrSns[diplexSensorId].diff;
                localMaxIndex = 1u;
            }
        }

        /* Prepare single-dimension centroid calculation array */
        if (localMax[0u] == 0u)
        {
            localDiffArray[0u][capsense_ADC_CENTROID_POS_PREV] = 0u;
            localDiffArray[0u][capsense_ADC_CENTROID_POS] = ptrSns[localMax[0u]].diff;
            localDiffArray[0u][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[localMax[0u] + 1u].diff;

        }
        else if (localMax[0u] == ((snsCount << 1u) - 1u))
        {
            diplexSensorId = diplexTable[localMax[0u] - 1u];
            localDiffArray[0u][capsense_ADC_CENTROID_POS_PREV] = ptrSns[diplexSensorId].diff;
            diplexSensorId = diplexTable[localMax[0u]];
            localDiffArray[0u][capsense_ADC_CENTROID_POS] = ptrSns[diplexSensorId].diff;
            localDiffArray[0u][capsense_ADC_CENTROID_POS_NEXT] = 0u;
        }
        else
        {
            diplexSensorId = diplexTable[localMax[0u] - 1u];
            localDiffArray[0u][capsense_ADC_CENTROID_POS_PREV] = ptrSns[diplexSensorId].diff;
            diplexSensorId = diplexTable[localMax[0u]];
            localDiffArray[0u][capsense_ADC_CENTROID_POS] = ptrSns[diplexSensorId].diff;
            diplexSensorId = diplexTable[localMax[0u] + 1u];
            localDiffArray[0u][capsense_ADC_CENTROID_POS_NEXT] = ptrSns[diplexSensorId].diff;
        }
    }

    return (uint32)(localMaxIndex);
}
#endif /* #if capsense_ADC_TOTAL_DIPLEXED_SLIDERS */


#if ((0u != capsense_ADC_TOTAL_LINEAR_SLIDERS) || \
     (capsense_ADC_ENABLE == capsense_ADC_CENTROID_3X3_CSD_EN))
/*******************************************************************************
* Function Name: capsense_ADC_DpCalcLinearCentroid
****************************************************************************//**
*
* \brief
*   Calculates the position of the linear slider.
*
* \details
*   The localMax[] is used to store the index of the maximum/maxima.
*   The localDiffArray[][] is used to store values of the maximum/maxima and neighbour differences.
*   The localMaxIndex is used to store the number of maxima have been actually found.
*
* \param position
*  The pointer to the position array for temporary position storage.
*
* \param multiplier
*  The multiplier used for position calculation. Contains the widget resolution and total sensor
*  information. It is generated by customizer.
*
* \param snsCount
*  The number of sensors in the linear slider. The doubled snsCount has to be passed
*  if this API is called for diplexed slider.
*
* \param offset
*  The additional position offset as half of the multiplier.
*
* \return Returns the number of positions calculated.
*
*******************************************************************************/
uint32 capsense_ADC_DpCalcLinearCentroid(uint16 position[], uint32 multiplier, uint32 snsCount, uint32 offset)
{
    int32 numerator;
    int32 denominator;
    uint32 i;

    for (i = 0u; i < localMaxIndex; i++)
    {
        /*
         * The capsense_ADC_DpFindLocalMaxSd API prepares the unified localDiffArray[][] for linear and radial sliders.
         *  Therefore, the difference of the first and the last elements of linear slider are cleared.
         */

        if (localMax[i] == 0u)
        {
            localDiffArray[i][capsense_ADC_CENTROID_POS_PREV] = 0u;
        }
        else
        {
            if (localMax[i] == (snsCount - 1u))
            {
                localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT] = 0u;
            }
        }

        /* Si+1 - Si-1 */
        numerator = (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT] -
                    (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_PREV];

        /* Si+1 + Si + Si-1 */
        denominator = (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_PREV] +
                      (int32) localDiffArray[i][capsense_ADC_CENTROID_POS] +
                      (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT];

        denominator = ((numerator * (int32)multiplier) / denominator) +
                      (((int32)localMax[i] * (int32)multiplier) + (int32)offset);

        /* Round result and shift 8 bits left */
        position[i] = LO16(((uint32)denominator + capsense_ADC_CENTROID_ROUND_VALUE) >> 8u);
    }
    return (uint32)(localMaxIndex);
}
#endif /* ((0u != capsense_ADC_TOTAL_LINEAR_SLIDERS) || \
          (capsense_ADC_ENABLE == capsense_ADC_CENTROID_3X3_CSD_EN)) */


#if capsense_ADC_TOTAL_RADIAL_SLIDERS
/*******************************************************************************
* Function Name: capsense_ADC_DpCalcRadialCentroid
****************************************************************************//**
*
* \brief
*   Calculates the position of the radial slider.
*
* \details
*   The localMax[] is used to store the index of the maximum/maxima.
*   The localDiffArray[][] is used to store values of the maximum/maxima and neighbour differences.
*   The localMaxIndex is used to store the number of maxima have been actually found.
*
* \param *position The pointer to the position array for temporary storage.
* \param multiplier The multiplier used for position calculation.
*                       Contains the widget resolution and total sensor information. It is generated by customizer.
* \param snsCount The total sensor number in the widget.
*
* \return Returns the number of positions calculated.
*
*******************************************************************************/
uint32 capsense_ADC_DpCalcRadialCentroid(uint16 position[], uint32 multiplier, uint32 snsCount)
{
    int32 numerator;
    int32 denominator;
    uint32 i;

    for (i = 0u; i < localMaxIndex; i++)
    {
        /* Si+1 - Si-1 */
        numerator = (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT] -
                    (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_PREV];

        /* Si+1 + Si + Si-1 */
        denominator = (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_PREV] +
                      (int32) localDiffArray[i][capsense_ADC_CENTROID_POS] +
                      (int32) localDiffArray[i][capsense_ADC_CENTROID_POS_NEXT];

        denominator = ((numerator * (int32)multiplier) / denominator) +
                       ((int32)localMax[i] * (int32)multiplier);

        if (denominator < 0)
        {
            denominator += ((int32)snsCount * (int32)multiplier);
        }

        /* Round result and shift 8 bits left */
        position[i] = LO16(((uint32)denominator + capsense_ADC_CENTROID_ROUND_VALUE) >> 8u);
    }
    return (uint32)(localMaxIndex);
}
#endif /* #if capsense_ADC_TOTAL_RADIAL_SLIDERS */


#if ( 0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN)
/*******************************************************************************
* Function Name: capsense_ADC_DpFindLocalMaxDd
****************************************************************************//**
*
* \brief
*   Finds up to 5 local maxima in the CSX TouchPad difference data.
*
* \details
*  The column and row number of each maximum and total number of found maxima
*  are stored in the structure pointed by ptr2CsxTouchpad in
*  the Flash Widget Structure.
*
* \param ptrFlashWdgt The pointer to the Flash Widget Structure.
*
*******************************************************************************/
void capsense_ADC_DpFindLocalMaxDd(
                        capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt)
{
    capsense_ADC_RAM_WD_CSX_TOUCHPAD_STRUCT *ptrWidgetRam = ptrFlashWdgt->ptr2WdgtRam;
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor =  ptrFlashWdgt->ptr2SnsRam;
    uint16 signalThreshold = (uint16)ptrWidgetRam->fingerTh - ptrWidgetRam->hysteresis;
    uint16 currDiff;
    uint8 rx;
    uint8 tx;
    uint8 snsShift;
    uint8 lastRx = ptrFlashWdgt->numCols - 1u;
    uint8 lastTx = ptrFlashWdgt->numRows - 1u;
    uint32 proceed = 0u;

    /* Initialize new touches structure */
    ptrNewTouches->touchNum = 0u;

    /* Go through all Rx electrodes */
    for (rx = 0u; rx <= lastRx; rx++)
    {
        /* Go through all Tx and RX(changed above) electrodes intersections and check if local maximum reqirement is met */
        for (tx = 0u; tx <= lastTx; tx++)
        {
            proceed = 0u;

            currDiff = ptrSensor->diff;

            if (currDiff < signalThreshold)
            {
                proceed = 1u;
            }

            /*
            * Check local maximum requirement: Comparing raw count of a local maximum candidate with
            * raw counts of sensors from the previous row.
            */
            if ((0u == proceed) && (rx > 0u))
            {
                /* Sensor(i-1, j+1) */
                snsShift = lastTx;

                if ((tx < lastTx) && (currDiff <= (ptrSensor - snsShift)->diff))
                {
                    proceed = 1u;
                }

                if (0u == proceed)
                {
                    /* Sensor(i-1, j) */
                    snsShift++;

                    if (currDiff <= (ptrSensor - snsShift)->diff)
                    {
                        proceed = 1u;
                    }
                }

                if (0u == proceed)
                {
                    /* Sensor(i-1, j-1) */
                    snsShift++;

                    if ((tx > 0u) && (currDiff <= (ptrSensor - snsShift)->diff))
                    {
                        proceed = 1u;
                    }
                }
            }

            /*
            * Check local maximum requirement: Comparing raw count of a local maximum candidate with
            * raw counts of sensors from the next row.
            */
            if ((0u == proceed) && (rx < lastRx))
            {
                /* Sensor(i+1, j+1) */
                snsShift = lastTx + 2u;

                if ((tx < lastTx) && (currDiff < (ptrSensor + snsShift)->diff))
                {
                    proceed = 1u;
                }

                if (0u == proceed)
                {
                    /* Sensor(i+1, j) */
                    snsShift--;

                    if (currDiff < (ptrSensor + snsShift)->diff)
                    {
                        proceed = 1u;
                    }
                }

                if (0u == proceed)
                {
                    /* Sensor(i+1, j-1) */
                    snsShift--;

                    if ((tx > 0u) && (currDiff < (ptrSensor + snsShift)->diff))
                    {
                        proceed = 1u;
                    }
                }
            }

            /*
            * Check local maximum requirement: Comparing raw count of a local maximum candidate with
            * raw counts of sensors from the same row
            * Sensor(i, j+1)
            */
            if ((0u == proceed) && (tx < lastTx))
            {
                if (currDiff < (ptrSensor + 1u)->diff)
                {
                    proceed = 1u;
                }
            }

            /* Sensor(i, j-1) */
            if ((0u == proceed) && (tx > 0u))
            {
                if (currDiff <= (ptrSensor - 1u)->diff)
                {
                    proceed = 1u;
                }
            }

            /* Add local maximum to the touch structure if there is a room */
            if ((0u == proceed) && (ptrNewTouches->touchNum < capsense_ADC_CSX_MAX_LOCAL_PEAKS))
            {
                ptrNewTouches->touch[ptrNewTouches->touchNum].x = rx;
                ptrNewTouches->touch[ptrNewTouches->touchNum].y = tx;

                ptrNewTouches->touch[ptrNewTouches->touchNum].rawCount = currDiff;
                ptrNewTouches->touchNum++;
            }

            ptrSensor++;
        }
    }
}


/* CY_ID633 */
#if defined(__ICCARM__)
    #pragma optimize=none
#endif /* (__ICCARM__) */
/*******************************************************************************
* Function Name: capsense_ADC_DpCalcTouchPadCentroid
****************************************************************************//**
*
* \brief
*   Calculates the position for each local maximum using the 3x3 algorithm.
*
* \details
*  Stores a result in the structure pointed by ptr2CsxTouchpad at the same
*  fields as the column/row number.
*
* \param ptrFlashWdgt The pointer to the Flash Widget Structure.
*
*******************************************************************************/
void capsense_ADC_DpCalcTouchPadCentroid(
                        capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt)
{
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor =  ptrFlashWdgt->ptr2SnsRam;
    uint8 number;
    uint8 i;
    uint8 j;
    uint8 lastRx = ptrFlashWdgt->numCols - 1u;
    uint8 lastTx = ptrFlashWdgt->numRows - 1u;
    uint16 centroid[3u][3u];
    int32 weightedSumX;
    int32 weightedSumY;
    uint32 totalSum;

    for(number = 0u; number < ptrNewTouches->touchNum; number++)
    {
        /* Set the sensor pointer to the local maximum sensor */
        ptrSensor =  ptrFlashWdgt->ptr2SnsRam;
        ptrSensor += (ptrNewTouches->touch[number].y + (ptrNewTouches->touch[number].x * ptrFlashWdgt->numRows));

        /* Prepare 3x3 centroid two dimensional array */
        /* Fill each row */
        for (i = 0u; i < capsense_ADC_CSX_TOUCHPAD_CENTROID_LENGTH; i++)
        {
            /* The first  condition could be valid only when local max on the first row (0 row) of Touchpad
             * The second condition could be valid only when local max on the last row of Touchpad
             * Then corresponding row (zero or the last) of 3x3 array is initialized to 0u */
            if (((((int32)ptrNewTouches->touch[number].x - 1) + (int32)i) < 0) ||
                ((((int32)ptrNewTouches->touch[number].x - 1) + (int32)i) > (int32)lastRx))
            {
                centroid[capsense_ADC_CSX_TOUCHPAD_CENTROID_PREVIOUS][i] = 0u;
                centroid[capsense_ADC_CSX_TOUCHPAD_CENTROID_CENTER][i] = 0u;
                centroid[capsense_ADC_CSX_TOUCHPAD_CENTROID_NEXT][i] = 0u;
            }
            else
            {
                /* Fill each column */
                for (j = 0u; j < capsense_ADC_CSX_TOUCHPAD_CENTROID_LENGTH; j++)
                {
                    /* The first  condition could be valid only when local max on the first column (0 row) of Touchpad
                     * The second condition could be valid only when local max on the last column of Touchpad
                     * Then corresponding column (zero or the last) of 3x3 array is initialized to 0u */
                    if (((((int32)ptrNewTouches->touch[number].y - 1) + (int32)j) < 0) ||
                        ((((int32)ptrNewTouches->touch[number].y - 1) + (int32)j) > (int32)lastTx))
                    {
                        centroid[j][i] = 0u;
                    }
                    else
                    {
                        centroid[j][i] = (uint16)(ptrSensor + (((i - 1u) * ptrFlashWdgt->numRows) + (j - 1u)))->diff;
                    }
                }
            }
        }

        weightedSumX = 0;
        weightedSumY = 0;
        totalSum = 0u;

        /* Calculate centroid */
        for (i = 0u; i < capsense_ADC_CSX_TOUCHPAD_CENTROID_LENGTH; i++)
        {
            for (j = 0u; j < capsense_ADC_CSX_TOUCHPAD_CENTROID_LENGTH; j++)
            {
                totalSum += centroid[i][j];
                weightedSumX += (int32)centroid[i][j] * ((int32)j - 1);
                weightedSumY += (int32)centroid[i][j] * ((int32)i - 1);
            }
        }

        /* The X position is calculated.
        * The weightedSumX value depends on a finger position shifted regarding the X electrode (ptrNewTouches->touch[number].x)
        * The multiplier ptrFlashWdgt->xCentroidMultiplier is a short from:
        * capsense_ADC_TOUCHPAD0_X_RESOLUTION * 256u) / (capsense_ADC_TOUCHPAD0_NUM_RX - CONFIG))
        * where CONFIG = 0 or 1 depends on TouchpadMultiplerMethod parameter
        */
        weightedSumX = ((weightedSumX * (int32)ptrFlashWdgt->xCentroidMultiplier) / (int32)totalSum) +
                        ((int32)ptrNewTouches->touch[number].x * (int32)ptrFlashWdgt->xCentroidMultiplier);
        /* Position correction for half of a sensor */
        #if (capsense_ADC_ENABLE == capsense_ADC_TOUCHPAD_MULT_METHOD)
            weightedSumX += (((int32)ptrFlashWdgt->xCentroidMultiplier) / 2);
        #endif

        /* The X position is rounded to the nearest integer value and normalized to the resolution range */
        ptrNewTouches->touch[number].x = LO16(((uint32)weightedSumX + capsense_ADC_CENTROID_ROUND_VALUE) >> 8u);

        /* The Y position is calculated.
        * The weightedSumY value depends on a finger position shifted regarding the Y electrode (ptrNewTouches->touch[number].y)
        * The multiplier ptrFlashWdgt->yCentroidMultiplier is a short from:
        * capsense_ADC_TOUCHPAD0_Y_RESOLUTION * 256u) / (capsense_ADC_TOUCHPAD0_NUM_TX - CONFIG))
        * where CONFIG = 0 or 1 depends on TouchpadMultiplerMethod parameter
        */
        weightedSumY = ((weightedSumY * (int32)ptrFlashWdgt->yCentroidMultiplier) / (int32)totalSum) +
                        ((int32)ptrNewTouches->touch[number].y * (int32)ptrFlashWdgt->yCentroidMultiplier);
        /* Position correction for half of a sensor */
        #if (capsense_ADC_ENABLE == capsense_ADC_TOUCHPAD_MULT_METHOD)
            weightedSumY += (((int32)ptrFlashWdgt->yCentroidMultiplier) / 2);
        #endif

        /* The Y position is rounded to the nearest integer value and normalized to the resolution range */
        ptrNewTouches->touch[number].y = LO16(((uint32)weightedSumY + capsense_ADC_CENTROID_ROUND_VALUE) >> 8u);

        /* The z value is a sum of raw counts of sensors that form 3x3 matrix with a local maximum in the center */
        ptrNewTouches->touch[number].z = LO8(totalSum >> capsense_ADC_CSX_TOUCHPAD_Z_SHIFT);
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_DpTouchTracking
****************************************************************************//**
*
* \brief
*   Tracks the found touches:
*    - associates them with previous touches (DistanceMap, Hungarian)
*    - applies the position filters
*    - suppresses excessive touches
*
* \details
*  The final touch data is placed into a structure pointed by the ptr2CsxTouchpad
*  member of the Flash Widget Structure.
*
* \param ptrFlashWdgt The pointer to the Flash Widget Structure.
*
*******************************************************************************/
void capsense_ADC_DpTouchTracking(
                        capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt)
{
    capsense_ADC_RAM_WD_CSX_TOUCHPAD_STRUCT *ptrWidgetRam = ptrFlashWdgt->ptr2WdgtRam;
    capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches = ptrFlashWdgt->ptr2CsxTouchpad;
    capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP *distanceMap;
    int8 *fingerPosIndex;
    static int8 touchPadBuffer[capsense_ADC_CSX_TOUCHPAD_BUFFER_SIZE];
    uint32 i;
    uint8 newTouchNum = ptrNewTouches->touchNum;
    uint16 fingerOnThreshold = (uint16)ptrWidgetRam->fingerTh + ptrWidgetRam->hysteresis;

    if ((0u != newTouchNum) || (0u != ptrOldTouches->touchNum))
    {
        /* Initialize variables */
        newActiveIDs = 0u;
        /* Getting active touch IDs from previous scan */
        oldActiveIDs = 0u;
        for (i = 0u; i < ptrOldTouches->touchNum; i++)
        {
            oldActiveIDs |= (uint8)(1u << ptrOldTouches->touch[i].id);
        }

        /* Set up the fingerPosIndex to the head of scratch buffer. It will be used to hold association between previous and current fingers */
        fingerPosIndex = touchPadBuffer;

        /* This is a int32 matrix sized MAX_LOCAL_PEAKS x MAX_LOCAL_PEAKS. Make sure its start address is divisible by 4 */
        distanceMap = (capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP *)
                      (((uint32)touchPadBuffer + (capsense_ADC_CSX_MAX_LOCAL_PEAKS + capsense_ADC_CSX_TOUCHPAD_PADDING)) &
                        (uint32)~capsense_ADC_CSX_TOUCHPAD_PADDING);

        if (0u < newTouchNum)
        {
            for (i = capsense_ADC_CSX_MAX_LOCAL_PEAKS; i-- > 0u;)
            {
                /* Set all new touches structure array members as not assigned */
                ptrNewTouches->touch[i].id = capsense_ADC_CSX_TOUCHPAD_UNDEFINED;
            }

            if (0u == ptrOldTouches->touchNum)
            {
                /* If the previous touch tracking had not any touches. */
                for (i = 0u; i < newTouchNum; i++)
                {
                    /* Initializes a new touch, set ID to next value and Age to 0. */
                    capsense_ADC_NewTouch(i, ptrWidgetRam->onDebounce, fingerOnThreshold);
                }
            }
            else
            {
                /* General case */
                if (newTouchNum >= ptrOldTouches->touchNum)
                {
                    if ((1u == newTouchNum) && (1u == ptrOldTouches->touchNum))
                    {
                        /* Don't call Hungarian for 1 current and 1 previous touch. */
                        fingerPosIndex[0u] = 0;
                    }
                    else
                    {
                        /* Calculating and filling Distance Map array. */
                        capsense_ADC_FillDistanceMap(distanceMap, ptrOldTouches);

                        /* Call Hungarian method procedure. */
                        capsense_ADC_Hungarian(newTouchNum, ptrOldTouches->touchNum, fingerPosIndex, distanceMap);
                    }

                    for (i = 0u; i < ptrOldTouches->touchNum; i++)
                    {
                        if (ptrWidgetRam->velocity <
                            capsense_ADC_CalcDistance((uint32)fingerPosIndex[i], i, ptrOldTouches))
                        {
                            /* Set new ID and reset Age. */
                            capsense_ADC_NewTouch((uint32)fingerPosIndex[i], ptrWidgetRam->onDebounce, fingerOnThreshold);
                        }
                        else
                        {
                            /* Set ID to previous value and increase Age. */
                            newActiveIDs |= (uint8)(1u << (ptrOldTouches->touch[i].id));
                            capsense_ADC_TransferTouch((uint32)fingerPosIndex[i], i, ptrOldTouches);
                        }
                    }

                    /* Added new fingers, they need to assign ID. */
                    if (newTouchNum > ptrOldTouches->touchNum)
                    {
                        /* Search new fingers. */
                        for (i = 0u; i < newTouchNum; i++)
                        {
                            /* New finger found. */
                            if (ptrNewTouches->touch[i].id == capsense_ADC_CSX_TOUCHPAD_UNDEFINED)
                            {
                                capsense_ADC_NewTouch(i, ptrWidgetRam->onDebounce, fingerOnThreshold);
                            }
                        }
                    }
                }
                else
                {
                    /* newTouchNum is less than ptrOldTouches->touchNum */

                    /* Calculating and filling Distance Map array. */
                    capsense_ADC_FillDistanceMap(distanceMap, ptrOldTouches);

                    /* Call Hungarian method procedure. */
                    capsense_ADC_Hungarian(ptrOldTouches->touchNum, newTouchNum, fingerPosIndex, distanceMap);

                    for (i = 0u; i < newTouchNum; i++)
                    {
                        if (ptrWidgetRam->velocity <
                            capsense_ADC_CalcDistance(i, (uint32)fingerPosIndex[i], ptrOldTouches))
                        {
                            /* Set new ID and reset Age. */
                            capsense_ADC_NewTouch(i, ptrWidgetRam->onDebounce, fingerOnThreshold);
                        }
                        else
                        {
                            /* Set ID to previous value and increase Age. */
                            newActiveIDs |= (uint8)(1u << (ptrOldTouches->touch[i].id));
                            capsense_ADC_TransferTouch(i, (uint32)fingerPosIndex[i], ptrOldTouches);
                        }
                    }
                }
            }

            capsense_ADC_TouchDownDebounce();
        }

        #if capsense_ADC_OFF_DEBOUNCE_EN
            capsense_ADC_LiftOffDebounce(ptrWidgetRam->offDebounce, ptrOldTouches);
        #endif

        if ((ptrNewTouches->touchNum >= 1u) || (ptrOldTouches->touchNum != 0u))
        {
            capsense_ADC_SortByAge();
        }

        /* Store new touches as old touches */
        for (i = ptrNewTouches->touchNum; i-- > 0u;)
        {
            capsense_ADC_CopyTouchRecord(&ptrOldTouches->touch[i], &ptrNewTouches->touch[i]);
        }

        ptrOldTouches->touchNum = ptrNewTouches->touchNum;

        /* Save ID allocation masks for usage in the next iteration. */
        oldActiveIDs = newActiveIDs;
    }
 }


/*******************************************************************************
* Function Name: capsense_ADC_TransferTouch
****************************************************************************//**
*
* \brief
*   Copies ID, increments age and decrements debounce(if debounce > 0) parameters
*   for the new touch that has been detected also in the old touches.
*
* \details
*   Copies ID, increments age and decrements debounce(if debounce > 0) parameters
*   for the new touch that has been detected also in the old touches.
*
* \param newIndex The touch index of touch array in the new touches structure.
* \param oldIndex The touch index of touch array in the old touches structure.
* \param ptrOldTouches The pointer to the old touches structure.
*
*******************************************************************************/
static void capsense_ADC_TransferTouch(
                            uint32 newIndex, uint32 oldIndex, capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches)
{
    ptrNewTouches->touch[newIndex].id = ptrOldTouches->touch[oldIndex].id;

    ptrNewTouches->touch[newIndex].age = ptrOldTouches->touch[oldIndex].age + 1u;

    /* Decrement debounce counter if the touch in touch down ot lift off stage (debounce counter > 0) */
    if (0u != (ptrOldTouches->touch[oldIndex].debounce & capsense_ADC_CSX_TOUCHPAD_DEBOUNCE_MASK))
    {
        ptrNewTouches->touch[newIndex].debounce = ptrOldTouches->touch[oldIndex].debounce - 1u;
    }
    else
    {
        ptrNewTouches->touch[newIndex].debounce = ptrOldTouches->touch[oldIndex].debounce;
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_NewTouch
****************************************************************************//**
*
* \brief
*   Set ID, age and on debounce parameters for a new touch.
*
* \details
*   Raw count of a local maximum has to be higher than fingerOnThreshold threshold
*   so the new touch is accepted. If raw count is lower than the fingerOnThreshold
*   than corresponding touch is marked with capsense_ADC_CSX_TOUCHPAD_FT_ON_FAIL
*   ID and will be deleted from new touches structure in capsense_ADC_SortByAge()
*   (new touches structure is reorganized in this case).
*
* \param newIndex The touch index of touch array in the new touches structure.
* \param onDebounce Counter value for touch down procedure.
* \param fingerOnThreshold The finger ON threshold (finger threshold + hysteresis)
*
*******************************************************************************/
static void capsense_ADC_NewTouch(uint32 newIndex, uint8 onDebounce, uint16 fingerOnThreshold)
{
    uint32 idx;

    /* Touch is not accepted */
    if (ptrNewTouches->touch[newIndex].rawCount < fingerOnThreshold)
    {
        ptrNewTouches->touch[newIndex].id = capsense_ADC_CSX_TOUCHPAD_FT_ON_FAIL;
    }
    else
    {
        /* Create a bit map of ID's currently used and previously used and search for the new lowest ID */
        idx = capsense_ADC_GetLowestId(((uint16)oldActiveIDs | (uint16)newActiveIDs));

        /* Indicate that ID is now taken */
        newActiveIDs |= (uint8)(1u << idx);

        /* Set the ID */
        ptrNewTouches->touch[newIndex].id = LO8(idx);

        /* Set the age */
        ptrNewTouches->touch[newIndex].age = 1u;

        /* New Finger goes through touchdown debounce procedure if required */
        ptrNewTouches->touch[newIndex].debounce = onDebounce | capsense_ADC_CSX_TOUCHPAD_TOUCH_DOWN;
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_GetLowestId
****************************************************************************//**
*
* \brief
*   Returns the lowest available touch ID.
*
* \details
*   Returns the lowest available touch ID.
*
* \param idMask The mask of IDs used in new and old touches.
*
* \return   Returns the lowest available touch ID. If no ID was available,
*           capsense_ADC_CSX_TOUCHPAD_TOUCH_ABSENT_ID is returned.
*
*******************************************************************************/
CY_INLINE static uint8 capsense_ADC_GetLowestId(uint16 idMask)
{
    uint32 idx;
    uint32 touchId = capsense_ADC_CSX_TOUCHPAD_TOUCH_ABSENT_ID;

    /* Search for the lowest available ID. */
    idMask >>= capsense_ADC_CSX_TOUCHPAD_TOUCH_MIN_ID;

    for (idx = capsense_ADC_CSX_TOUCHPAD_TOUCH_MIN_ID; idx <= capsense_ADC_CSX_TOUCHPAD_TOUCH_MAX_ID; idx++)
    {
        /* Determine if the new ID is available. */
        if (0u == (idMask & 1u))
        {
            touchId = idx;
            break;
        }

        idMask >>= 1u;
    }

    /* Return an indicator of failure. */
    return (uint8)(touchId);
}


/*******************************************************************************
* Function Name: capsense_ADC_TouchDownDebounce
****************************************************************************//**
*
* \brief
*   Handles touch down de-bouncing.
*
* \details
*   Even if a new touch is detected it is not considered as active until
*   on debounce counter has not reached zero. If on debounce counter has reached zero
*   the touch down mask is cleared. Otherwise the age of the new finger is cleared
*   (it is considered as not active)
*
*******************************************************************************/
CY_INLINE static void capsense_ADC_TouchDownDebounce(void)
{
    uint32 i;

    for (i = 0u; i < ptrNewTouches->touchNum; i++)
    {
        /* If it is a touchdown debouncing finger its age is set to zero */
        if (0u != (ptrNewTouches->touch[i].debounce & capsense_ADC_CSX_TOUCHPAD_TOUCH_DOWN))
        {
            if ((ptrNewTouches->touch[i].debounce & capsense_ADC_CSX_TOUCHPAD_DEBOUNCE_MASK) <= 1u)
            {
                /* If debounce counter reached zero than touch down stage
                 * is finished and corresponding mask is cleared
                 */
                ptrNewTouches->touch[i].debounce &=
                    (uint8)~(capsense_ADC_CSX_TOUCHPAD_TOUCH_DOWN | capsense_ADC_CSX_TOUCHPAD_DEBOUNCE_MASK);
            }
            else
            {
                /* Set the age to zero - finger is not active */
                ptrNewTouches->touch[i].age = 0u;
            }
        }
    }
}


#if (0u != capsense_ADC_OFF_DEBOUNCE_EN)
/*******************************************************************************
* Function Name: capsense_ADC_LiftOffDebounce
****************************************************************************//**
*
* \brief
*   Handles lift off de-bouncing.
*
* \details
*   Even if a touch is not present in new touches, but present in old
*   touches this means it is lift off event. This touch is considered as active and
*   is added to new touches structure until the offDebounce counter reaches zero.
*   The offDebounce counter is set when lift off event is detected and is decremented
*   each time the capsense_ADC_LiftOffDebounce() API is called.
*
* \param offDebounce   The off debounce counter value.
* \param ptrOldTouches The pointer to the old touches structure.
*
*******************************************************************************/
CY_INLINE static void capsense_ADC_LiftOffDebounce(uint8 offDebounce,
                                                       capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches)
{
    uint32 i;
    uint8 liftOffMask = (uint8)(~newActiveIDs) & oldActiveIDs;

    if(liftOffMask != 0u)
    {
        for (i = 0u; i < ptrOldTouches->touchNum; i++)
        {
            /*
             * The old touch is not found in the new touches.
             * Lift off procedure starts and the old touch is copied to the new touches if there is a room.
             */

            if (((uint8)(0x01u << ptrOldTouches->touch[i].id) & liftOffMask) != 0u)
            {
                /* If there is a room in new touches structure and the old touch is not under touch down debounce procedure */
                if ((ptrNewTouches->touchNum < capsense_ADC_CSX_MAX_LOCAL_PEAKS) &&
                    (0u == (ptrOldTouches->touch[i].debounce & capsense_ADC_CSX_TOUCHPAD_TOUCH_DOWN)))
                {
                    /* Lift off debouncing starts if there is not lift off mask in the old touch */
                    if ((ptrOldTouches->touch[i].debounce & capsense_ADC_CSX_TOUCHPAD_LIFT_OFF) == 0u)
                    {
                        ptrOldTouches->touch[i].debounce = offDebounce | capsense_ADC_CSX_TOUCHPAD_LIFT_OFF;

                        /* Copy the old finger data to the new one using TransferTouch API to manage age and debounce */
                        capsense_ADC_TransferTouch((uint32)ptrNewTouches->touchNum, i, ptrOldTouches);
                        ptrNewTouches->touch[ptrNewTouches->touchNum].x = ptrOldTouches->touch[i].x;
                        ptrNewTouches->touch[ptrNewTouches->touchNum].y = ptrOldTouches->touch[i].y;
                        ptrNewTouches->touch[ptrNewTouches->touchNum].z = ptrOldTouches->touch[i].z;
                        ptrNewTouches->touch[ptrNewTouches->touchNum].rawCount = ptrOldTouches->touch[i].rawCount;
                        ptrNewTouches->touchNum++;
                    }
                    else
                    {
                        /* Check whether debounce counter is reached zero if there is a lift off mask in the old touch */
                       if ((ptrOldTouches->touch[i].debounce & capsense_ADC_CSX_TOUCHPAD_DEBOUNCE_MASK) == 0u)
                       {
                            /* Clear lift off mask if debounce counter has reached zero */
                            ptrOldTouches->touch[i].debounce &= (uint8)~capsense_ADC_CSX_TOUCHPAD_LIFT_OFF;
                       }
                       else
                       {
                            /* Copy the old finger data to the new one using TransferTouch API to manage age and debounce */
                            capsense_ADC_TransferTouch((uint32)ptrNewTouches->touchNum, i, ptrOldTouches);
                            ptrNewTouches->touch[ptrNewTouches->touchNum].x = ptrOldTouches->touch[i].x;
                            ptrNewTouches->touch[ptrNewTouches->touchNum].y = ptrOldTouches->touch[i].y;
                            ptrNewTouches->touch[ptrNewTouches->touchNum].z = ptrOldTouches->touch[i].z;
                            ptrNewTouches->touch[ptrNewTouches->touchNum].rawCount = ptrOldTouches->touch[i].rawCount;
                            ptrNewTouches->touchNum++;
                       }
                    }
                }
            }
        }
    }
}
#endif /* (0u != capsense_ADC_OFF_DEBOUNCE_EN) */

/*******************************************************************************
* Function Name: capsense_ADC_CalcDistance
****************************************************************************//**
*
* \brief
*   Calculates squared distance between old and new touches pointed by the input
*   parameters.
*
* \details
*   Calculates squared distance between old and new touches pointed by the input
*   parameters.
*
* \param newIndex      The index of touch in the new touches structure.
* \param oldIndex      The index of touch in the old touches structure.
* \param ptrOldTouches The pointer to the old touches structure.
*
* \return Returns the squared distance.
*
*******************************************************************************/
static uint32 capsense_ADC_CalcDistance(uint32 newIndex, uint32 oldIndex,
                                                      capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches)
{
    int32 result;
    int32 xDistance = (int32)(ptrOldTouches->touch[oldIndex].x) - (int32)(ptrNewTouches->touch[newIndex].x);
    int32 yDistance = (int32)(ptrOldTouches->touch[oldIndex].y) - (int32)(ptrNewTouches->touch[newIndex].y);

    result = ((xDistance * xDistance) + (yDistance *yDistance));
    return (uint32)result;
}


/*******************************************************************************
* Function Name: capsense_ADC_FillDistanceMap
****************************************************************************//**
*
* \brief
*   Populates the distance map used for the Hungarian method with distance
*   squared values.
*
* \details
*   Distance squared is used instead of distance to eliminate square root
*   calculation, which requires a lot of execution time.
*
* \param distanceMap   The pointer to a 2-dimensional array of int32's
*                          with dimensions capsense_ADC_CSX_MAX_LOCAL_PEAKS x
*                          capsense_ADC_CSX_MAX_LOCAL_PEAKS
* \param ptrOldTouches The pointer to the old touches structure.
*
* \return The contents of distanceMap[][] are modified.
*
*******************************************************************************/
static void capsense_ADC_FillDistanceMap(capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP *distanceMap,
                                             capsense_ADC_CSX_TOUCHPAD_DATA_STRUCT *ptrOldTouches)
{
    uint32 i;
    uint32 j;

    if (ptrNewTouches->touchNum >= ptrOldTouches->touchNum)
    {
        for (i = ptrNewTouches->touchNum; i-- > 0u; )
        {
            for (j = ptrOldTouches->touchNum; j-- > 0u; )
            {
                distanceMap[i][j] = (int32)capsense_ADC_CalcDistance(i, j, ptrOldTouches);
            }
        }
    }
    else
    {
        for (i = ptrOldTouches->touchNum; i-- > 0u;)
        {
            for (j = ptrNewTouches->touchNum; j-- > 0u;)
            {
                distanceMap[i][j] = (int32)capsense_ADC_CalcDistance(j, i, ptrOldTouches);
            }
        }
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_Hungarian
****************************************************************************//**
*
* \brief
*   Executes the Hungarian Method on a distance map to track motion of two touch sets
*   (old touches vs new touches)
*
* \details
*   This function uses the Hungarian method described in specification 001-63362.
*   There is no bounds checking on the parameters. It is the calling function's
*   responsibility to ensure parameter validity.
*
* \param rowCount       Number of elements in row of distanceMap matrix. This value must be
*                       greater than or equal to colCount.
* \param colCount       Number of elements in column of distanceMap matrix.This value must
*                       be greater than or equal to 1.
* \param fingerPosIndex The pointer to an array where associations between the
*                             previous and current touches are returned.
* \param distanceMap    The 2-dimensional map of distances between the nodes in each
*                          coordinate set. The 1st index of distanceMap corresponds to nodes
*                          in the 1st coordinate data set, and the 2nd index of distanceMap
*                          corresponds to the 2nd coordinate data set. Each element in
*                          distanceMap is the square of the distance between the
*                          corresponding coordinates in the 1st and 2nd data set.
*
*
* \return Returns fingerPosIndex, the associations between the 1st and 2nd coordinate set are
*                          returned in the array referenced by this pointer. It is indexed
*                          by the 2nd coordinate set, and its elements are the corresponding
*                          index in the 1st coordinate set.
*
*******************************************************************************/
static void capsense_ADC_Hungarian(uint8 rowCount, uint8 colCount, int8 *fingerPosIndex,
                             capsense_ADC_CSX_TOUCHPAD_DISTANCE_MAP *distanceMap)
{
    int32 col[capsense_ADC_CSX_MAX_LOCAL_PEAKS];
    int32 row[capsense_ADC_CSX_MAX_LOCAL_PEAKS];
    int32 *mins;
    int32 delta;

    int8 *links;
    int8 *visited;
    int8 *markIndices;

    int32 colValue = 0;
    int32 markedI = 0;
    int32 markedJ = 0;
    int32 i = 0;
    int32 i1 = 0;
    int32 j = 0;
    int32 j1 = 0;

    mins = (int32 *)(distanceMap + capsense_ADC_CSX_MAX_LOCAL_PEAKS);
    links = (int8 *)(mins + capsense_ADC_CSX_MAX_LOCAL_PEAKS);
    visited = links + capsense_ADC_CSX_MAX_LOCAL_PEAKS;
    markIndices = visited + capsense_ADC_CSX_MAX_LOCAL_PEAKS;

    (void)memset(col, 0, (uint32)colCount * 4u);

    /* Initialize row and markIndices arrays */
    for (i1 = (int32)rowCount; i1-- > 0;)
    {
        row[i1] = 0;
        markIndices[i1] = -1;
    }

    /* Go through all columns */
    for (i = (int32)colCount; i-- > 0;)
    {
        /* Initialize visited, links, mins arrays. They used for every column */
        for (i1 = (int32)rowCount; i1-- > 0;)
        {
            visited[i1] = 0;
            links[i1] = -1;
            mins[i1] = (int32)capsense_ADC_CSX_TOUCHPAD_INT32;
        }

        /* Next two variables are used to mark column and row */
        markedI = i;
        markedJ = -1;

        while (markedI != -1)
        {
            j = -1;
            colValue = col[markedI];

            /* Go through all rows */
            for (j1 = (int32)rowCount; j1-- > 0;)
            {
                if (visited[j1] == 0)
                {
                    delta = distanceMap[j1][markedI] - row[j1] - colValue;

                    /* Find the minimum element index in column i */
                    if (mins[j1] > delta)
                    {
                        mins[j1] = delta;
                        links[j1] = (int8)markedJ;
                    }

                    if ((j == -1) || (mins[j1] < mins[j]))
                    {
                        j = j1;
                    }
                }
            }

            delta = mins[j];

            /* Go through all row */
            for (j1 = (int32)rowCount; j1-- > 0;)
            {
                if (visited[j1] != 0)
                {
                    col[markIndices[j1]] += delta;
                    row[j1] -= delta;
                }
                else
                {
                    mins[j1] -= delta;
                }
            }

            col[i] +=  delta;

            visited[j] = 1;
            markedJ = j;
            markedI = markIndices[j];
        }

        while (links[j] != -1)
        {
            markIndices[j] = markIndices[links[j]];
            j = links[j];
        }

        markIndices[j] = (int8)i;
    }

    /* Provide an association between two sets of touches */
    for (j = (int32)rowCount; j-- > 0;)
    {
        if (markIndices[j] != -1)
        {
            fingerPosIndex[markIndices[j]] = (int8)j;
        }
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_SortByAge
****************************************************************************//**
*
* \brief
*   Sorts the new touches array by age (in decrementing order) and Id (in incrementing order) fields.
*
* \details
*   Sorts the new touches array by age (in decrementing order) and Id (in incrementing order) fields.
*
*******************************************************************************/
CY_INLINE static void capsense_ADC_SortByAge(void)
{
    uint32 i;
    uint32 j;
    capsense_ADC_CSX_TOUCHPAD_PEAK_STRUCT tempTouch;
    uint32 newTouchNum = ptrNewTouches->touchNum;

    /*
     * Delete failed touch by coping(rewriting) the last touch content to the failed touch.
     * If the last touch record is invalid try the penult touch record and so on.
     */

    for (i = 0u; i < newTouchNum; i++)
    {
        if (ptrNewTouches->touch[i].id > capsense_ADC_CSX_TOUCHPAD_TOUCH_MAX_ID)
        {
            for (j = (newTouchNum - 1u); j > i; j--)
            {
                /* Check the touch records from the last to the current.
                 * If the touch record is valid then replace the current touch record
                 */
                if (ptrNewTouches->touch[j].id <= capsense_ADC_CSX_TOUCHPAD_TOUCH_MAX_ID)
                {
                    capsense_ADC_CopyTouchRecord(&ptrNewTouches->touch[i], &ptrNewTouches->touch[j]);

                    /* Finish the loop. The valid touch record is found and copied down */
                    break;
                }
                else
                {
                    /* Decrement the number of touch records.
                     * The last touch record is invalid - try the penult touch record
                     */
                    newTouchNum--;
                }
            }

            /* Decrement the number of touch records.
             * The last touch record is valid and copied to the current position (i)
             */
            newTouchNum--;
        }
    }

    /* Set new number of touches */
    ptrNewTouches->touchNum = (uint8)newTouchNum;

    /* Sort new touches structure */
    for (i = 0u; i < newTouchNum; i++)
    {
        for (j = (i + 1u); j < newTouchNum; j++)
        {
            /* if next touches have higher age or lower id with the same age then swap touches */
            if ((ptrNewTouches->touch[i].age < ptrNewTouches->touch[j].age)      ||
                ((ptrNewTouches->touch[i].age == ptrNewTouches->touch[j].age) &&
                 (ptrNewTouches->touch[i].id > ptrNewTouches->touch[j].id)))
            {
                /* Swap touches */
                capsense_ADC_CopyTouchRecord(&tempTouch, &ptrNewTouches->touch[i]);
                capsense_ADC_CopyTouchRecord(&ptrNewTouches->touch[i], &ptrNewTouches->touch[j]);
                capsense_ADC_CopyTouchRecord(&ptrNewTouches->touch[j], &tempTouch);
            }
        }
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_CopyTouchRecord
****************************************************************************//**
*
* \brief
*   Copies content from the source touch structure to the destination touch structure.
*
* \details
*   Copies content from the source touch structure to the destination touch structure.
*
* \param *destination The pointer to the destination touch structure.
* \param *source      The pointer to the source touch structure.
*
*******************************************************************************/
static void capsense_ADC_CopyTouchRecord(capsense_ADC_CSX_TOUCHPAD_PEAK_STRUCT *destination,
                                                       capsense_ADC_CSX_TOUCHPAD_PEAK_STRUCT *source)
{
    destination->x        =  source->x;
    destination->y        =  source->y;
    destination->z        =  source->z;
    destination->rawCount =  source->rawCount;
    destination->id       =  source->id;
    destination->age      =  source->age;
    destination->debounce =  source->debounce;
}


/*******************************************************************************
* Function Name: capsense_ADC_DpFilterTouchRecord
****************************************************************************//**
*
* \brief
*   Filter position data of every valid touch, if there is a room in RAM Widget Data Structure
*   and update corresponding fields in RAM Widget Data Structure
*
* \details
*  This API checks every touch in the new touches structure if it is valid until there is a room
*  in the RAM Widget Data Structure (where touch reports are stored). If touch is valid
*  (valid id and age > 0) then touch is filtered if filter is enabled. At the end the
*  corresponding fields are updated in the RAM Widget Data Structure.
*
* \param ptrFlashWdgt The pointer to the Flash Widget Structure.
*
* \return The number of reported touches to the RAM Data Structure.
*
*******************************************************************************/
uint32 capsense_ADC_DpFilterTouchRecord(capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt)
{
    uint32 i;
    uint32 reportedTouchNum = 0u;
    capsense_ADC_RAM_WD_CSX_TOUCHPAD_STRUCT *ptrWidgetRam = ptrFlashWdgt->ptr2WdgtRam;

    #if (0u != capsense_ADC_POSITION_FILTER_EN)
        uint32 oldIdMask = 0u;
        uint32 j;
        uint16 filteredX;
        uint16 filteredY;
        capsense_ADC_TOUCHPAD_POS_HISTORY_STRUCT *ptrHistory;

    #endif /* (0u != capsense_ADC_POSITION_FILTER_EN) */

    #if (0u != capsense_ADC_POSITION_FILTER_EN)
        ptrHistory = ptrFlashWdgt->ptr2PosHistory;
        /* Find what Ids were active in the previous report */
        for (i = 0u; i < capsense_ADC_CSX_MAX_FINGERS; i++)
        {
            oldIdMask |= 0x01Lu << ptrWidgetRam->touch[i].id;
        }
    #endif /* (0u != capsense_ADC_POSITION_FILTER_EN) */

    /* Go through all touch fields in RAM Data Structure */
    for (i = 0u; i < capsense_ADC_CSX_MAX_FINGERS; i++)
    {
        /* Check if touch is valid to be reported: age has to be higher than 0. Id has been checked in SortByAge API */
        if ((i < ptrNewTouches->touchNum) && (ptrNewTouches->touch[i].age > 0u))
        {
            #if (0u == capsense_ADC_POSITION_FILTER_EN)
                /* Report touch to the RAM Data Structure if position filter is disabled in general */
                ptrWidgetRam->touch[i].x = ptrNewTouches->touch[i].x;
                ptrWidgetRam->touch[i].y = ptrNewTouches->touch[i].y;
                ptrWidgetRam->touch[i].z = ptrNewTouches->touch[i].z;
                ptrWidgetRam->touch[i].id = ptrNewTouches->touch[i].id;
            #else

                filteredX = ptrNewTouches->touch[i].x;
                filteredY = ptrNewTouches->touch[i].y;

                /* Initialize position and filter history if the touch has the id that was absent in the previous touch report */
                if (0u == (oldIdMask & (1Lu << ptrNewTouches->touch[i].id)))
                {
                    ptrWidgetRam->touch[i].x = ptrNewTouches->touch[i].x;
                    ptrWidgetRam->touch[i].y = ptrNewTouches->touch[i].y;
                    ptrWidgetRam->touch[i].z = ptrNewTouches->touch[i].z;
                    ptrWidgetRam->touch[i].id = ptrNewTouches->touch[i].id;
                    if (NULL != ptrHistory)
                    {
                        capsense_ADC_InitPosFiltersDd(&ptrHistory[i], filteredX, filteredY);
                    }
                }
                /* Find corresponding position history of the new touch (by id) in the RAW Widget Data Structure and Position History */
                else
                {
                    /*
                    * Index <i> addresses new touch array and final reported in data structure array.
                    * Index <j> addresses filter history and previously reported in data structure array.
                    *
                    * If new touch appears, then it is always added at the and of arrays, therefore it
                    * is safe to overwrite history with new touch.
                    * Another case is moving touch from its previous reported index to new index.
                    * This new index is always lower, so filter history of touch (i-1) was already taken
                    * and processed for touch (i-1). Therefore, again, it is safely to copy filter history
                    * from j to i.
                    */
                    for(j = 0u; j < capsense_ADC_CSX_MAX_FINGERS; j++)
                    {
                        if(ptrNewTouches->touch[i].id == ptrWidgetRam->touch[j].id)
                        {
                            capsense_ADC_RunPosFiltersDd(ptrFlashWdgt, i, j, &filteredX, &filteredY);

                            ptrWidgetRam->touch[i].x = filteredX;
                            ptrWidgetRam->touch[i].y = filteredY;
                            ptrWidgetRam->touch[i].z = ptrNewTouches->touch[i].z;
                            ptrWidgetRam->touch[i].id = ptrNewTouches->touch[i].id;
                        }
                    }
                }
            #endif
            reportedTouchNum++;
        }
        else
        {
            ptrWidgetRam->touch[i].x = capsense_ADC_CSX_TOUCHPAD_POSITION_NONE;
            ptrWidgetRam->touch[i].y = capsense_ADC_CSX_TOUCHPAD_POSITION_NONE;
            ptrWidgetRam->touch[i].z = LO8(capsense_ADC_CSX_TOUCHPAD_POSITION_NONE);
            ptrWidgetRam->touch[i].id = capsense_ADC_CSX_TOUCHPAD_UNDEFINED;

            #if (0u != capsense_ADC_POSITION_FILTER_EN)
                if (NULL != ptrHistory)
                {
                    /* Initialize history for non-valid touches */
                    capsense_ADC_InitPosFiltersDd(&ptrHistory[i], capsense_ADC_CSX_TOUCHPAD_POSITION_NONE, capsense_ADC_CSX_TOUCHPAD_POSITION_NONE);
                }
            #endif /* (0u != capsense_ADC_POSITION_FILTER_EN) */
        }
    }
    return reportedTouchNum;
}

#endif /* #if capsense_ADC_CSX_TOUCHPAD_WIDGET_EN */

#if (0u != capsense_ADC_POSITION_FILTER_EN)
/*******************************************************************************
* Function Name: capsense_ADC_InitPosFiltersSd
****************************************************************************//**
*
* \brief
*  Writes desired value into single-dimension position filter history.
*
* \details
*  Writes desired value into single-dimension position filter history.
*
* \param ptrHistory
*  The pointer to the structure that holds previous historical position value.
*
* \param value
*  The desired value to initialize position filters history.
*
*******************************************************************************/
void capsense_ADC_InitPosFiltersSd(capsense_ADC_SLIDER_POS_HISTORY_STRUCT *ptrHistory, uint16 value)
{
    if (NULL != ptrHistory)
    {
        #if (0u != capsense_ADC_POS_MEDIAN_FILTER_EN)
            ptrHistory->posMedianZ1 = value;
            ptrHistory->posMedianZ2 = value;
        #endif /* #if (0u != capsense_ADC_POS_MEDIAN_FILTER_EN) */

        #if (0u != capsense_ADC_POS_IIR_FILTER_EN)
            ptrHistory->posIIR = value;
        #endif /* #if (0u != capsense_ADC_POS_IIR_FILTER_EN) */

        #if (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN)
            ptrHistory->posAIIR = value;
        #endif /* (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN) */

        #if (0u != capsense_ADC_POS_AVERAGE_FILTER_EN)
            ptrHistory->posAverage = value;
        #endif /* #if (0u != capsense_ADC_POS_AVERAGE_FILTER_EN) */

        #if (0u != capsense_ADC_POS_JITTER_FILTER_EN)
            ptrHistory->posJitter = value;
        #endif /* #if (0u != capsense_ADC_POS_JITTER_FILTER_EN) */
    }
}

#if ((0u != capsense_ADC_CSD_TOUCHPAD_WIDGET_EN) || (0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN))
/*******************************************************************************
* Function Name: capsense_ADC_InitPosFiltersDd
****************************************************************************//**
*
* \brief
*  Writes desired value into two-dimension position filter history.
*
* \details
*  Writes desired value into two-dimension position filter history.
*
* \param ptrHistory
*  The pointer to the structure that holds previous historical position value.
*
* \param posX
*  The desired value of X position to initialize position filters history.
*
* \param posY
*  The desired value of Y position to initialize position filters history.
*
*******************************************************************************/
void capsense_ADC_InitPosFiltersDd(capsense_ADC_TOUCHPAD_POS_HISTORY_STRUCT *ptrHistory, uint16 posX, uint16 posY)
{
    if (NULL != ptrHistory)
    {
        capsense_ADC_InitPosFiltersSd(&ptrHistory->xPos, posX);
        capsense_ADC_InitPosFiltersSd(&ptrHistory->yPos, posY);
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_RunPosFiltersDd
****************************************************************************//**
*
* \brief
*  Filters two-dimension touch position of touchpad widget.
*
* \details
*  Filters two-dimension touch position of touchpad widget.
*
* \param ptrFlashWdgt
*  The pointer to the Flash Widget Object.
*
* \param i
*  The index in the touch array where newly filtered position should be stored to.
*
* \param j
*  The index in the touch array where previous position filter history should be
*  taken from.
*
* \param posX
*  The pointer to new X position to be filtered.
*
* \param posY
*  The pointer to new Y position to be filtered.
*
*******************************************************************************/
void capsense_ADC_RunPosFiltersDd(capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt, uint32 i, uint32 j,
            uint16 * posX, uint16 * posY)
{
    uint16 filteredX;
    uint16 filteredY;
    uint32 filterConfig;
    capsense_ADC_TOUCHPAD_POS_HISTORY_STRUCT *ptrHistory;
    capsense_ADC_SLIDER_POS_HISTORY_STRUCT *ptrHistoryPosX;
    capsense_ADC_SLIDER_POS_HISTORY_STRUCT *ptrHistoryPosY;
    capsense_ADC_SLIDER_POS_HISTORY_STRUCT *ptrNewHistoryPosX;
    capsense_ADC_SLIDER_POS_HISTORY_STRUCT *ptrNewHistoryPosY;

    #if ((0u != capsense_ADC_POS_AVERAGE_FILTER_EN) || \
         (0u != capsense_ADC_POS_MEDIAN_FILTER_EN))
        uint16 tempPosition;
    #endif /* ((0u != capsense_ADC_POS_AVERAGE_FILTER_EN) ||
         (0u != capsense_ADC_POS_MEDIAN_FILTER_EN)) */

    #if (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN)
        ADAPTIVE_FILTER_CONTEXT_STRUCT contextAIIR;
    #endif /* (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN) */

    #if (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN)
        ADAPTIVE_FILTER_CONFIG_STRUCT const *ptrAiirConfig = NULL;
    #endif /* (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN) */

    filteredX = *posX;
    filteredY = *posY;
    filterConfig = ptrFlashWdgt->staticConfig;
    ptrHistory = ptrFlashWdgt->ptr2PosHistory;
    ptrHistoryPosX = &ptrHistory[j].xPos;
    ptrHistoryPosY = &ptrHistory[j].yPos;
    ptrNewHistoryPosX = &ptrHistory[i].xPos;
    ptrNewHistoryPosY = &ptrHistory[i].yPos;

    #if (0u != capsense_ADC_POS_MEDIAN_FILTER_EN)
        if (0u != (filterConfig & capsense_ADC_POS_MEDIAN_FILTER_MASK))
        {
            tempPosition = (uint16)capsense_ADC_FtMedian((uint32)ptrHistoryPosX->posMedianZ2, (uint32)ptrHistoryPosX->posMedianZ1, (uint32)filteredX);
            /* Store filter history from <j> place of previous report to <i> place of new report */
            ptrNewHistoryPosX->posMedianZ2 = ptrHistoryPosX->posMedianZ1;
            ptrNewHistoryPosX->posMedianZ1 = filteredX;
            filteredX = tempPosition;
            tempPosition = (uint16)capsense_ADC_FtMedian((uint32)ptrHistoryPosY->posMedianZ2, (uint32)ptrHistoryPosY->posMedianZ1, (uint32)filteredY);
            /* Store filter history from <j> place of previous report to <i> place of new report */
            ptrNewHistoryPosY->posMedianZ2 = ptrHistoryPosY->posMedianZ1;
            ptrNewHistoryPosY->posMedianZ1 = filteredY;
            filteredY = tempPosition;
        }
    #endif

    #if (0u != capsense_ADC_POS_IIR_FILTER_EN)
        if (0u != (filterConfig & capsense_ADC_POS_IIR_FILTER_MASK))
        {
            filteredX = (uint16)capsense_ADC_FtIIR1stOrder((uint32)filteredX, (uint32)ptrHistoryPosX->posIIR, (uint32)ptrFlashWdgt->iirFilterCoeff, 0uL);
            ptrNewHistoryPosX->posIIR = filteredX;
            filteredY = (uint16)capsense_ADC_FtIIR1stOrder((uint32)filteredY, (uint32)ptrHistoryPosY->posIIR, (uint32)ptrFlashWdgt->iirFilterCoeff, 0uL);
            ptrNewHistoryPosY->posIIR = filteredY;
        }
    #endif /* #if (0u != capsense_ADC_POS_IIR_FILTER_EN) */

    #if (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN)
        if (0u != (filterConfig & capsense_ADC_AIIR_FILTER_MASK))
        {
            switch(capsense_ADC_GET_SENSE_METHOD(ptrFlashWdgt))
            {
            #if (0u != capsense_ADC_CSD_TOUCHPAD_WIDGET_EN)
                case capsense_ADC_SENSE_METHOD_CSD_E:
                    ptrAiirConfig = &(((capsense_ADC_RAM_WD_CSD_TOUCHPAD_STRUCT *)ptrFlashWdgt->ptr2WdgtRam)->aiirConfig);
                    break;
            #endif /* #if (0u != capsense_ADC_CSD_TOUCHPAD_WIDGET_EN) */

            #if (0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN)
                case capsense_ADC_SENSE_METHOD_CSX_E:
                    ptrAiirConfig = &(((capsense_ADC_RAM_WD_CSX_TOUCHPAD_STRUCT *)ptrFlashWdgt->ptr2WdgtRam)->aiirConfig);
                    break;
            #endif /* #if (0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN) */

            default:
                CYASSERT(0u);
                break;
            }
            contextAIIR.previousX = ptrHistoryPosX->posAIIR;
            contextAIIR.previousY = ptrHistoryPosY->posAIIR;
            contextAIIR.coefficient = ptrHistoryPosX->posAIIRCoeff;
            AdaptiveFilter_Run(ptrAiirConfig, &contextAIIR, &filteredX, &filteredY);
            ptrNewHistoryPosX->posAIIR = contextAIIR.previousX;
            ptrNewHistoryPosY->posAIIR = contextAIIR.previousY;
            ptrNewHistoryPosX->posAIIRCoeff = contextAIIR.coefficient;
        }
    #endif /* (0u != capsense_ADC_POS_ADAPTIVE_IIR_FILTER_EN) */

    #if (0u != capsense_ADC_POS_AVERAGE_FILTER_EN)
        if (0u != (filterConfig & capsense_ADC_POS_AVERAGE_FILTER_MASK))
        {
            tempPosition = filteredX;
            filteredX = (uint16)(filteredX + ptrHistoryPosX->posAverage) >> 1u;
            ptrNewHistoryPosX->posAverage = tempPosition;
            tempPosition = filteredY;
            filteredY = (uint16)(filteredY + ptrHistoryPosY->posAverage) >> 1u;
            ptrNewHistoryPosY->posAverage = tempPosition;
        }
    #endif /* #if (0u != capsense_ADC_POS_AVERAGE_FILTER_EN) */

    #if (0u != capsense_ADC_POS_JITTER_FILTER_EN)
        if (0u != (filterConfig & capsense_ADC_POS_JITTER_FILTER_MASK))
        {
            filteredX = (uint16)capsense_ADC_FtJitter((uint32)filteredX, (uint32)ptrHistoryPosX->posJitter);
            ptrNewHistoryPosX->posJitter = filteredX;
            filteredY = (uint16)capsense_ADC_FtJitter((uint32)filteredY, (uint32)ptrHistoryPosY->posJitter);
            ptrNewHistoryPosY->posJitter = filteredY;
        }
    #endif /* #if (0u != capsense_ADC_POS_JITTER_FILTER_EN) */

    *posX = filteredX;
    *posY = filteredY;
}
#endif /* ((0u != capsense_ADC_CSD_TOUCHPAD_WIDGET_EN) || (0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN)) */

#endif /* (0u != capsense_ADC_POSITION_FILTER_EN) */


/* [] END OF FILE */
