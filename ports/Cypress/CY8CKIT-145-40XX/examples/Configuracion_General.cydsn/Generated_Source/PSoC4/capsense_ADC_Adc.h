/***************************************************************************//**
* \file capsense_ADC_Adc.h
* \version 7.10
*
* \brief
*   This file provides the sources of APIs specific to the ADC implementation.
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

#if !defined(CY_SENSE_capsense_ADC_ADC_H)
#define CY_SENSE_capsense_ADC_ADC_H

#include "cytypes.h"
#include "capsense_ADC_Configuration.h"
#include "capsense_ADC_Structure.h"

#if (capsense_ADC_ADC_EN)

/*******************************************************************************
* Function Prototypes
*******************************************************************************/

/**
* \cond SECTION_STANDALONE_ADC
* \addtogroup group_adc_public
* \{
*/
#if (capsense_ADC_ENABLE == capsense_ADC_ADC_STANDALONE_EN)
    void capsense_ADC_Start(void);
    void capsense_ADC_Sleep(void);
    void capsense_ADC_Wakeup(void);
#endif  /* (capsense_ADC_ENABLE == capsense_ADC_ADC_STANDALONE_EN) */

/** \}
* \endcond */

/**
* \cond SECTION_ADC_PUBLIC
* \addtogroup group_adc_public
* \{
*/
cystatus capsense_ADC_AdcStartConvert(uint8 chId);
uint8 capsense_ADC_AdcIsBusy(void);
uint16 capsense_ADC_AdcReadResult_mVolts(uint8 chId);
uint16 capsense_ADC_AdcGetResult_mVolts(uint8 chId);
cystatus capsense_ADC_AdcCalibrate(void);

void capsense_ADC_Stop(void);
void capsense_ADC_Resume(void);

/** \}
* \endcond */

CY_ISR_PROTO(capsense_ADC_AdcIntrHandler);

/**
* \cond SECTION_ADC_INTERNAL
* \addtogroup group_adc_internal
* \{
*/

void capsense_ADC_AdcInitialize(void);
void capsense_ADC_SetAdcChannel(uint8 chId, uint32 state);
void capsense_ADC_ConfigAdcResources(void);
void capsense_ADC_StartAdcFSM(uint32 measureMode);
cystatus capsense_ADC_AdcCaptureResources(void);
cystatus capsense_ADC_AdcReleaseResources(void);
void capsense_ADC_ClearAdcChannels(void);
void capsense_ADC_SetNonDedicatedAdcChannel(uint8 chId, uint32 state);

/** \}
* \endcond */

/**************************************
* Global software/external variables
**************************************/

extern uint16 capsense_ADC_adcVrefMv;

/**************************************
*           API Constants
**************************************/

/* Error value if given bad channel ID. */
#define capsense_ADC_AdcVALUE_BAD_CHAN_ID            (0x0000FFFFuL)
#define capsense_ADC_AdcVALUE_BAD_RESULT             (0x0000FFFFuL)

/* Statuses defined for use with IsBusy */
#define capsense_ADC_AdcSTATUS_LASTCHAN_MASK         (0x0000000FuL)
#define capsense_ADC_AdcSTATUS_FSM_MASK              (0x000000F0uL)
#define capsense_ADC_AdcSTATUS_IDLE                  (0x00u)
#define capsense_ADC_AdcSTATUS_CALIBPH1              (0x10u)
#define capsense_ADC_AdcSTATUS_CALIBPH2              (0x20u)
#define capsense_ADC_AdcSTATUS_CALIBPH3              (0x30u)
#define capsense_ADC_AdcSTATUS_CONVERTING            (0x40u)
#define capsense_ADC_AdcSTATUS_OVERFLOW              (0x80u)

/* Potential channel states */
#define capsense_ADC_AdcCHAN_CONNECT                 (1uL)
#define capsense_ADC_AdcCHAN_DISCONNECT              (0uL)

/* Active channel when ADC is not configured */
#define capsense_ADC_AdcNO_CHANNEL                   (0xFFu)

#define capsense_ADC_AdcGPIO_PC_INPUT                (0x1uL)

/* Default filter delay */
#define capsense_ADC_AdcFILTER_DELAY_DEFAULT         (2uL)

