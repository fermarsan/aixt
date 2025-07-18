/***************************************************************************//**
* \file capsense_ADC_Filter.h
* \version 7.10
*
* \brief
*   This file contains the definitions for all firmware filters
*   implementation.
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

#if !defined(CY_SENSE_capsense_ADC_FILTER_H)
#define CY_SENSE_capsense_ADC_FILTER_H

#include "cytypes.h"
#include "CyLib.h"
#include "cyfitter.h"

#include "capsense_ADC_Structure.h"
#include "capsense_ADC_Configuration.h"

/***************************************
* Function Prototypes
***************************************/

/*******************************************************************************
* LOW LEVEL API
*******************************************************************************/
/**
* \cond (SECTION_C_LOW_LEVEL || SECTION_I_LOW_LEVEL)
* \addtogroup group_c_low_level
* \{
*/

cystatus capsense_ADC_UpdateAllBaselines(void);
cystatus capsense_ADC_UpdateWidgetBaseline(uint32 widgetId);
cystatus capsense_ADC_UpdateSensorBaseline(uint32 widgetId, uint32 sensorId);

void capsense_ADC_InitializeAllBaselines(void);
void capsense_ADC_InitializeWidgetBaseline(uint32 widgetId);
void capsense_ADC_InitializeSensorBaseline(uint32 widgetId, uint32 sensorId);

#if ((capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) || \
     (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)))
    void capsense_ADC_InitializeAllFilters(void);
    void capsense_ADC_InitializeWidgetFilter(uint32 widgetId);
#endif /* ((capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) || \
           (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))) */

/** \}
* \endcond */


/*******************************************************************************
* Function Prototypes - internal functions
*******************************************************************************/
/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

void capsense_ADC_FtInitialize(void);

#if (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN))
    void capsense_ADC_RunNoiseEnvelope(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_InitializeNoiseEnvelope(uint32 widgetId, uint32 sensorId);
#endif /* (0u != (capsense_ADC_CSD_AUTOTUNE & capsense_ADC_CSD_SS_TH_EN)) */

#if (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN)
    void capsense_ADC_InitializeIIR(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_RunIIR(uint32 widgetId, uint32 sensorId);
#endif /* (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN) */

#if (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
    void capsense_ADC_InitializeMedian(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_RunMedian(uint32 widgetId, uint32 sensorId);
#endif /* (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN) */

#if (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)
    void capsense_ADC_InitializeAverage(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_RunAverage(uint32 widgetId, uint32 sensorId);
#endif /* (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN) */

void capsense_ADC_FtInitializeBaseline(capsense_ADC_RAM_SNS_STRUCT *ptrSensor, uint32 wdType);
uint32 capsense_ADC_FtUpdateBaseline(
                            capsense_ADC_RAM_WD_BASE_STRUCT *ptrWidgetRam,
                            capsense_ADC_RAM_SNS_STRUCT *ptrSensor,
                            uint32 wdType);

#if (capsense_ADC_POS_MEDIAN_FILTER_EN || capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
uint32 capsense_ADC_FtMedian(uint32 x1, uint32 x2, uint32 x3);
#endif /*capsense_ADC_POS_MEDIAN_FILTER_EN || capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN*/

uint32 capsense_ADC_FtIIR1stOrder(uint32 input, uint32 prevOutput, uint32 n, uint32 shift);

#if (capsense_ADC_POS_JITTER_FILTER_EN)
    uint32 capsense_ADC_FtJitter(uint32 input, uint32 prevOutput);
#endif /* capsense_ADC_POS_JITTER_FILTER_EN */

void capsense_ADC_FtInitializeBaselineChannel(capsense_ADC_RAM_SNS_STRUCT *ptrSensor, uint32 wdType, uint32 channel);

#if (capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN)
    void capsense_ADC_FtRunEnabledFilters(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_FtRunEnabledFiltersInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                                      capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
#endif /* (capsense_ADC_ENABLE == capsense_ADC_RC_FILTER_EN) */


#if (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN)
    void capsense_ADC_InitializeIIRInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                                  capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
    void capsense_ADC_RunIIRInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                           capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
#endif /* (capsense_ADC_REGULAR_RC_IIR_FILTER_EN || capsense_ADC_PROX_RC_IIR_FILTER_EN) */

#if (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN)
    void capsense_ADC_InitializeMedianInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                                     capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
    void capsense_ADC_RunMedianInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                              capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
#endif /* (capsense_ADC_REGULAR_RC_MEDIAN_FILTER_EN || capsense_ADC_PROX_RC_MEDIAN_FILTER_EN) */

#if (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN)
    void capsense_ADC_InitializeAverageInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                                      capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
    void capsense_ADC_RunAverageInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                               capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType);
#endif /* (capsense_ADC_REGULAR_RC_AVERAGE_FILTER_EN || capsense_ADC_PROX_RC_AVERAGE_FILTER_EN) */

#if (capsense_ADC_ENABLE == capsense_ADC_ALP_FILTER_EN)
    void capsense_ADC_InitializeALP(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_RunALP(uint32 widgetId, uint32 sensorId);
    void capsense_ADC_InitializeALPInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                                capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj,
                                                uint32 wdType);
    void capsense_ADC_ConfigRunALPInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                        capsense_ADC_RAM_WD_BASE_STRUCT *ptrRamWdgt,
                                        capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj,
                                        uint32 wdType);
    void capsense_ADC_RunALPInternal(capsense_ADC_PTR_FILTER_VARIANT ptrFilterHistObj,
                                        ALP_FLTR_CONFIG_STRUCT *ptrAlpFilterConfig,
                                        capsense_ADC_RAM_SNS_STRUCT *ptrSensorObj,
                                        uint32 wdType);
#endif /* (capsense_ADC_ENABLE == capsense_ADC_ALP_FILTER_EN) */

/** \}
* \endcond */

/***************************************
* Initial Parameter Constants
***************************************/
#define NOISE_ENVELOPE_SHIFT                        (0x02u)
#define NOISE_ENVELOPE_RUN_DIFF_SHIFT               (0x03u)
#define NOISE_ENVELOPE_SIGN_REG                     (0x0Fu)
#define NOISE_ENVELOPE_SIGN_REG_SHIFT               (0x01u)
#define NOISE_ENVELOPE_RESET_COUNTER                (0x0Au)
#define NOISE_ENVELOPE_4_TIMES                      (0x02u)

#endif /* End CY_SENSE_capsense_ADC_FILTER_H */


/* [] END OF FILE */
