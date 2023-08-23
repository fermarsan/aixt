/***************************************************************************//**
* \file CapSense_SensingCSD_LL.h
* \version 7.10
*
* \brief
*   This file provides the headers of APIs specific to CSD sensing implementation.
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

#if !defined(CY_SENSE_CapSense_SENSINGCSD_LL_H)
#define CY_SENSE_CapSense_SENSINGCSD_LL_H

#include <CyLib.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <cypins.h>
#include "CapSense_Structure.h"
#include "CapSense_Configuration.h"
#include "CapSense_Sensing.h"

/****************************************************************************
* Register and mode mask definition
****************************************************************************/

#if (CapSense_ENABLE == CapSense_CSDV2)
    #define CapSense_CSD_CSDCMP_INIT                                (CapSense_CSDCMP_CSDCMP_DISABLED)

    /* SW_HS_P_SEL switches state for Coarse initialization of CMOD (sense path) */
    #if (CapSense_ENABLE == CapSense_CSD_EN)
        #if (CapSense_CSD__CMOD_PAD == CapSense_CMOD_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_COARSE_CMOD               (CapSense_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #elif (CapSense_CSD__CSHIELD_PAD == CapSense_CMOD_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_COARSE_CMOD               (CapSense_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #else
            #define CapSense_CSD_HS_P_SEL_COARSE_CMOD               (CapSense_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #endif /* (CapSense_CSD__CMOD_PAD == CapSense_CMOD_CONNECTION) */
    #else
        #define CapSense_CSD_HS_P_SEL_COARSE_CMOD                   (0x00000000uL)
    #endif /* (CapSense_ENABLE == CapSense_CSD_EN) */

    #if ((CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) && \
        (CapSense_ENABLE == CapSense_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_COARSE_TANK               (CapSense_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (CapSense_CSD__CSHIELD_PAD == CapSense_CTANK_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_COARSE_TANK               (CapSense_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (CapSense_CSD__CMOD_PAD == CapSense_CTANK_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_COARSE_TANK               (CapSense_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define CapSense_CSD_HS_P_SEL_COARSE_TANK               (CapSense_SW_HS_P_SEL_SW_HMMA_STATIC_CLOSE)
        #endif /* (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION) */
    #else
        #define CapSense_CSD_HS_P_SEL_COARSE_TANK                   (0x00000000uL)
    #endif /* ((CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) && \
               (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)) */

    #define CapSense_CSD_SW_HS_P_SEL_COARSE                         (CapSense_HS_P_SEL_COARSE_CMOD | CapSense_CSD_HS_P_SEL_COARSE_TANK)

    /* C_mod config */
    #if ((CapSense_CSD__CMOD_PAD == CapSense_CMOD_CONNECTION) || (CapSense_CSD__CMOD_PAD == CapSense_CTANK_CONNECTION))
        #define CapSense_CSD_SW_FW_MOD_SEL_INIT             (CapSense_SW_FW_MOD_SEL_SW_F1PM_STATIC_CLOSE |\
                                                                     CapSense_SW_FW_MOD_SEL_SW_F1MA_STATIC_CLOSE |\
                                                                     CapSense_SW_FW_MOD_SEL_SW_F1CA_STATIC_CLOSE)
        #define CapSense_SW_DSI_SEL_CMODPAD                 (CapSense_SW_DSI_CMOD)
    #else
        #define CapSense_CSD_SW_FW_MOD_SEL_INIT             (0x00000000uL)
        #define CapSense_SW_DSI_SEL_CMODPAD                 (0x00000000uL)
    #endif /* (CapSense_CSD__CMOD_PAD == CapSense_CMOD_CONNECTION) */

    /* C_tank config */
    #if ((CapSense_CSD__CSH_TANK_PAD == CapSense_CMOD_CONNECTION) || (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION))
        #define CapSense_CSD_SW_FW_TANK_SEL_INIT            (CapSense_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE |\
                                                                     CapSense_SW_FW_TANK_SEL_SW_F2MA_STATIC_CLOSE |\
                                                                     CapSense_SW_FW_TANK_SEL_SW_F2CA_STATIC_CLOSE)
        #define CapSense_SW_DSI_SEL_TANKPAD                 (CapSense_SW_DSI_CTANK)
    #else
        #define CapSense_CSD_SW_FW_TANK_SEL_INIT            (0x00000000uL)
        #define CapSense_SW_DSI_SEL_TANKPAD                 (0x00000000uL)
    #endif /* (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION) */

    #define CapSense_CSD_SW_SHIELD_SEL_INIT                 (CapSense_SW_SHIELD_SEL_SW_HCAV_HSCMP)

    /* Defining default HW configuration according to settings in customizer. */
    #define CapSense_DEFAULT_CSD_CONFIG                 (CapSense_CONFIG_FILTER_DELAY_12MHZ |\
                                                                 CapSense_CONFIG_SAMPLE_SYNC_MASK)
    #if (CapSense_ENABLE == CapSense_CSD_AUTO_ZERO_EN)
        /* Enable CSDCMP */
        #define CapSense_CSD_CSDCMP_SCAN                (CapSense_CSDCMP_CSDCMP_EN_MASK |\
                                                                 CapSense_CSDCMP_AZ_EN_MASK)
    #else
        /* Enable CSDCMP */
        #define CapSense_CSD_CSDCMP_SCAN                (CapSense_CSDCMP_CSDCMP_EN_MASK)
    #endif /* (CapSense_ENABLE == CapSense_CSD_AUTO_ZERO_EN) */

    #if ((CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) && \
        (CapSense_ENABLE == CapSense_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (CapSense_CSD__CSHIELD_PAD == CapSense_CTANK_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (CapSense_CSD__CMOD_PAD == CapSense_CTANK_CONNECTION)
            #define CapSense_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define CapSense_CSD_HS_P_SEL_SCAN_TANK                 (CapSense_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
        #endif /* (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION) */
        #define CapSense_CSD_SW_HS_P_SEL_SCAN                       (CapSense_HS_P_SEL_SCAN_TANK)
    #elif(CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
        #define CapSense_CSD_SW_HS_P_SEL_SCAN                       (CapSense_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
    #else
        #define CapSense_CSD_SW_HS_P_SEL_SCAN                       (CapSense_STATIC_OPEN)
    #endif /* ((CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) && \
               (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)) */

    /* SW_FW_MOD_SEL switches state for Coarse initialization of CMOD (sense path) */
    #define CapSense_CSD_SW_FW_MOD_SEL_SCAN                     (0x00000000uL)

    #if((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && \
        (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) && \
        (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION))
        #define CapSense_CSD_SW_FW_TANK_SEL_SCAN                (CapSense_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE | \
                                                                         CapSense_SW_FW_TANK_SEL_SW_F2CB_STATIC_CLOSE)
    #else
        #define CapSense_CSD_SW_FW_TANK_SEL_SCAN                (0x00000000uL)
    #endif /* ((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && \
               (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) && \
               (CapSense_CSD__CSH_TANK_PAD == CapSense_CTANK_CONNECTION)) */

    /* Shield switch default config */
    #if ((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && \
         (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN))
        #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
            #define CapSense_CSD_SW_SHIELD_SEL_SCAN             (CapSense_SW_SHIELD_SEL_SW_HCBG_HSCMP)
        #else
            #define CapSense_CSD_SW_SHIELD_SEL_SCAN             (CapSense_SW_SHIELD_SEL_SW_HCBV_HSCMP)
        #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */
    #elif(CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
        #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
            #define CapSense_CSD_SW_SHIELD_SEL_SCAN             (CapSense_SW_SHIELD_SEL_SW_HCBV_PHI1 | \
                                                                         CapSense_SW_SHIELD_SEL_SW_HCBG_PHI2_HSCMP)
        #else
            #define CapSense_CSD_SW_SHIELD_SEL_SCAN             (CapSense_SW_SHIELD_SEL_SW_HCBG_PHI1 | \
                                                                         CapSense_SW_SHIELD_SEL_SW_HCBV_PHI2_HSCMP)
        #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */
    #else
        #define CapSense_CSD_SW_SHIELD_SEL_SCAN                 (0x00000000uL)
    #endif /* ((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && \
               (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN)) */

    #define CapSense_CSD_SW_RES_INIT                            (CapSense_CSD_INIT_SWITCH_RES << CYFLD_CSD_RES_HCAV__OFFSET)
    #define CapSense_CSD_SW_RES_SCAN                            ((CapSense_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBV__OFFSET) |\
                                                                         (CapSense_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBG__OFFSET))

    #define CapSense_CSD_SHIELD_GPIO_DM                         (CapSense_GPIO_STRGDRV)
    #define CapSense_CSD_SENSOR_HSIOM_SEL                       (CapSense_HSIOM_SEL_CSD_SENSE)
    #define CapSense_CSD_SHIELD_HSIOM_SEL                       (CapSense_HSIOM_SEL_CSD_SHIELD)
    #define CapSense_CSD_CMOD_HSIOM_SEL                         (CapSense_HSIOM_SEL_AMUXA)

    #define CapSense_DEFAULT_IDAC_MOD_BALL_MODE                 ((uint32)CapSense_IDAC_MOD_BALL_MODE_FULL <<\
                                                                         CYFLD_CSD_BAL_MODE__OFFSET)
    #define CapSense_DEFAULT_IDAC_COMP_BALL_MODE                ((uint32)CapSense_IDAC_COMP_BALL_MODE_FULL <<\
                                                                         CYFLD_CSD_BAL_MODE__OFFSET)

    #define CapSense_DEFAULT_SENSE_DUTY_SEL                     (CapSense_SENSE_DUTY_OVERLAP_PHI1_MASK |\
                                                                         CapSense_SENSE_DUTY_OVERLAP_PHI2_MASK)

    #define CapSense_CSD_CAL_MIDDLE_VALUE                       (0x40u)
    #define CapSense_CSD_CAL_IDAC_MAX_VALUE                     (127u)

    #define CapSense_DELAY_EXTRACYCLES_NUM                      (9u)

    /* Clock Source Mode */
    #if (CapSense_CLK_SOURCE_DIRECT == CapSense_CSD_SNS_CLK_SOURCE)
        #define CapSense_DEFAULT_MODULATION_MODE                (CapSense_CLK_SOURCE_DIRECT)
    #elif (CapSense_CLK_SOURCE_PRSAUTO == CapSense_CSD_SNS_CLK_SOURCE)
        #define CapSense_DEFAULT_MODULATION_MODE                (CapSense_CLK_SOURCE_SSC2)
    #elif ((CapSense_CLK_SOURCE_PRS8) == CapSense_CSD_SNS_CLK_SOURCE)
        #define CapSense_DEFAULT_MODULATION_MODE                (CapSense_CSD_SNS_CLK_SOURCE)
    #elif ((CapSense_CLK_SOURCE_PRS12) == CapSense_CSD_SNS_CLK_SOURCE)
        #define CapSense_DEFAULT_MODULATION_MODE                (CapSense_CSD_SNS_CLK_SOURCE)
    #else
        #define CapSense_DEFAULT_MODULATION_MODE                (CapSense_CSD_SNS_CLK_SOURCE)
    #endif /* (CapSense_CLK_SOURCE_DIRECT != CapSense_CSD_SNS_CLK_SOURCE) */

    /* IDACs Ranges */
    #if (CapSense_IDAC_GAIN_LOW == CapSense_CSD_IDAC_GAIN)
        #define CapSense_DEFAULT_IDAC_MOD_RANGE                 ((uint32)CapSense_IDAC_MOD_RANGE_IDAC_LO << CYFLD_CSD_RANGE__OFFSET)
        #define CapSense_DEFAULT_IDAC_COMP_RANGE                ((uint32)CapSense_IDAC_COMP_RANGE_IDAC_LO << CYFLD_CSD_RANGE__OFFSET)
    #elif (CapSense_IDAC_GAIN_MEDIUM == CapSense_CSD_IDAC_GAIN)
        #define CapSense_DEFAULT_IDAC_MOD_RANGE                 ((uint32)CapSense_IDAC_MOD_RANGE_IDAC_MED << CYFLD_CSD_RANGE__OFFSET)
        #define CapSense_DEFAULT_IDAC_COMP_RANGE                ((uint32)CapSense_IDAC_COMP_RANGE_IDAC_MED << CYFLD_CSD_RANGE__OFFSET)
    #else
        #define CapSense_DEFAULT_IDAC_MOD_RANGE                 ((uint32)CapSense_IDAC_MOD_RANGE_IDAC_HI << CYFLD_CSD_RANGE__OFFSET)
        #define CapSense_DEFAULT_IDAC_COMP_RANGE                ((uint32)CapSense_IDAC_COMP_RANGE_IDAC_HI << CYFLD_CSD_RANGE__OFFSET)
    #endif

    /* IDACs Polarities */
    #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
        #define CapSense_DEFAULT_IDAC_MOD_POLARITY              ((uint32)CapSense_IDAC_MOD_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
        #define CapSense_DEFAULT_IDAC_COMP_POLARITY             ((uint32)CapSense_IDAC_COMP_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
    #else
        #define CapSense_DEFAULT_IDAC_MOD_POLARITY              ((uint32)CapSense_IDAC_MOD_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
        #define CapSense_DEFAULT_IDAC_COMP_POLARITY             ((uint32)CapSense_IDAC_COMP_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
    #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */

    #define CapSense_SW_REFGEN_VREF_SRC                         (CapSense_SW_REFGEN_SEL_SW_SGR_MASK)

    /* IDAC legs configuration */
    #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            #define CapSense_DEFAULT_SW_REFGEN_SEL              (CapSense_SW_REFGEN_VREF_SRC | CapSense_SW_REFGEN_SEL_SW_IAIB_MASK)
    #else
            #define CapSense_DEFAULT_SW_REFGEN_SEL              (CapSense_SW_REFGEN_VREF_SRC)
    #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

    /* IDACs register configuration is based on the Component configuration */
    #define CapSense_IDAC_MOD_DEFAULT_CFG                       (CapSense_DEFAULT_IDAC_MOD_RANGE | \
                                                                         CapSense_DEFAULT_IDAC_MOD_POLARITY | \
                                                                         CapSense_DEFAULT_IDAC_MOD_BALL_MODE | \
                                                                        ((uint32)(CapSense_IDAC_MOD_LEG1_MODE_CSD << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)(CapSense_IDAC_MOD_LEG2_MODE_CSD << CYFLD_CSD_LEG2_MODE__OFFSET)) | \
                                                                         CapSense_IDAC_MOD_LEG1_EN_MASK)

    #define CapSense_IDAC_COMP_DEFAULT_CFG                      (CapSense_DEFAULT_IDAC_COMP_RANGE | \
                                                                         CapSense_DEFAULT_IDAC_COMP_POLARITY | \
                                                                         CapSense_DEFAULT_IDAC_COMP_BALL_MODE | \
                                                                        ((uint32)(CapSense_IDAC_COMP_LEG1_MODE_CSD_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)(CapSense_IDAC_COMP_LEG2_MODE_CSD_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET)) | \
                                                                         CapSense_IDAC_COMP_LEG1_EN_MASK)

    #define CapSense_IDAC_MOD_CALIBRATION_CFG                   ((uint32)(CapSense_DEFAULT_IDAC_MOD_RANGE | \
                                                                         CapSense_DEFAULT_IDAC_MOD_POLARITY | \
                                                                         CapSense_DEFAULT_IDAC_MOD_BALL_MODE | \
                                                                        ((uint32)(CapSense_IDAC_MOD_LEG1_MODE_CSD << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                         CapSense_IDAC_MOD_LEG1_EN_MASK | \
                                                                        ((uint32)((uint32)CapSense_IDAC_MOD_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))))

    #define CapSense_IDAC_COMP_CALIBRATION_CFG                  ((uint32)(CapSense_DEFAULT_IDAC_COMP_RANGE | \
                                                                         CapSense_DEFAULT_IDAC_COMP_POLARITY | \
                                                                         CapSense_DEFAULT_IDAC_COMP_BALL_MODE | \
                                                                        ((uint32)((uint32)CapSense_IDAC_COMP_LEG1_MODE_GP_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)) | \
                                                                        ((uint32)((uint32)CapSense_IDAC_COMP_LEG2_MODE_GP_STATIC << CYFLD_CSD_LEG2_MODE__OFFSET))))
