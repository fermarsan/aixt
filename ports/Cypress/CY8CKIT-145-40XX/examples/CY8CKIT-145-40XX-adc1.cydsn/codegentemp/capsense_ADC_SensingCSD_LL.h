/***************************************************************************//**
* \file capsense_ADC_SensingCSD_LL.h
* \version 7.10
*
* \brief
*   This file provides the headers of APIs specific to CSD sensing implementation.
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

#if !defined(CY_SENSE_capsense_ADC_SENSINGCSD_LL_H)
#define CY_SENSE_capsense_ADC_SENSINGCSD_LL_H

#include <CyLib.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <cypins.h>
#include "capsense_ADC_Structure.h"
#include "capsense_ADC_Configuration.h"
#include "capsense_ADC_Sensing.h"

/****************************************************************************
* Register and mode mask definition
****************************************************************************/

#if (capsense_ADC_ENABLE == capsense_ADC_CSDV2)
    #define capsense_ADC_CSD_CSDCMP_INIT                                (capsense_ADC_CSDCMP_CSDCMP_DISABLED)

    /* SW_HS_P_SEL switches state for Coarse initialization of CMOD (sense path) */
    #if (capsense_ADC_ENABLE == capsense_ADC_CSD_EN)
        #if (capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CMOD_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_CMOD               (capsense_ADC_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #elif (capsense_ADC_CSD__CSHIELD_PAD == capsense_ADC_CMOD_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_CMOD               (capsense_ADC_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #else
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_CMOD               (capsense_ADC_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #endif /* (capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CMOD_CONNECTION) */
    #else
        #define capsense_ADC_CSD_HS_P_SEL_COARSE_CMOD                   (0x00000000uL)
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_EN) */

    #if ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) && \
        (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_TANK               (capsense_ADC_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (capsense_ADC_CSD__CSHIELD_PAD == capsense_ADC_CTANK_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_TANK               (capsense_ADC_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CTANK_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_TANK               (capsense_ADC_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define capsense_ADC_CSD_HS_P_SEL_COARSE_TANK               (capsense_ADC_SW_HS_P_SEL_SW_HMMA_STATIC_CLOSE)
        #endif /* (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION) */
    #else
        #define capsense_ADC_CSD_HS_P_SEL_COARSE_TANK                   (0x00000000uL)
    #endif /* ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) && \
               (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN)) */

    #define capsense_ADC_CSD_SW_HS_P_SEL_COARSE                         (capsense_ADC_HS_P_SEL_COARSE_CMOD | capsense_ADC_CSD_HS_P_SEL_COARSE_TANK)

    /* C_mod config */
    #if ((capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CMOD_CONNECTION) || (capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CTANK_CONNECTION))
        #define capsense_ADC_CSD_SW_FW_MOD_SEL_INIT             (capsense_ADC_SW_FW_MOD_SEL_SW_F1PM_STATIC_CLOSE |\
                                                                     capsense_ADC_SW_FW_MOD_SEL_SW_F1MA_STATIC_CLOSE |\
                                                                     capsense_ADC_SW_FW_MOD_SEL_SW_F1CA_STATIC_CLOSE)
        #define capsense_ADC_SW_DSI_SEL_CMODPAD                 (capsense_ADC_SW_DSI_CMOD)
    #else
        #define capsense_ADC_CSD_SW_FW_MOD_SEL_INIT             (0x00000000uL)
        #define capsense_ADC_SW_DSI_SEL_CMODPAD                 (0x00000000uL)
    #endif /* (capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CMOD_CONNECTION) */

    /* C_tank config */
    #if ((capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CMOD_CONNECTION) || (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION))
        #define capsense_ADC_CSD_SW_FW_TANK_SEL_INIT            (capsense_ADC_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE |\
                                                                     capsense_ADC_SW_FW_TANK_SEL_SW_F2MA_STATIC_CLOSE |\
                                                                     capsense_ADC_SW_FW_TANK_SEL_SW_F2CA_STATIC_CLOSE)
        #define capsense_ADC_SW_DSI_SEL_TANKPAD                 (capsense_ADC_SW_DSI_CTANK)
    #else
        #define capsense_ADC_CSD_SW_FW_TANK_SEL_INIT            (0x00000000uL)
        #define capsense_ADC_SW_DSI_SEL_TANKPAD                 (0x00000000uL)
    #endif /* (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION) */

    #define capsense_ADC_CSD_SW_SHIELD_SEL_INIT                 (capsense_ADC_SW_SHIELD_SEL_SW_HCAV_HSCMP)

    /* Defining default HW configuration according to settings in customizer. */
    #define capsense_ADC_DEFAULT_CSD_CONFIG                 (capsense_ADC_CONFIG_FILTER_DELAY_12MHZ |\
                                                                 capsense_ADC_CONFIG_SAMPLE_SYNC_MASK)
    #if (capsense_ADC_ENABLE == capsense_ADC_CSD_AUTO_ZERO_EN)
        /* Enable CSDCMP */
        #define capsense_ADC_CSD_CSDCMP_SCAN                (capsense_ADC_CSDCMP_CSDCMP_EN_MASK |\
                                                                 capsense_ADC_CSDCMP_AZ_EN_MASK)
    #else
        /* Enable CSDCMP */
        #define capsense_ADC_CSD_CSDCMP_SCAN                (capsense_ADC_CSDCMP_CSDCMP_EN_MASK)
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_AUTO_ZERO_EN) */

    #if ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) && \
        (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (capsense_ADC_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (capsense_ADC_CSD__CSHIELD_PAD == capsense_ADC_CTANK_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (capsense_ADC_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (capsense_ADC_CSD__CMOD_PAD == capsense_ADC_CTANK_CONNECTION)
            #define capsense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (capsense_ADC_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define capsense_ADC_CSD_HS_P_SEL_SCAN_TANK                 (capsense_ADC_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
        #endif /* (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION) */
        #define capsense_ADC_CSD_SW_HS_P_SEL_SCAN                       (capsense_ADC_HS_P_SEL_SCAN_TANK)
    #elif(capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN)
        #define capsense_ADC_CSD_SW_HS_P_SEL_SCAN                       (capsense_ADC_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
    #else
        #define capsense_ADC_CSD_SW_HS_P_SEL_SCAN                       (capsense_ADC_STATIC_OPEN)
    #endif /* ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) && \
               (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN)) */

    /* SW_FW_MOD_SEL switches state for Coarse initialization of CMOD (sense path) */
    #define capsense_ADC_CSD_SW_FW_MOD_SEL_SCAN                     (0x00000000uL)

    #if((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) && \
        (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) && \
        (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION))
        #define capsense_ADC_CSD_SW_FW_TANK_SEL_SCAN                (capsense_ADC_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE | \
                                                                         capsense_ADC_SW_FW_TANK_SEL_SW_F2CB_STATIC_CLOSE)
    #else
        #define capsense_ADC_CSD_SW_FW_TANK_SEL_SCAN                (0x00000000uL)
    #endif /* ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) && \
               (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) && \
               (capsense_ADC_CSD__CSH_TANK_PAD == capsense_ADC_CTANK_CONNECTION)) */

    /* Shield switch default config */
    #if ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) && \
         (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN))
        #if (capsense_ADC_IDAC_SINKING == capsense_ADC_CSD_IDAC_CONFIG)
            #define capsense_ADC_CSD_SW_SHIELD_SEL_SCAN             (capsense_ADC_SW_SHIELD_SEL_SW_HCBG_HSCMP)
        #else
            #define capsense_ADC_CSD_SW_SHIELD_SEL_SCAN             (capsense_ADC_SW_SHIELD_SEL_SW_HCBV_HSCMP)
        #endif /* (capsense_ADC_IDAC_SINKING == capsense_ADC_CSD_IDAC_CONFIG) */
    #elif(capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN)
        #if (capsense_ADC_IDAC_SINKING == capsense_ADC_CSD_IDAC_CONFIG)
            #define capsense_ADC_CSD_SW_SHIELD_SEL_SCAN             (capsense_ADC_SW_SHIELD_SEL_SW_HCBV_PHI1 | \
                                                                         capsense_ADC_SW_SHIELD_SEL_SW_HCBG_PHI2_HSCMP)
        #else
            #define capsense_ADC_CSD_SW_SHIELD_SEL_SCAN             (capsense_ADC_SW_SHIELD_SEL_SW_HCBG_PHI1 | \
                                                                         capsense_ADC_SW_SHIELD_SEL_SW_HCBV_PHI2_HSCMP)
        #endif /* (capsense_ADC_IDAC_SINKING == capsense_ADC_CSD_IDAC_CONFIG) */
    #else
        #define capsense_ADC_CSD_SW_SHIELD_SEL_SCAN                 (0x00000000uL)
    #endif /* ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) && \
               (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN)) */

    #define capsense_ADC_CSD_SW_RES_INIT                            (capsense_ADC_CSD_INIT_SWITCH_RES << CYFLD_CSD_RES_HCAV__OFFSET)
    #define capsense_ADC_CSD_SW_RES_SCAN                            ((capsense_ADC_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBV__OFFSET) |\
                                                                         (capsense_ADC_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBG__OFFSET))

    #define capsense_ADC_CSD_SHIELD_GPIO_DM                         (capsense_ADC_GPIO_STRGDRV)
    #define capsense_ADC_CSD_SENSOR_HSIOM_SEL                       (capsense_ADC_HSIOM_SEL_CSD_SENSE)
    #define capsense_ADC_CSD_SHIELD_HSIOM_SEL                       (capsense_ADC_HSIOM_SEL_CSD_SHIELD)
    #define capsense_ADC_CSD_CMOD_HSIOM_SEL                         (capsense_ADC_HSIOM_SEL_AMUXA)

    #define capsense_ADC_DEFAULT_IDAC_MOD_BALL_MODE                 ((uint32)capsense_ADC_IDAC_MOD_BALL_MODE_FULL <<\
                                                                         CYFLD_CSD_BAL_MODE__OFFSET)
    #define capsense_ADC_DEFAULT_IDAC_COMP_BALL_MODE                ((uint32)capsense_ADC_IDAC_COMP_BALL_MODE_FULL <<\
                                                                         CYFLD_CSD_BAL_MODE__OFFSET)

    #define capsense_ADC_DEFAULT_SENSE_DUTY_SEL                     (capsense_ADC_SENSE_DUTY_OVERLAP_PHI1_MASK |\
                                                                         capsense_ADC_SENSE_DUTY_OVERLAP_PHI2_MASK)

    #define capsense_ADC_CSD_CAL_MIDDLE_VALUE                       (0x40u)
    #define capsense_ADC_CSD_CAL_IDAC_MAX_VALUE                     (127u)

    #define capsense_ADC_DELAY_EXTRACYCLES_NUM                      (9u)

    /* Clock Source Mode */
    #if (capsense_ADC_CLK_SOURCE_DIRECT == capsense_ADC_CSD_SNS_CLK_SOURCE)
        #define capsense_ADC_DEFAULT_MODULATION_MODE                (capsense_ADC_CLK_SOURCE_DIRECT)
    #elif (capsense_ADC_CLK_SOURCE_PRSAUTO == capsense_ADC_CSD_SNS_CLK_SOURCE)
        #define capsense_ADC_DEFAULT_MODULATION_MODE                (capsense_ADC_CLK_SOURCE_SSC2)
    #elif ((capsense_ADC_CLK_SOURCE_PRS8) == capsense_ADC_CSD_SNS_CLK_SOURCE)
        #define capsense_ADC_DEFAULT_MODULATION_MODE                (capsense_ADC_CSD_SNS_CLK_SOURCE)
    #elif ((capsense_ADC_CLK_SOURCE_PRS12) == capsense_ADC_CSD_SNS_CLK_SOURCE)
        #define capsense_ADC_DEFAULT_MODULATION_MODE                (capsense_ADC_CSD_SNS_CLK_SOURCE)
    #else
        #define capsense_ADC_DEFAULT_MODULATION_MODE                (capsense_ADC_CSD_SNS_CLK_SOURCE)
    #endif /* (capsense_ADC_CLK_SOURCE_DIRECT != capsense_ADC_CSD_SNS_CLK_SOURCE) */

    /* IDACs Ranges */
    #if (capsense_ADC_IDAC_GAIN_LOW == capsense_ADC_CSD_IDAC_GAIN)
        #define capsense_ADC_DEFAULT_IDAC_MOD_RANGE                 ((uint32)capsense_ADC_IDAC_MOD_RANGE_IDAC_LO << CYFLD_CSD_RANGE__OFFSET)
        #define capsense_ADC_DEFAULT_IDAC_COMP_RANGE                ((uint32)capsense_ADC_IDAC_COMP_RANGE_IDAC_LO << CYFLD_CSD_RANGE__OFFSET)
    #elif (capsense_ADC_IDAC_GAIN_MEDIUM == capsense_ADC_CSD_IDAC_GAIN)
        #define capsense_ADC_DEFAULT_IDAC_MOD_RANGE                 ((uint32)capsense_ADC_IDAC_MOD_RANGE_IDAC_MED << CYFLD_CSD_RANGE__OFFSET)
        #define capsense_ADC_DEFAULT_IDAC_COMP_RANGE                ((uint32)capsense_ADC_IDAC_COMP_RANGE_IDAC_MED << CYFLD_CSD_RANGE__OFFSET)
    #else
        #define capsense_ADC_DEFAULT_IDAC_MOD_RANGE                 ((uint32)capsense_ADC_IDAC_MOD_RANGE_IDAC_HI << CYFLD_CSD_RANGE__OFFSET)
        #define capsense_ADC_DEFAULT_IDAC_COMP_RANGE                ((uint32)capsense_ADC_IDAC_COMP_RANGE_IDAC_HI << CYFLD_CSD_RANGE__OFFSET)
    #endif

    /* IDACs Polarities */
    #if (capsense_ADC_IDAC_SINKING == capsense_ADC_CSD_IDAC_CONFIG)
        #define capsense_ADC_DEFAULT_IDAC_MOD_POLARITY              ((uint32)capsense_ADC_IDAC_MOD_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
        #define capsense_ADC_DEFAULT_IDAC_COMP_POLARITY             ((uint32)capsense_ADC_IDAC_COMP_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
    #else
        #define capsense_ADC_DEFAULT_IDAC_MOD_POLARITY              ((uint32)capsense_ADC_IDAC_MOD_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
        #define capsense_ADC_DEFAULT_IDAC_COMP_POLARITY             ((uint32)capsense_ADC_IDAC_COMP_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
    #endif /* (capsense_ADC_IDAC_SINKING == capsense_ADC_CSD_IDAC_CONFIG) */

    #define capsense_ADC_SW_REFGEN_VREF_SRC                         (capsense_ADC_SW_REFGEN_SEL_SW_SGR_MASK)

    /* IDAC legs configuration */
    #if (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_COMP_EN)
            #define capsense_ADC_DEFAULT_SW_REFGEN_SEL              (capsense_ADC_SW_REFGEN_VREF_SRC | capsense_ADC_SW_REFGEN_SEL_SW_IAIB_MASK)
    #else
            #define capsense_ADC_DEFAULT_SW_REFGEN_SEL              (capsense_ADC_SW_REFGEN_VREF_SRC)
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_COMP_EN) */

    /* IDACs register configuration is based on the Component configuration */
    #define capsense_ADC_IDAC_MOD_DEFAULT_CFG                       (capsense_ADC_DEFAULT_IDAC_MOD_RANGE | \
                                                                         capsense_ADC_DEFAULT_IDAC_MOD_POLARITY | \
                                                                         capsense_ADC_DEFAULT_IDAC_MOD_BALL_MODE | \
                                                                        ((uint32)(capsense_ADC_IDAC_MOD_LEG1_MODE_CSD << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)(capsense_ADC_IDAC_MOD_LEG2_MODE_CSD << CYFLD_CSD_LEG2_MODE__OFFSET)) | \
                                                                         capsense_ADC_IDAC_MOD_LEG1_EN_MASK)

    #define capsense_ADC_IDAC_COMP_DEFAULT_CFG                      (capsense_ADC_DEFAULT_IDAC_COMP_RANGE | \
                                                                         capsense_ADC_DEFAULT_IDAC_COMP_POLARITY | \
                                                                         capsense_ADC_DEFAULT_IDAC_COMP_BALL_MODE | \
                                                                        ((uint32)(capsense_ADC_IDAC_COMP_LEG1_MODE_CSD_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)(capsense_ADC_IDAC_COMP_LEG2_MODE_CSD_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET)) | \
                                                                         capsense_ADC_IDAC_COMP_LEG1_EN_MASK)

    #define capsense_ADC_IDAC_MOD_CALIBRATION_CFG                   ((uint32)(capsense_ADC_DEFAULT_IDAC_MOD_RANGE | \
                                                                         capsense_ADC_DEFAULT_IDAC_MOD_POLARITY | \
                                                                         capsense_ADC_DEFAULT_IDAC_MOD_BALL_MODE | \
                                                                        ((uint32)(capsense_ADC_IDAC_MOD_LEG1_MODE_CSD << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                         capsense_ADC_IDAC_MOD_LEG1_EN_MASK | \
                                                                        ((uint32)((uint32)capsense_ADC_IDAC_MOD_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))))

    #define capsense_ADC_IDAC_COMP_CALIBRATION_CFG                  ((uint32)(capsense_ADC_DEFAULT_IDAC_COMP_RANGE | \
                                                                         capsense_ADC_DEFAULT_IDAC_COMP_POLARITY | \
                                                                         capsense_ADC_DEFAULT_IDAC_COMP_BALL_MODE | \
                                                                        ((uint32)((uint32)capsense_ADC_IDAC_COMP_LEG1_MODE_GP_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)((uint32)capsense_ADC_IDAC_COMP_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))))
