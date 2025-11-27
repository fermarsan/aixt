/***************************************************************************//**
* \file capsense_ADC_SmartSense_LL.h
* \version 7.10
*
* \brief
*   This file provides the sources of APIs specific to the SmartSense implementation.
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

#if !defined(CY_SENSE_SMARTSENSE_LL_H)
#define CY_SENSE_SMARTSENSE_LL_H

/* Check versions of compilers. */

#include "cytypes.h"

/*******************************************************************************
* Declares HW SmartSense data structure for CSD widgets
*******************************************************************************/
typedef struct
{
    /**
     *  Sensor parasitic capacitance in fF 10^-15
     */
    uint32 sensorCap;

    /**
     *  iDac Gain in pA
     */
    uint32 iDacGain;

    /**
     *  Pointer to SnsClk divider
     */
    uint16 *ptrSenseClk;

    /**
     *  Pointer to sigPFC value (Signal Per Finger Capacitance)
     */
    uint16 *sigPFC;

    /**
     *  CsdSnsClockConstantR (Set in Expression view)
     */
    uint16 snsClkConstantR;

    /**
     *  Vref in mVolts (Set in Expression view)
     */
    uint16 vRef;

    /**
     *  Finger capacitance in fF 10^-15 (Set in Basic tab in pF 10^-12)
     */
    uint16 fingerCap;

    /**
     *  Sense Input Clock in kHz
     */
    uint16 snsClkInputClock;

    /**
     *  Calibration target
     */
    uint16 calTarget;

    /**
     *  IDAC code
     */
    uint8 iDacMod;

    /**
     *  IDAC code
     */
    uint8 iDacComp;

}AUTO_TUNE_CONFIG_TYPE;

/**
* \cond SECTION_STRUCTURES
* \addtogroup group_structures
* \{
*/

/***************************************************************************//**
* \brief Declares Noise envelope data structure for CSD widgets when SmartSense is enabled
*******************************************************************************/
typedef struct
{
    /**
     * Parameter 0 configuration
     */
    uint16 param0;
    /**
     * Parameter 1 configuration
     */
    uint16 param1;
    /**
     * Parameter 2 configuration
     */
    uint16 param2;
    /**
     * Parameter 3 configuration
     */
    uint16 param3;
    /**
     * Parameter 4 configuration
     */
    uint16 param4;
    /**
     * Parameter 5 configuration
     */
    uint8  param5;
    /**
     * Parameter 6 configuration
     */
    uint8  param6;
} SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT;

/** \}
* \endcond */

/*******************************************************************************
* Declares Update Thresholds structure
*******************************************************************************/
typedef struct
{
    /**
     *  Widget Finger Threshold.
     */
    uint16 fingerTh;

    /**
     *  Widget Noise Threshold.
     */
    uint8  noiseTh;

    /**
     *  Widget Negative Noise Threshold.
     */
    uint8  nNoiseTh;

    /**
     *  Widget Hysteresis for the signal crossing finger threshold.
     */
    uint8  hysteresis;
} SMARTSENSE_UPDATE_THRESHOLDS_STRUCT;


/*****************************************************
* Function Prototypes
*****************************************************/

uint32 SmartSense_TunePrescalers(AUTO_TUNE_CONFIG_TYPE *config);
uint8 SmartSense_TuneSensitivity(AUTO_TUNE_CONFIG_TYPE *config);

void SmartSense_UpdateThresholds(const SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope,
                                SMARTSENSE_UPDATE_THRESHOLDS_STRUCT *ptrThresholds,
                                uint16 sigPFC,
                                uint32 startFlag);

void SmartSense_InitializeNoiseEnvelope(uint16 rawCount,
                                        uint16 sigPFC,
                                        SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope);

void SmartSense_RunNoiseEnvelope(uint16 rawCount,
                                 uint16 sigPFC,
                                 SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope);

#endif /* End CY_SENSE_SMARTSENSE_LL_H */


/* [] END OF FILE */
