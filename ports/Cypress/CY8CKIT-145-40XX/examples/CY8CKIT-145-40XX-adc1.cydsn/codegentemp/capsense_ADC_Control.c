/***************************************************************************//**
* \file capsense_ADC_Control.c
* \version 7.10
*
* \brief
*   This file provides the source code to the Control module API of the
*   Component.
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
#include "cyPm.h"
#include "capsense_ADC_Configuration.h"
#include "capsense_ADC_Structure.h"
#include "capsense_ADC_Control.h"
#include "capsense_ADC_Processing.h"
#include "capsense_ADC_Filter.h"
#include "capsense_ADC_Sensing.h"
#include "capsense_ADC_Tuner.h"

#if (capsense_ADC_ENABLE == capsense_ADC_SELF_TEST_EN)
    #include "capsense_ADC_SelfTest.h"
#endif

#if (0u != capsense_ADC_ADC_EN)
    #include "capsense_ADC_Adc.h"
#endif /* (0u != capsense_ADC_ADC_EN) */

#if ((capsense_ADC_ENABLE == capsense_ADC_GES_GLOBAL_EN) || \
     (capsense_ADC_ENABLE == capsense_ADC_BALLISTIC_MULTIPLIER_EN))
    #include "capsense_ADC_Gesture.h"
#endif /* (capsense_ADC_ENABLE == capsense_ADC_GES_GLOBAL_EN) */

/***********************************************************************************************************************
* Local definition
***********************************************************************************************************************/
#define capsense_ADC_INIT_DONE   (1u)
#define capsense_ADC_INIT_NEEDED (0u)

/***********************************************************************************************************************
* Local variables
***********************************************************************************************************************/
static uint8 capsense_ADC_InitVar = capsense_ADC_INIT_NEEDED;

/*******************************************************************************
* Function Name: capsense_ADC_Start
****************************************************************************//**
*
* \brief
*  Initializes the Component hardware and firmware modules. This function is
*  called by the application program prior to calling any other function of the
*  Component.
*
* \details
*  This function initializes the Component hardware and firmware modules and
*  is called by the application program prior to calling any other API
*  of the Component. When this function is called, the following tasks are
*  executed as part of the initialization process:
*    1. Initialize the registers of the \ref group_structures variable
*       capsense_ADC_dsRam based on the user selection in the Component
*       configuration wizard.
*    2. Configure the hardware to perform sensing.
*    \if SECTION_C_HIGH_LEVEL
*    3. If SmartSense Auto-tuning is selected for the CSD Tuning mode in the
*       Basic tab, the auto-tuning algorithm is executed to set the optimal
*       values for the hardware parameters of the widgets/sensors.
*    \endif
*    4. Calibrate the sensors and find the optimal values for IDACs of each
*       widget / sensor, if the Enable IDAC auto-calibration is enabled in the
*       Mode's Setting tabs.
*    5. Perform scanning for all the sensors and initialize the baseline history.
*    6. If the firmware filters are enabled in the Advanced General tab, the
*       filter histories are also initialized.

*  Any next call of this API repeats an initialization process except for
*  data structure initialization. Therefore, it is possible to change the
*  Component configuration from the application program by writing registers to the
*  data structure and calling this function again. This is also
*  done inside the capsense_ADC_RunTuner() function when a restart command
*  is received.
*
*  When the Component operation is stopped by the capsense_ADC_Stop()
*  function, the capsense_ADC_Start() function repeats an initialization
*  process including data structure initialization.
*
* \return
*  Returns the status of the initialization process. If CYRET_SUCCESS is not
*  received, some of the initialization fails and the Component may not operate
*  as expected.
*
*******************************************************************************/
cystatus capsense_ADC_Start(void)
{
    cystatus result;
    uint32 watchdogCounter;

    /* Initialize capsense_ADC modules */
    result = capsense_ADC_Initialize();

    #if (capsense_ADC_CSD_AUTOTUNE != capsense_ADC_CSD_SS_DIS)
        if (CYRET_SUCCESS == result)
        {
            result = capsense_ADC_SsAutoTune();
        }
    #endif /* #if (capsense_ADC_CSD_AUTOTUNE != capsense_ADC_CSD_SS_DIS) */

    #if (capsense_ADC_ANY_NONSS_AUTOCAL)
        if (CYRET_SUCCESS == result)
        {
            result = capsense_ADC_CalibrateAllWidgets();
        }
    #endif

    if (CYRET_SUCCESS == result)
    {
        result = capsense_ADC_ScanAllWidgets();
    }

    if (CYRET_SUCCESS == result)
    {
        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = capsense_ADC_SW_WATCHDOG_SCAN_ALL;

        /* Wait for scan to finish. */
        while((capsense_ADC_NOT_BUSY != capsense_ADC_IsBusy()) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }
        if (0u == watchdogCounter)
        {
            result = CYRET_TIMEOUT;
        }
    }

    capsense_ADC_FtInitialize();
    capsense_ADC_InitializeAllBaselines();

    #if(capsense_ADC_ENABLE == capsense_ADC_GES_GLOBAL_EN)
        if (CYRET_SUCCESS == result)
        {
            capsense_ADC_InitializeGestures();
        }
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_GES_GLOBAL_EN) */

    #if (0u != capsense_ADC_BALLISTIC_MULTIPLIER_EN)
        if (CYRET_SUCCESS == result)
        {
            capsense_ADC_InitializeBallisticMultiplier();
        }
    #endif /* (0u != capsense_ADC_BALLISTIC_MULTIPLIER_EN) */

    #if (0u != capsense_ADC_ADC_EN)
        capsense_ADC_AdcInitialize();
    #endif /* (0u != capsense_ADC_ADC_EN) */

    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_Initialize
