/***************************************************************************//**
* \file capsense_ADC_Filter.c
* \version 7.10
*
* \brief
*   This file contains the implementation source code to implement all
*   firmware filters.
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

#include "capsense_ADC_Filter.h"
#include "capsense_ADC_Configuration.h"

#if (0 != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
    #include "capsense_ADC_SmartSense_LL.h"
#endif /* (0 != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

#if (capsense_ADC_ENABLE == capsense_ADC_SELF_TEST_EN)
    #include "capsense_ADC_SelfTest.h"
#endif

/*******************************************************************************
* Function Name: capsense_ADC_FtInitialize
****************************************************************************//**
*
* \brief
*  Initializes all the firmware filter history, except the baseline filter.
*
* \details
*  Initializes all the firmware filter history, except the baseline filter.
*
*******************************************************************************/
void capsense_ADC_FtInitialize(void)
{
    #if ((capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) || \
         (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)))
        capsense_ADC_InitializeAllFilters();
    #endif /* ((capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) || \
               (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))) */
}


/*******************************************************************************
* Function Name: capsense_ADC_UpdateAllBaselines
****************************************************************************//**
*
* \brief
*  Updates the baseline for all the sensors in all the widgets.
*
* \details
*  Updates the baseline for all the sensors in all the widgets. Baseline updating is a
*  part of data processing performed by the process functions. So, no need to
*  call this function except a specific process flow is implemented.
*
*  This function ignores the value of the wdgtEnable register. Multiple calling
*  of this function (or any other function with a baseline updating task)
*  without scanning leads to unexpected behavior.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
* \return
*  Returns the status of the update baseline operation of all the widgets:
*  - CYRET_SUCCESS - The operation is successfully completed.
*  - CYRET_BAD_DATA - The baseline processing failed.
*
*******************************************************************************/
cystatus capsense_ADC_UpdateAllBaselines(void)
{
    uint32 widgetId;
    cystatus bslnStatus = CYRET_SUCCESS;

    for(widgetId = capsense_ADC_TOTAL_WIDGETS; widgetId-- > 0u;)
    {
        bslnStatus |= capsense_ADC_UpdateWidgetBaseline(widgetId);
    }

    return(bslnStatus);
}


/*******************************************************************************
* Function Name: capsense_ADC_UpdateWidgetBaseline
****************************************************************************//**
*
* \brief
*  Updates the baselines for all the sensors in a widget specified by the input
*  parameter.
*
* \details
*  This function performs exactly the same tasks as
*  capsense_ADC_UpdateAllBaselines() but only for a specified widget.
*
*  This function ignores the value of the wdgtEnable register. Multiple calling
*  of this function (or any other function with a baseline updating task)
*  without scanning leads to unexpected behavior.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
* \param widgetId
*  Specifies the ID number of the widget to update the baseline of all the sensors
*  in the widget.
*  A macro for the widget ID can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_WDGT_ID.
*
* \return
*  Returns the status of the specified widget update baseline operation:
*  - CYRET_SUCCESS - The operation is successfully completed.
*  - CYRET_BAD_DATA - The baseline processing is failed.
*
*******************************************************************************/
cystatus capsense_ADC_UpdateWidgetBaseline(uint32 widgetId)
{
    uint32 sensorId;
    uint32 sensorsNumber;

    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    cystatus bslnStatus = CYRET_SUCCESS;

    /* Find total amount of sensors in specified widget */
    sensorsNumber = capsense_ADC_GET_SNS_CNT_BY_PTR(ptrWidget);

    for(sensorId = sensorsNumber; sensorId-- > 0u;)
    {
        bslnStatus |= capsense_ADC_UpdateSensorBaseline(widgetId, sensorId);
    }

    return(bslnStatus);
}


