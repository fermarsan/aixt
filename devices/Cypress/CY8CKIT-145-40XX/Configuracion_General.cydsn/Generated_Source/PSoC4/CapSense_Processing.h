/***************************************************************************//**
* \file CapSense_Processing.h
* \version 7.10
*
* \brief
*   This file provides the function prototypes for the Data Processing module.
*   The Data Processing module is responsible for the low level raw counts
*   processing provided by the sensing module, maintaining baseline and
*   difference values and performing high-level widget processing like updating
*   button status or calculating slider position.
*
* \see CapSense v7.10 Datasheet
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

#if !defined(CY_SENSE_CapSense_DATA_PROCESS_H)
#define CY_SENSE_CapSense_DATA_PROCESS_H

#include "CapSense_Configuration.h"
#include "CapSense_Structure.h"

#if (0 != (CapSense_CSD_AUTOTUNE & CapSense_CSD_SS_TH_EN))
    #include "CapSense_SmartSense_LL.h"
#endif /* (0 != (CapSense_CSD_AUTOTUNE & CapSense_CSD_SS_TH_EN)) */

/*******************************************************************************
* Definitions
*******************************************************************************/

/* Defines the data processing tasks */

/* Applies all enabled filters in the default order to the raw counts */
#define CapSense_PROCESS_FILTER             (0x01Lu)

/* Updates baselines using current raw count values for the widget/sensor */
#define CapSense_PROCESS_BASELINE           (0x02Lu)

/* Calculates differences for the widget/sensor */
#define CapSense_PROCESS_DIFFCOUNTS         (0x04Lu)

/* Runs the noise envelope filter to measure noise magnitude for the widget/sensor */
#define CapSense_PROCESS_CALC_NOISE         (0x08Lu)

/* Updates widget thresholds based on raw counts noise magnitude */
#define CapSense_PROCESS_THRESHOLDS         (0x10Lu)

/* Runs the widget-specific processing algorithms and updates it status */
#define CapSense_PROCESS_STATUS             (0x20Lu)

/* Runs the deconvolution algorithm for the widgets with the multiphase TX scanning */
#define CapSense_PROCESS_DECONVOLUTION      (0x40Lu)

/* Definition that combines all possible processing tasks */
#define CapSense_PROCESS_ALL    (CapSense_PROCESS_FILTER        | \
                                         CapSense_PROCESS_BASELINE      | \
                                         CapSense_PROCESS_DIFFCOUNTS    | \
                                         CapSense_PROCESS_CALC_NOISE    | \
                                         CapSense_PROCESS_THRESHOLDS    | \
                                         CapSense_PROCESS_DECONVOLUTION | \
                                         CapSense_PROCESS_STATUS )

/*******************************************************************************
* Function Prototypes - internal functions.
*******************************************************************************/
/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

void CapSense_DpInitialize(void);

#if ((0u != CapSense_BUTTON_WIDGET_EN) || (0u != CapSense_CSX_MATRIX_WIDGET_EN))
    uint32 CapSense_DpProcessButton(uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if ((0u != CapSense_BUTTON_WIDGET_EN) || (0u != CapSense_CSX_MATRIX_WIDGET_EN)) */

#if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN)
    uint32 CapSense_DpProcessCsxTouchpad(
                uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN) */

#if (0u != CapSense_PROXIMITY_WIDGET_EN)
    uint32 CapSense_DpProcessProximity(uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_PROXIMITY_WIDGET_EN) */

#if (0u != CapSense_ENCODERDIAL_WIDGET_EN)
    uint32 CapSense_DpProcessEncoderDial(uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_PROXIMITY_WIDGET_EN) */

#if (0u != CapSense_SLIDER_WIDGET_EN)
    uint32 CapSense_DpProcessSlider(uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_SLIDER_WIDGET_EN) */

#if (0u != CapSense_CSD_MATRIX_WIDGET_EN)
    uint32 CapSense_DpProcessCsdMatrix(uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_CSD_MATRIX_WIDGET_EN) */

#if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN)
    uint32 CapSense_DpProcessCsdTouchpad(
                uint32 currStatus, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN) */

#if (0u != CapSense_TOTAL_CSD_WIDGETS)
    uint32 CapSense_DpProcessCsdWidgetRawCounts(
                    CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 CapSense_DpProcessCsdSensorRawCountsExt(
                    CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt,
                    CapSense_RAM_SNS_STRUCT *curSnsPtr,
                    CapSense_PTR_FILTER_VARIANT fltrHistV,
                     uint32 mode);

    void CapSense_DpProcessCsdWidgetStatus(uint32 widgetId, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_TOTAL_CSD_WIDGETS) */

#if (0u != CapSense_TOTAL_CSX_WIDGETS)
    uint32 CapSense_DpProcessCsxWidgetRawCounts(
            CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 CapSense_DpProcessCsxSensorRawCountsExt(
                    CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt,
                    CapSense_RAM_SNS_STRUCT *curSnsPtr,
                    CapSense_PTR_FILTER_VARIANT fltrHistV,
                     uint32 mode);

    void CapSense_DpProcessCsxWidgetStatus(
                uint32 widgetId, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_TOTAL_CSX_WIDGETS) */

#if (0u != CapSense_TOTAL_ISX_WIDGETS)
    uint32 CapSense_DpProcessIsxWidgetRawCounts(
            CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 CapSense_DpProcessIsxSensorRawCountsExt(
                    CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt,
                    CapSense_RAM_SNS_STRUCT *ptrSns,
                    CapSense_PTR_FILTER_VARIANT fltrHistV,
                     uint32 mode);

    void CapSense_DpProcessIsxWidgetStatus(
                uint32 wdgtId, CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_TOTAL_ISX_WIDGETS) */

void CapSense_DpUpdateDifferences(
        CapSense_RAM_WD_BASE_STRUCT  *ptrRamWdgt, CapSense_RAM_SNS_STRUCT *curSnsPtr);

#if (0u != (CapSense_CSD_AUTOTUNE & CapSense_CSD_SS_TH_EN))
    void CapSense_DpUpdateThresholds(
                    CapSense_RAM_WD_BASE_STRUCT *ptrRamWdgt,
                    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope,
                    uint32 startFlag);
#endif /* #if (0u != (CapSense_CSD_AUTOTUNE & CapSense_CSD_SS_TH_EN)) */

#if (0u != CapSense_CSX_MULTIPHASE_TX_EN)
    void CapSense_DpDeconvolution(CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_CSX_MULTIPHASE_TX_EN) */


/** \}
* \endcond */

/*******************************************************************************
* API Constants
*******************************************************************************/

#if (0u != CapSense_ENCODERDIAL_WIDGET_EN)
    #define CapSense_DIALTRANSITION_CW0      (0x1u)
    #define CapSense_DIALTRANSITION_CW1      (0x7u)
    #define CapSense_DIALTRANSITION_CW2      (0x8u)
    #define CapSense_DIALTRANSITION_CW3      (0xEu)
    #define CapSense_DIALTRANSITION_CCW0     (0x2u)
    #define CapSense_DIALTRANSITION_CCW1     (0x4u)
    #define CapSense_DIALTRANSITION_CCW2     (0xBu)
    #define CapSense_DIALTRANSITION_CCW3     (0xDu)
#endif /* (0u != CapSense_ENCODERDIAL_WIDGET_EN) */

#endif /* End CY_SENSE_CapSense_DATA_PROCESS_H */


/* [] END OF FILE */