****************************************************************************//**
*
* \brief
*  This function initializes the capsense_ADC Component.
*
* \details
*  This API initializes all sub-modules of the capsense_ADC Component:
*   - Data Structure - set the default Component parameters defined in the Customizer.
*   - Data Processing - resets all widget statuses.
*   - Tuner - resets tuning state.
*   - Sensing - prepares CSD HW for operation.
*
*  Note that Data Structure module is initialized only once after the reset or
*  capsense_ADC_Stop() API is called. The repeated calls of Initialize API
*  will not re-initialize Data Structure. This is done to preserve Component
*  parameters that user may set in runtime.
*
* \return
*  Return CYRET_SUCCESS if the initialization was successful.
*
*******************************************************************************/
cystatus capsense_ADC_Initialize(void)
{
    cystatus result;

    /* The Data Structure and Tuner are initialized only once */
    if (capsense_ADC_INIT_NEEDED == capsense_ADC_InitVar)
    {
        capsense_ADC_DsInitialize();
        capsense_ADC_TuInitialize();
        capsense_ADC_InitVar = capsense_ADC_INIT_DONE;
    }

    capsense_ADC_DpInitialize();

    result = capsense_ADC_SsInitialize();

    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_Stop
****************************************************************************//**
*
* \brief
*  Stops the Component operation.
*
* \details
*  This function stops the Component operation, no sensor scanning can be
*  executed when the Component is stopped. Once stopped, the hardware block may
*  be reconfigured by the application program for any other special usage. The
*  Component operation can be resumed by calling the capsense_ADC_Resume()
*  function or the Component can be reset by calling the
*  capsense_ADC_Start() function.
*
*  This function is called when no scanning is in progress.
*  I.e. capsense_ADC_IsBusy() returns a non-busy status.
*
* \return
*  Returns the status of the stop process. If CYRET_SUCCESS is not received,
*  the stop process fails and retries may be required.
*
*******************************************************************************/
cystatus capsense_ADC_Stop(void)
{
    cystatus result = CYRET_SUCCESS;

    #if (capsense_ADC_ENABLE == capsense_ADC_ADC_EN)
        /* Release CSD resources */
        result = capsense_ADC_SsReleaseResources();

        /* Release ADC resources */
        capsense_ADC_AdcStop();
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_ADC_EN) */

    capsense_ADC_InitVar = capsense_ADC_INIT_NEEDED;

    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_Resume
****************************************************************************//**
*
* \brief
*  Resumes the Component operation if the capsense_ADC_Stop() function was
*  called previously.
*
* \details
*  This function resumes the Component operation if the operation is stopped
*  previously by the capsense_ADC_Stop() function. The following tasks are
*  executed as part of the operation resume process:
*    1. Reset all the Widgets/Sensors statuses.
*    2. Configure the hardware to perform sensing.
*
* \return
*  Returns the status of the resume process. If CYRET_SUCCESS is not received,
*  the resume process fails and retries may be required.
*
*******************************************************************************/
cystatus capsense_ADC_Resume(void)
{
    cystatus result;

    /* The Tuner are initialized only once in order not to break communication */
    if (capsense_ADC_INIT_NEEDED == capsense_ADC_InitVar)
    {
        capsense_ADC_TuInitialize();
        capsense_ADC_InitVar = capsense_ADC_INIT_DONE;
    }
    capsense_ADC_DpInitialize();

    result = capsense_ADC_SsInitialize();

    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_ProcessAllWidgets
****************************************************************************//**
*
* \brief
*  Performs full data processing of all enabled widgets.
*
* \details
*  This function performs all data processes for all enabled widgets in the
*  Component. The following tasks are executed as part of processing all the
*  widgets:
*    1. Apply raw count filters to the raw counts, if they are enabled in the
*       customizer.
*    2. Update the thresholds if the SmartSense Full Auto-Tuning is enabled in
*       the customizer.
*    3. Update the baselines and difference counts for all the sensors.
*    4. Update the sensor and widget status (on/off), update the centroid for
*       the sliders and the X/Y position for the touchpads.
*
*  This function is called by an application program only after all the enabled
*  widgets (and sensors) in the Component is scanned. Calling this function
*  multiple times without sensor scanning causes unexpected behavior.
*
*  The disabled widgets are not processed by this function. To disable/enable
*  a widget, set the appropriate values in the
*  capsense_ADC_WDGT_ENABLE<RegisterNumber>_PARAM_ID register using the
*  capsense_ADC_SetParam() function.
*
*  If the Ballistic multiplier filter is enabled the Timestamp must be
*  updated before calling this function using the
*  capsense_ADC_IncrementGestureTimestamp() function.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
*  If the ballistic multiplier filter is enabled, make sure the timestamp is
*  updated before calling this function. Use one of the following functions to update
*  the timestamp:
*  - capsense_ADC_IncrementGestureTimestamp().
*  - capsense_ADC_SetGestureTimestamp().
*
* \return
*  Returns the status of the processing operation. If CYRET_SUCCESS is not received,
*  the processing fails and retries may be required.
*
*******************************************************************************/
cystatus capsense_ADC_ProcessAllWidgets(void)
{
    uint32 wdgtId;
    cystatus result = CYRET_SUCCESS;
    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt;

    ptrFlashWdgt = capsense_ADC_dsFlash.wdgtArray;

    for (wdgtId = 0u; wdgtId < capsense_ADC_TOTAL_WIDGETS; wdgtId++)
    {
        if (0uL != capsense_ADC_GET_WIDGET_EN_STATUS(wdgtId))
        {
            switch(capsense_ADC_GET_SENSE_METHOD(ptrFlashWdgt))
            {
            #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS)
                case capsense_ADC_SENSE_METHOD_CSD_E:
                    result = capsense_ADC_DpProcessCsdWidgetRawCounts(ptrFlashWdgt);
                    capsense_ADC_DpProcessCsdWidgetStatus(wdgtId, ptrFlashWdgt);
                    break;
            #endif /* #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS) */

            #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS)
                case capsense_ADC_SENSE_METHOD_CSX_E:
                    result = capsense_ADC_DpProcessCsxWidgetRawCounts(ptrFlashWdgt);
                    capsense_ADC_DpProcessCsxWidgetStatus(wdgtId, ptrFlashWdgt);
                    break;
            #endif /* #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS) */

            #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS)
                case capsense_ADC_SENSE_METHOD_ISX_E:
                    result = capsense_ADC_DpProcessIsxWidgetRawCounts(ptrFlashWdgt);
                    capsense_ADC_DpProcessIsxWidgetStatus(wdgtId, ptrFlashWdgt);
                    break;
            #endif /* #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS) */

            default:
                CYASSERT(0u);
                break;
            }

            #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
                if (CYRET_SUCCESS != result)
                {
                    capsense_ADC_UpdateTestResultBaselineDuplication(wdgtId, result);
                    result = CYRET_BAD_DATA;
                }
            #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

        }
        ptrFlashWdgt++;
    }
    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_ProcessWidget
****************************************************************************//**
*
* \brief
*  Performs full data processing of the specified widget if it is enabled.
*
* \details
*  This function performs exactly the same tasks as
*  capsense_ADC_ProcessAllWidgets(), but only for a specified widget. This
*  function can be used along with the capsense_ADC_SetupWidget() and
*  capsense_ADC_Scan() functions to scan and process data for a specific
*  widget. This function is called only after all the sensors in the
*  widgets are scanned. A disabled widget is not processed by this function.
*
*  A pipeline scan method (i.e. during scanning of a widget perform processing
*  of the previously scanned widget) can be implemented using this function and
*  it may reduce the total execution time, increase the refresh rate and
*  decrease the average power consumption.
*
*  If the Ballistic multiplier filter is enabled the Timestamp must be
*  updated before calling this function using the
*  capsense_ADC_IncrementGestureTimestamp() function.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
*  If the specified widget has enabled ballistic multiplier filter, make sure
*  the timestamp is updated before calling this function. Use one of the following
*  functions to update the timestamp:
*  - capsense_ADC_IncrementGestureTimestamp().
*  - capsense_ADC_SetGestureTimestamp().
*
* \param widgetId
*  Specifies the ID number of the widget to be processed.
*  A macro for the widget ID can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_WDGT_ID
*
* \return
*  Returns the status of the widget processing:
*  - CYRET_SUCCESS - The operation is successfully completed.
*  - CYRET_BAD_PARAM - The input parameter is invalid.
*  - CYRET_INVALID_STATE - The specified widget is disabled.
*  - CYRET_BAD_DATA - The processing is failed.
*
*******************************************************************************/
cystatus capsense_ADC_ProcessWidget(uint32 widgetId)
{
    cystatus result = CYRET_SUCCESS;
    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt;

    if (widgetId >= capsense_ADC_TOTAL_WIDGETS)
    {
        result = CYRET_BAD_PARAM;
    }

    if ((CYRET_SUCCESS == result) && (0uL == capsense_ADC_GET_WIDGET_EN_STATUS(widgetId)))
    {
        result = CYRET_INVALID_STATE;
    }

    if (CYRET_SUCCESS == result)
    {
        ptrFlashWdgt = &capsense_ADC_dsFlash.wdgtArray[widgetId];

        switch(capsense_ADC_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS)
            case capsense_ADC_SENSE_METHOD_CSD_E:
                result = capsense_ADC_DpProcessCsdWidgetRawCounts(ptrFlashWdgt);
                capsense_ADC_DpProcessCsdWidgetStatus(widgetId, ptrFlashWdgt);
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS) */

        #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS)
            case capsense_ADC_SENSE_METHOD_CSX_E:
                result = capsense_ADC_DpProcessCsxWidgetRawCounts(ptrFlashWdgt);
                capsense_ADC_DpProcessCsxWidgetStatus(widgetId, ptrFlashWdgt);
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS) */

        #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS)
            case capsense_ADC_SENSE_METHOD_ISX_E:
                result = capsense_ADC_DpProcessIsxWidgetRawCounts(ptrFlashWdgt);
                capsense_ADC_DpProcessIsxWidgetStatus(widgetId, ptrFlashWdgt);
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS) */

        default:
            CYASSERT(0u);
            break;
        }

        #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
            if (CYRET_SUCCESS != result)
            {
                capsense_ADC_UpdateTestResultBaselineDuplication(widgetId, result);
                result = CYRET_BAD_DATA;
            }
        #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */
    }
    return result;
}