/*******************************************************************************
* Function Name: capsense_ADC_UpdateSensorBaseline
****************************************************************************//**
*
* \brief
*  Updates the baseline for a sensor in a widget specified by the input parameters.
*
* \details
*  This function performs exactly the same tasks as
*  capsense_ADC_UpdateAllBaselines() and
*  capsense_ADC_UpdateWidgetBaseline() but only for a specified sensor.
*
*  This function ignores the value of the wdgtEnable register. Multiple calling
*  of this function (or any other function with a baseline updating task)
*  without scanning leads to unexpected behavior.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
* \param widgetId
*  Specifies the ID number of the widget to update the baseline of the sensor
*  specified by the sensorId argument.
*  A macro for the widget ID can be found in the capsense_ADC Configuration header
*  file defined as capsense_ADC_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to update its baseline.
*  A macro for the sensor ID within a specified widget can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_SNS<SensorNumber>_ID.
*
* \return
*  Returns the status of the specified sensor update baseline operation:
*  - CYRET_SUCCESS - The operation is successfully completed.
*  - CYRET_BAD_DATA - The baseline processing failed.
*
*******************************************************************************/
cystatus capsense_ADC_UpdateSensorBaseline(uint32 widgetId, uint32 sensorId)
{
    uint32 result = CYRET_SUCCESS;

    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_WD_BASE_STRUCT *ptrWidgetRam = (capsense_ADC_RAM_WD_BASE_STRUCT *)ptrWidget->ptr2WdgtRam;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    result = capsense_ADC_FtUpdateBaseline(ptrWidgetRam, ptrSensor, (uint32)ptrWidget->wdgtType);

    #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
        if (CYRET_SUCCESS != result)
        {
            result = CYRET_BAD_DATA;
            capsense_ADC_UpdateTestResultBaselineDuplication(widgetId, sensorId);
        }
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_FtUpdateBaseline
****************************************************************************//**
*
* \brief
*  Updates the baseline for a sensor specified by an input parameter.
*
* \details
*  Check a matching of present baseline and its inverse duplication. If they
*  match then updates the baseline for a sensor specified by an input parameter.
*  If don't match the function return capsense_ADC_TST_BSLN_DUPLICATION
*  result and don't update baseline.
*
* \param ptrWidgetRam
*  The pointer to the widget RAM structure where all the widget parameters
*  are stored.
*
* \param ptrSensor
*  The pointer to the sensor RAM structure where all the sensor parameters
*  are stored.
*
* \param wdType
*  Specifies the type of a widget.
*
* \return
*  Returns a status indicating whether the baseline has been updated:
*  - CYRET_SUCCESS if baseline updating was successful.
*  - capsense_ADC_PROCESS_BASELINE_FAILED if present sensor's any channel
*    baseline and its inversion doesn't matched.
*
*******************************************************************************/
uint32 capsense_ADC_FtUpdateBaseline(
                                capsense_ADC_RAM_WD_BASE_STRUCT *ptrWidgetRam,
                                capsense_ADC_RAM_SNS_STRUCT *ptrSensor,
                                uint32 wdType)
{
    uint32 sign;
    uint32 difference;
    uint32 freqChannel;
    uint32 baselineCoeff;
    uint32 result = CYRET_SUCCESS;

    #if (capsense_ADC_TOTAL_WIDGETS)
        uint32 history;
    #endif /* (capsense_ADC_TOTAL_WIDGETS) */

    /* Apply baseline to every channel in sensor */
    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
            if (ptrSensor->bslnInv[freqChannel] != ((uint16) ~(ptrSensor->bsln[freqChannel])))
            {
                result = capsense_ADC_PROCESS_BASELINE_FAILED;
            }
            else
            {
        #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

        /* Calculate signal value and its sign */
        if(ptrSensor->raw[freqChannel] >= ptrSensor->bsln[freqChannel])
        {
            difference = (uint32)ptrSensor->raw[freqChannel] - (uint32)ptrSensor->bsln[freqChannel];
            sign = 1u;
            ptrSensor->negBslnRstCnt[freqChannel] = 0u;
        }
        else
        {
            difference = (uint32)ptrSensor->bsln[freqChannel] - (uint32)ptrSensor->raw[freqChannel];
            sign = 0u;
        }

        /* Reset baseline if condition is met */
        if((sign == 0u) && (difference > (uint32) ptrWidgetRam->nNoiseTh))
        {
            if(ptrSensor->negBslnRstCnt[freqChannel] >= ptrWidgetRam->lowBslnRst)
            {
                capsense_ADC_FtInitializeBaselineChannel(ptrSensor, wdType, freqChannel);
            }
            else
            {
                ptrSensor->negBslnRstCnt[freqChannel]++;
            }
        }
        else
        {
            #if (!capsense_ADC_SENSOR_AUTO_RESET_EN)
                /* Update baseline only if signal is in range between noiseThreshold and negativenoiseThreshold */
                if ((difference <= (uint32)ptrWidgetRam->noiseTh) ||
                    ((difference <= (uint32) ptrWidgetRam->nNoiseTh) && (sign == 0u)))
                {
            #endif /* (capsense_ADC_CSD_AUTO_RESET == capsense_ADC_CSD_AUTO_RESET_DISABLE) */

            #if (capsense_ADC_BASELINE_TYPE == capsense_ADC_IIR_BASELINE)
                /* Calculate baseline value */
                if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
                {
                    #if (capsense_ADC_REGULAR_SENSOR_EN)
                        #if (capsense_ADC_REGULAR_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                            history = (uint32) ptrSensor->bsln[freqChannel] << 8u;
                            history |= ptrSensor->bslnExt[freqChannel];
                        #else
                            history = ptrSensor->bsln[freqChannel];
                        #endif /* (capsense_ADC_REGULAR_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */

                        #if (capsense_ADC_ENABLE == capsense_ADC_WD_BSLN_COEFF_EN)
                            baselineCoeff = ptrWidgetRam->bslnCoeff;
                        #else /* (capsense_ADC_ENABLE == capsense_ADC_WD_BSLN_COEFF_EN) */
                            baselineCoeff = capsense_ADC_REGULAR_IIR_BL_N;
                        #endif /* (capsense_ADC_ENABLE == capsense_ADC_WD_BSLN_COEFF_EN) */

                        history =  capsense_ADC_FtIIR1stOrder(
                                        (uint32)ptrSensor->raw[freqChannel],
                                        history, baselineCoeff,
                                        capsense_ADC_REGULAR_IIR_BL_SHIFT);

                        #if (capsense_ADC_REGULAR_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                            ptrSensor->bsln[freqChannel] = LO16(history >> 8u);
                            ptrSensor->bslnExt[freqChannel] = LO8(history);
                        #else
                            ptrSensor->bsln[freqChannel] = LO16(history);
                        #endif /* (capsense_ADC_REGULAR_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
                    #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
                }
                else
                {
                    #if (capsense_ADC_PROXIMITY_SENSOR_EN)
                        #if (capsense_ADC_PROX_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                            history = (uint32) ptrSensor->bsln[freqChannel] << 8u;
                            history |= ptrSensor->bslnExt[freqChannel];
                        #else
                            history = (uint32) ptrSensor->bsln[freqChannel];
                        #endif /* (capsense_ADC_PROX_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */

                        #if (capsense_ADC_ENABLE == capsense_ADC_WD_BSLN_COEFF_EN)
                            baselineCoeff = ptrWidgetRam->bslnCoeff;
                        #else /* (capsense_ADC_ENABLE == capsense_ADC_WD_BSLN_COEFF_EN) */
                            baselineCoeff = capsense_ADC_PROX_IIR_BL_N;
                        #endif /* (capsense_ADC_ENABLE == capsense_ADC_WD_BSLN_COEFF_EN) */

                        history = capsense_ADC_FtIIR1stOrder(
                                        (uint32)ptrSensor->raw[freqChannel],
                                        history, baselineCoeff,
                                        capsense_ADC_PROX_IIR_BL_SHIFT);

                        #if (capsense_ADC_PROX_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                            ptrSensor->bsln[freqChannel] = LO16(history >> 8u);
                            ptrSensor->bslnExt[freqChannel] = LO8(history);
                        #else
                            ptrSensor->bsln[freqChannel] = LO16(history);
                        #endif /* (capsense_ADC_PROX_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
                    #endif /* (capsense_ADC_PROX_SENSOR_EN) */
                }
            #else /* (capsense_ADC_CSD_BASELINE_TYPE == capsense_ADC_IIR_BASELINE) */

                /******************************************************************
                * This is the place where the bucket algorithm should be implemented.
                * The bucket method will be implemented in future Component version.
                *******************************************************************/

            #endif /* (capsense_ADC_CSD_BASELINE_TYPE == capsense_ADC_IIR_BASELINE) */

            #if (!capsense_ADC_SENSOR_AUTO_RESET_EN)
                }
            #endif /* (!capsense_ADC_SENSOR_AUTO_RESET_EN) */
        }

        #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
            /* Update baseline inversion of every channel in sensor */
            ptrSensor->bslnInv[freqChannel] = ~(ptrSensor->bsln[freqChannel]);
            }
        #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

    }
    return result;
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeAllBaselines
****************************************************************************//**
*
* \brief
*  Initializes (or re-initializes) the baselines of all the sensors of all the widgets.
*
* \details
*  Initializes the baseline for all the sensors of all the widgets. Also, this function
*  can be used to re-initialize baselines. capsense_ADC_Start() calls this
*  API as part of capsense_ADC operation initialization.
*
*  If any raw count filter is enabled, make sure the raw count filter history is
*  initialized as well using one of these functions:
*  - capsense_ADC_InitializeAllFilters().
*  - capsense_ADC_InitializeWidgetFilter().
*
*******************************************************************************/
void capsense_ADC_InitializeAllBaselines(void)
{
    uint32 widgetId;

    for(widgetId = capsense_ADC_TOTAL_WIDGETS; widgetId-- > 0u;)
    {
        capsense_ADC_InitializeWidgetBaseline(widgetId);
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeWidgetBaseline
****************************************************************************//**
*
* \brief
*  Initializes (or re-initializes) the baselines of all the sensors in a widget
*  specified by the input parameter.
*
* \details
*  Initializes (or re-initializes) the baseline for all the sensors of the
*  specified widget.
*
*  If any raw count filter is enabled, make sure the raw count filter history is
*  initialized as well using one of these functions:
*  - capsense_ADC_InitializeAllFilters().
*  - capsense_ADC_InitializeWidgetFilter().
*
* \param widgetId
*  Specifies the ID number of a widget to initialize the baseline of all the sensors
*  in the widget.
*  A macro for the widget ID can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void capsense_ADC_InitializeWidgetBaseline(uint32 widgetId)
{
    uint32 sensorId;
    uint32 sensorsNumber;

    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];

    /* Find total amount of sensors in specified widget */
    sensorsNumber = capsense_ADC_GET_SNS_CNT_BY_PTR(ptrWidget);

    for(sensorId = sensorsNumber; sensorId-- > 0u;)
    {
        capsense_ADC_InitializeSensorBaseline(widgetId, sensorId);
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeSensorBaseline
****************************************************************************//**
*
* \brief
*  Initializes (or re-initializes) the baseline of a sensor in a widget specified
*  by the input parameters.
*
* \details
*  Initializes (or re-initializes) the baseline for a specified sensor within
*  a specified widget.
*
* \param widgetId
*  Specifies the ID number of a widget to initialize the baseline of the sensor
*  in the widget.
*  A macro for the widget ID can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to initialize its
*  baseline.
*  A macro for the sensor ID within a specified widget can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_SNS<SensorNumber>_ID.
*
*******************************************************************************/
void capsense_ADC_InitializeSensorBaseline(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = NULL;
    ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    capsense_ADC_FtInitializeBaseline(ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_FtInitializeBaseline
****************************************************************************//**
*
* \brief
*  Initializes the baseline history for a sensor indicated by an input
*  parameter.
*
* \details
*  Initializes the baseline history for a sensor indicated by an input
*  parameter.
*
* \param *ptrSensor
*  The pointer to the sensor RAM object.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_FtInitializeBaseline(capsense_ADC_RAM_SNS_STRUCT *ptrSensor, uint32 wdType)
{
    uint32 freqChannel;

    /* Apply baseline initialization to every channel in sensor */
    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        capsense_ADC_FtInitializeBaselineChannel(ptrSensor, wdType, freqChannel);
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_FtInitializeBaselineChannel
****************************************************************************//**
*
* \brief
*  Initializes the baseline history for a sensor indicated by an input
*  parameter.
*
* \details
*  Initializes the baseline history for a sensor indicated by an input
*  parameter.
*
* \param *ptrSensor
*  The pointer to the sensor RAM object.
*
* \param wdType
*  Specifies the type of a widget.
*
* \param channel
*  Specifies the number of the channel to be initialized.
*
*******************************************************************************/
void capsense_ADC_FtInitializeBaselineChannel(capsense_ADC_RAM_SNS_STRUCT *ptrSensor, uint32 wdType, uint32 channel)
{
    #if (capsense_ADC_BASELINE_TYPE == capsense_ADC_IIR_BASELINE)
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN)
                #if (capsense_ADC_REGULAR_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                    ptrSensor->bslnExt[channel] = 0u;
                #endif /* (capsense_ADC_REGULAR_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN)
                #if (capsense_ADC_PROX_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                    ptrSensor->bslnExt[channel] = 0u;
                #endif /* (capsense_ADC_PROX_IIR_BL_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
            #endif /* (capsense_ADC_PROX_SENSOR_EN) */
        }
    #else
        /* capsense_ADC_BASELINE_TYPE == capsense_ADC_BUCKET_BASELINE */
        ptrSensor->bslnExt[channel] = 0u;
    #endif /* (capsense_ADC_BASELINE_TYPE == capsense_ADC_IIR_BASELINE) */

    ptrSensor->bsln[channel] = ptrSensor->raw[channel];

    #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
    /* Update baseline inversion of the channel in sensor */
        ptrSensor->bslnInv[channel] = ~(ptrSensor->bsln[channel]);
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

    ptrSensor->negBslnRstCnt[channel] = 0u;
}

#if ((capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) || \
     (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)))
/*******************************************************************************
* Function Name: capsense_ADC_InitializeAllFilters
****************************************************************************//**
*
* \brief
*  Initializes (or re-initializes) the raw count filter history of all the
*  sensors of all the widgets.
*
* \details
*  Initializes the raw count filter history for all the sensors of all the
*  widgets. Also, this function can be used to re-initialize baselines.
*  capsense_ADC_Start() calls this API as part of capsense_ADC
*  operation initialization.
*
*******************************************************************************/
void capsense_ADC_InitializeAllFilters(void)
{
    uint32 widgetId;

    for(widgetId = capsense_ADC_TOTAL_WIDGETS; widgetId-- > 0u;)
    {
        capsense_ADC_InitializeWidgetFilter(widgetId);
    }
}

/*******************************************************************************
* Function Name: capsense_ADC_InitializeWidgetFilter
****************************************************************************//**
*
* \brief
*  Initializes (or re-initializes) the raw count filter history of all the sensors
*  in a widget specified by the input parameter.
*
* \details
*  Initializes (or re-initializes) the raw count filter history of all the sensors
*  in a widget specified by the input parameter.
*
* \param widgetId
*  Specifies the ID number of a widget to initialize the filter history of all
*  the sensors in the widget.
*  A macro for the widget ID can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void capsense_ADC_InitializeWidgetFilter(uint32 widgetId)
{
    uint32 sensorId;
    uint32 sensorsNumber;

    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget;
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    #if (capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN)
        capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;
    #endif

    #if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
        capsense_ADC_RAM_WD_BASE_STRUCT *ptrWidgetRam;
        SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope = NULL;
    #endif /* (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

    ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];

    #if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
        ptrWidgetRam = ptrWidget->ptr2WdgtRam;
    #endif /* (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

    /* Find total amount of sensors in specified widget */
    sensorsNumber = capsense_ADC_GET_SNS_CNT_BY_PTR(ptrWidget);

    for (sensorId = sensorsNumber; sensorId-- > 0u;)
    {
        /* Find pointer to specified sensor object */
        ptrSensor = ptrWidget->ptr2SnsRam;
        ptrSensor = &ptrSensor[sensorId];

        #if (capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN)
            /* Find pointer to to specified filter sensor object */
            ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
        #endif

        #if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
            /* Find pointer to specified noise envelope sensor object */
            ptrNoiseEnvelope = ptrWidget->ptr2NoiseEnvlp;
            ptrNoiseEnvelope = &ptrNoiseEnvelope[sensorId];
        #endif /* (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

        if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (0u != capsense_ADC_REGULAR_RC_ALP_FILTER_EN)
                ptrFilterHistObj.ptrAlp = &ptrFilterHistObj.ptrAlp[sensorId];
            #elif (0u != capsense_ADC_REGULAR_RC_FILTER_EN)
                ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
            #endif
        }
        else
        {
            #if (0u != capsense_ADC_PROX_RC_ALP_FILTER_EN)
                ptrFilterHistObj.ptrAlp = &ptrFilterHistObj.ptrAlp[sensorId];
            #elif (0u != capsense_ADC_PROX_RC_FILTER_EN)
                ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
            #endif /* #if (0u != capsense_ADC_PROX_RC_FILTER_EN) */
        }

        #if (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN)
            capsense_ADC_InitializeIIRInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
        #endif /* (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN) */

        #if (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
            capsense_ADC_InitializeMedianInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
        #endif /* (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN) */

        #if (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)
            capsense_ADC_InitializeAverageInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
        #endif /* (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN) */

        #if (capsense_ADC_ALP_FILTER_EN)
            capsense_ADC_InitializeALPInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
        #endif

        #if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
            if (capsense_ADC_SENSE_METHOD_CSD_E ==
                capsense_ADC_GET_SENSE_METHOD(&capsense_ADC_dsFlash.wdgtArray[widgetId]))
            {
                SmartSense_InitializeNoiseEnvelope(ptrSensor->raw[0u], ptrWidgetRam->sigPFC, ptrNoiseEnvelope);
            }
        #endif /* (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */
    }
}
#endif /* ((capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) || \
           (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))) */