#else
    #if (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_COMP_EN)
        #define capsense_ADC_CSD_CAL_IDAC_MAX_VALUE                 (127u)
        #define capsense_ADC_CSD_CAL_MIDDLE_VALUE                   (0x40u)
    #else
        #define capsense_ADC_CSD_CAL_IDAC_MAX_VALUE                 (255u)
        #define capsense_ADC_CSD_CAL_MIDDLE_VALUE                   (0x80u)
    #endif

    #define capsense_ADC_IDAC_MOD_CFG_MASK                  (capsense_ADC_IDAC_POLARITY1_MIR_MASK |\
                                                                capsense_ADC_IDAC_MOD_RANGE_MASK |\
                                                                capsense_ADC_IDAC_MOD_MODE_MASK |\
                                                                capsense_ADC_IDAC_MOD_MASK)

    #define capsense_ADC_IDAC_COMP_CFG_MASK                 (capsense_ADC_IDAC_POLARITY2_MIR_MASK |\
                                                                capsense_ADC_IDAC_COMP_RANGE_MASK |\
                                                                capsense_ADC_IDAC_COMP_MODE_MASK |\
                                                                capsense_ADC_IDAC_COMP_MASK)

        #define capsense_ADC_PRS_8_CONFIG                       capsense_ADC_CONFIG_PRS_SELECT_MASK
    #define capsense_ADC_PRS_12_CONFIG                      (capsense_ADC_CONFIG_PRS_12_8_MASK |\
                                                                capsense_ADC_CONFIG_PRS_SELECT_MASK)

    /* Third-generation HW block Initial PRS mode */
    #if (capsense_ADC_CLK_SOURCE_PRS8 == capsense_ADC_CSD_SNS_CLK_SOURCE)
        #define capsense_ADC_DEFAULT_MODULATION_MODE        capsense_ADC_CONFIG_PRS_SELECT_MASK

    #elif (capsense_ADC_CLK_SOURCE_PRS12 == capsense_ADC_CSD_SNS_CLK_SOURCE)
        #define capsense_ADC_DEFAULT_MODULATION_MODE        (capsense_ADC_CONFIG_PRS_12_8_MASK |\
                                                                capsense_ADC_CONFIG_PRS_SELECT_MASK)
    #else
        #define capsense_ADC_DEFAULT_MODULATION_MODE        (0u)
    #endif /* (capsense_ADC_CSD_SNS_CLK_SOURCE == capsense_ADC_PRS_8BITS) */

    /* Defining default CSD configuration according to settings in customizer. */
    #define capsense_ADC_DEFAULT_CSD_CONFIG                 (capsense_ADC_CONFIG_SENSE_COMP_BW_MASK |\
                                                                capsense_ADC_DEFAULT_IDAC_POLARITY |\
                                                                capsense_ADC_CONFIG_SENSE_INSEL_MASK |\
                                                                capsense_ADC_CONFIG_REFBUF_DRV_MASK)

    /* Third-generation HW block Defining mask intended for clearing bits related to pre-charging options. */
    #define capsense_ADC_PRECHARGE_CONFIG_MASK              (capsense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                capsense_ADC_CONFIG_COMP_MODE_MASK |\
                                                                capsense_ADC_CONFIG_COMP_PIN_MASK  |\
                                                                capsense_ADC_CONFIG_REFBUF_OUTSEL_MASK)

    #define capsense_ADC_CMOD_PRECHARGE_CONFIG              (capsense_ADC_DEFAULT_CSD_CONFIG |\
                                                                capsense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                capsense_ADC_CONFIG_COMP_PIN_MASK)

    #define capsense_ADC_CMOD_PRECHARGE_CONFIG_CSD_EN       (capsense_ADC_DEFAULT_CSD_CONFIG |\
                                                                capsense_ADC_CSD_ENABLE_MASK |\
                                                                capsense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                capsense_ADC_CONFIG_COMP_PIN_MASK)


    #if (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN)
        #if((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_TANK_EN) &&\
            (capsense_ADC_CSH_PRECHARGE_IO_BUF == capsense_ADC_CSD_CSH_PRECHARGE_SRC))
            #define  capsense_ADC_CTANK_PRECHARGE_CONFIG    (capsense_ADC_DEFAULT_CSD_CONFIG |\
                                                                 capsense_ADC_CONFIG_REFBUF_OUTSEL_MASK |\
                                                                 capsense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                 capsense_ADC_CONFIG_COMP_MODE_MASK |\
                                                                 capsense_ADC_CONFIG_PRS_CLEAR_MASK |\
                                                                 capsense_ADC_CONFIG_COMP_PIN_MASK)
        #else
            #define  capsense_ADC_CTANK_PRECHARGE_CONFIG    (capsense_ADC_DEFAULT_CSD_CONFIG |\
                                                                 capsense_ADC_CONFIG_REFBUF_EN_MASK |\
                                                                 capsense_ADC_CONFIG_PRS_CLEAR_MASK |\
                                                                 capsense_ADC_CONFIG_REFBUF_OUTSEL_MASK)
        #endif
    #else
        #define  capsense_ADC_CTANK_PRECHARGE_CONFIG    (capsense_ADC_DEFAULT_CSD_CONFIG |\
                                                             capsense_ADC_CONFIG_REFBUF_OUTSEL_MASK |\
                                                             capsense_ADC_CONFIG_PRS_CLEAR_MASK)
    #endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) */


    #define  capsense_ADC_CTANK_PRECHARGE_CONFIG_CSD_EN     (capsense_ADC_CTANK_PRECHARGE_CONFIG |\
                                                                 capsense_ADC_CONFIG_ENABLE_MASK |\
                                                                 capsense_ADC_CONFIG_SENSE_COMP_EN_MASK)