#else
    #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
        #define CapSense_CSD_CAL_IDAC_MAX_VALUE                 (127u)
        #define CapSense_CSD_CAL_MIDDLE_VALUE                   (0x40u)
    #else
        #define CapSense_CSD_CAL_IDAC_MAX_VALUE                 (255u)
        #define CapSense_CSD_CAL_MIDDLE_VALUE                   (0x80u)
    #endif

    #define CapSense_IDAC_MOD_CFG_MASK                  (CapSense_IDAC_POLARITY1_MIR_MASK |\
                                                                CapSense_IDAC_MOD_RANGE_MASK |\
                                                                CapSense_IDAC_MOD_MODE_MASK |\
                                                                CapSense_IDAC_MOD_MASK)

    #define CapSense_IDAC_COMP_CFG_MASK                 (CapSense_IDAC_POLARITY2_MIR_MASK |\
                                                                CapSense_IDAC_COMP_RANGE_MASK |\
                                                                CapSense_IDAC_COMP_MODE_MASK |\
                                                                CapSense_IDAC_COMP_MASK)

        #define CapSense_PRS_8_CONFIG                       CapSense_CONFIG_PRS_SELECT_MASK
    #define CapSense_PRS_12_CONFIG                      (CapSense_CONFIG_PRS_12_8_MASK |\
                                                                CapSense_CONFIG_PRS_SELECT_MASK)

    /* Third-generation HW block Initial PRS mode */
    #if (CapSense_CLK_SOURCE_PRS8 == CapSense_CSD_SNS_CLK_SOURCE)
        #define CapSense_DEFAULT_MODULATION_MODE        CapSense_CONFIG_PRS_SELECT_MASK

    #elif (CapSense_CLK_SOURCE_PRS12 == CapSense_CSD_SNS_CLK_SOURCE)
        #define CapSense_DEFAULT_MODULATION_MODE        (CapSense_CONFIG_PRS_12_8_MASK |\
                                                                CapSense_CONFIG_PRS_SELECT_MASK)
    #else
        #define CapSense_DEFAULT_MODULATION_MODE        (0u)
    #endif /* (CapSense_CSD_SNS_CLK_SOURCE == CapSense_PRS_8BITS) */

    /* Defining default CSD configuration according to settings in customizer. */
    #define CapSense_DEFAULT_CSD_CONFIG                 (CapSense_CONFIG_SENSE_COMP_BW_MASK |\
                                                                CapSense_DEFAULT_IDAC_POLARITY |\
                                                                CapSense_CONFIG_SENSE_INSEL_MASK |\
                                                                CapSense_CONFIG_REFBUF_DRV_MASK)

    /* Third-generation HW block Defining mask intended for clearing bits related to pre-charging options. */
    #define CapSense_PRECHARGE_CONFIG_MASK              (CapSense_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_CONFIG_COMP_MODE_MASK |\
                                                                CapSense_CONFIG_COMP_PIN_MASK  |\
                                                                CapSense_CONFIG_REFBUF_OUTSEL_MASK)

    #define CapSense_CMOD_PRECHARGE_CONFIG              (CapSense_DEFAULT_CSD_CONFIG |\
                                                                CapSense_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_CONFIG_COMP_PIN_MASK)

    #define CapSense_CMOD_PRECHARGE_CONFIG_CSD_EN       (CapSense_DEFAULT_CSD_CONFIG |\
                                                                CapSense_CSD_ENABLE_MASK |\
                                                                CapSense_CONFIG_REFBUF_EN_MASK |\
                                                                CapSense_CONFIG_COMP_PIN_MASK)


    #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
        #if((CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) &&\
            (CapSense_CSH_PRECHARGE_IO_BUF == CapSense_CSD_CSH_PRECHARGE_SRC))
            #define  CapSense_CTANK_PRECHARGE_CONFIG    (CapSense_DEFAULT_CSD_CONFIG |\
                                                                 CapSense_CONFIG_REFBUF_OUTSEL_MASK |\
                                                                 CapSense_CONFIG_REFBUF_EN_MASK |\
                                                                 CapSense_CONFIG_COMP_MODE_MASK |\
                                                                 CapSense_CONFIG_PRS_CLEAR_MASK |\
                                                                 CapSense_CONFIG_COMP_PIN_MASK)
        #else
            #define  CapSense_CTANK_PRECHARGE_CONFIG    (CapSense_DEFAULT_CSD_CONFIG |\
                                                                 CapSense_CONFIG_REFBUF_EN_MASK |\
                                                                 CapSense_CONFIG_PRS_CLEAR_MASK |\
                                                                 CapSense_CONFIG_REFBUF_OUTSEL_MASK)
        #endif
    #else
        #define  CapSense_CTANK_PRECHARGE_CONFIG    (CapSense_DEFAULT_CSD_CONFIG |\
                                                             CapSense_CONFIG_REFBUF_OUTSEL_MASK |\
                                                             CapSense_CONFIG_PRS_CLEAR_MASK)
    #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */


    #define  CapSense_CTANK_PRECHARGE_CONFIG_CSD_EN     (CapSense_CTANK_PRECHARGE_CONFIG |\
                                                                 CapSense_CONFIG_ENABLE_MASK |\
                                                                 CapSense_CONFIG_SENSE_COMP_EN_MASK)