#if (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN)
/*******************************************************************************
* Function Name: capsense_ADC_InitializeIIR
****************************************************************************//**
*
* \brief
*  Initialize the IIR filter history.
*
* \details
*  Initialize the IIR filter history.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_InitializeIIR(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }

    capsense_ADC_InitializeIIRInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_RunIIR
****************************************************************************//**
*
* \brief
*  Executes the IIR filter algorithm on a sensor indicated by an input
*  parameter.
*
* \details
*  Executes the IIR filter algorithm on a sensor indicated by an input
*  parameter.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_RunIIR(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }

    capsense_ADC_RunIIRInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}

/*******************************************************************************
* Function Name: capsense_ADC_InitializeIIRInternal
****************************************************************************//**
*
* \brief
*  Initializes the IIR filter history.
*
* \details
*  Initializes the IIR filter history.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_InitializeIIRInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                            capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 freqChannel;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_IIR_FILTER_EN)
                #if (capsense_ADC_REGULAR_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistory = ptrSensorObj->raw[freqChannel];
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistoryLow = 0u;
                #else
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistory = ptrSensorObj->raw[freqChannel] << capsense_ADC_REGULAR_IIR_RC_SHIFT;
                #endif /* (capsense_ADC_REGULAR_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_IIR_FILTER_EN)
                #if (capsense_ADC_PROX_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistory = ptrSensorObj->raw[freqChannel];
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistoryLow = 0u;
                #else
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistory = ptrSensorObj->raw[freqChannel] << capsense_ADC_PROX_IIR_RC_SHIFT;
                #endif /* (capsense_ADC_PROX_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
            #endif /* (capsense_ADC_PROX_SENSOR_EN) */
        }
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_RunIIRInternal
****************************************************************************//**
*
* \brief
*  Run the IIR filter.
*
* \details
*  Run the IIR filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_RunIIRInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                     capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 freqChannel;
    uint32 temp;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_IIR_FILTER_EN)
                #if (capsense_ADC_REGULAR_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                    temp = ((uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistory << capsense_ADC_REGULAR_IIR_RC_SHIFT);
                    temp |= ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistoryLow;
                    temp = capsense_ADC_FtIIR1stOrder((uint32)ptrSensorObj->raw[freqChannel],
                                                        temp,
                                                        capsense_ADC_REGULAR_IIR_RC_N,
                                                        capsense_ADC_REGULAR_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistory = LO16(temp >>capsense_ADC_REGULAR_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistoryLow = LO8(temp);
                    ptrSensorObj->raw[freqChannel] = LO16(temp >>capsense_ADC_REGULAR_IIR_RC_SHIFT);
                #else
                    temp =capsense_ADC_FtIIR1stOrder((uint32)ptrSensorObj->raw[freqChannel],
                                                        (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistory,
                                                        capsense_ADC_REGULAR_IIR_RC_N,
                                                        capsense_ADC_REGULAR_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].iirHistory = LO16(temp);
                    ptrSensorObj->raw[freqChannel] = LO16(temp >>capsense_ADC_REGULAR_IIR_RC_SHIFT);
                #endif /* (capsense_ADC_REGULAR_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_IIR_FILTER_EN)
                #if (capsense_ADC_PROX_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE)
                    temp =  ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistory << capsense_ADC_PROX_IIR_RC_SHIFT;
                    temp |= ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistoryLow;
                    temp =capsense_ADC_FtIIR1stOrder((uint32)ptrSensorObj->raw[freqChannel],
                                                        temp,
                                                        capsense_ADC_PROX_IIR_RC_N,
                                                        capsense_ADC_PROX_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistory = LO16(temp >>capsense_ADC_PROX_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistoryLow = LO8(temp);
                    ptrSensorObj->raw[freqChannel] = LO16(temp >>capsense_ADC_PROX_IIR_RC_SHIFT);
                #else
                    temp =capsense_ADC_FtIIR1stOrder((uint32)ptrSensorObj->raw[freqChannel],
                                                        (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistory,
                                                        capsense_ADC_PROX_IIR_RC_N,
                                                        capsense_ADC_PROX_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].iirHistory = LO16(temp);
                    ptrSensorObj->raw[freqChannel] = LO16(temp >>capsense_ADC_PROX_IIR_RC_SHIFT);
                #endif /* (capsense_ADC_PROX_IIR_RC_TYPE == capsense_ADC_IIR_FILTER_PERFORMANCE) */
            #endif /* (capsense_ADC_PROX_SENSOR_EN) */
        }
    }
}
#endif /* #if (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN) */


#if (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)

/*******************************************************************************
* Function Name: capsense_ADC_InitializeMedian
****************************************************************************//**
*
* \brief
*  Initializes the Median filter history.
*
* \details
*  Initializes the Median filter history.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_InitializeMedian(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }

    capsense_ADC_InitializeMedianInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_RunMedian
****************************************************************************//**
*
* \brief
*  Executes the Median filter algorithm on a sensor indicated by an input
*  parameter.
*
* \details
*  Executes the Median filter algorithm on a sensor indicated by an input
*  parameter.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_RunMedian(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }

    capsense_ADC_RunMedianInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeMedianInternal
****************************************************************************//**
*
* \brief
*  Initializes the Median filter.
*
* \details
*  Initializes the Median filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_InitializeMedianInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                               capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 freqChannel;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN)
                ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[0u] = ptrSensorObj->raw[freqChannel];
                ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[1u] = ptrSensorObj->raw[freqChannel];
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
                ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[0u] = ptrSensorObj->raw[freqChannel];
                ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[1u] = ptrSensorObj->raw[freqChannel];
            #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
        }
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_RunMedianInternal
****************************************************************************//**
*
* \brief
*  Runs the Median filter.
*
* \details
*  Runs the Median filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_RunMedianInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                        capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 freqChannel;

    #if ((capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN) || \
         (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_MEDIAN_FILTER_EN))
        uint32 temp;
    #endif

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN)
                temp = capsense_ADC_FtMedian((uint32)ptrSensorObj->raw[freqChannel],\
                                                 (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[0u],\
                                                 (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[1u]);
                ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[1u] = \
                ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[0u];
                ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].medHistory[0u] = ptrSensorObj->raw[freqChannel];
                ptrSensorObj->raw[freqChannel] = LO16(temp);
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
                temp = capsense_ADC_FtMedian((uint32)ptrSensorObj->raw[freqChannel],\
                                                 (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[0u],\
                                                 (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[1u]);
                ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[1u] = \
                ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[0u];
                ptrFilterHistObj.ptrProx->proxChannel[freqChannel].medHistory[0u] = ptrSensorObj->raw[freqChannel];
                ptrSensorObj->raw[freqChannel] = LO16(temp);
            #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
        }
    }
}
#endif /* (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN) */


#if (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)

/*******************************************************************************
* Function Name: capsense_ADC_InitializeAverage
****************************************************************************//**
*
* \brief
*  Initializes the average filter history.
*
* \details
*  Initializes the average filter history.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_InitializeAverage(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }

    capsense_ADC_InitializeAverageInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_RunAverage
****************************************************************************//**
*
* \brief
*  Executes the average filter algorithm on a sensor indicated by an input
*  parameter.
*
* \details
*  Executes the average filter algorithm on a sensor indicated by an input
*  parameter.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_RunAverage(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }

    capsense_ADC_RunAverageInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeAverageInternal
****************************************************************************//**
*
* \brief
*  Initializes the average filter.
*
* \details
*  Initializes the average filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_InitializeAverageInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,\
                                                  capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 freqChannel;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN)
                ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[0] = ptrSensorObj->raw[freqChannel];
                #if (capsense_ADC_REGULAR_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_4)
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[1u] = ptrSensorObj->raw[freqChannel];
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[2u] = ptrSensorObj->raw[freqChannel];
                #endif /* capsense_ADC_REGULAR_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_4 */
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)
                ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[0] = ptrSensorObj->raw[freqChannel];
                    #if (capsense_ADC_PROX_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_4)
                        ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[1u] = ptrSensorObj->raw[freqChannel];
                        ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[2u] = ptrSensorObj->raw[freqChannel];
                    #endif /* capsense_ADC_REGULAR_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_4 */
            #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
        }
    }
}