/* Adc Config */
#define capsense_ADC_AdcCONFIG_DEFAULT               (capsense_ADC_CONFIG_ENABLE_MASK | \
                                                                            capsense_ADC_CONFIG_SAMPLE_SYNC_MASK | \
                                                                            capsense_ADC_CONFIG_SENSE_EN_MASK | \
                                                                            capsense_ADC_CONFIG_DSI_COUNT_SEL_MASK | \
                                                                            capsense_ADC_AdcFILTER_DELAY_DEFAULT)

/* Measurement modes */
#define capsense_ADC_AdcMEASMODE_OFF                 (0x0uL << CYFLD_CSD_ADC_MODE__OFFSET)
#define capsense_ADC_AdcMEASMODE_VREF                (0x1uL << CYFLD_CSD_ADC_MODE__OFFSET)
#define capsense_ADC_AdcMEASMODE_VREFBY2             (0x2uL << CYFLD_CSD_ADC_MODE__OFFSET)
#define capsense_ADC_AdcMEASMODE_VIN                 (0x3uL << CYFLD_CSD_ADC_MODE__OFFSET)

/* Clock defines */
#define capsense_ADC_AdcSENSE_DIV_DEFAULT            (0x4uL)
#define capsense_ADC_AdcTOTAL_CLOCK_DIV              (capsense_ADC_ADC_MODCLK_DIV_DEFAULT * \
                                                                         capsense_ADC_AdcSENSE_DIV_DEFAULT)

/* The MAX possible value of the AZ time in CSD_SENSE cycles. The value is limited by the width of the SEQ_TIME register */
#define capsense_ADC_ADC_SEQ_TIME_MAX                               (0x100u)

#define capsense_ADC_ADC_SEQ_TIME_CYCLES                            (((CYDEV_BCLK__HFCLK__HZ * capsense_ADC_ADC_AZ_TIME) / \
                                                                         capsense_ADC_AdcTOTAL_CLOCK_DIV) / 1000000uL)

#if (capsense_ADC_ADC_SEQ_TIME_MAX < capsense_ADC_ADC_SEQ_TIME_CYCLES)
    #define capsense_ADC_AdcSEQ_TIME_BASE            (capsense_ADC_ADC_SEQ_TIME_MAX)
#else
    #define capsense_ADC_AdcSEQ_TIME_BASE            (capsense_ADC_ADC_SEQ_TIME_CYCLES)
#endif

#if (0 == capsense_ADC_AdcSEQ_TIME_BASE)
    #define capsense_ADC_AdcSEQ_TIME_DEFAUL          (1u)
#else
    #define capsense_ADC_AdcSEQ_TIME_DEFAUL          (capsense_ADC_AdcSEQ_TIME_BASE)
#endif

/* Acquisition time definitions: ADC_CTL */
#define capsense_ADC_AdcACQUISITION_BASE             ((capsense_ADC_ADC_ACQUISITION_TIME_US * \
                                                                        (CYDEV_BCLK__HFCLK__MHZ)) / \
                                                                         capsense_ADC_AdcTOTAL_CLOCK_DIV)

/* SEQ_START field definitions */
#define capsense_ADC_AdcFSMSETTING_ABORT             (0x1uL << CYFLD_CSD_ABORT__OFFSET)
#define capsense_ADC_AdcFSMSETTING_DSI_START_EN      (0x1uL << CYFLD_CSD_DSI_START_EN__OFFSET)
#define capsense_ADC_AdcFSMSETTING_AZ0SKIP           (0x1uL << CYFLD_CSD_AZ0_SKIP__OFFSET)
#define capsense_ADC_AdcFSMSETTING_AZ1SKIP           (0x1uL << CYFLD_CSD_AZ1_SKIP__OFFSET)


#define capsense_ADC_AdcFSMSETTING_NOAZSKIP          (0uL)
#define capsense_ADC_AdcFSMSETTING_AZSKIP_DEFAULT    (capsense_ADC_AdcFSMSETTING_AZ0SKIP \
                                                                            | ((0u != capsense_ADC_ADC_AZ_EN) \
                                                                            ? 0u \
                                                                            : capsense_ADC_AdcFSMSETTING_AZ1SKIP))
#define capsense_ADC_AdcFSMSETTING_DSIIGNORE         (0x00000000uL)
#define capsense_ADC_AdcFSMSETTING_NOABORT           (0x00000000uL)
#define capsense_ADC_AdcFSMSETTING_SEQMODE           (0x00000000uL)
#define capsense_ADC_AdcFSMSETTING_START             (0x00000001uL)