#endif /* (CapSense_ENABLE == CapSense_CSDV2) */

#define CapSense_CSD_AVG_CYCLES_PER_LOOP                   (5u)
#define CapSense_CSD_MEASURE_MAX_TIME_US                   (200000u)
#define CapSense_CSD_PRECHARGE_MAX_TIME_US                 (50u)
#define CapSense_CSD_ONE_CLOCK_MAX_TIME_US                 (50u)
#define CapSense_WIDGET_MAX_SCAN_TIME_US                   (5u * 1000000u)

#define CapSense_CSD_CALIBR_WATCHDOG_CYCLES_NUM            (((CYDEV_BCLK__SYSCLK__MHZ) * (CapSense_CSD_MEASURE_MAX_TIME_US)) /\
                                                                    (CapSense_CSD_AVG_CYCLES_PER_LOOP))
#define CapSense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM         (((CYDEV_BCLK__SYSCLK__MHZ) * (CapSense_CSD_PRECHARGE_MAX_TIME_US)) /\
                                                                    (CapSense_CSD_AVG_CYCLES_PER_LOOP))
#define CapSense_ONE_CLOCK_WATCHDOG_CYCLES_NUM             (((CYDEV_BCLK__SYSCLK__MHZ) * (CapSense_CSD_ONE_CLOCK_MAX_TIME_US)) /\
                                                                    (CapSense_CSD_AVG_CYCLES_PER_LOOP))