/*******************************************************************************
* Function Name: capsense_ADC_RunAverageInternal
****************************************************************************//**
*
* \brief
*  Runs the average filter.
*
* \details
*  Runs the average filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_RunAverageInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,\
                                           capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 freqChannel;
    uint32 temp;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN)
                #if (capsense_ADC_REGULAR_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_2)
                    temp = ((uint32)ptrSensorObj->raw[freqChannel] +
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[0]) >> 1u;
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[0] = ptrSensorObj->raw[freqChannel];
                    ptrSensorObj->raw[freqChannel] = LO16(temp);
                #else
                    temp = ((uint32)ptrSensorObj->raw[freqChannel] +
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[0] +
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[1u] +
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[2u]) >> 2u;

                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[2u] =
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[1u];
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[1u] =
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[0];
                    ptrFilterHistObj.ptrRegular->regularChannel[freqChannel].avgHistory[0] = ptrSensorObj->raw[freqChannel];
                    ptrSensorObj->raw[freqChannel] = LO16(temp);
                #endif /* capsense_ADC_REGULAR_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_4 */
            #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)
                #if (capsense_ADC_PROX_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_2)
                    temp = ((uint32)ptrSensorObj->raw[freqChannel] +
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[0]) >> 1u;
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[0] = ptrSensorObj->raw[freqChannel];
                    ptrSensorObj->raw[freqChannel] = LO16(temp);
                #else
                    temp = ((uint32)ptrSensorObj->raw[freqChannel] +
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[0] +
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[1u] +
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[2u]) >> 2u;

                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[2u] =
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[1u];
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[1u] =
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[0];
                    ptrFilterHistObj.ptrProx->proxChannel[freqChannel].avgHistory[0] = ptrSensorObj->raw[freqChannel];
                    ptrSensorObj->raw[freqChannel] = LO16(temp);
                #endif /* capsense_ADC_PROX_AVERAGE_LEN == capsense_ADC_AVERAGE_FILTER_LEN_4 */
            #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
        }
    }
}
#endif /* (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN) */