#endif /* (capsense_ADC_ENABLE == capsense_ADC_CSDV2) */

#define capsense_ADC_CSD_AVG_CYCLES_PER_LOOP                   (5u)
#define capsense_ADC_CSD_MEASURE_MAX_TIME_US                   (200000u)
#define capsense_ADC_CSD_PRECHARGE_MAX_TIME_US                 (50u)
#define capsense_ADC_CSD_ONE_CLOCK_MAX_TIME_US                 (50u)
#define capsense_ADC_WIDGET_MAX_SCAN_TIME_US                   (5u * 1000000u)

#define capsense_ADC_CSD_CALIBR_WATCHDOG_CYCLES_NUM            (((CYDEV_BCLK__SYSCLK__MHZ) * (capsense_ADC_CSD_MEASURE_MAX_TIME_US)) /\
                                                                    (capsense_ADC_CSD_AVG_CYCLES_PER_LOOP))
#define capsense_ADC_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM         (((CYDEV_BCLK__SYSCLK__MHZ) * (capsense_ADC_CSD_PRECHARGE_MAX_TIME_US)) /\
                                                                    (capsense_ADC_CSD_AVG_CYCLES_PER_LOOP))
#define capsense_ADC_ONE_CLOCK_WATCHDOG_CYCLES_NUM             (((CYDEV_BCLK__SYSCLK__MHZ) * (capsense_ADC_CSD_ONE_CLOCK_MAX_TIME_US)) /\
                                                                    (capsense_ADC_CSD_AVG_CYCLES_PER_LOOP))