/*******************************************************************************
* Function Name: capsense_ADC_ProcessWidgetExt
****************************************************************************//**
*
* \brief
*  Performs customized data processing on the selected widget.
*
* \details
*  This function performs data processes for the specified widget specified by
*  the mode parameter. The execution order of the requested operations is from
*  LSB to MSB of the mode parameter. For a different order, this API
*  can be called multiple times with the required mode parameter.
*
*  This function can be used with any of the available scan functions. This
*  function is called only after all the sensors in the specified widget are
*  scanned. Calling this function multiple times with the same mode without
*  sensor scanning causes unexpected behavior. This function ignores the value
*  of the wdgtEnable register.
*  \if SECTION_C_LOW_LEVEL
*  The capsense_ADC_PROCESS_CALC_NOISE and
*  capsense_ADC_PROCESS_THRESHOLDS flags are supported by the CSD sensing
*  method only when Auto-tuning mode is enabled.
*  \endif
*  The pipeline scan method (i.e. during scanning of a widget, processing
*  of a previously scanned widget is performed) can be implemented using this
*  function and it may reduce the total scan/process time, increase the refresh
*  rate and decrease the power consumption.
*
*  If the Ballistic multiplier filter is enabled the Timestamp must be
*  updated before calling this function using the
*  capsense_ADC_IncrementGestureTimestamp() function.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
*  If the specified widget has enabled ballistic multiplier filter, make sure
*  the timestamp is updated before calling this function. Use one of the following
*  functions to update the timestamp:
*  - capsense_ADC_IncrementGestureTimestamp().
*  - capsense_ADC_SetGestureTimestamp().
*
* \param widgetId
*  Specifies the ID number of the widget to be processed.
*  A macro for the widget ID can be found in the capsense_ADC Configuration header
*  file defined as capsense_ADC_<WidgetName>_WDGT_ID.

* \param mode
*  Specifies the type of widget processing to be executed for the
*  specified widget:
*    1. Bits [31..6] - Reserved.
*    2. Bits [5..0] - capsense_ADC_PROCESS_ALL - Execute all the tasks.
*    3. Bit [5] - capsense_ADC_PROCESS_STATUS - Update the status (on/off,
*       centroid position).
*    \if SECTION_C_LOW_LEVEL
*    4. Bit [4] - capsense_ADC_PROCESS_THRESHOLDS - Update the thresholds
*       (only in CSD auto-tuning mode).
*    5. Bit [3] - capsense_ADC_PROCESS_CALC_NOISE - Calculate the noise (only in
*       CSD auto-tuning mode).
*    \endif
*    6. Bit [2] - capsense_ADC_PROCESS_DIFFCOUNTS - Update the difference counts.
*    7. Bit [1] - capsense_ADC_PROCESS_BASELINE - Update the baselines.
*    8. Bit [0] - capsense_ADC_PROCESS_FILTER - Run the firmware filters.
*
* \return
*  Returns the status of the widget processing operation:
*  - CYRET_SUCCESS - The processing is successfully performed.
*  - CYRET_BAD_PARAM - The input parameter is invalid.
*  - CYRET_BAD_DATA - The processing is failed.
*
*******************************************************************************/
cystatus capsense_ADC_ProcessWidgetExt(uint32 widgetId, uint32 mode)
{
    uint32 snsCount;
    cystatus result = CYRET_BAD_PARAM;
    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt;
    capsense_ADC_PTR_FILTER_VARIANT fltrHistV;
    capsense_ADC_RAM_SNS_STRUCT *ptrSnsTmp;

    #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS)
        uint32 isProxWdgt;
    #endif

    if (widgetId < capsense_ADC_TOTAL_WIDGETS)
    {
        ptrFlashWdgt = &capsense_ADC_dsFlash.wdgtArray[widgetId];
        snsCount = capsense_ADC_GET_SNS_CNT_BY_PTR(ptrFlashWdgt);
        ptrSnsTmp = ptrFlashWdgt->ptr2SnsRam;
        fltrHistV.ptr = ptrFlashWdgt->ptr2FltrHistory;

        switch(capsense_ADC_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS)
            case capsense_ADC_SENSE_METHOD_CSD_E:
            {
                /* Determine if widget is type of proximity.
                 * The Proximity widgets use different filters and
                 * therefore have different filter history object structure */
                isProxWdgt = (capsense_ADC_GET_WIDGET_TYPE(ptrFlashWdgt) == capsense_ADC_WD_PROXIMITY_E) ? 1Lu : 0Lu;

                /* Run the desired processing for the all CSD widget sensors */
                for (;snsCount-- > 0u;)
                {
                    result = capsense_ADC_DpProcessCsdSensorRawCountsExt(ptrFlashWdgt, ptrSnsTmp, fltrHistV, mode);

                    #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
                        if (CYRET_SUCCESS != result)
                        {
                            result = (result | capsense_ADC_TST_LSBYTE) & snsCount;
                        }
                    #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

                    /* Move to the next sensor and filter history objects */
                    ptrSnsTmp++;
                    capsense_ADC_INC_FLTR_OBJ_VARIANT(isProxWdgt, fltrHistV);
                }

                if (0u != (mode & capsense_ADC_PROCESS_STATUS))
                {
                    capsense_ADC_DpProcessCsdWidgetStatus(widgetId, ptrFlashWdgt);
                }
                break;
            }
        #endif /* #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS) */

        #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS)
            case capsense_ADC_SENSE_METHOD_CSX_E:

                #if (0u != capsense_ADC_CSX_MULTIPHASE_TX_EN)
                    if ((0u != (mode & capsense_ADC_PROCESS_DECONVOLUTION)) &&
                        (0u != (ptrFlashWdgt->staticConfig & capsense_ADC_MULTIPHASE_TX_MASK)))
                    {
                        capsense_ADC_DpDeconvolution(ptrFlashWdgt);
                    }
                #endif /* #if (0u != capsense_ADC_CSX_MULTIPHASE_TX_EN) */

                /* Run the desired processing for the all CSX widget sensors */
                for (;snsCount-- > 0u;)
                {
                    result = capsense_ADC_DpProcessCsxSensorRawCountsExt(ptrFlashWdgt, ptrSnsTmp, fltrHistV, mode);

                    #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
                        if (CYRET_SUCCESS != result)
                        {
                            result = (result | capsense_ADC_TST_LSBYTE) & snsCount;
                        }
                    #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

                    /* Move to the next sensor and filter history objects */
                    ptrSnsTmp++;
                    capsense_ADC_INC_REG_FLTR_OBJ(fltrHistV);
                }

                if (0u != (mode & capsense_ADC_PROCESS_STATUS))
                {
                    capsense_ADC_DpProcessCsxWidgetStatus(widgetId, ptrFlashWdgt);
                }
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS) */

        #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS)
            case capsense_ADC_SENSE_METHOD_ISX_E:
                /* Run the desired processing for the all ISX widget sensors */
                for (;snsCount-- > 0u;)
                {
                    result = capsense_ADC_DpProcessIsxSensorRawCountsExt(ptrFlashWdgt, ptrSnsTmp, fltrHistV, mode);

                    #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
                        if (CYRET_SUCCESS != result)
                        {
                            result = (result | capsense_ADC_TST_LSBYTE) & snsCount;
                        }
                    #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

                    /* Move to the next sensor and filter history objects */
                    ptrSnsTmp++;
                    capsense_ADC_INC_REG_FLTR_OBJ(fltrHistV);
                }

                if (0u != (mode & capsense_ADC_PROCESS_STATUS))
                {
                    capsense_ADC_DpProcessIsxWidgetStatus(widgetId, ptrFlashWdgt);
                }
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS) */

        default:
            CYASSERT(0u);
            break;
        }

        #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
            if (CYRET_SUCCESS != result)
            {
                capsense_ADC_UpdateTestResultBaselineDuplication(widgetId, snsCount);
                result = CYRET_BAD_DATA;
            }
        #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

    }
    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_ProcessSensorExt