#if (capsense_ADC_ENABLE == capsense_ADC_ALP_FILTER_EN)
/*******************************************************************************
* Function Name: capsense_ADC_InitializeALP
****************************************************************************//**
*
* \brief
*  Initializes the ALP filter history.
*
* \details
*  Initializes the ALP filter history.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_InitializeALP(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    ptrFilterHistObj.ptrAlp = &ptrFilterHistObj.ptrAlp[sensorId];
    capsense_ADC_InitializeALPInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_RunALP
****************************************************************************//**
*
* \brief
*  Executes the ALP filter algorithm on a sensor indicated by an input
*  parameter.
*
* \details
*  Executes the ALP filter algorithm on a sensor indicated by an input
*  parameter.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_RunALP(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;
    ALP_FLTR_CONFIG_STRUCT alpFilterConfig;
    ALP_FLTR_CONFIG_STRUCT *ptrAlpFilterConfig = &alpFilterConfig;
    capsense_ADC_RAM_WD_BASE_STRUCT *ptrRamWidget = ptrWidget->ptr2WdgtRam;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    ptrAlpFilterConfig->configParam0 = ptrRamWidget->alpOnTh;
    ptrAlpFilterConfig->configParam1 = ptrRamWidget->alpOffTh;
    ptrAlpFilterConfig->configParam2 = ptrRamWidget->fingerTh;
    ptrAlpFilterConfig->configParam3 = ptrRamWidget->noiseTh;
    ptrAlpFilterConfig->configParam4 = ptrRamWidget->hysteresis;

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    ptrFilterHistObj.ptrAlp = &ptrFilterHistObj.ptrAlp[sensorId];

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (capsense_ADC_REGULAR_SENSOR_EN)
            ptrAlpFilterConfig->configParam5 = capsense_ADC_REGULAR_RC_ALP_FILTER_COEFF;
        #endif /* (capsense_ADC_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (capsense_ADC_PROXIMITY_SENSOR_EN)
            ptrAlpFilterConfig->configParam5 = capsense_ADC_PROX_RC_ALP_FILTER_COEFF;
        #endif /* (capsense_ADC_PROXIMITY_SENSOR_EN) */
    }
    capsense_ADC_RunALPInternal(ptrFilterHistObj, ptrAlpFilterConfig, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeALPInternal
****************************************************************************//**
*
* \brief
*  Initializes the ALP filter.
*
* \details
*  Initializes the ALP filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*
*******************************************************************************/
void capsense_ADC_InitializeALPInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                            capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj,
                                            uint32 wdType)
{
    uint32 freqChannel;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_ALP_FILTER_EN)
                ALP_Initialize(&ptrFilterHistObj.ptrAlp->channel[freqChannel], &ptrSensorObj->raw[freqChannel]);
            #endif
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_ALP_FILTER_EN)
                ALP_Initialize(&ptrFilterHistObj.ptrAlp->channel[freqChannel], &ptrSensorObj->raw[freqChannel]);
            #endif
        }
    }
}