#define capsense_ADC_WIDGET_MAX_SCAN_TIME                      (((CYDEV_BCLK__SYSCLK__MHZ) * (capsense_ADC_WIDGET_MAX_SCAN_TIME_US)) /\
                                                                    (capsense_ADC_CSD_AVG_CYCLES_PER_LOOP))

/***************************************
* Global software variables
***************************************/

extern uint32 capsense_ADC_configCsd;

#if (capsense_ADC_ENABLE == capsense_ADC_CSD_NOISE_METRIC_EN)
    extern uint8 capsense_ADC_badConversionsNum;
#endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_NOISE_METRIC_EN) */


/***************************************
* Function Prototypes
**************************************/

/**
* \cond SECTION_C_LOW_LEVEL
* \addtogroup group_c_low_level
* \{
*/

void capsense_ADC_CSDSetupWidget(uint32 widgetId);
void capsense_ADC_CSDSetupWidgetExt(uint32 widgetId, uint32 sensorId);
void capsense_ADC_CSDScan(void);
void capsense_ADC_CSDScanExt(void);
#if ((capsense_ADC_CSD_SS_DIS != capsense_ADC_CSD_AUTOTUNE) || \
     (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_AUTOCAL_EN))
    cystatus capsense_ADC_CSDCalibrateWidget(uint32 widgetId, uint32 target);