****************************************************************************//**
*
* \brief
*  Performs customized data processing on the selected widget's sensor.
*
* \details
*  This function performs data processes for the specified sensor specified by
*  the mode parameter. The execution order of the requested operations is from
*  LSB to MSB of the mode parameter. For a different order, this
*  function can be called multiple times with the required mode parameter.
*
*  This function can be used with any of the available scan functions. This
*  function is called only after a specified sensor in the widget is
*  scanned. Calling this function multiple times with the same mode without
*  sensor scanning causes unexpected behavior. This function ignores the value
*  of the wdgtEnable register.
*
*  \if SECTION_C_LOW_LEVEL
*  The capsense_ADC_PROCESS_CALC_NOISE and
*  capsense_ADC_PROCESS_THRESHOLDS flags are supported by the CSD sensing
*  method only when Auto-tuning mode is enabled.
*  \endif
*
*  The pipeline scan method (i.e. during scanning of a sensor, processing
*  of a previously scanned sensor is performed) can be implemented using this
*  function and it may reduce the total scan/process time, increase the refresh
*  rate and decrease the power consumption.
*
*  If the Self-test library is enabled, this function executes the baseline duplication
*  test. Refer to capsense_ADC_CheckBaselineDuplication() for details.
*
* \param widgetId
*  Specifies the ID number of the widget to process one of its sensors.
*  A macro for the widget ID can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to process it.
*  A macro for the sensor ID within a specified widget can be found in the
*  capsense_ADC Configuration header file defined as
*  capsense_ADC_<WidgetName>_SNS<SensorNumber>_ID.
*
* \param mode
*  Specifies the type of the sensor processing that needs to be executed for the
*  specified sensor:
*    1. Bits [31..5] - Reserved.
*    2. Bits [4..0] - capsense_ADC_PROCESS_ALL - Executes all the tasks.
*    \if SECTION_C_LOW_LEVEL
*    3. Bit [4] - capsense_ADC_PROCESS_THRESHOLDS - Updates the thresholds (only
*       in auto-tuning mode).
*    4. Bit [3] - capsense_ADC_PROCESS_CALC_NOISE - Calculates the noise (only
*       in auto-tuning mode).
*    \endif
*    5. Bit [2] - capsense_ADC_PROCESS_DIFFCOUNTS - Updates the difference count.
*    6. Bit [1] - capsense_ADC_PROCESS_BASELINE - Updates the baseline.
*    7. Bit [0] - capsense_ADC_PROCESS_FILTER - Runs the firmware filters.
*
* \return
*  Returns the status of the sensor process operation:
*  - CYRET_SUCCESS - The processing is successfully performed.
*  - CYRET_BAD_PARAM - The input parameter is invalid.
*  - CYRET_BAD_DATA - The processing is failed.
*
*******************************************************************************/
cystatus capsense_ADC_ProcessSensorExt(uint32 widgetId, uint32 sensorId, uint32 mode)
{
    cystatus result = CYRET_BAD_PARAM;
    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt;
    capsense_ADC_PTR_FILTER_VARIANT fltrHistV;
    capsense_ADC_RAM_SNS_STRUCT *ptrSnsTmp;

    if ((widgetId < capsense_ADC_TOTAL_WIDGETS) && (sensorId < capsense_ADC_GET_SENSOR_COUNT(widgetId)))
    {
        result = CYRET_SUCCESS;

        ptrFlashWdgt = &capsense_ADC_dsFlash.wdgtArray[widgetId];
        fltrHistV.ptr = ptrFlashWdgt->ptr2FltrHistory;
        ptrSnsTmp = ptrFlashWdgt->ptr2SnsRam;
        ptrSnsTmp += sensorId;

        switch(capsense_ADC_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS)
            case capsense_ADC_SENSE_METHOD_CSD_E:
                if (capsense_ADC_WD_PROXIMITY_E == (capsense_ADC_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType)
                {
                    #if (0u != capsense_ADC_PROX_RC_ALP_FILTER_EN)
                        fltrHistV.ptr = &fltrHistV.ptrAlp[sensorId];
                    #elif (0u != capsense_ADC_PROX_RC_FILTER_EN)
                        fltrHistV.ptr = &fltrHistV.ptrProx[sensorId];
                    #endif
                }
                else
                {
                    #if (0u != capsense_ADC_REGULAR_RC_ALP_FILTER_EN)
                        fltrHistV.ptr = &fltrHistV.ptrAlp[sensorId];
                    #elif (0u != capsense_ADC_REGULAR_RC_FILTER_EN)
                        fltrHistV.ptr = &fltrHistV.ptrRegular[sensorId];
                    #endif
                }

                result = capsense_ADC_DpProcessCsdSensorRawCountsExt(ptrFlashWdgt, ptrSnsTmp, fltrHistV, mode);
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS) */

        #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS)
            case capsense_ADC_SENSE_METHOD_CSX_E:
                #if (0u != capsense_ADC_REGULAR_RC_ALP_FILTER_EN)
                    fltrHistV.ptr = &fltrHistV.ptrAlp[sensorId];
                #elif (0u != capsense_ADC_REGULAR_RC_FILTER_EN)
                    fltrHistV.ptr = &fltrHistV.ptrRegular[sensorId];
                #endif

                result = capsense_ADC_DpProcessCsxSensorRawCountsExt(ptrFlashWdgt, ptrSnsTmp, fltrHistV, mode);
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS) */

        #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS)
            case capsense_ADC_SENSE_METHOD_ISX_E:
                if (capsense_ADC_WD_PROXIMITY_E == (capsense_ADC_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType)
                {
                    #if (0u != capsense_ADC_PROX_RC_FILTER_EN)
                        fltrHistV.ptr = &fltrHistV.ptrProx[sensorId];
                    #endif /* #if (0u != capsense_ADC_PROX_RC_FILTER_EN) */
                }
                else
                {
                    #if (0u != capsense_ADC_REGULAR_RC_FILTER_EN)
                        fltrHistV.ptr = &fltrHistV.ptrRegular[sensorId];
                    #endif /* #if (0u != capsense_ADC_REGULAR_RC_FILTER_EN) */
                }

                result = capsense_ADC_DpProcessIsxSensorRawCountsExt(ptrFlashWdgt, ptrSnsTmp, fltrHistV, mode);
                break;
        #endif /* #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS) */

        default:
            CYASSERT(0u);
            break;
        }

        #if (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN)
            if (CYRET_SUCCESS != result)
            {
                capsense_ADC_UpdateTestResultBaselineDuplication(widgetId, sensorId);
                result = CYRET_BAD_DATA;
            }
        #endif /* (capsense_ADC_ENABLE == capsense_ADC_TST_BSLN_DUPLICATION_EN) */

    }
    return result;
}

/*******************************************************************************
* Function Name: capsense_ADC_Sleep
****************************************************************************//**
*
* \brief
*  Prepares the Component for deep sleep.
*
* \details
*  Currently this function is empty and exists as a place for future updates,
*  this function will be used to prepare the Component to enter deep sleep.
*
*******************************************************************************/
void capsense_ADC_Sleep(void)
{
}


/*******************************************************************************
* Function Name: capsense_ADC_Wakeup
****************************************************************************//**
*
* \brief
*  Resumes the Component after deep sleep power mode.
*
* \details
*  Resumes the Component after deep sleep power mode. This function is used to
*  resume the Component after exiting deep sleep.
*
*******************************************************************************/
void capsense_ADC_Wakeup(void)
{
    #if(capsense_ADC_ENABLE == capsense_ADC_CSDV2)
        #if(capsense_ADC_BLOCK_ANALOG_WAKEUP_DELAY_US > 0uL)
            CyDelayUs(capsense_ADC_BLOCK_ANALOG_WAKEUP_DELAY_US);
        #endif /* (capsense_ADC_BLOCK_ANALOG_WAKEUP_DELAY_US > 0uL) */
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_CSDV2) */
}


/* [] END OF FILE */