/*******************************************************************************
* Function Name: capsense_ADC_ConfigRunALPInternal
****************************************************************************//**
*
* \brief
*  Prepares ALP configuration structure and runs the filter.
*
* \details
*  Prepares ALP configuration structure and runs the filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrRamWdgt
*  The pointer to the RAM widget object.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_ConfigRunALPInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                    capsense_ADC_RAM_WD_BASE_STRUCT *ptrRamWdgt,
                                    capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj,
                                    uint32 wdType)
{
    ALP_FLTR_CONFIG_STRUCT alpFilterConfig;

    alpFilterConfig.configParam0 = ptrRamWdgt->alpOnTh;
    alpFilterConfig.configParam1 = ptrRamWdgt->alpOffTh;
    alpFilterConfig.configParam2 = ptrRamWdgt->fingerTh;
    alpFilterConfig.configParam3 = ptrRamWdgt->noiseTh;
    alpFilterConfig.configParam4 = ptrRamWdgt->hysteresis;

    capsense_ADC_RunALPInternal(ptrFilterHistObj, &alpFilterConfig, ptrSensorObj, wdType);
}

/*******************************************************************************
* Function Name: capsense_ADC_RunALPInternal
****************************************************************************//**
*
* \brief
*  Runs the ALP filter.
*
* \details
*  Runs the ALP filter.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrAlpFilterConfig
*  The pointer to the filter configuration object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_RunALPInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                    ALP_FLTR_CONFIG_STRUCT *ptrAlpFilterConfig,
                                    capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj,
                                    uint32 wdType)
{
    uint32 freqChannel;

    for(freqChannel = capsense_ADC_NUM_SCAN_FREQS; freqChannel-- > 0u;)
    {
        if ((capsense_ADC_WD_TYPE_ENUM)wdType != capsense_ADC_WD_PROXIMITY_E)
        {
            #if (capsense_ADC_REGULAR_SENSOR_EN && capsense_ADC_REGULAR_RC_ALP_FILTER_EN)
                ptrAlpFilterConfig->configParam5 = capsense_ADC_REGULAR_RC_ALP_FILTER_COEFF;
                ALP_Run(&ptrFilterHistObj.ptrAlp->channel[freqChannel], ptrAlpFilterConfig, &ptrSensorObj->raw[freqChannel], &ptrSensorObj->bsln[freqChannel]);
            #endif
        }
        else
        {
            #if (capsense_ADC_PROXIMITY_SENSOR_EN && capsense_ADC_PROX_RC_ALP_FILTER_EN)
                ptrAlpFilterConfig->configParam5 = capsense_ADC_PROX_RC_ALP_FILTER_COEFF;
                ALP_Run(&ptrFilterHistObj.ptrAlp->channel[freqChannel], ptrAlpFilterConfig, &ptrSensorObj->raw[freqChannel], &ptrSensorObj->bsln[freqChannel]);
            #endif
        }
    }
}
#endif /* (capsense_ADC_ENABLE == capsense_ADC_ALP_FILTER_EN) */

