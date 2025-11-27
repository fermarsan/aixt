/***************************************************************************//**
* \file capsense_ADC_Processing.h
* \version 7.10
*
* \brief
*   This file provides the function prototypes for the Data Processing module.
*   The Data Processing module is responsible for the low level raw counts
*   processing provided by the sensing module, maintaining baseline and
*   difference values and performing high-level widget processing like updating
*   button status or calculating slider position.
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

#if !defined(CY_SENSE_capsense_ADC_DATA_PROCESS_H)
#define CY_SENSE_capsense_ADC_DATA_PROCESS_H

#include "capsense_ADC_Configuration.h"
#include "capsense_ADC_Structure.h"

#if (0 != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
    #include "capsense_ADC_SmartSense_LL.h"
#endif /* (0 != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

/*******************************************************************************
* Definitions
*******************************************************************************/

/* Defines the data processing tasks */

/* Applies all enabled filters in the default order to the raw counts */
#define capsense_ADC_PROCESS_FILTER             (0x01Lu)

/* Updates baselines using current raw count values for the widget/sensor */
#define capsense_ADC_PROCESS_BASELINE           (0x02Lu)

/* Calculates differences for the widget/sensor */
#define capsense_ADC_PROCESS_DIFFCOUNTS         (0x04Lu)

/* Runs the noise envelope filter to measure noise magnitude for the widget/sensor */
#define capsense_ADC_PROCESS_CALC_NOISE         (0x08Lu)

/* Updates widget thresholds based on raw counts noise magnitude */
#define capsense_ADC_PROCESS_THRESHOLDS         (0x10Lu)

/* Runs the widget-specific processing algorithms and updates it status */
#define capsense_ADC_PROCESS_STATUS             (0x20Lu)

/* Runs the deconvolution algorithm for the widgets with the multiphase TX scanning */
#define capsense_ADC_PROCESS_DECONVOLUTION      (0x40Lu)

/* Definition that combines all possible processing tasks */
#define capsense_ADC_PROCESS_ALL    (capsense_ADC_PROCESS_FILTER        | \
                                         capsense_ADC_PROCESS_BASELINE      | \
                                         capsense_ADC_PROCESS_DIFFCOUNTS    | \
                                         capsense_ADC_PROCESS_CALC_NOISE    | \
                                         capsense_ADC_PROCESS_THRESHOLDS    | \
                                         capsense_ADC_PROCESS_DECONVOLUTION | \
                                         capsense_ADC_PROCESS_STATUS )

/*******************************************************************************
* Function Prototypes - internal functions.
*******************************************************************************/
/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

void capsense_ADC_DpInitialize(void);

#if ((0u != capsense_ADC_BUTTON_WIDGET_EN) || (0u != capsense_ADC_CSX_MATRIX_WIDGET_EN))
    uint32 capsense_ADC_DpProcessButton(uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if ((0u != capsense_ADC_BUTTON_WIDGET_EN) || (0u != capsense_ADC_CSX_MATRIX_WIDGET_EN)) */

#if (0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN)
    uint32 capsense_ADC_DpProcessCsxTouchpad(
                uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_CSX_TOUCHPAD_WIDGET_EN) */

#if (0u != capsense_ADC_PROXIMITY_WIDGET_EN)
    uint32 capsense_ADC_DpProcessProximity(uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_PROXIMITY_WIDGET_EN) */

#if (0u != capsense_ADC_ENCODERDIAL_WIDGET_EN)
    uint32 capsense_ADC_DpProcessEncoderDial(uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_PROXIMITY_WIDGET_EN) */

#if (0u != capsense_ADC_SLIDER_WIDGET_EN)
    uint32 capsense_ADC_DpProcessSlider(uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_SLIDER_WIDGET_EN) */

#if (0u != capsense_ADC_CSD_MATRIX_WIDGET_EN)
    uint32 capsense_ADC_DpProcessCsdMatrix(uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_CSD_MATRIX_WIDGET_EN) */

#if (0u != capsense_ADC_CSD_TOUCHPAD_WIDGET_EN)
    uint32 capsense_ADC_DpProcessCsdTouchpad(
                uint32 currStatus, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_CSD_TOUCHPAD_WIDGET_EN) */

#if (0u != capsense_ADC_TOTAL_CSD_WIDGETS)
    uint32 capsense_ADC_DpProcessCsdWidgetRawCounts(
                    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 capsense_ADC_DpProcessCsdSensorRawCountsExt(
                    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt,
                    capsense_ADC_RAM_SNS_STRUCT *curSnsPtr,
                    capsense_ADC_PTR_FILTER_VARIANT fltrHistV,
                     uint32 mode);

    void capsense_ADC_DpProcessCsdWidgetStatus(uint32 widgetId, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_TOTAL_CSD_WIDGETS) */

#if (0u != capsense_ADC_TOTAL_CSX_WIDGETS)
    uint32 capsense_ADC_DpProcessCsxWidgetRawCounts(
            capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 capsense_ADC_DpProcessCsxSensorRawCountsExt(
                    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt,
                    capsense_ADC_RAM_SNS_STRUCT *curSnsPtr,
                    capsense_ADC_PTR_FILTER_VARIANT fltrHistV,
                     uint32 mode);

    void capsense_ADC_DpProcessCsxWidgetStatus(
                uint32 widgetId, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_TOTAL_CSX_WIDGETS) */

#if (0u != capsense_ADC_TOTAL_ISX_WIDGETS)
    uint32 capsense_ADC_DpProcessIsxWidgetRawCounts(
            capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 capsense_ADC_DpProcessIsxSensorRawCountsExt(
                    capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt,
                    capsense_ADC_RAM_SNS_STRUCT *ptrSns,
                    capsense_ADC_PTR_FILTER_VARIANT fltrHistV,
                     uint32 mode);

    void capsense_ADC_DpProcessIsxWidgetStatus(
                uint32 wdgtId, capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_TOTAL_ISX_WIDGETS) */

void capsense_ADC_DpUpdateDifferences(
        capsense_ADC_RAM_WD_BASE_STRUCT  *ptrRamWdgt, capsense_ADC_RAM_SNS_STRUCT *curSnsPtr);

#if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
    void capsense_ADC_DpUpdateThresholds(
                    capsense_ADC_RAM_WD_BASE_STRUCT *ptrRamWdgt,
                    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope,
                    uint32 startFlag);
#endif /* #if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

#if (0u != capsense_ADC_CSX_MULTIPHASE_TX_EN)
    void capsense_ADC_DpDeconvolution(capsense_ADC_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != capsense_ADC_CSX_MULTIPHASE_TX_EN) */


/** \}
* \endcond */

/*******************************************************************************
* API Constants
*******************************************************************************/

#if (0u != capsense_ADC_ENCODERDIAL_WIDGET_EN)
    #define capsense_ADC_DIALTRANSITION_CW0      (0x1u)
    #define capsense_ADC_DIALTRANSITION_CW1      (0x7u)
    #define capsense_ADC_DIALTRANSITION_CW2      (0x8u)
    #define capsense_ADC_DIALTRANSITION_CW3      (0xEu)
    #define capsense_ADC_DIALTRANSITION_CCW0     (0x2u)
    #define capsense_ADC_DIALTRANSITION_CCW1     (0x4u)
    #define capsense_ADC_DIALTRANSITION_CCW2     (0xBu)
    #define capsense_ADC_DIALTRANSITION_CCW3     (0xDu)
#endif /* (0u != capsense_ADC_ENCODERDIAL_WIDGET_EN) */

#endif /* End CY_SENSE_capsense_ADC_DATA_PROCESS_H */


/* [] END OF FILE */