#define CapSense_WIDGET_MAX_SCAN_TIME                      (((CYDEV_BCLK__SYSCLK__MHZ) * (CapSense_WIDGET_MAX_SCAN_TIME_US)) /\
                                                                    (CapSense_CSD_AVG_CYCLES_PER_LOOP))

/***************************************
* Global software variables
***************************************/

extern uint32 CapSense_configCsd;

#if (CapSense_ENABLE == CapSense_CSD_NOISE_METRIC_EN)
    extern uint8 CapSense_badConversionsNum;
#endif /* (CapSense_ENABLE == CapSense_CSD_NOISE_METRIC_EN) */


/***************************************
* Function Prototypes
**************************************/

/**
* \cond SECTION_C_LOW_LEVEL
* \addtogroup group_c_low_level
* \{
*/

void CapSense_CSDSetupWidget(uint32 widgetId);
void CapSense_CSDSetupWidgetExt(uint32 widgetId, uint32 sensorId);
void CapSense_CSDScan(void);
void CapSense_CSDScanExt(void);
#if ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
     (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN))
    cystatus CapSense_CSDCalibrateWidget(uint32 widgetId, uint32 target);
#endif /* ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
           (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN))  */
void CapSense_CSDConnectSns(CapSense_FLASH_IO_STRUCT const *snsAddrPtr);
void CapSense_CSDDisconnectSns(CapSense_FLASH_IO_STRUCT const *snsAddrPtr);

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