#if (capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN)
/*******************************************************************************
* Function Name: capsense_ADC_FtRunEnabledFilters
****************************************************************************//**
*
* \brief
*  Runs all enabled filters.
*
* \details
*  Runs all enabled filters.
*
* \param widgetId
*  Specifies the ID number of a widget to update the IIR filter history.
*
* \param sensorId
*  Specifies the ID number of a sensor in the widget to update the IIR
*  filter history.
*
*******************************************************************************/
void capsense_ADC_FtRunEnabledFilters(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((capsense_ADC_WD_TYPE_ENUM)ptrWidget->wdgtType != capsense_ADC_WD_PROXIMITY_E)
    {
        #if (0u != capsense_ADC_REGULAR_RC_ALP_FILTER_EN)
            ptrFilterHistObj.ptr = &ptrFilterHistObj.ptrAlp[sensorId];
        #elif (0u != capsense_ADC_REGULAR_RC_FILTER_EN)
            ptrFilterHistObj.ptr = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif
    }
    else
    {
        #if (0u != capsense_ADC_PROX_RC_ALP_FILTER_EN)
            ptrFilterHistObj.ptr = &ptrFilterHistObj.ptrAlp[sensorId];
        #elif (0u != capsense_ADC_PROX_RC_FILTER_EN)
            ptrFilterHistObj.ptr = &ptrFilterHistObj.ptrProx[sensorId];
        #endif
    }

    capsense_ADC_FtRunEnabledFiltersInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
    #if (capsense_ADC_ALP_FILTER_EN)
        capsense_ADC_ConfigRunALPInternal(ptrFilterHistObj, ptrWidget->ptr2WdgtRam, ptrSensor, (uint32)ptrWidget->wdgtType);
    #endif
}