#endif /* ((capsense_ADC_CSD_SS_DIS != capsense_ADC_CSD_AUTOTUNE) || \
           (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_AUTOCAL_EN))  */
void capsense_ADC_CSDConnectSns(capsense_ADC_FLASH_IO_STRUCT const *snsAddrPtr);
void capsense_ADC_CSDDisconnectSns(capsense_ADC_FLASH_IO_STRUCT const *snsAddrPtr);

/** \}
* \endcond */

/*****************************************************
* Function Prototypes - internal Low Level functions
*****************************************************/

/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

void capsense_ADC_SsCSDInitialize(void);
void capsense_ADC_SsCSDStartSample(void);
void capsense_ADC_SsCSDSetUpIdacs(capsense_ADC_RAM_WD_BASE_STRUCT const *ptrWdgt);
void capsense_ADC_SsCSDConfigClock(void);
void capsense_ADC_SsCSDElectrodeCheck(void);
#if ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) && \
     (0u != capsense_ADC_CSD_TOTAL_SHIELD_COUNT))
    void capsense_ADC_SsCSDEnableShieldElectrodes(void);
    void capsense_ADC_SsCSDDisableShieldElectrodes(void);
    void capsense_ADC_SsCSDSetShieldElectrodesState(uint32 state);
#endif /* ((capsense_ADC_ENABLE == capsense_ADC_CSD_SHIELD_EN) && \
           (0u != capsense_ADC_CSD_TOTAL_SHIELD_COUNT)) */