void CapSense_SsCSDInitialize(void);
void CapSense_SsCSDStartSample(void);
void CapSense_SsCSDSetUpIdacs(CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt);
void CapSense_SsCSDConfigClock(void);
void CapSense_SsCSDElectrodeCheck(void);
#if ((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && \
     (0u != CapSense_CSD_TOTAL_SHIELD_COUNT))
    void CapSense_SsCSDEnableShieldElectrodes(void);
    void CapSense_SsCSDDisableShieldElectrodes(void);
    void CapSense_SsCSDSetShieldElectrodesState(uint32 state);
#endif /* ((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && \
           (0u != CapSense_CSD_TOTAL_SHIELD_COUNT)) */
#if (CapSense_ENABLE == CapSense_CSDV2)
    uint32 CapSense_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc);
#endif /* (CapSense_ENABLE == CapSense_CSDV2) */
void CapSense_SsCSDCalculateScanDuration(CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt);
void CapSense_SsCSDConnectSensorExt(uint32 widgetId, uint32 sensorId);
void CapSense_SsCSDDisconnectSnsExt(uint32 widgetId, uint32 sensorId);

#if ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
     (CapSense_ENABLE == CapSense_SELF_TEST_EN) || \
     (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN))
#endif /* ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
           (CapSense_ENABLE == CapSense_SELF_TEST_EN) || \
           (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN)) */

/** \}
* \endcond */

/***************************************
* Global software variables
***************************************/
extern uint32 CapSense_configCsd;

/* Interrupt handler */
extern CY_ISR_PROTO(CapSense_CSDPostSingleScan);
extern CY_ISR_PROTO(CapSense_CSDPostMultiScan);
#if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
extern CY_ISR_PROTO(CapSense_CSDPostMultiScanGanged);
#endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */
#if (CapSense_ENABLE == CapSense_CSD_NOISE_METRIC_EN)
    extern uint8 CapSense_badConversionsNum;
#endif /* (CapSense_ENABLE == CapSense_CSD_NOISE_METRIC_EN) */

#endif /* End CY_SENSE_CapSense_SENSINGCSD_LL_H */


/* [] END OF FILE */