/*******************************************************************************
* Function Name: capsense_ADC_FtRunEnabledFiltersInternal
****************************************************************************//**
*
* \brief
*  Runs all enabled filters.
*
* \details
*  Runs all enabled filters.
*
* \param ptrFilterHistObj
*  The pointer to the filter RAM object of the sensor.
*
* \param ptrSensorObj
*  The pointer to the sensor RAM object of the sensor.
*
* \param wdType
*  Specifies the type of a widget.
*
*******************************************************************************/
void capsense_ADC_FtRunEnabledFiltersInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                                  capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    #if (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
        capsense_ADC_RunMedianInternal(ptrFilterHistObj, ptrSensorObj, wdType);
    #endif /* (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN) */

    #if (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN)
        capsense_ADC_RunIIRInternal(ptrFilterHistObj, ptrSensorObj, wdType);
    #endif /* (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN) */

    #if (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)
        capsense_ADC_RunAverageInternal(ptrFilterHistObj, ptrSensorObj, wdType);
    #endif /* (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN) */
}
#endif /* (capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) */


#if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
/*******************************************************************************
* Function Name: capsense_ADC_RunNoiseEnvelope
****************************************************************************//**
*
* \brief
*  Executes the noise envelope  filter algorithm on a sensor indicated by
*  an input parameter to measure the pk-to-pk noise in the sensor raw count.
*
* \details
*  Executes the noise envelope  filter algorithm on a sensor indicated by
*  an input parameter to measure the pk-to-pk noise in the sensor raw count.
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_RunNoiseEnvelope(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_WD_BASE_STRUCT *ptrWidgetRam = ptrWidget->ptr2WdgtRam;
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope = NULL;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrNoiseEnvelope = ptrWidget->ptr2NoiseEnvlp;
    ptrNoiseEnvelope = &ptrNoiseEnvelope[sensorId];

    SmartSense_RunNoiseEnvelope(ptrSensor->raw[0u], ptrWidgetRam->sigPFC, ptrNoiseEnvelope);
}


/*******************************************************************************
* Function Name: capsense_ADC_InitializeNoiseEnvelope
****************************************************************************//**
*
* \brief
*  Initializes the noise-envelope filter
*
* \details
*  Initializes the noise-envelope filter
*
* \param widgetId
*  Specifies the ID number of the widget.
*
* \param sensorId
*  Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void capsense_ADC_InitializeNoiseEnvelope(uint32 widgetId, uint32 sensorId)
{
    capsense_ADC_FLASH_WD_STRUCT const *ptrWidget = &capsense_ADC_dsFlash.wdgtArray[widgetId];
    capsense_ADC_RAM_WD_BASE_STRUCT *ptrWidgetRam = ptrWidget->ptr2WdgtRam;
    capsense_ADC_RAM_SNS_STRUCT *ptrSensor = NULL;
    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope = NULL;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    /* Find pointer to specified filter sensor object */
    ptrNoiseEnvelope = ptrWidget->ptr2NoiseEnvlp;
    ptrNoiseEnvelope = &ptrNoiseEnvelope[sensorId];

    SmartSense_InitializeNoiseEnvelope(ptrSensor->raw[0u], ptrWidgetRam->sigPFC, ptrNoiseEnvelope);
}
#endif /* (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */


#if (capsense_ADC_POS_MEDIAN_FILTER_EN || capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
/*******************************************************************************
* Function Name: capsense_ADC_FtMedian
****************************************************************************//**
*
* \brief
*  Return the median value from the three passed arguments.
*
* \details
*  Return the median value from the three passed arguments.
*
* \param x1
*  The first value to be compared.
*
* \param x2
*  The second value to be compared.
*
* \param x3
*  The third value to be compared.
*
* \return
*  Returns the median value of input arguments.
*
*******************************************************************************/
uint32 capsense_ADC_FtMedian(uint32 x1, uint32 x2, uint32 x3)
{
    uint32 tmp;

    if (x1 > x2)
    {
        tmp = x2;
        x2 = x1;
        x1 = tmp;
    }

    if (x2 > x3)
    {
        x2 = x3;
    }

    return ((x1 > x2) ? x1 : x2);
}
#endif /*capsense_ADC_POS_MEDIAN_FILTER_EN || capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN*/


/*******************************************************************************
* Function Name: capsense_ADC_FtIIR1stOrder
****************************************************************************//**
*
* \brief
*  Return the filtered data by the IIR 1-st order algorithm
*
* \details
*  Return the filtered data by the IIR 1-st order algorithm
*
* \param input
*  The data to be filtered.
*
* \param prevOutput
*  The previous filtered data.
*
* \param n
*  The IIR filter coefficient (n/256).
*
* \param shift
*  The parameter is used to shift input data to have free LSB
*  bits for a fraction storage of the filter output calculation.
*
* \return
*  Returns the filtered data.
*
*******************************************************************************/
uint32 capsense_ADC_FtIIR1stOrder(uint32 input, uint32 prevOutput, uint32 n, uint32 shift)
{
    uint32 filteredOutput;

    /*
    * n - IIR filter coefficient (n/256)
    * shift - Used to shift input data to have free LSB bits
    * for fraction storage of filter output calculation
    */
    filteredOutput = ((n * (input << shift)) + ((capsense_ADC_IIR_COEFFICIENT_K - n) * prevOutput)) >> 8u;

    /* Shift operation of output will be done in upper level API if needed */
    return filteredOutput;
}


#if (capsense_ADC_POS_JITTER_FILTER_EN)
/*******************************************************************************
* Function Name: capsense_ADC_FtJitter
****************************************************************************//**
*
* \brief
*  Returns the filtered data by the jitter algorithm.
*
* \details
*  Returns the filtered data by the jitter algorithm.
*
* \param input
*  The data to be filtered.
*
* \param prevOutput
*  The previous filtered data.
*
* \return
*  Returns the filtered data.
*
*******************************************************************************/
uint32 capsense_ADC_FtJitter(uint32 input, uint32 prevOutput)
{
    if (prevOutput > input)
    {
        input++;
    }
    else if (prevOutput < input)
    {
        input--;
    }
    else
    {
        /* Nothing to do - MISRA 14.1 requirement*/
    }
    return input;
}
#endif /* capsense_ADC_POS_JITTER_FILTER_EN */


/* [] END OF FILE */