/* IDACB definitions
*  The idac configuration for ADC use is mostly static, with only the VAL field varying.
*   Dynamic Polarity = 1 << 7
*   Polarity (normal) = 0 << 8
*   Balance, Leg1, Leg2 modes = don't care.
*   DSI Control Enable (no mix) = 0 << 21
*   Range (low) = 0 << 22
*   Leg1, Leg2 enable = 0
*   Leg3 enable = 1 << 26
*/
#define capsense_ADC_AdcIDACB_CONFIG                 (0x04000080uL)
#define capsense_ADC_AdcCLK16_MASK                   (0x0000FFFFuL)
#define capsense_ADC_AdcCLK16VAL_SHIFT               (8uL)

/* Switch definitions */
#define capsense_ADC_AdcSW_HSP_DEFAULT               (0x10000000uL)
#define capsense_ADC_AdcSW_HSN_DEFAULT               (0x00100000uL)
#define capsense_ADC_AdcSW_HSP_GETINPOL              (0x00010000uL)
#define capsense_ADC_AdcSW_HSN_GETINPOL              (0x01000000uL)
#define capsense_ADC_AdcSW_SHIELD_DEFAULT            (0x00000000uL)
#define capsense_ADC_AdcSW_SHIELD_VDDA2CSDBUSB       (0x00000100uL)
#define capsense_ADC_AdcSW_BYP_DEFAULT               (0x00110000uL)
#define capsense_ADC_AdcSW_CMPP_DEFAULT              (0x00000000uL)
#define capsense_ADC_AdcSW_CMPN_DEFAULT              (0x00000000uL)
#define capsense_ADC_AdcSW_REFGEN_DEFAULT            (0x10000000uL)

#define capsense_ADC_AdcSW_FWMOD_DEFAULT             (0x01100000uL)
#define capsense_ADC_AdcSW_FWTANK_DEFAULT            (0x01100000uL)

/* The reference voltage macros */
#define capsense_ADC_AdcSW_CTANK_PINSHIFT            (9uL)
#define capsense_ADC_AdcSW_CMOD_PINSHIFT             (6uL)
#define capsense_ADC_AdcSW_CMOD_PORT_MASK            (0x400uL)

#define capsense_ADC_AdcLVTHRESH                     (2700uL)

/* The reference voltage is measured at nominal 2400 mV. Measured amount is stored in CYREG_SFLASH_CSDV2_CSD0_ADC_TRIM1 */
#define capsense_ADC_AdcVREFCALIB_BASE               (2400uL)

/* RefGen settings */
#define capsense_ADC_AdcREFGEN_GAIN_SHIFT            (CYFLD_CSD_GAIN__OFFSET)

/* At low voltage, REFGEN is enabled and bypassed. */
#define capsense_ADC_AdcSW_AMUBUF_LV                 (0x01000100uL)
#define capsense_ADC_AdcAMBUF_LV                     (0x00000002uL)
/* At normal voltage, REFGEN uses customizer-defined gain */
#define capsense_ADC_AdcREFGEN_NORM                  (0x00000041uL | (capsense_ADC_ADC_GAIN << \
                                                                            capsense_ADC_AdcREFGEN_GAIN_SHIFT))
#define capsense_ADC_AdcSW_AMUBUF_NORM               (0x00000000uL)

/* HSCOMP definitions */
#define capsense_ADC_AdcHSCMP_AZ_DEFAULT             (capsense_ADC_HSCMP_EN_MASK | \
                                                                            (capsense_ADC_ADC_AZ_EN << CYFLD_CSD_AZ_EN__OFFSET))

/* ADC_RES definitions */
#define capsense_ADC_AdcRES_MAX                      ((1uL << capsense_ADC_ADC_RESOLUTION) - 1uL)
#define capsense_ADC_AdcADC_RES_OVERFLOW_MASK        (0x40000000uL)
#define capsense_ADC_AdcADC_RES_ABORT_MASK           (0x80000000uL)
#define capsense_ADC_AdcADC_RES_HSCMPPOL_MASK        (0x00010000uL)
#define capsense_ADC_AdcADC_RES_VALUE_MASK           (0x0000FFFFuL)

#endif  /* capsense_ADC_ADC_EN */

#endif  /* CY_SENSE_capsense_ADC_ADC_H */


/* [] END OF FILE */
