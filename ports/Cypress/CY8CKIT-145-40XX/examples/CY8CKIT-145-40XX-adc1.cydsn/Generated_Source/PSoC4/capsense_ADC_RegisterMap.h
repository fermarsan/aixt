/***************************************************************************//**
* \file capsense_ADC_RegisterMap.h
* \version 7.10
*
* \brief
*   This file provides the definitions for the Component data structure register.
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

#if !defined(CY_SENSE_capsense_ADC_REGISTER_MAP_H)
#define CY_SENSE_capsense_ADC_REGISTER_MAP_H

#include <cytypes.h>
#include "capsense_ADC_Configuration.h"
#include "capsense_ADC_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define capsense_ADC_CONFIG_ID_VALUE                        (capsense_ADC_dsRam.configId)
#define capsense_ADC_CONFIG_ID_OFFSET                       (0u)
#define capsense_ADC_CONFIG_ID_SIZE                         (2u)
#define capsense_ADC_CONFIG_ID_PARAM_ID                     (0x87000000u)

#define capsense_ADC_DEVICE_ID_VALUE                        (capsense_ADC_dsRam.deviceId)
#define capsense_ADC_DEVICE_ID_OFFSET                       (2u)
#define capsense_ADC_DEVICE_ID_SIZE                         (2u)
#define capsense_ADC_DEVICE_ID_PARAM_ID                     (0x8B000002u)

#define capsense_ADC_HW_CLOCK_VALUE                         (capsense_ADC_dsRam.hwClock)
#define capsense_ADC_HW_CLOCK_OFFSET                        (4u)
#define capsense_ADC_HW_CLOCK_SIZE                          (2u)
#define capsense_ADC_HW_CLOCK_PARAM_ID                      (0x86000004u)

#define capsense_ADC_TUNER_CMD_VALUE                        (capsense_ADC_dsRam.tunerCmd)
#define capsense_ADC_TUNER_CMD_OFFSET                       (6u)
#define capsense_ADC_TUNER_CMD_SIZE                         (2u)
#define capsense_ADC_TUNER_CMD_PARAM_ID                     (0xA1000006u)

#define capsense_ADC_SCAN_COUNTER_VALUE                     (capsense_ADC_dsRam.scanCounter)
#define capsense_ADC_SCAN_COUNTER_OFFSET                    (8u)
#define capsense_ADC_SCAN_COUNTER_SIZE                      (2u)
#define capsense_ADC_SCAN_COUNTER_PARAM_ID                  (0x85000008u)

#define capsense_ADC_STATUS_VALUE                           (capsense_ADC_dsRam.status)
#define capsense_ADC_STATUS_OFFSET                          (12u)
#define capsense_ADC_STATUS_SIZE                            (4u)
#define capsense_ADC_STATUS_PARAM_ID                        (0xCB00000Cu)

#define capsense_ADC_WDGT_ENABLE0_VALUE                     (capsense_ADC_dsRam.wdgtEnable[0u])
#define capsense_ADC_WDGT_ENABLE0_OFFSET                    (16u)
#define capsense_ADC_WDGT_ENABLE0_SIZE                      (4u)
#define capsense_ADC_WDGT_ENABLE0_PARAM_ID                  (0xE6000010u)

#define capsense_ADC_WDGT_STATUS0_VALUE                     (capsense_ADC_dsRam.wdgtStatus[0u])
#define capsense_ADC_WDGT_STATUS0_OFFSET                    (20u)
#define capsense_ADC_WDGT_STATUS0_SIZE                      (4u)
#define capsense_ADC_WDGT_STATUS0_PARAM_ID                  (0xCC000014u)

#define capsense_ADC_SNS_STATUS0_VALUE                      (capsense_ADC_dsRam.snsStatus[0u])
#define capsense_ADC_SNS_STATUS0_OFFSET                     (24u)
#define capsense_ADC_SNS_STATUS0_SIZE                       (1u)
#define capsense_ADC_SNS_STATUS0_PARAM_ID                   (0x48000018u)

#define capsense_ADC_SNS_STATUS1_VALUE                      (capsense_ADC_dsRam.snsStatus[1u])
#define capsense_ADC_SNS_STATUS1_OFFSET                     (25u)
#define capsense_ADC_SNS_STATUS1_SIZE                       (1u)
#define capsense_ADC_SNS_STATUS1_PARAM_ID                   (0x4E000019u)

#define capsense_ADC_SNS_STATUS2_VALUE                      (capsense_ADC_dsRam.snsStatus[2u])
#define capsense_ADC_SNS_STATUS2_OFFSET                     (26u)
#define capsense_ADC_SNS_STATUS2_SIZE                       (1u)
#define capsense_ADC_SNS_STATUS2_PARAM_ID                   (0x4400001Au)

#define capsense_ADC_SNS_STATUS3_VALUE                      (capsense_ADC_dsRam.snsStatus[3u])
#define capsense_ADC_SNS_STATUS3_OFFSET                     (27u)
#define capsense_ADC_SNS_STATUS3_SIZE                       (1u)
#define capsense_ADC_SNS_STATUS3_PARAM_ID                   (0x4200001Bu)

#define capsense_ADC_ADC_RESULT0_VALUE                      (capsense_ADC_dsRam.adcResult[0u])
#define capsense_ADC_ADC_RESULT0_OFFSET                     (28u)
#define capsense_ADC_ADC_RESULT0_SIZE                       (2u)
#define capsense_ADC_ADC_RESULT0_PARAM_ID                   (0x8100001Cu)

#define capsense_ADC_ADC_CODE0_VALUE                        (capsense_ADC_dsRam.adcCode[0u])
#define capsense_ADC_ADC_CODE0_OFFSET                       (30u)
#define capsense_ADC_ADC_CODE0_SIZE                         (2u)
#define capsense_ADC_ADC_CODE0_PARAM_ID                     (0x8D00001Eu)

#define capsense_ADC_ADC_STATUS_VALUE                       (capsense_ADC_dsRam.adcStatus)
#define capsense_ADC_ADC_STATUS_OFFSET                      (32u)
#define capsense_ADC_ADC_STATUS_SIZE                        (1u)
#define capsense_ADC_ADC_STATUS_PARAM_ID                    (0x45000020u)

#define capsense_ADC_ADC_IDAC_VALUE                         (capsense_ADC_dsRam.adcIdac)
#define capsense_ADC_ADC_IDAC_OFFSET                        (33u)
#define capsense_ADC_ADC_IDAC_SIZE                          (1u)
#define capsense_ADC_ADC_IDAC_PARAM_ID                      (0x43000021u)

#define capsense_ADC_ADC_ACTIVE_CH_VALUE                    (capsense_ADC_dsRam.adcActiveCh)
#define capsense_ADC_ADC_ACTIVE_CH_OFFSET                   (34u)
#define capsense_ADC_ADC_ACTIVE_CH_SIZE                     (1u)
#define capsense_ADC_ADC_ACTIVE_CH_PARAM_ID                 (0x49000022u)

#define capsense_ADC_CSD0_CONFIG_VALUE                      (capsense_ADC_dsRam.csd0Config)
#define capsense_ADC_CSD0_CONFIG_OFFSET                     (36u)
#define capsense_ADC_CSD0_CONFIG_SIZE                       (2u)
#define capsense_ADC_CSD0_CONFIG_PARAM_ID                   (0xAA800024u)

#define capsense_ADC_MOD_CSD_CLK_VALUE                      (capsense_ADC_dsRam.modCsdClk)
#define capsense_ADC_MOD_CSD_CLK_OFFSET                     (38u)
#define capsense_ADC_MOD_CSD_CLK_SIZE                       (1u)
#define capsense_ADC_MOD_CSD_CLK_PARAM_ID                   (0x6E800026u)

#define capsense_ADC_ADC_RESOLUTION_VALUE                   (capsense_ADC_dsRam.adcResolution)
#define capsense_ADC_ADC_RESOLUTION_OFFSET                  (39u)
#define capsense_ADC_ADC_RESOLUTION_SIZE                    (1u)
#define capsense_ADC_ADC_RESOLUTION_PARAM_ID                (0x43800027u)

#define capsense_ADC_ADC_AZTIME_VALUE                       (capsense_ADC_dsRam.adcAzTime)
#define capsense_ADC_ADC_AZTIME_OFFSET                      (40u)
#define capsense_ADC_ADC_AZTIME_SIZE                        (1u)
#define capsense_ADC_ADC_AZTIME_PARAM_ID                    (0x4A800028u)

#define capsense_ADC_BTN2_RESOLUTION_VALUE                  (capsense_ADC_dsRam.wdgtList.btn2.resolution)
#define capsense_ADC_BTN2_RESOLUTION_OFFSET                 (42u)
#define capsense_ADC_BTN2_RESOLUTION_SIZE                   (2u)
#define capsense_ADC_BTN2_RESOLUTION_PARAM_ID               (0x8E80002Au)

#define capsense_ADC_BTN2_FINGER_TH_VALUE                   (capsense_ADC_dsRam.wdgtList.btn2.fingerTh)
#define capsense_ADC_BTN2_FINGER_TH_OFFSET                  (44u)
#define capsense_ADC_BTN2_FINGER_TH_SIZE                    (2u)
#define capsense_ADC_BTN2_FINGER_TH_PARAM_ID                (0x8380002Cu)

#define capsense_ADC_BTN2_NOISE_TH_VALUE                    (capsense_ADC_dsRam.wdgtList.btn2.noiseTh)
#define capsense_ADC_BTN2_NOISE_TH_OFFSET                   (46u)
#define capsense_ADC_BTN2_NOISE_TH_SIZE                     (1u)
#define capsense_ADC_BTN2_NOISE_TH_PARAM_ID                 (0x4780002Eu)

#define capsense_ADC_BTN2_NNOISE_TH_VALUE                   (capsense_ADC_dsRam.wdgtList.btn2.nNoiseTh)
#define capsense_ADC_BTN2_NNOISE_TH_OFFSET                  (47u)
#define capsense_ADC_BTN2_NNOISE_TH_SIZE                    (1u)
#define capsense_ADC_BTN2_NNOISE_TH_PARAM_ID                (0x4180002Fu)

#define capsense_ADC_BTN2_HYSTERESIS_VALUE                  (capsense_ADC_dsRam.wdgtList.btn2.hysteresis)
#define capsense_ADC_BTN2_HYSTERESIS_OFFSET                 (48u)
#define capsense_ADC_BTN2_HYSTERESIS_SIZE                   (1u)
#define capsense_ADC_BTN2_HYSTERESIS_PARAM_ID               (0x4D800030u)

#define capsense_ADC_BTN2_ON_DEBOUNCE_VALUE                 (capsense_ADC_dsRam.wdgtList.btn2.onDebounce)
#define capsense_ADC_BTN2_ON_DEBOUNCE_OFFSET                (49u)
#define capsense_ADC_BTN2_ON_DEBOUNCE_SIZE                  (1u)
#define capsense_ADC_BTN2_ON_DEBOUNCE_PARAM_ID              (0x4B800031u)

#define capsense_ADC_BTN2_LOW_BSLN_RST_VALUE                (capsense_ADC_dsRam.wdgtList.btn2.lowBslnRst)
#define capsense_ADC_BTN2_LOW_BSLN_RST_OFFSET               (50u)
#define capsense_ADC_BTN2_LOW_BSLN_RST_SIZE                 (1u)
#define capsense_ADC_BTN2_LOW_BSLN_RST_PARAM_ID             (0x41800032u)

#define capsense_ADC_BTN2_IDAC_MOD0_VALUE                   (capsense_ADC_dsRam.wdgtList.btn2.idacMod[0u])
#define capsense_ADC_BTN2_IDAC_MOD0_OFFSET                  (51u)
#define capsense_ADC_BTN2_IDAC_MOD0_SIZE                    (1u)
#define capsense_ADC_BTN2_IDAC_MOD0_PARAM_ID                (0x4A000033u)

#define capsense_ADC_BTN2_IDAC_GAIN_INDEX_VALUE             (capsense_ADC_dsRam.wdgtList.btn2.idacGainIndex)
#define capsense_ADC_BTN2_IDAC_GAIN_INDEX_OFFSET            (52u)
#define capsense_ADC_BTN2_IDAC_GAIN_INDEX_SIZE              (1u)
#define capsense_ADC_BTN2_IDAC_GAIN_INDEX_PARAM_ID          (0x4C800034u)

#define capsense_ADC_BTN2_SNS_CLK_VALUE                     (capsense_ADC_dsRam.wdgtList.btn2.snsClk)
#define capsense_ADC_BTN2_SNS_CLK_OFFSET                    (54u)
#define capsense_ADC_BTN2_SNS_CLK_SIZE                      (2u)
#define capsense_ADC_BTN2_SNS_CLK_PARAM_ID                  (0x88800036u)

#define capsense_ADC_BTN2_SNS_CLK_SOURCE_VALUE              (capsense_ADC_dsRam.wdgtList.btn2.snsClkSource)
#define capsense_ADC_BTN2_SNS_CLK_SOURCE_OFFSET             (56u)
#define capsense_ADC_BTN2_SNS_CLK_SOURCE_SIZE               (1u)
#define capsense_ADC_BTN2_SNS_CLK_SOURCE_PARAM_ID           (0x4F800038u)

#define capsense_ADC_BTN2_FINGER_CAP_VALUE                  (capsense_ADC_dsRam.wdgtList.btn2.fingerCap)
#define capsense_ADC_BTN2_FINGER_CAP_OFFSET                 (58u)
#define capsense_ADC_BTN2_FINGER_CAP_SIZE                   (2u)
#define capsense_ADC_BTN2_FINGER_CAP_PARAM_ID               (0xAD00003Au)

#define capsense_ADC_BTN2_SIGPFC_VALUE                      (capsense_ADC_dsRam.wdgtList.btn2.sigPFC)
#define capsense_ADC_BTN2_SIGPFC_OFFSET                     (60u)
#define capsense_ADC_BTN2_SIGPFC_SIZE                       (2u)
#define capsense_ADC_BTN2_SIGPFC_PARAM_ID                   (0xA000003Cu)

#define capsense_ADC_BTN1_RESOLUTION_VALUE                  (capsense_ADC_dsRam.wdgtList.btn1.resolution)
#define capsense_ADC_BTN1_RESOLUTION_OFFSET                 (62u)
#define capsense_ADC_BTN1_RESOLUTION_SIZE                   (2u)
#define capsense_ADC_BTN1_RESOLUTION_PARAM_ID               (0x8981003Eu)

#define capsense_ADC_BTN1_FINGER_TH_VALUE                   (capsense_ADC_dsRam.wdgtList.btn1.fingerTh)
#define capsense_ADC_BTN1_FINGER_TH_OFFSET                  (64u)
#define capsense_ADC_BTN1_FINGER_TH_SIZE                    (2u)
#define capsense_ADC_BTN1_FINGER_TH_PARAM_ID                (0x84810040u)

#define capsense_ADC_BTN1_NOISE_TH_VALUE                    (capsense_ADC_dsRam.wdgtList.btn1.noiseTh)
#define capsense_ADC_BTN1_NOISE_TH_OFFSET                   (66u)
#define capsense_ADC_BTN1_NOISE_TH_SIZE                     (1u)
#define capsense_ADC_BTN1_NOISE_TH_PARAM_ID                 (0x40810042u)

#define capsense_ADC_BTN1_NNOISE_TH_VALUE                   (capsense_ADC_dsRam.wdgtList.btn1.nNoiseTh)
#define capsense_ADC_BTN1_NNOISE_TH_OFFSET                  (67u)
#define capsense_ADC_BTN1_NNOISE_TH_SIZE                    (1u)
#define capsense_ADC_BTN1_NNOISE_TH_PARAM_ID                (0x46810043u)

#define capsense_ADC_BTN1_HYSTERESIS_VALUE                  (capsense_ADC_dsRam.wdgtList.btn1.hysteresis)
#define capsense_ADC_BTN1_HYSTERESIS_OFFSET                 (68u)
#define capsense_ADC_BTN1_HYSTERESIS_SIZE                   (1u)
#define capsense_ADC_BTN1_HYSTERESIS_PARAM_ID               (0x4D810044u)

#define capsense_ADC_BTN1_ON_DEBOUNCE_VALUE                 (capsense_ADC_dsRam.wdgtList.btn1.onDebounce)
#define capsense_ADC_BTN1_ON_DEBOUNCE_OFFSET                (69u)
#define capsense_ADC_BTN1_ON_DEBOUNCE_SIZE                  (1u)
#define capsense_ADC_BTN1_ON_DEBOUNCE_PARAM_ID              (0x4B810045u)

#define capsense_ADC_BTN1_LOW_BSLN_RST_VALUE                (capsense_ADC_dsRam.wdgtList.btn1.lowBslnRst)
#define capsense_ADC_BTN1_LOW_BSLN_RST_OFFSET               (70u)
#define capsense_ADC_BTN1_LOW_BSLN_RST_SIZE                 (1u)
#define capsense_ADC_BTN1_LOW_BSLN_RST_PARAM_ID             (0x41810046u)

#define capsense_ADC_BTN1_IDAC_MOD0_VALUE                   (capsense_ADC_dsRam.wdgtList.btn1.idacMod[0u])
#define capsense_ADC_BTN1_IDAC_MOD0_OFFSET                  (71u)
#define capsense_ADC_BTN1_IDAC_MOD0_SIZE                    (1u)
#define capsense_ADC_BTN1_IDAC_MOD0_PARAM_ID                (0x4A010047u)

#define capsense_ADC_BTN1_IDAC_GAIN_INDEX_VALUE             (capsense_ADC_dsRam.wdgtList.btn1.idacGainIndex)
#define capsense_ADC_BTN1_IDAC_GAIN_INDEX_OFFSET            (72u)
#define capsense_ADC_BTN1_IDAC_GAIN_INDEX_SIZE              (1u)
#define capsense_ADC_BTN1_IDAC_GAIN_INDEX_PARAM_ID          (0x4E810048u)

#define capsense_ADC_BTN1_SNS_CLK_VALUE                     (capsense_ADC_dsRam.wdgtList.btn1.snsClk)
#define capsense_ADC_BTN1_SNS_CLK_OFFSET                    (74u)
#define capsense_ADC_BTN1_SNS_CLK_SIZE                      (2u)
#define capsense_ADC_BTN1_SNS_CLK_PARAM_ID                  (0x8A81004Au)

#define capsense_ADC_BTN1_SNS_CLK_SOURCE_VALUE              (capsense_ADC_dsRam.wdgtList.btn1.snsClkSource)
#define capsense_ADC_BTN1_SNS_CLK_SOURCE_OFFSET             (76u)
#define capsense_ADC_BTN1_SNS_CLK_SOURCE_SIZE               (1u)
#define capsense_ADC_BTN1_SNS_CLK_SOURCE_PARAM_ID           (0x4F81004Cu)

#define capsense_ADC_BTN1_FINGER_CAP_VALUE                  (capsense_ADC_dsRam.wdgtList.btn1.fingerCap)
#define capsense_ADC_BTN1_FINGER_CAP_OFFSET                 (78u)
#define capsense_ADC_BTN1_FINGER_CAP_SIZE                   (2u)
#define capsense_ADC_BTN1_FINGER_CAP_PARAM_ID               (0xAD01004Eu)

#define capsense_ADC_BTN1_SIGPFC_VALUE                      (capsense_ADC_dsRam.wdgtList.btn1.sigPFC)
#define capsense_ADC_BTN1_SIGPFC_OFFSET                     (80u)
#define capsense_ADC_BTN1_SIGPFC_SIZE                       (2u)
#define capsense_ADC_BTN1_SIGPFC_PARAM_ID                   (0xA7010050u)

#define capsense_ADC_BTN0_RESOLUTION_VALUE                  (capsense_ADC_dsRam.wdgtList.btn0.resolution)
#define capsense_ADC_BTN0_RESOLUTION_OFFSET                 (82u)
#define capsense_ADC_BTN0_RESOLUTION_SIZE                   (2u)
#define capsense_ADC_BTN0_RESOLUTION_PARAM_ID               (0x88820052u)

#define capsense_ADC_BTN0_FINGER_TH_VALUE                   (capsense_ADC_dsRam.wdgtList.btn0.fingerTh)
#define capsense_ADC_BTN0_FINGER_TH_OFFSET                  (84u)
#define capsense_ADC_BTN0_FINGER_TH_SIZE                    (2u)
#define capsense_ADC_BTN0_FINGER_TH_PARAM_ID                (0x85820054u)

#define capsense_ADC_BTN0_NOISE_TH_VALUE                    (capsense_ADC_dsRam.wdgtList.btn0.noiseTh)
#define capsense_ADC_BTN0_NOISE_TH_OFFSET                   (86u)
#define capsense_ADC_BTN0_NOISE_TH_SIZE                     (1u)
#define capsense_ADC_BTN0_NOISE_TH_PARAM_ID                 (0x41820056u)

#define capsense_ADC_BTN0_NNOISE_TH_VALUE                   (capsense_ADC_dsRam.wdgtList.btn0.nNoiseTh)
#define capsense_ADC_BTN0_NNOISE_TH_OFFSET                  (87u)
#define capsense_ADC_BTN0_NNOISE_TH_SIZE                    (1u)
#define capsense_ADC_BTN0_NNOISE_TH_PARAM_ID                (0x47820057u)

#define capsense_ADC_BTN0_HYSTERESIS_VALUE                  (capsense_ADC_dsRam.wdgtList.btn0.hysteresis)
#define capsense_ADC_BTN0_HYSTERESIS_OFFSET                 (88u)
#define capsense_ADC_BTN0_HYSTERESIS_SIZE                   (1u)
#define capsense_ADC_BTN0_HYSTERESIS_PARAM_ID               (0x4E820058u)

#define capsense_ADC_BTN0_ON_DEBOUNCE_VALUE                 (capsense_ADC_dsRam.wdgtList.btn0.onDebounce)
#define capsense_ADC_BTN0_ON_DEBOUNCE_OFFSET                (89u)
#define capsense_ADC_BTN0_ON_DEBOUNCE_SIZE                  (1u)
#define capsense_ADC_BTN0_ON_DEBOUNCE_PARAM_ID              (0x48820059u)

#define capsense_ADC_BTN0_LOW_BSLN_RST_VALUE                (capsense_ADC_dsRam.wdgtList.btn0.lowBslnRst)
#define capsense_ADC_BTN0_LOW_BSLN_RST_OFFSET               (90u)
#define capsense_ADC_BTN0_LOW_BSLN_RST_SIZE                 (1u)
#define capsense_ADC_BTN0_LOW_BSLN_RST_PARAM_ID             (0x4282005Au)

#define capsense_ADC_BTN0_IDAC_MOD0_VALUE                   (capsense_ADC_dsRam.wdgtList.btn0.idacMod[0u])
#define capsense_ADC_BTN0_IDAC_MOD0_OFFSET                  (91u)
#define capsense_ADC_BTN0_IDAC_MOD0_SIZE                    (1u)
#define capsense_ADC_BTN0_IDAC_MOD0_PARAM_ID                (0x4902005Bu)

#define capsense_ADC_BTN0_IDAC_GAIN_INDEX_VALUE             (capsense_ADC_dsRam.wdgtList.btn0.idacGainIndex)
#define capsense_ADC_BTN0_IDAC_GAIN_INDEX_OFFSET            (92u)
#define capsense_ADC_BTN0_IDAC_GAIN_INDEX_SIZE              (1u)
#define capsense_ADC_BTN0_IDAC_GAIN_INDEX_PARAM_ID          (0x4F82005Cu)

#define capsense_ADC_BTN0_SNS_CLK_VALUE                     (capsense_ADC_dsRam.wdgtList.btn0.snsClk)
#define capsense_ADC_BTN0_SNS_CLK_OFFSET                    (94u)
#define capsense_ADC_BTN0_SNS_CLK_SIZE                      (2u)
#define capsense_ADC_BTN0_SNS_CLK_PARAM_ID                  (0x8B82005Eu)

#define capsense_ADC_BTN0_SNS_CLK_SOURCE_VALUE              (capsense_ADC_dsRam.wdgtList.btn0.snsClkSource)
#define capsense_ADC_BTN0_SNS_CLK_SOURCE_OFFSET             (96u)
#define capsense_ADC_BTN0_SNS_CLK_SOURCE_SIZE               (1u)
#define capsense_ADC_BTN0_SNS_CLK_SOURCE_PARAM_ID           (0x43820060u)

#define capsense_ADC_BTN0_FINGER_CAP_VALUE                  (capsense_ADC_dsRam.wdgtList.btn0.fingerCap)
#define capsense_ADC_BTN0_FINGER_CAP_OFFSET                 (98u)
#define capsense_ADC_BTN0_FINGER_CAP_SIZE                   (2u)
#define capsense_ADC_BTN0_FINGER_CAP_PARAM_ID               (0xA1020062u)

#define capsense_ADC_BTN0_SIGPFC_VALUE                      (capsense_ADC_dsRam.wdgtList.btn0.sigPFC)
#define capsense_ADC_BTN0_SIGPFC_OFFSET                     (100u)
#define capsense_ADC_BTN0_SIGPFC_SIZE                       (2u)
#define capsense_ADC_BTN0_SIGPFC_PARAM_ID                   (0xAC020064u)

#define capsense_ADC_LINEARSLIDER0_RESOLUTION_VALUE         (capsense_ADC_dsRam.wdgtList.linearslider0.resolution)
#define capsense_ADC_LINEARSLIDER0_RESOLUTION_OFFSET        (102u)
#define capsense_ADC_LINEARSLIDER0_RESOLUTION_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_RESOLUTION_PARAM_ID      (0x85830066u)

#define capsense_ADC_LINEARSLIDER0_FINGER_TH_VALUE          (capsense_ADC_dsRam.wdgtList.linearslider0.fingerTh)
#define capsense_ADC_LINEARSLIDER0_FINGER_TH_OFFSET         (104u)
#define capsense_ADC_LINEARSLIDER0_FINGER_TH_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_FINGER_TH_PARAM_ID       (0x8A830068u)

#define capsense_ADC_LINEARSLIDER0_NOISE_TH_VALUE           (capsense_ADC_dsRam.wdgtList.linearslider0.noiseTh)
#define capsense_ADC_LINEARSLIDER0_NOISE_TH_OFFSET          (106u)
#define capsense_ADC_LINEARSLIDER0_NOISE_TH_SIZE            (1u)
#define capsense_ADC_LINEARSLIDER0_NOISE_TH_PARAM_ID        (0x4E83006Au)

#define capsense_ADC_LINEARSLIDER0_NNOISE_TH_VALUE          (capsense_ADC_dsRam.wdgtList.linearslider0.nNoiseTh)
#define capsense_ADC_LINEARSLIDER0_NNOISE_TH_OFFSET         (107u)
#define capsense_ADC_LINEARSLIDER0_NNOISE_TH_SIZE           (1u)
#define capsense_ADC_LINEARSLIDER0_NNOISE_TH_PARAM_ID       (0x4883006Bu)

#define capsense_ADC_LINEARSLIDER0_HYSTERESIS_VALUE         (capsense_ADC_dsRam.wdgtList.linearslider0.hysteresis)
#define capsense_ADC_LINEARSLIDER0_HYSTERESIS_OFFSET        (108u)
#define capsense_ADC_LINEARSLIDER0_HYSTERESIS_SIZE          (1u)
#define capsense_ADC_LINEARSLIDER0_HYSTERESIS_PARAM_ID      (0x4383006Cu)

#define capsense_ADC_LINEARSLIDER0_ON_DEBOUNCE_VALUE        (capsense_ADC_dsRam.wdgtList.linearslider0.onDebounce)
#define capsense_ADC_LINEARSLIDER0_ON_DEBOUNCE_OFFSET       (109u)
#define capsense_ADC_LINEARSLIDER0_ON_DEBOUNCE_SIZE         (1u)
#define capsense_ADC_LINEARSLIDER0_ON_DEBOUNCE_PARAM_ID     (0x4583006Du)

#define capsense_ADC_LINEARSLIDER0_LOW_BSLN_RST_VALUE       (capsense_ADC_dsRam.wdgtList.linearslider0.lowBslnRst)
#define capsense_ADC_LINEARSLIDER0_LOW_BSLN_RST_OFFSET      (110u)
#define capsense_ADC_LINEARSLIDER0_LOW_BSLN_RST_SIZE        (1u)
#define capsense_ADC_LINEARSLIDER0_LOW_BSLN_RST_PARAM_ID    (0x4F83006Eu)

#define capsense_ADC_LINEARSLIDER0_IDAC_MOD0_VALUE          (capsense_ADC_dsRam.wdgtList.linearslider0.idacMod[0u])
#define capsense_ADC_LINEARSLIDER0_IDAC_MOD0_OFFSET         (111u)
#define capsense_ADC_LINEARSLIDER0_IDAC_MOD0_SIZE           (1u)
#define capsense_ADC_LINEARSLIDER0_IDAC_MOD0_PARAM_ID       (0x4403006Fu)

#define capsense_ADC_LINEARSLIDER0_IDAC_GAIN_INDEX_VALUE    (capsense_ADC_dsRam.wdgtList.linearslider0.idacGainIndex)
#define capsense_ADC_LINEARSLIDER0_IDAC_GAIN_INDEX_OFFSET   (112u)
#define capsense_ADC_LINEARSLIDER0_IDAC_GAIN_INDEX_SIZE     (1u)
#define capsense_ADC_LINEARSLIDER0_IDAC_GAIN_INDEX_PARAM_ID (0x45830070u)

#define capsense_ADC_LINEARSLIDER0_SNS_CLK_VALUE            (capsense_ADC_dsRam.wdgtList.linearslider0.snsClk)
#define capsense_ADC_LINEARSLIDER0_SNS_CLK_OFFSET           (114u)
#define capsense_ADC_LINEARSLIDER0_SNS_CLK_SIZE             (2u)
#define capsense_ADC_LINEARSLIDER0_SNS_CLK_PARAM_ID         (0x81830072u)

#define capsense_ADC_LINEARSLIDER0_SNS_CLK_SOURCE_VALUE     (capsense_ADC_dsRam.wdgtList.linearslider0.snsClkSource)
#define capsense_ADC_LINEARSLIDER0_SNS_CLK_SOURCE_OFFSET    (116u)
#define capsense_ADC_LINEARSLIDER0_SNS_CLK_SOURCE_SIZE      (1u)
#define capsense_ADC_LINEARSLIDER0_SNS_CLK_SOURCE_PARAM_ID  (0x44830074u)

#define capsense_ADC_LINEARSLIDER0_FINGER_CAP_VALUE         (capsense_ADC_dsRam.wdgtList.linearslider0.fingerCap)
#define capsense_ADC_LINEARSLIDER0_FINGER_CAP_OFFSET        (118u)
#define capsense_ADC_LINEARSLIDER0_FINGER_CAP_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_FINGER_CAP_PARAM_ID      (0xA6030076u)

#define capsense_ADC_LINEARSLIDER0_SIGPFC_VALUE             (capsense_ADC_dsRam.wdgtList.linearslider0.sigPFC)
#define capsense_ADC_LINEARSLIDER0_SIGPFC_OFFSET            (120u)
#define capsense_ADC_LINEARSLIDER0_SIGPFC_SIZE              (2u)
#define capsense_ADC_LINEARSLIDER0_SIGPFC_PARAM_ID          (0xA9030078u)

#define capsense_ADC_LINEARSLIDER0_POSITION0_VALUE          (capsense_ADC_dsRam.wdgtList.linearslider0.position[0u])
#define capsense_ADC_LINEARSLIDER0_POSITION0_OFFSET         (122u)
#define capsense_ADC_LINEARSLIDER0_POSITION0_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_POSITION0_PARAM_ID       (0x8E03007Au)

#define capsense_ADC_BTN2_SNS0_RAW0_VALUE                   (capsense_ADC_dsRam.snsList.btn2[0u].raw[0u])
#define capsense_ADC_BTN2_SNS0_RAW0_OFFSET                  (124u)
#define capsense_ADC_BTN2_SNS0_RAW0_SIZE                    (2u)
#define capsense_ADC_BTN2_SNS0_RAW0_PARAM_ID                (0x8600007Cu)

#define capsense_ADC_BTN2_SNS0_BSLN0_VALUE                  (capsense_ADC_dsRam.snsList.btn2[0u].bsln[0u])
#define capsense_ADC_BTN2_SNS0_BSLN0_OFFSET                 (126u)
#define capsense_ADC_BTN2_SNS0_BSLN0_SIZE                   (2u)
#define capsense_ADC_BTN2_SNS0_BSLN0_PARAM_ID               (0x8A00007Eu)

#define capsense_ADC_BTN2_SNS0_BSLN_EXT0_VALUE              (capsense_ADC_dsRam.snsList.btn2[0u].bslnExt[0u])
#define capsense_ADC_BTN2_SNS0_BSLN_EXT0_OFFSET             (128u)
#define capsense_ADC_BTN2_SNS0_BSLN_EXT0_SIZE               (1u)
#define capsense_ADC_BTN2_SNS0_BSLN_EXT0_PARAM_ID           (0x4C000080u)

#define capsense_ADC_BTN2_SNS0_DIFF_VALUE                   (capsense_ADC_dsRam.snsList.btn2[0u].diff)
#define capsense_ADC_BTN2_SNS0_DIFF_OFFSET                  (130u)
#define capsense_ADC_BTN2_SNS0_DIFF_SIZE                    (2u)
#define capsense_ADC_BTN2_SNS0_DIFF_PARAM_ID                (0x88000082u)

#define capsense_ADC_BTN2_SNS0_NEG_BSLN_RST_CNT0_VALUE      (capsense_ADC_dsRam.snsList.btn2[0u].negBslnRstCnt[0u])
#define capsense_ADC_BTN2_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (132u)
#define capsense_ADC_BTN2_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define capsense_ADC_BTN2_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4D000084u)

#define capsense_ADC_BTN2_SNS0_IDAC_COMP0_VALUE             (capsense_ADC_dsRam.snsList.btn2[0u].idacComp[0u])
#define capsense_ADC_BTN2_SNS0_IDAC_COMP0_OFFSET            (133u)
#define capsense_ADC_BTN2_SNS0_IDAC_COMP0_SIZE              (1u)
#define capsense_ADC_BTN2_SNS0_IDAC_COMP0_PARAM_ID          (0x4B000085u)

#define capsense_ADC_BTN1_SNS0_RAW0_VALUE                   (capsense_ADC_dsRam.snsList.btn1[0u].raw[0u])
#define capsense_ADC_BTN1_SNS0_RAW0_OFFSET                  (134u)
#define capsense_ADC_BTN1_SNS0_RAW0_SIZE                    (2u)
#define capsense_ADC_BTN1_SNS0_RAW0_PARAM_ID                (0x89000086u)

#define capsense_ADC_BTN1_SNS0_BSLN0_VALUE                  (capsense_ADC_dsRam.snsList.btn1[0u].bsln[0u])
#define capsense_ADC_BTN1_SNS0_BSLN0_OFFSET                 (136u)
#define capsense_ADC_BTN1_SNS0_BSLN0_SIZE                   (2u)
#define capsense_ADC_BTN1_SNS0_BSLN0_PARAM_ID               (0x86000088u)

#define capsense_ADC_BTN1_SNS0_BSLN_EXT0_VALUE              (capsense_ADC_dsRam.snsList.btn1[0u].bslnExt[0u])
#define capsense_ADC_BTN1_SNS0_BSLN_EXT0_OFFSET             (138u)
#define capsense_ADC_BTN1_SNS0_BSLN_EXT0_SIZE               (1u)
#define capsense_ADC_BTN1_SNS0_BSLN_EXT0_PARAM_ID           (0x4200008Au)

#define capsense_ADC_BTN1_SNS0_DIFF_VALUE                   (capsense_ADC_dsRam.snsList.btn1[0u].diff)
#define capsense_ADC_BTN1_SNS0_DIFF_OFFSET                  (140u)
#define capsense_ADC_BTN1_SNS0_DIFF_SIZE                    (2u)
#define capsense_ADC_BTN1_SNS0_DIFF_PARAM_ID                (0x8700008Cu)

#define capsense_ADC_BTN1_SNS0_NEG_BSLN_RST_CNT0_VALUE      (capsense_ADC_dsRam.snsList.btn1[0u].negBslnRstCnt[0u])
#define capsense_ADC_BTN1_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (142u)
#define capsense_ADC_BTN1_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define capsense_ADC_BTN1_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4300008Eu)

#define capsense_ADC_BTN1_SNS0_IDAC_COMP0_VALUE             (capsense_ADC_dsRam.snsList.btn1[0u].idacComp[0u])
#define capsense_ADC_BTN1_SNS0_IDAC_COMP0_OFFSET            (143u)
#define capsense_ADC_BTN1_SNS0_IDAC_COMP0_SIZE              (1u)
#define capsense_ADC_BTN1_SNS0_IDAC_COMP0_PARAM_ID          (0x4500008Fu)

#define capsense_ADC_BTN0_SNS0_RAW0_VALUE                   (capsense_ADC_dsRam.snsList.btn0[0u].raw[0u])
#define capsense_ADC_BTN0_SNS0_RAW0_OFFSET                  (144u)
#define capsense_ADC_BTN0_SNS0_RAW0_SIZE                    (2u)
#define capsense_ADC_BTN0_SNS0_RAW0_PARAM_ID                (0x81000090u)

#define capsense_ADC_BTN0_SNS0_BSLN0_VALUE                  (capsense_ADC_dsRam.snsList.btn0[0u].bsln[0u])
#define capsense_ADC_BTN0_SNS0_BSLN0_OFFSET                 (146u)
#define capsense_ADC_BTN0_SNS0_BSLN0_SIZE                   (2u)
#define capsense_ADC_BTN0_SNS0_BSLN0_PARAM_ID               (0x8D000092u)

#define capsense_ADC_BTN0_SNS0_BSLN_EXT0_VALUE              (capsense_ADC_dsRam.snsList.btn0[0u].bslnExt[0u])
#define capsense_ADC_BTN0_SNS0_BSLN_EXT0_OFFSET             (148u)
#define capsense_ADC_BTN0_SNS0_BSLN_EXT0_SIZE               (1u)
#define capsense_ADC_BTN0_SNS0_BSLN_EXT0_PARAM_ID           (0x48000094u)

#define capsense_ADC_BTN0_SNS0_DIFF_VALUE                   (capsense_ADC_dsRam.snsList.btn0[0u].diff)
#define capsense_ADC_BTN0_SNS0_DIFF_OFFSET                  (150u)
#define capsense_ADC_BTN0_SNS0_DIFF_SIZE                    (2u)
#define capsense_ADC_BTN0_SNS0_DIFF_PARAM_ID                (0x8C000096u)

#define capsense_ADC_BTN0_SNS0_NEG_BSLN_RST_CNT0_VALUE      (capsense_ADC_dsRam.snsList.btn0[0u].negBslnRstCnt[0u])
#define capsense_ADC_BTN0_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (152u)
#define capsense_ADC_BTN0_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define capsense_ADC_BTN0_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4B000098u)

#define capsense_ADC_BTN0_SNS0_IDAC_COMP0_VALUE             (capsense_ADC_dsRam.snsList.btn0[0u].idacComp[0u])
#define capsense_ADC_BTN0_SNS0_IDAC_COMP0_OFFSET            (153u)
#define capsense_ADC_BTN0_SNS0_IDAC_COMP0_SIZE              (1u)
#define capsense_ADC_BTN0_SNS0_IDAC_COMP0_PARAM_ID          (0x4D000099u)

#define capsense_ADC_LINEARSLIDER0_SNS0_RAW0_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[0u].raw[0u])
#define capsense_ADC_LINEARSLIDER0_SNS0_RAW0_OFFSET         (154u)
#define capsense_ADC_LINEARSLIDER0_SNS0_RAW0_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS0_RAW0_PARAM_ID       (0x8F00009Au)

#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN0_VALUE         (capsense_ADC_dsRam.snsList.linearslider0[0u].bsln[0u])
#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN0_OFFSET        (156u)
#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN0_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN0_PARAM_ID      (0x8200009Cu)

#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN_EXT0_VALUE     (capsense_ADC_dsRam.snsList.linearslider0[0u].bslnExt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN_EXT0_OFFSET    (158u)
#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN_EXT0_SIZE      (1u)
#define capsense_ADC_LINEARSLIDER0_SNS0_BSLN_EXT0_PARAM_ID  (0x4600009Eu)

#define capsense_ADC_LINEARSLIDER0_SNS0_DIFF_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[0u].diff)
#define capsense_ADC_LINEARSLIDER0_SNS0_DIFF_OFFSET         (160u)
#define capsense_ADC_LINEARSLIDER0_SNS0_DIFF_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS0_DIFF_PARAM_ID       (0x8E0000A0u)

#define capsense_ADC_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_VALUE (capsense_ADC_dsRam.snsList.linearslider0[0u].negBslnRstCnt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_OFFSET (162u)
#define capsense_ADC_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_SIZE (1u)
#define capsense_ADC_LINEARSLIDER0_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID (0x4A0000A2u)

#define capsense_ADC_LINEARSLIDER0_SNS0_IDAC_COMP0_VALUE    (capsense_ADC_dsRam.snsList.linearslider0[0u].idacComp[0u])
#define capsense_ADC_LINEARSLIDER0_SNS0_IDAC_COMP0_OFFSET   (163u)
#define capsense_ADC_LINEARSLIDER0_SNS0_IDAC_COMP0_SIZE     (1u)
#define capsense_ADC_LINEARSLIDER0_SNS0_IDAC_COMP0_PARAM_ID (0x4C0000A3u)

#define capsense_ADC_LINEARSLIDER0_SNS1_RAW0_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[1u].raw[0u])
#define capsense_ADC_LINEARSLIDER0_SNS1_RAW0_OFFSET         (164u)
#define capsense_ADC_LINEARSLIDER0_SNS1_RAW0_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS1_RAW0_PARAM_ID       (0x8F0000A4u)

#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN0_VALUE         (capsense_ADC_dsRam.snsList.linearslider0[1u].bsln[0u])
#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN0_OFFSET        (166u)
#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN0_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN0_PARAM_ID      (0x830000A6u)

#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN_EXT0_VALUE     (capsense_ADC_dsRam.snsList.linearslider0[1u].bslnExt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN_EXT0_OFFSET    (168u)
#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN_EXT0_SIZE      (1u)
#define capsense_ADC_LINEARSLIDER0_SNS1_BSLN_EXT0_PARAM_ID  (0x440000A8u)

#define capsense_ADC_LINEARSLIDER0_SNS1_DIFF_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[1u].diff)
#define capsense_ADC_LINEARSLIDER0_SNS1_DIFF_OFFSET         (170u)
#define capsense_ADC_LINEARSLIDER0_SNS1_DIFF_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS1_DIFF_PARAM_ID       (0x800000AAu)

#define capsense_ADC_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_VALUE (capsense_ADC_dsRam.snsList.linearslider0[1u].negBslnRstCnt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_OFFSET (172u)
#define capsense_ADC_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_SIZE (1u)
#define capsense_ADC_LINEARSLIDER0_SNS1_NEG_BSLN_RST_CNT0_PARAM_ID (0x450000ACu)

#define capsense_ADC_LINEARSLIDER0_SNS1_IDAC_COMP0_VALUE    (capsense_ADC_dsRam.snsList.linearslider0[1u].idacComp[0u])
#define capsense_ADC_LINEARSLIDER0_SNS1_IDAC_COMP0_OFFSET   (173u)
#define capsense_ADC_LINEARSLIDER0_SNS1_IDAC_COMP0_SIZE     (1u)
#define capsense_ADC_LINEARSLIDER0_SNS1_IDAC_COMP0_PARAM_ID (0x430000ADu)

#define capsense_ADC_LINEARSLIDER0_SNS2_RAW0_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[2u].raw[0u])
#define capsense_ADC_LINEARSLIDER0_SNS2_RAW0_OFFSET         (174u)
#define capsense_ADC_LINEARSLIDER0_SNS2_RAW0_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS2_RAW0_PARAM_ID       (0x810000AEu)

#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN0_VALUE         (capsense_ADC_dsRam.snsList.linearslider0[2u].bsln[0u])
#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN0_OFFSET        (176u)
#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN0_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN0_PARAM_ID      (0x8B0000B0u)

#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN_EXT0_VALUE     (capsense_ADC_dsRam.snsList.linearslider0[2u].bslnExt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN_EXT0_OFFSET    (178u)
#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN_EXT0_SIZE      (1u)
#define capsense_ADC_LINEARSLIDER0_SNS2_BSLN_EXT0_PARAM_ID  (0x4F0000B2u)

#define capsense_ADC_LINEARSLIDER0_SNS2_DIFF_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[2u].diff)
#define capsense_ADC_LINEARSLIDER0_SNS2_DIFF_OFFSET         (180u)
#define capsense_ADC_LINEARSLIDER0_SNS2_DIFF_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS2_DIFF_PARAM_ID       (0x8A0000B4u)

#define capsense_ADC_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_VALUE (capsense_ADC_dsRam.snsList.linearslider0[2u].negBslnRstCnt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_OFFSET (182u)
#define capsense_ADC_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_SIZE (1u)
#define capsense_ADC_LINEARSLIDER0_SNS2_NEG_BSLN_RST_CNT0_PARAM_ID (0x4E0000B6u)

#define capsense_ADC_LINEARSLIDER0_SNS2_IDAC_COMP0_VALUE    (capsense_ADC_dsRam.snsList.linearslider0[2u].idacComp[0u])
#define capsense_ADC_LINEARSLIDER0_SNS2_IDAC_COMP0_OFFSET   (183u)
#define capsense_ADC_LINEARSLIDER0_SNS2_IDAC_COMP0_SIZE     (1u)
#define capsense_ADC_LINEARSLIDER0_SNS2_IDAC_COMP0_PARAM_ID (0x480000B7u)

#define capsense_ADC_LINEARSLIDER0_SNS3_RAW0_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[3u].raw[0u])
#define capsense_ADC_LINEARSLIDER0_SNS3_RAW0_OFFSET         (184u)
#define capsense_ADC_LINEARSLIDER0_SNS3_RAW0_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS3_RAW0_PARAM_ID       (0x890000B8u)

#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN0_VALUE         (capsense_ADC_dsRam.snsList.linearslider0[3u].bsln[0u])
#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN0_OFFSET        (186u)
#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN0_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN0_PARAM_ID      (0x850000BAu)

#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN_EXT0_VALUE     (capsense_ADC_dsRam.snsList.linearslider0[3u].bslnExt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN_EXT0_OFFSET    (188u)
#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN_EXT0_SIZE      (1u)
#define capsense_ADC_LINEARSLIDER0_SNS3_BSLN_EXT0_PARAM_ID  (0x400000BCu)

#define capsense_ADC_LINEARSLIDER0_SNS3_DIFF_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[3u].diff)
#define capsense_ADC_LINEARSLIDER0_SNS3_DIFF_OFFSET         (190u)
#define capsense_ADC_LINEARSLIDER0_SNS3_DIFF_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS3_DIFF_PARAM_ID       (0x840000BEu)

#define capsense_ADC_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_VALUE (capsense_ADC_dsRam.snsList.linearslider0[3u].negBslnRstCnt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_OFFSET (192u)
#define capsense_ADC_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_SIZE (1u)
#define capsense_ADC_LINEARSLIDER0_SNS3_NEG_BSLN_RST_CNT0_PARAM_ID (0x410000C0u)

#define capsense_ADC_LINEARSLIDER0_SNS3_IDAC_COMP0_VALUE    (capsense_ADC_dsRam.snsList.linearslider0[3u].idacComp[0u])
#define capsense_ADC_LINEARSLIDER0_SNS3_IDAC_COMP0_OFFSET   (193u)
#define capsense_ADC_LINEARSLIDER0_SNS3_IDAC_COMP0_SIZE     (1u)
#define capsense_ADC_LINEARSLIDER0_SNS3_IDAC_COMP0_PARAM_ID (0x470000C1u)

#define capsense_ADC_LINEARSLIDER0_SNS4_RAW0_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[4u].raw[0u])
#define capsense_ADC_LINEARSLIDER0_SNS4_RAW0_OFFSET         (194u)
#define capsense_ADC_LINEARSLIDER0_SNS4_RAW0_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS4_RAW0_PARAM_ID       (0x850000C2u)

#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN0_VALUE         (capsense_ADC_dsRam.snsList.linearslider0[4u].bsln[0u])
#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN0_OFFSET        (196u)
#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN0_SIZE          (2u)
#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN0_PARAM_ID      (0x880000C4u)

#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN_EXT0_VALUE     (capsense_ADC_dsRam.snsList.linearslider0[4u].bslnExt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN_EXT0_OFFSET    (198u)
#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN_EXT0_SIZE      (1u)
#define capsense_ADC_LINEARSLIDER0_SNS4_BSLN_EXT0_PARAM_ID  (0x4C0000C6u)

#define capsense_ADC_LINEARSLIDER0_SNS4_DIFF_VALUE          (capsense_ADC_dsRam.snsList.linearslider0[4u].diff)
#define capsense_ADC_LINEARSLIDER0_SNS4_DIFF_OFFSET         (200u)
#define capsense_ADC_LINEARSLIDER0_SNS4_DIFF_SIZE           (2u)
#define capsense_ADC_LINEARSLIDER0_SNS4_DIFF_PARAM_ID       (0x8B0000C8u)

#define capsense_ADC_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_VALUE (capsense_ADC_dsRam.snsList.linearslider0[4u].negBslnRstCnt[0u])
#define capsense_ADC_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_OFFSET (202u)
#define capsense_ADC_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_SIZE (1u)
#define capsense_ADC_LINEARSLIDER0_SNS4_NEG_BSLN_RST_CNT0_PARAM_ID (0x4F0000CAu)

#define capsense_ADC_LINEARSLIDER0_SNS4_IDAC_COMP0_VALUE    (capsense_ADC_dsRam.snsList.linearslider0[4u].idacComp[0u])
#define capsense_ADC_LINEARSLIDER0_SNS4_IDAC_COMP0_OFFSET   (203u)
#define capsense_ADC_LINEARSLIDER0_SNS4_IDAC_COMP0_SIZE     (1u)
#define capsense_ADC_LINEARSLIDER0_SNS4_IDAC_COMP0_PARAM_ID (0x490000CBu)

#define capsense_ADC_SNR_TEST_WIDGET_ID_VALUE               (capsense_ADC_dsRam.snrTestWidgetId)
#define capsense_ADC_SNR_TEST_WIDGET_ID_OFFSET              (204u)
#define capsense_ADC_SNR_TEST_WIDGET_ID_SIZE                (1u)
#define capsense_ADC_SNR_TEST_WIDGET_ID_PARAM_ID            (0x690000CCu)

#define capsense_ADC_SNR_TEST_SENSOR_ID_VALUE               (capsense_ADC_dsRam.snrTestSensorId)
#define capsense_ADC_SNR_TEST_SENSOR_ID_OFFSET              (205u)
#define capsense_ADC_SNR_TEST_SENSOR_ID_SIZE                (1u)
#define capsense_ADC_SNR_TEST_SENSOR_ID_PARAM_ID            (0x6F0000CDu)

#define capsense_ADC_SNR_TEST_SCAN_COUNTER_VALUE            (capsense_ADC_dsRam.snrTestScanCounter)
#define capsense_ADC_SNR_TEST_SCAN_COUNTER_OFFSET           (206u)
#define capsense_ADC_SNR_TEST_SCAN_COUNTER_SIZE             (2u)
#define capsense_ADC_SNR_TEST_SCAN_COUNTER_PARAM_ID         (0x860000CEu)

#define capsense_ADC_SNR_TEST_RAW_COUNT0_VALUE              (capsense_ADC_dsRam.snrTestRawCount[0u])
#define capsense_ADC_SNR_TEST_RAW_COUNT0_OFFSET             (208u)
#define capsense_ADC_SNR_TEST_RAW_COUNT0_SIZE               (2u)
#define capsense_ADC_SNR_TEST_RAW_COUNT0_PARAM_ID           (0x8C0000D0u)

#define capsense_ADC_SCAN_CSD_ISC_VALUE                     (capsense_ADC_dsRam.scanCsdISC)
#define capsense_ADC_SCAN_CSD_ISC_OFFSET                    (210u)
#define capsense_ADC_SCAN_CSD_ISC_SIZE                      (1u)
#define capsense_ADC_SCAN_CSD_ISC_PARAM_ID                  (0x480000D2u)

#define capsense_ADC_SCAN_CURRENT_ISC_VALUE                 (capsense_ADC_dsRam.scanCurrentISC)
#define capsense_ADC_SCAN_CURRENT_ISC_OFFSET                (211u)
#define capsense_ADC_SCAN_CURRENT_ISC_SIZE                  (1u)
#define capsense_ADC_SCAN_CURRENT_ISC_PARAM_ID              (0x4E0000D3u)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define capsense_ADC_BTN2_PTR2SNS_FLASH_VALUE               (capsense_ADC_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define capsense_ADC_BTN2_PTR2SNS_FLASH_OFFSET              (0u)
#define capsense_ADC_BTN2_PTR2SNS_FLASH_SIZE                (4u)
#define capsense_ADC_BTN2_PTR2SNS_FLASH_PARAM_ID            (0xD1000000u)

#define capsense_ADC_BTN2_PTR2WD_RAM_VALUE                  (capsense_ADC_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define capsense_ADC_BTN2_PTR2WD_RAM_OFFSET                 (4u)
#define capsense_ADC_BTN2_PTR2WD_RAM_SIZE                   (4u)
#define capsense_ADC_BTN2_PTR2WD_RAM_PARAM_ID               (0xD0000004u)

#define capsense_ADC_BTN2_PTR2SNS_RAM_VALUE                 (capsense_ADC_dsFlash.wdgtArray[0].ptr2SnsRam)
#define capsense_ADC_BTN2_PTR2SNS_RAM_OFFSET                (8u)
#define capsense_ADC_BTN2_PTR2SNS_RAM_SIZE                  (4u)
#define capsense_ADC_BTN2_PTR2SNS_RAM_PARAM_ID              (0xD3000008u)

#define capsense_ADC_BTN2_PTR2FLTR_HISTORY_VALUE            (capsense_ADC_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define capsense_ADC_BTN2_PTR2FLTR_HISTORY_OFFSET           (12u)
#define capsense_ADC_BTN2_PTR2FLTR_HISTORY_SIZE             (4u)
#define capsense_ADC_BTN2_PTR2FLTR_HISTORY_PARAM_ID         (0xD200000Cu)

#define capsense_ADC_BTN2_PTR2DEBOUNCE_VALUE                (capsense_ADC_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define capsense_ADC_BTN2_PTR2DEBOUNCE_OFFSET               (16u)
#define capsense_ADC_BTN2_PTR2DEBOUNCE_SIZE                 (4u)
#define capsense_ADC_BTN2_PTR2DEBOUNCE_PARAM_ID             (0xD4000010u)

#define capsense_ADC_BTN2_STATIC_CONFIG_VALUE               (capsense_ADC_dsFlash.wdgtArray[0].staticConfig)
#define capsense_ADC_BTN2_STATIC_CONFIG_OFFSET              (20u)
#define capsense_ADC_BTN2_STATIC_CONFIG_SIZE                (4u)
#define capsense_ADC_BTN2_STATIC_CONFIG_PARAM_ID            (0xD5000014u)

#define capsense_ADC_BTN2_TOTAL_NUM_SNS_VALUE               (capsense_ADC_dsFlash.wdgtArray[0].totalNumSns)
#define capsense_ADC_BTN2_TOTAL_NUM_SNS_OFFSET              (24u)
#define capsense_ADC_BTN2_TOTAL_NUM_SNS_SIZE                (2u)
#define capsense_ADC_BTN2_TOTAL_NUM_SNS_PARAM_ID            (0x99000018u)

#define capsense_ADC_BTN2_TYPE_VALUE                        (capsense_ADC_dsFlash.wdgtArray[0].wdgtType)
#define capsense_ADC_BTN2_TYPE_OFFSET                       (26u)
#define capsense_ADC_BTN2_TYPE_SIZE                         (1u)
#define capsense_ADC_BTN2_TYPE_PARAM_ID                     (0x5D00001Au)

#define capsense_ADC_BTN2_NUM_COLS_VALUE                    (capsense_ADC_dsFlash.wdgtArray[0].numCols)
#define capsense_ADC_BTN2_NUM_COLS_OFFSET                   (27u)
#define capsense_ADC_BTN2_NUM_COLS_SIZE                     (1u)
#define capsense_ADC_BTN2_NUM_COLS_PARAM_ID                 (0x5B00001Bu)

#define capsense_ADC_BTN2_X_RESOLUTION_VALUE                (capsense_ADC_dsFlash.wdgtArray[0].xResolution)
#define capsense_ADC_BTN2_X_RESOLUTION_OFFSET               (28u)
#define capsense_ADC_BTN2_X_RESOLUTION_SIZE                 (2u)
#define capsense_ADC_BTN2_X_RESOLUTION_PARAM_ID             (0x9800001Cu)

#define capsense_ADC_BTN2_X_CENT_MULT_VALUE                 (capsense_ADC_dsFlash.wdgtArray[0].xCentroidMultiplier)
#define capsense_ADC_BTN2_X_CENT_MULT_OFFSET                (32u)
#define capsense_ADC_BTN2_X_CENT_MULT_SIZE                  (4u)
#define capsense_ADC_BTN2_X_CENT_MULT_PARAM_ID              (0xDB000020u)

#define capsense_ADC_BTN2_PTR2NOISE_ENVLP_VALUE             (capsense_ADC_dsFlash.wdgtArray[0].ptr2NoiseEnvlp)
#define capsense_ADC_BTN2_PTR2NOISE_ENVLP_OFFSET            (36u)
#define capsense_ADC_BTN2_PTR2NOISE_ENVLP_SIZE              (4u)
#define capsense_ADC_BTN2_PTR2NOISE_ENVLP_PARAM_ID          (0xDA000024u)

#define capsense_ADC_BTN2_IIR_FILTER_COEFF_VALUE            (capsense_ADC_dsFlash.wdgtArray[0].iirFilterCoeff)
#define capsense_ADC_BTN2_IIR_FILTER_COEFF_OFFSET           (40u)
#define capsense_ADC_BTN2_IIR_FILTER_COEFF_SIZE             (1u)
#define capsense_ADC_BTN2_IIR_FILTER_COEFF_PARAM_ID         (0x5E000028u)

#define capsense_ADC_BTN1_PTR2SNS_FLASH_VALUE               (capsense_ADC_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define capsense_ADC_BTN1_PTR2SNS_FLASH_OFFSET              (44u)
#define capsense_ADC_BTN1_PTR2SNS_FLASH_SIZE                (4u)
#define capsense_ADC_BTN1_PTR2SNS_FLASH_PARAM_ID            (0xDB01002Cu)

#define capsense_ADC_BTN1_PTR2WD_RAM_VALUE                  (capsense_ADC_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define capsense_ADC_BTN1_PTR2WD_RAM_OFFSET                 (48u)
#define capsense_ADC_BTN1_PTR2WD_RAM_SIZE                   (4u)
#define capsense_ADC_BTN1_PTR2WD_RAM_PARAM_ID               (0xDD010030u)

#define capsense_ADC_BTN1_PTR2SNS_RAM_VALUE                 (capsense_ADC_dsFlash.wdgtArray[1].ptr2SnsRam)
#define capsense_ADC_BTN1_PTR2SNS_RAM_OFFSET                (52u)
#define capsense_ADC_BTN1_PTR2SNS_RAM_SIZE                  (4u)
#define capsense_ADC_BTN1_PTR2SNS_RAM_PARAM_ID              (0xDC010034u)

#define capsense_ADC_BTN1_PTR2FLTR_HISTORY_VALUE            (capsense_ADC_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define capsense_ADC_BTN1_PTR2FLTR_HISTORY_OFFSET           (56u)
#define capsense_ADC_BTN1_PTR2FLTR_HISTORY_SIZE             (4u)
#define capsense_ADC_BTN1_PTR2FLTR_HISTORY_PARAM_ID         (0xDF010038u)

#define capsense_ADC_BTN1_PTR2DEBOUNCE_VALUE                (capsense_ADC_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define capsense_ADC_BTN1_PTR2DEBOUNCE_OFFSET               (60u)
#define capsense_ADC_BTN1_PTR2DEBOUNCE_SIZE                 (4u)
#define capsense_ADC_BTN1_PTR2DEBOUNCE_PARAM_ID             (0xDE01003Cu)

#define capsense_ADC_BTN1_STATIC_CONFIG_VALUE               (capsense_ADC_dsFlash.wdgtArray[1].staticConfig)
#define capsense_ADC_BTN1_STATIC_CONFIG_OFFSET              (64u)
#define capsense_ADC_BTN1_STATIC_CONFIG_SIZE                (4u)
#define capsense_ADC_BTN1_STATIC_CONFIG_PARAM_ID            (0xDF010040u)

#define capsense_ADC_BTN1_TOTAL_NUM_SNS_VALUE               (capsense_ADC_dsFlash.wdgtArray[1].totalNumSns)
#define capsense_ADC_BTN1_TOTAL_NUM_SNS_OFFSET              (68u)
#define capsense_ADC_BTN1_TOTAL_NUM_SNS_SIZE                (2u)
#define capsense_ADC_BTN1_TOTAL_NUM_SNS_PARAM_ID            (0x91010044u)

#define capsense_ADC_BTN1_TYPE_VALUE                        (capsense_ADC_dsFlash.wdgtArray[1].wdgtType)
#define capsense_ADC_BTN1_TYPE_OFFSET                       (70u)
#define capsense_ADC_BTN1_TYPE_SIZE                         (1u)
#define capsense_ADC_BTN1_TYPE_PARAM_ID                     (0x55010046u)

#define capsense_ADC_BTN1_NUM_COLS_VALUE                    (capsense_ADC_dsFlash.wdgtArray[1].numCols)
#define capsense_ADC_BTN1_NUM_COLS_OFFSET                   (71u)
#define capsense_ADC_BTN1_NUM_COLS_SIZE                     (1u)
#define capsense_ADC_BTN1_NUM_COLS_PARAM_ID                 (0x53010047u)

#define capsense_ADC_BTN1_X_RESOLUTION_VALUE                (capsense_ADC_dsFlash.wdgtArray[1].xResolution)
#define capsense_ADC_BTN1_X_RESOLUTION_OFFSET               (72u)
#define capsense_ADC_BTN1_X_RESOLUTION_SIZE                 (2u)
#define capsense_ADC_BTN1_X_RESOLUTION_PARAM_ID             (0x92010048u)

#define capsense_ADC_BTN1_X_CENT_MULT_VALUE                 (capsense_ADC_dsFlash.wdgtArray[1].xCentroidMultiplier)
#define capsense_ADC_BTN1_X_CENT_MULT_OFFSET                (76u)
#define capsense_ADC_BTN1_X_CENT_MULT_SIZE                  (4u)
#define capsense_ADC_BTN1_X_CENT_MULT_PARAM_ID              (0xDC01004Cu)

#define capsense_ADC_BTN1_PTR2NOISE_ENVLP_VALUE             (capsense_ADC_dsFlash.wdgtArray[1].ptr2NoiseEnvlp)
#define capsense_ADC_BTN1_PTR2NOISE_ENVLP_OFFSET            (80u)
#define capsense_ADC_BTN1_PTR2NOISE_ENVLP_SIZE              (4u)
#define capsense_ADC_BTN1_PTR2NOISE_ENVLP_PARAM_ID          (0xDA010050u)

#define capsense_ADC_BTN1_IIR_FILTER_COEFF_VALUE            (capsense_ADC_dsFlash.wdgtArray[1].iirFilterCoeff)
#define capsense_ADC_BTN1_IIR_FILTER_COEFF_OFFSET           (84u)
#define capsense_ADC_BTN1_IIR_FILTER_COEFF_SIZE             (1u)
#define capsense_ADC_BTN1_IIR_FILTER_COEFF_PARAM_ID         (0x5C010054u)

#define capsense_ADC_BTN0_PTR2SNS_FLASH_VALUE               (capsense_ADC_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define capsense_ADC_BTN0_PTR2SNS_FLASH_OFFSET              (88u)
#define capsense_ADC_BTN0_PTR2SNS_FLASH_SIZE                (4u)
#define capsense_ADC_BTN0_PTR2SNS_FLASH_PARAM_ID            (0xDD020058u)

#define capsense_ADC_BTN0_PTR2WD_RAM_VALUE                  (capsense_ADC_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define capsense_ADC_BTN0_PTR2WD_RAM_OFFSET                 (92u)
#define capsense_ADC_BTN0_PTR2WD_RAM_SIZE                   (4u)
#define capsense_ADC_BTN0_PTR2WD_RAM_PARAM_ID               (0xDC02005Cu)

#define capsense_ADC_BTN0_PTR2SNS_RAM_VALUE                 (capsense_ADC_dsFlash.wdgtArray[2].ptr2SnsRam)
#define capsense_ADC_BTN0_PTR2SNS_RAM_OFFSET                (96u)
#define capsense_ADC_BTN0_PTR2SNS_RAM_SIZE                  (4u)
#define capsense_ADC_BTN0_PTR2SNS_RAM_PARAM_ID              (0xD0020060u)

#define capsense_ADC_BTN0_PTR2FLTR_HISTORY_VALUE            (capsense_ADC_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define capsense_ADC_BTN0_PTR2FLTR_HISTORY_OFFSET           (100u)
#define capsense_ADC_BTN0_PTR2FLTR_HISTORY_SIZE             (4u)
#define capsense_ADC_BTN0_PTR2FLTR_HISTORY_PARAM_ID         (0xD1020064u)

#define capsense_ADC_BTN0_PTR2DEBOUNCE_VALUE                (capsense_ADC_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define capsense_ADC_BTN0_PTR2DEBOUNCE_OFFSET               (104u)
#define capsense_ADC_BTN0_PTR2DEBOUNCE_SIZE                 (4u)
#define capsense_ADC_BTN0_PTR2DEBOUNCE_PARAM_ID             (0xD2020068u)

#define capsense_ADC_BTN0_STATIC_CONFIG_VALUE               (capsense_ADC_dsFlash.wdgtArray[2].staticConfig)
#define capsense_ADC_BTN0_STATIC_CONFIG_OFFSET              (108u)
#define capsense_ADC_BTN0_STATIC_CONFIG_SIZE                (4u)
#define capsense_ADC_BTN0_STATIC_CONFIG_PARAM_ID            (0xD302006Cu)

#define capsense_ADC_BTN0_TOTAL_NUM_SNS_VALUE               (capsense_ADC_dsFlash.wdgtArray[2].totalNumSns)
#define capsense_ADC_BTN0_TOTAL_NUM_SNS_OFFSET              (112u)
#define capsense_ADC_BTN0_TOTAL_NUM_SNS_SIZE                (2u)
#define capsense_ADC_BTN0_TOTAL_NUM_SNS_PARAM_ID            (0x9A020070u)

#define capsense_ADC_BTN0_TYPE_VALUE                        (capsense_ADC_dsFlash.wdgtArray[2].wdgtType)
#define capsense_ADC_BTN0_TYPE_OFFSET                       (114u)
#define capsense_ADC_BTN0_TYPE_SIZE                         (1u)
#define capsense_ADC_BTN0_TYPE_PARAM_ID                     (0x5E020072u)

#define capsense_ADC_BTN0_NUM_COLS_VALUE                    (capsense_ADC_dsFlash.wdgtArray[2].numCols)
#define capsense_ADC_BTN0_NUM_COLS_OFFSET                   (115u)
#define capsense_ADC_BTN0_NUM_COLS_SIZE                     (1u)
#define capsense_ADC_BTN0_NUM_COLS_PARAM_ID                 (0x58020073u)

#define capsense_ADC_BTN0_X_RESOLUTION_VALUE                (capsense_ADC_dsFlash.wdgtArray[2].xResolution)
#define capsense_ADC_BTN0_X_RESOLUTION_OFFSET               (116u)
#define capsense_ADC_BTN0_X_RESOLUTION_SIZE                 (2u)
#define capsense_ADC_BTN0_X_RESOLUTION_PARAM_ID             (0x9B020074u)

#define capsense_ADC_BTN0_X_CENT_MULT_VALUE                 (capsense_ADC_dsFlash.wdgtArray[2].xCentroidMultiplier)
#define capsense_ADC_BTN0_X_CENT_MULT_OFFSET                (120u)
#define capsense_ADC_BTN0_X_CENT_MULT_SIZE                  (4u)
#define capsense_ADC_BTN0_X_CENT_MULT_PARAM_ID              (0xD7020078u)

#define capsense_ADC_BTN0_PTR2NOISE_ENVLP_VALUE             (capsense_ADC_dsFlash.wdgtArray[2].ptr2NoiseEnvlp)
#define capsense_ADC_BTN0_PTR2NOISE_ENVLP_OFFSET            (124u)
#define capsense_ADC_BTN0_PTR2NOISE_ENVLP_SIZE              (4u)
#define capsense_ADC_BTN0_PTR2NOISE_ENVLP_PARAM_ID          (0xD602007Cu)

#define capsense_ADC_BTN0_IIR_FILTER_COEFF_VALUE            (capsense_ADC_dsFlash.wdgtArray[2].iirFilterCoeff)
#define capsense_ADC_BTN0_IIR_FILTER_COEFF_OFFSET           (128u)
#define capsense_ADC_BTN0_IIR_FILTER_COEFF_SIZE             (1u)
#define capsense_ADC_BTN0_IIR_FILTER_COEFF_PARAM_ID         (0x53020080u)

#define capsense_ADC_LINEARSLIDER0_PTR2SNS_FLASH_VALUE      (capsense_ADC_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define capsense_ADC_LINEARSLIDER0_PTR2SNS_FLASH_OFFSET     (132u)
#define capsense_ADC_LINEARSLIDER0_PTR2SNS_FLASH_SIZE       (4u)
#define capsense_ADC_LINEARSLIDER0_PTR2SNS_FLASH_PARAM_ID   (0xD6030084u)

#define capsense_ADC_LINEARSLIDER0_PTR2WD_RAM_VALUE         (capsense_ADC_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define capsense_ADC_LINEARSLIDER0_PTR2WD_RAM_OFFSET        (136u)
#define capsense_ADC_LINEARSLIDER0_PTR2WD_RAM_SIZE          (4u)
#define capsense_ADC_LINEARSLIDER0_PTR2WD_RAM_PARAM_ID      (0xD5030088u)

#define capsense_ADC_LINEARSLIDER0_PTR2SNS_RAM_VALUE        (capsense_ADC_dsFlash.wdgtArray[3].ptr2SnsRam)
#define capsense_ADC_LINEARSLIDER0_PTR2SNS_RAM_OFFSET       (140u)
#define capsense_ADC_LINEARSLIDER0_PTR2SNS_RAM_SIZE         (4u)
#define capsense_ADC_LINEARSLIDER0_PTR2SNS_RAM_PARAM_ID     (0xD403008Cu)

#define capsense_ADC_LINEARSLIDER0_PTR2FLTR_HISTORY_VALUE   (capsense_ADC_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define capsense_ADC_LINEARSLIDER0_PTR2FLTR_HISTORY_OFFSET  (144u)
#define capsense_ADC_LINEARSLIDER0_PTR2FLTR_HISTORY_SIZE    (4u)
#define capsense_ADC_LINEARSLIDER0_PTR2FLTR_HISTORY_PARAM_ID (0xD2030090u)

#define capsense_ADC_LINEARSLIDER0_PTR2DEBOUNCE_VALUE       (capsense_ADC_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define capsense_ADC_LINEARSLIDER0_PTR2DEBOUNCE_OFFSET      (148u)
#define capsense_ADC_LINEARSLIDER0_PTR2DEBOUNCE_SIZE        (4u)
#define capsense_ADC_LINEARSLIDER0_PTR2DEBOUNCE_PARAM_ID    (0xD3030094u)

#define capsense_ADC_LINEARSLIDER0_STATIC_CONFIG_VALUE      (capsense_ADC_dsFlash.wdgtArray[3].staticConfig)
#define capsense_ADC_LINEARSLIDER0_STATIC_CONFIG_OFFSET     (152u)
#define capsense_ADC_LINEARSLIDER0_STATIC_CONFIG_SIZE       (4u)
#define capsense_ADC_LINEARSLIDER0_STATIC_CONFIG_PARAM_ID   (0xD0030098u)

#define capsense_ADC_LINEARSLIDER0_TOTAL_NUM_SNS_VALUE      (capsense_ADC_dsFlash.wdgtArray[3].totalNumSns)
#define capsense_ADC_LINEARSLIDER0_TOTAL_NUM_SNS_OFFSET     (156u)
#define capsense_ADC_LINEARSLIDER0_TOTAL_NUM_SNS_SIZE       (2u)
#define capsense_ADC_LINEARSLIDER0_TOTAL_NUM_SNS_PARAM_ID   (0x9E03009Cu)

#define capsense_ADC_LINEARSLIDER0_TYPE_VALUE               (capsense_ADC_dsFlash.wdgtArray[3].wdgtType)
#define capsense_ADC_LINEARSLIDER0_TYPE_OFFSET              (158u)
#define capsense_ADC_LINEARSLIDER0_TYPE_SIZE                (1u)
#define capsense_ADC_LINEARSLIDER0_TYPE_PARAM_ID            (0x5A03009Eu)

#define capsense_ADC_LINEARSLIDER0_NUM_COLS_VALUE           (capsense_ADC_dsFlash.wdgtArray[3].numCols)
#define capsense_ADC_LINEARSLIDER0_NUM_COLS_OFFSET          (159u)
#define capsense_ADC_LINEARSLIDER0_NUM_COLS_SIZE            (1u)
#define capsense_ADC_LINEARSLIDER0_NUM_COLS_PARAM_ID        (0x5C03009Fu)

#define capsense_ADC_LINEARSLIDER0_X_RESOLUTION_VALUE       (capsense_ADC_dsFlash.wdgtArray[3].xResolution)
#define capsense_ADC_LINEARSLIDER0_X_RESOLUTION_OFFSET      (160u)
#define capsense_ADC_LINEARSLIDER0_X_RESOLUTION_SIZE        (2u)
#define capsense_ADC_LINEARSLIDER0_X_RESOLUTION_PARAM_ID    (0x920300A0u)

#define capsense_ADC_LINEARSLIDER0_X_CENT_MULT_VALUE        (capsense_ADC_dsFlash.wdgtArray[3].xCentroidMultiplier)
#define capsense_ADC_LINEARSLIDER0_X_CENT_MULT_OFFSET       (164u)
#define capsense_ADC_LINEARSLIDER0_X_CENT_MULT_SIZE         (4u)
#define capsense_ADC_LINEARSLIDER0_X_CENT_MULT_PARAM_ID     (0xDC0300A4u)

#define capsense_ADC_LINEARSLIDER0_PTR2NOISE_ENVLP_VALUE    (capsense_ADC_dsFlash.wdgtArray[3].ptr2NoiseEnvlp)
#define capsense_ADC_LINEARSLIDER0_PTR2NOISE_ENVLP_OFFSET   (168u)
#define capsense_ADC_LINEARSLIDER0_PTR2NOISE_ENVLP_SIZE     (4u)
#define capsense_ADC_LINEARSLIDER0_PTR2NOISE_ENVLP_PARAM_ID (0xDF0300A8u)

#define capsense_ADC_LINEARSLIDER0_IIR_FILTER_COEFF_VALUE   (capsense_ADC_dsFlash.wdgtArray[3].iirFilterCoeff)
#define capsense_ADC_LINEARSLIDER0_IIR_FILTER_COEFF_OFFSET  (172u)
#define capsense_ADC_LINEARSLIDER0_IIR_FILTER_COEFF_SIZE    (1u)
#define capsense_ADC_LINEARSLIDER0_IIR_FILTER_COEFF_PARAM_ID (0x590300ACu)


#endif /* End CY_SENSE_capsense_ADC_REGISTER_MAP_H */


/* [] END OF FILE */