#if (capsense_ADC_ENABLE == capsense_ADC_CSDV2)
    uint32 capsense_ADC_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc);
#endif /* (capsense_ADC_ENABLE == capsense_ADC_CSDV2) */
void capsense_ADC_SsCSDCalculateScanDuration(capsense_ADC_RAM_WD_BASE_STRUCT const *ptrWdgt);
void capsense_ADC_SsCSDConnectSensorExt(uint32 widgetId, uint32 sensorId);
void capsense_ADC_SsCSDDisconnectSnsExt(uint32 widgetId, uint32 sensorId);

#if ((capsense_ADC_CSD_SS_DIS != capsense_ADC_CSD_AUTOTUNE) || \
     (capsense_ADC_ENABLE == capsense_ADC_SELF_TEST_EN) || \
     (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_AUTOCAL_EN))
#endif /* ((capsense_ADC_CSD_SS_DIS != capsense_ADC_CSD_AUTOTUNE) || \
           (capsense_ADC_ENABLE == capsense_ADC_SELF_TEST_EN) || \
           (capsense_ADC_ENABLE == capsense_ADC_CSD_IDAC_AUTOCAL_EN)) */

/** \}
* \endcond */

/***************************************
* Global software variables
***************************************/
extern uint32 capsense_ADC_configCsd;

/* Interrupt handler */
extern CY_ISR_PROTO(capsense_ADC_CSDPostSingleScan);
extern CY_ISR_PROTO(capsense_ADC_CSDPostMultiScan);
#if (capsense_ADC_ENABLE == capsense_ADC_CSD_GANGED_SNS_EN)
extern CY_ISR_PROTO(capsense_ADC_CSDPostMultiScanGanged);
#endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_GANGED_SNS_EN) */
#if (capsense_ADC_ENABLE == capsense_ADC_CSD_NOISE_METRIC_EN)
    extern uint8 capsense_ADC_badConversionsNum;
#endif /* (capsense_ADC_ENABLE == capsense_ADC_CSD_NOISE_METRIC_EN) */

#endif /* End CY_SENSE_capsense_ADC_SENSINGCSD_LL_H */


/* [] END OF FILE */
