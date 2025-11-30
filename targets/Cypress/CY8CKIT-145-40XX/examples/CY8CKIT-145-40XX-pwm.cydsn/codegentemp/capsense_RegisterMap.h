/***************************************************************************//**
* \file capsense_RegisterMap.h
* \version 7.10
*
* \brief
*   This file provides the definitions for the Component data structure register.
*
* \see capsense v7.10 Datasheet
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

#if !defined(CY_SENSE_capsense_REGISTER_MAP_H)
#define CY_SENSE_capsense_REGISTER_MAP_H

#include <cytypes.h>
#include "capsense_Configuration.h"
#include "capsense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define capsense_CONFIG_ID_VALUE                            (capsense_dsRam.configId)
#define capsense_CONFIG_ID_OFFSET                           (0u)
#define capsense_CONFIG_ID_SIZE                             (2u)
#define capsense_CONFIG_ID_PARAM_ID                         (0x87000000u)

#define capsense_DEVICE_ID_VALUE                            (capsense_dsRam.deviceId)
#define capsense_DEVICE_ID_OFFSET                           (2u)
#define capsense_DEVICE_ID_SIZE                             (2u)
#define capsense_DEVICE_ID_PARAM_ID                         (0x8B000002u)

#define capsense_HW_CLOCK_VALUE                             (capsense_dsRam.hwClock)
#define capsense_HW_CLOCK_OFFSET                            (4u)
#define capsense_HW_CLOCK_SIZE                              (2u)
#define capsense_HW_CLOCK_PARAM_ID                          (0x86000004u)

#define capsense_TUNER_CMD_VALUE                            (capsense_dsRam.tunerCmd)
#define capsense_TUNER_CMD_OFFSET                           (6u)
#define capsense_TUNER_CMD_SIZE                             (2u)
#define capsense_TUNER_CMD_PARAM_ID                         (0xA1000006u)

#define capsense_SCAN_COUNTER_VALUE                         (capsense_dsRam.scanCounter)
#define capsense_SCAN_COUNTER_OFFSET                        (8u)
#define capsense_SCAN_COUNTER_SIZE                          (2u)
#define capsense_SCAN_COUNTER_PARAM_ID                      (0x85000008u)

#define capsense_STATUS_VALUE                               (capsense_dsRam.status)
#define capsense_STATUS_OFFSET                              (12u)
#define capsense_STATUS_SIZE                                (4u)
#define capsense_STATUS_PARAM_ID                            (0xCB00000Cu)

#define capsense_WDGT_ENABLE0_VALUE                         (capsense_dsRam.wdgtEnable[0u])
#define capsense_WDGT_ENABLE0_OFFSET                        (16u)
#define capsense_WDGT_ENABLE0_SIZE                          (4u)
#define capsense_WDGT_ENABLE0_PARAM_ID                      (0xE6000010u)

#define capsense_WDGT_STATUS0_VALUE                         (capsense_dsRam.wdgtStatus[0u])
#define capsense_WDGT_STATUS0_OFFSET                        (20u)
#define capsense_WDGT_STATUS0_SIZE                          (4u)
#define capsense_WDGT_STATUS0_PARAM_ID                      (0xCC000014u)

#define capsense_SNS_STATUS0_VALUE                          (capsense_dsRam.snsStatus[0u])
#define capsense_SNS_STATUS0_OFFSET                         (24u)
#define capsense_SNS_STATUS0_SIZE                           (1u)
#define capsense_SNS_STATUS0_PARAM_ID                       (0x48000018u)

#define capsense_SNS_STATUS1_VALUE                          (capsense_dsRam.snsStatus[1u])
#define capsense_SNS_STATUS1_OFFSET                         (25u)
#define capsense_SNS_STATUS1_SIZE                           (1u)
#define capsense_SNS_STATUS1_PARAM_ID                       (0x4E000019u)

#define capsense_SNS_STATUS2_VALUE                          (capsense_dsRam.snsStatus[2u])
#define capsense_SNS_STATUS2_OFFSET                         (26u)
#define capsense_SNS_STATUS2_SIZE                           (1u)
#define capsense_SNS_STATUS2_PARAM_ID                       (0x4400001Au)

#define capsense_SNS_STATUS3_VALUE                          (capsense_dsRam.snsStatus[3u])
#define capsense_SNS_STATUS3_OFFSET                         (27u)
#define capsense_SNS_STATUS3_SIZE                           (1u)
#define capsense_SNS_STATUS3_PARAM_ID                       (0x4200001Bu)

#define capsense_CSD0_CONFIG_VALUE                          (capsense_dsRam.csd0Config)
#define capsense_CSD0_CONFIG_OFFSET                         (28u)
#define capsense_CSD0_CONFIG_SIZE                           (2u)
#define capsense_CSD0_CONFIG_PARAM_ID                       (0xA780001Cu)

#define capsense_MOD_CSD_CLK_VALUE                          (capsense_dsRam.modCsdClk)
#define capsense_MOD_CSD_CLK_OFFSET                         (30u)
#define capsense_MOD_CSD_CLK_SIZE                           (1u)
#define capsense_MOD_CSD_CLK_PARAM_ID                       (0x6380001Eu)

#define capsense_MOD_CSX_CLK_VALUE                          (capsense_dsRam.modCsxClk)
#define capsense_MOD_CSX_CLK_OFFSET                         (31u)
#define capsense_MOD_CSX_CLK_SIZE                           (1u)
#define capsense_MOD_CSX_CLK_PARAM_ID                       (0x6580001Fu)

#define capsense_BTN0_RESOLUTION_VALUE                      (capsense_dsRam.wdgtList.btn0.resolution)
#define capsense_BTN0_RESOLUTION_OFFSET                     (32u)
#define capsense_BTN0_RESOLUTION_SIZE                       (2u)
#define capsense_BTN0_RESOLUTION_PARAM_ID                   (0xAB800020u)

#define capsense_BTN0_FINGER_TH_VALUE                       (capsense_dsRam.wdgtList.btn0.fingerTh)
#define capsense_BTN0_FINGER_TH_OFFSET                      (34u)
#define capsense_BTN0_FINGER_TH_SIZE                        (2u)
#define capsense_BTN0_FINGER_TH_PARAM_ID                    (0xA7800022u)

#define capsense_BTN0_NOISE_TH_VALUE                        (capsense_dsRam.wdgtList.btn0.noiseTh)
#define capsense_BTN0_NOISE_TH_OFFSET                       (36u)
#define capsense_BTN0_NOISE_TH_SIZE                         (1u)
#define capsense_BTN0_NOISE_TH_PARAM_ID                     (0x62800024u)

#define capsense_BTN0_NNOISE_TH_VALUE                       (capsense_dsRam.wdgtList.btn0.nNoiseTh)
#define capsense_BTN0_NNOISE_TH_OFFSET                      (37u)
#define capsense_BTN0_NNOISE_TH_SIZE                        (1u)
#define capsense_BTN0_NNOISE_TH_PARAM_ID                    (0x64800025u)

#define capsense_BTN0_HYSTERESIS_VALUE                      (capsense_dsRam.wdgtList.btn0.hysteresis)
#define capsense_BTN0_HYSTERESIS_OFFSET                     (38u)
#define capsense_BTN0_HYSTERESIS_SIZE                       (1u)
#define capsense_BTN0_HYSTERESIS_PARAM_ID                   (0x6E800026u)

#define capsense_BTN0_ON_DEBOUNCE_VALUE                     (capsense_dsRam.wdgtList.btn0.onDebounce)
#define capsense_BTN0_ON_DEBOUNCE_OFFSET                    (39u)
#define capsense_BTN0_ON_DEBOUNCE_SIZE                      (1u)
#define capsense_BTN0_ON_DEBOUNCE_PARAM_ID                  (0x68800027u)

#define capsense_BTN0_LOW_BSLN_RST_VALUE                    (capsense_dsRam.wdgtList.btn0.lowBslnRst)
#define capsense_BTN0_LOW_BSLN_RST_OFFSET                   (40u)
#define capsense_BTN0_LOW_BSLN_RST_SIZE                     (1u)
#define capsense_BTN0_LOW_BSLN_RST_PARAM_ID                 (0x61800028u)

#define capsense_BTN0_IDAC_MOD0_VALUE                       (capsense_dsRam.wdgtList.btn0.idacMod[0u])
#define capsense_BTN0_IDAC_MOD0_OFFSET                      (41u)
#define capsense_BTN0_IDAC_MOD0_SIZE                        (1u)
#define capsense_BTN0_IDAC_MOD0_PARAM_ID                    (0x41000029u)

#define capsense_BTN0_IDAC_GAIN_INDEX_VALUE                 (capsense_dsRam.wdgtList.btn0.idacGainIndex)
#define capsense_BTN0_IDAC_GAIN_INDEX_OFFSET                (42u)
#define capsense_BTN0_IDAC_GAIN_INDEX_SIZE                  (1u)
#define capsense_BTN0_IDAC_GAIN_INDEX_PARAM_ID              (0x6D80002Au)

#define capsense_BTN0_SNS_CLK_VALUE                         (capsense_dsRam.wdgtList.btn0.snsClk)
#define capsense_BTN0_SNS_CLK_OFFSET                        (44u)
#define capsense_BTN0_SNS_CLK_SIZE                          (2u)
#define capsense_BTN0_SNS_CLK_PARAM_ID                      (0xA880002Cu)

#define capsense_BTN0_SNS_CLK_SOURCE_VALUE                  (capsense_dsRam.wdgtList.btn0.snsClkSource)
#define capsense_BTN0_SNS_CLK_SOURCE_OFFSET                 (46u)
#define capsense_BTN0_SNS_CLK_SOURCE_SIZE                   (1u)
#define capsense_BTN0_SNS_CLK_SOURCE_PARAM_ID               (0x4780002Eu)

#define capsense_BTN1_RESOLUTION_VALUE                      (capsense_dsRam.wdgtList.btn1.resolution)
#define capsense_BTN1_RESOLUTION_OFFSET                     (48u)
#define capsense_BTN1_RESOLUTION_SIZE                       (2u)
#define capsense_BTN1_RESOLUTION_PARAM_ID                   (0xAD810030u)

#define capsense_BTN1_FINGER_TH_VALUE                       (capsense_dsRam.wdgtList.btn1.fingerTh)
#define capsense_BTN1_FINGER_TH_OFFSET                      (50u)
#define capsense_BTN1_FINGER_TH_SIZE                        (2u)
#define capsense_BTN1_FINGER_TH_PARAM_ID                    (0xA1810032u)

#define capsense_BTN1_NOISE_TH_VALUE                        (capsense_dsRam.wdgtList.btn1.noiseTh)
#define capsense_BTN1_NOISE_TH_OFFSET                       (52u)
#define capsense_BTN1_NOISE_TH_SIZE                         (1u)
#define capsense_BTN1_NOISE_TH_PARAM_ID                     (0x64810034u)

#define capsense_BTN1_NNOISE_TH_VALUE                       (capsense_dsRam.wdgtList.btn1.nNoiseTh)
#define capsense_BTN1_NNOISE_TH_OFFSET                      (53u)
#define capsense_BTN1_NNOISE_TH_SIZE                        (1u)
#define capsense_BTN1_NNOISE_TH_PARAM_ID                    (0x62810035u)

#define capsense_BTN1_HYSTERESIS_VALUE                      (capsense_dsRam.wdgtList.btn1.hysteresis)
#define capsense_BTN1_HYSTERESIS_OFFSET                     (54u)
#define capsense_BTN1_HYSTERESIS_SIZE                       (1u)
#define capsense_BTN1_HYSTERESIS_PARAM_ID                   (0x68810036u)

#define capsense_BTN1_ON_DEBOUNCE_VALUE                     (capsense_dsRam.wdgtList.btn1.onDebounce)
#define capsense_BTN1_ON_DEBOUNCE_OFFSET                    (55u)
#define capsense_BTN1_ON_DEBOUNCE_SIZE                      (1u)
#define capsense_BTN1_ON_DEBOUNCE_PARAM_ID                  (0x6E810037u)

#define capsense_BTN1_LOW_BSLN_RST_VALUE                    (capsense_dsRam.wdgtList.btn1.lowBslnRst)
#define capsense_BTN1_LOW_BSLN_RST_OFFSET                   (56u)
#define capsense_BTN1_LOW_BSLN_RST_SIZE                     (1u)
#define capsense_BTN1_LOW_BSLN_RST_PARAM_ID                 (0x67810038u)

#define capsense_BTN1_IDAC_MOD0_VALUE                       (capsense_dsRam.wdgtList.btn1.idacMod[0u])
#define capsense_BTN1_IDAC_MOD0_OFFSET                      (57u)
#define capsense_BTN1_IDAC_MOD0_SIZE                        (1u)
#define capsense_BTN1_IDAC_MOD0_PARAM_ID                    (0x47010039u)

#define capsense_BTN1_IDAC_GAIN_INDEX_VALUE                 (capsense_dsRam.wdgtList.btn1.idacGainIndex)
#define capsense_BTN1_IDAC_GAIN_INDEX_OFFSET                (58u)
#define capsense_BTN1_IDAC_GAIN_INDEX_SIZE                  (1u)
#define capsense_BTN1_IDAC_GAIN_INDEX_PARAM_ID              (0x6B81003Au)

#define capsense_BTN1_SNS_CLK_VALUE                         (capsense_dsRam.wdgtList.btn1.snsClk)
#define capsense_BTN1_SNS_CLK_OFFSET                        (60u)
#define capsense_BTN1_SNS_CLK_SIZE                          (2u)
#define capsense_BTN1_SNS_CLK_PARAM_ID                      (0xAE81003Cu)

#define capsense_BTN1_SNS_CLK_SOURCE_VALUE                  (capsense_dsRam.wdgtList.btn1.snsClkSource)
#define capsense_BTN1_SNS_CLK_SOURCE_OFFSET                 (62u)
#define capsense_BTN1_SNS_CLK_SOURCE_SIZE                   (1u)
#define capsense_BTN1_SNS_CLK_SOURCE_PARAM_ID               (0x4181003Eu)

#define capsense_BTN2_RESOLUTION_VALUE                      (capsense_dsRam.wdgtList.btn2.resolution)
#define capsense_BTN2_RESOLUTION_OFFSET                     (64u)
#define capsense_BTN2_RESOLUTION_SIZE                       (2u)
#define capsense_BTN2_RESOLUTION_PARAM_ID                   (0xAA820040u)

#define capsense_BTN2_FINGER_TH_VALUE                       (capsense_dsRam.wdgtList.btn2.fingerTh)
#define capsense_BTN2_FINGER_TH_OFFSET                      (66u)
#define capsense_BTN2_FINGER_TH_SIZE                        (2u)
#define capsense_BTN2_FINGER_TH_PARAM_ID                    (0xA6820042u)

#define capsense_BTN2_NOISE_TH_VALUE                        (capsense_dsRam.wdgtList.btn2.noiseTh)
#define capsense_BTN2_NOISE_TH_OFFSET                       (68u)
#define capsense_BTN2_NOISE_TH_SIZE                         (1u)
#define capsense_BTN2_NOISE_TH_PARAM_ID                     (0x63820044u)

#define capsense_BTN2_NNOISE_TH_VALUE                       (capsense_dsRam.wdgtList.btn2.nNoiseTh)
#define capsense_BTN2_NNOISE_TH_OFFSET                      (69u)
#define capsense_BTN2_NNOISE_TH_SIZE                        (1u)
#define capsense_BTN2_NNOISE_TH_PARAM_ID                    (0x65820045u)

#define capsense_BTN2_HYSTERESIS_VALUE                      (capsense_dsRam.wdgtList.btn2.hysteresis)
#define capsense_BTN2_HYSTERESIS_OFFSET                     (70u)
#define capsense_BTN2_HYSTERESIS_SIZE                       (1u)
#define capsense_BTN2_HYSTERESIS_PARAM_ID                   (0x6F820046u)

#define capsense_BTN2_ON_DEBOUNCE_VALUE                     (capsense_dsRam.wdgtList.btn2.onDebounce)
#define capsense_BTN2_ON_DEBOUNCE_OFFSET                    (71u)
#define capsense_BTN2_ON_DEBOUNCE_SIZE                      (1u)
#define capsense_BTN2_ON_DEBOUNCE_PARAM_ID                  (0x69820047u)

#define capsense_BTN2_LOW_BSLN_RST_VALUE                    (capsense_dsRam.wdgtList.btn2.lowBslnRst)
#define capsense_BTN2_LOW_BSLN_RST_OFFSET                   (72u)
#define capsense_BTN2_LOW_BSLN_RST_SIZE                     (1u)
#define capsense_BTN2_LOW_BSLN_RST_PARAM_ID                 (0x60820048u)

#define capsense_BTN2_IDAC_MOD0_VALUE                       (capsense_dsRam.wdgtList.btn2.idacMod[0u])
#define capsense_BTN2_IDAC_MOD0_OFFSET                      (73u)
#define capsense_BTN2_IDAC_MOD0_SIZE                        (1u)
#define capsense_BTN2_IDAC_MOD0_PARAM_ID                    (0x40020049u)

#define capsense_BTN2_IDAC_GAIN_INDEX_VALUE                 (capsense_dsRam.wdgtList.btn2.idacGainIndex)
#define capsense_BTN2_IDAC_GAIN_INDEX_OFFSET                (74u)
#define capsense_BTN2_IDAC_GAIN_INDEX_SIZE                  (1u)
#define capsense_BTN2_IDAC_GAIN_INDEX_PARAM_ID              (0x6C82004Au)

#define capsense_BTN2_SNS_CLK_VALUE                         (capsense_dsRam.wdgtList.btn2.snsClk)
#define capsense_BTN2_SNS_CLK_OFFSET                        (76u)
#define capsense_BTN2_SNS_CLK_SIZE                          (2u)
#define capsense_BTN2_SNS_CLK_PARAM_ID                      (0xA982004Cu)

#define capsense_BTN2_SNS_CLK_SOURCE_VALUE                  (capsense_dsRam.wdgtList.btn2.snsClkSource)
#define capsense_BTN2_SNS_CLK_SOURCE_OFFSET                 (78u)
#define capsense_BTN2_SNS_CLK_SOURCE_SIZE                   (1u)
#define capsense_BTN2_SNS_CLK_SOURCE_PARAM_ID               (0x4682004Eu)

#define capsense_LINEARSLIDER_RESOLUTION_VALUE              (capsense_dsRam.wdgtList.linearslider.resolution)
#define capsense_LINEARSLIDER_RESOLUTION_OFFSET             (80u)
#define capsense_LINEARSLIDER_RESOLUTION_SIZE               (2u)
#define capsense_LINEARSLIDER_RESOLUTION_PARAM_ID           (0xAC830050u)

#define capsense_LINEARSLIDER_FINGER_TH_VALUE               (capsense_dsRam.wdgtList.linearslider.fingerTh)
#define capsense_LINEARSLIDER_FINGER_TH_OFFSET              (82u)
#define capsense_LINEARSLIDER_FINGER_TH_SIZE                (2u)
#define capsense_LINEARSLIDER_FINGER_TH_PARAM_ID            (0xA0830052u)

#define capsense_LINEARSLIDER_NOISE_TH_VALUE                (capsense_dsRam.wdgtList.linearslider.noiseTh)
#define capsense_LINEARSLIDER_NOISE_TH_OFFSET               (84u)
#define capsense_LINEARSLIDER_NOISE_TH_SIZE                 (1u)
#define capsense_LINEARSLIDER_NOISE_TH_PARAM_ID             (0x65830054u)

#define capsense_LINEARSLIDER_NNOISE_TH_VALUE               (capsense_dsRam.wdgtList.linearslider.nNoiseTh)
#define capsense_LINEARSLIDER_NNOISE_TH_OFFSET              (85u)
#define capsense_LINEARSLIDER_NNOISE_TH_SIZE                (1u)
#define capsense_LINEARSLIDER_NNOISE_TH_PARAM_ID            (0x63830055u)

#define capsense_LINEARSLIDER_HYSTERESIS_VALUE              (capsense_dsRam.wdgtList.linearslider.hysteresis)
#define capsense_LINEARSLIDER_HYSTERESIS_OFFSET             (86u)
#define capsense_LINEARSLIDER_HYSTERESIS_SIZE               (1u)
#define capsense_LINEARSLIDER_HYSTERESIS_PARAM_ID           (0x69830056u)

#define capsense_LINEARSLIDER_ON_DEBOUNCE_VALUE             (capsense_dsRam.wdgtList.linearslider.onDebounce)
#define capsense_LINEARSLIDER_ON_DEBOUNCE_OFFSET            (87u)
#define capsense_LINEARSLIDER_ON_DEBOUNCE_SIZE              (1u)
#define capsense_LINEARSLIDER_ON_DEBOUNCE_PARAM_ID          (0x6F830057u)

#define capsense_LINEARSLIDER_LOW_BSLN_RST_VALUE            (capsense_dsRam.wdgtList.linearslider.lowBslnRst)
#define capsense_LINEARSLIDER_LOW_BSLN_RST_OFFSET           (88u)
#define capsense_LINEARSLIDER_LOW_BSLN_RST_SIZE             (1u)
#define capsense_LINEARSLIDER_LOW_BSLN_RST_PARAM_ID         (0x66830058u)

#define capsense_LINEARSLIDER_IDAC_MOD0_VALUE               (capsense_dsRam.wdgtList.linearslider.idacMod[0u])
#define capsense_LINEARSLIDER_IDAC_MOD0_OFFSET              (89u)
#define capsense_LINEARSLIDER_IDAC_MOD0_SIZE                (1u)
#define capsense_LINEARSLIDER_IDAC_MOD0_PARAM_ID            (0x46030059u)

#define capsense_LINEARSLIDER_IDAC_GAIN_INDEX_VALUE         (capsense_dsRam.wdgtList.linearslider.idacGainIndex)
#define capsense_LINEARSLIDER_IDAC_GAIN_INDEX_OFFSET        (90u)
#define capsense_LINEARSLIDER_IDAC_GAIN_INDEX_SIZE          (1u)
#define capsense_LINEARSLIDER_IDAC_GAIN_INDEX_PARAM_ID      (0x4183005Au)

#define capsense_LINEARSLIDER_SNS_CLK_VALUE                 (capsense_dsRam.wdgtList.linearslider.snsClk)
#define capsense_LINEARSLIDER_SNS_CLK_OFFSET                (92u)
#define capsense_LINEARSLIDER_SNS_CLK_SIZE                  (2u)
#define capsense_LINEARSLIDER_SNS_CLK_PARAM_ID              (0xAF83005Cu)

#define capsense_LINEARSLIDER_SNS_CLK_SOURCE_VALUE          (capsense_dsRam.wdgtList.linearslider.snsClkSource)
#define capsense_LINEARSLIDER_SNS_CLK_SOURCE_OFFSET         (94u)
#define capsense_LINEARSLIDER_SNS_CLK_SOURCE_SIZE           (1u)
#define capsense_LINEARSLIDER_SNS_CLK_SOURCE_PARAM_ID       (0x4083005Eu)

#define capsense_LINEARSLIDER_POSITION0_VALUE               (capsense_dsRam.wdgtList.linearslider.position[0u])
#define capsense_LINEARSLIDER_POSITION0_OFFSET              (96u)
#define capsense_LINEARSLIDER_POSITION0_SIZE                (2u)
#define capsense_LINEARSLIDER_POSITION0_PARAM_ID            (0x85030060u)

#define capsense_BTN0_RX0_RAW0_VALUE                        (capsense_dsRam.snsList.btn0[0u].raw[0u])
#define capsense_BTN0_RX0_RAW0_OFFSET                       (98u)
#define capsense_BTN0_RX0_RAW0_SIZE                         (2u)
#define capsense_BTN0_RX0_RAW0_PARAM_ID                     (0x8C000062u)

#define capsense_BTN0_RX0_BSLN0_VALUE                       (capsense_dsRam.snsList.btn0[0u].bsln[0u])
#define capsense_BTN0_RX0_BSLN0_OFFSET                      (100u)
#define capsense_BTN0_RX0_BSLN0_SIZE                        (2u)
#define capsense_BTN0_RX0_BSLN0_PARAM_ID                    (0x81000064u)

#define capsense_BTN0_RX0_BSLN_EXT0_VALUE                   (capsense_dsRam.snsList.btn0[0u].bslnExt[0u])
#define capsense_BTN0_RX0_BSLN_EXT0_OFFSET                  (102u)
#define capsense_BTN0_RX0_BSLN_EXT0_SIZE                    (1u)
#define capsense_BTN0_RX0_BSLN_EXT0_PARAM_ID                (0x45000066u)

#define capsense_BTN0_RX0_DIFF_VALUE                        (capsense_dsRam.snsList.btn0[0u].diff)
#define capsense_BTN0_RX0_DIFF_OFFSET                       (104u)
#define capsense_BTN0_RX0_DIFF_SIZE                         (2u)
#define capsense_BTN0_RX0_DIFF_PARAM_ID                     (0x82000068u)

#define capsense_BTN0_RX0_NEG_BSLN_RST_CNT0_VALUE           (capsense_dsRam.snsList.btn0[0u].negBslnRstCnt[0u])
#define capsense_BTN0_RX0_NEG_BSLN_RST_CNT0_OFFSET          (106u)
#define capsense_BTN0_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define capsense_BTN0_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4600006Au)

#define capsense_BTN0_RX0_IDAC_COMP0_VALUE                  (capsense_dsRam.snsList.btn0[0u].idacComp[0u])
#define capsense_BTN0_RX0_IDAC_COMP0_OFFSET                 (107u)
#define capsense_BTN0_RX0_IDAC_COMP0_SIZE                   (1u)
#define capsense_BTN0_RX0_IDAC_COMP0_PARAM_ID               (0x4000006Bu)

#define capsense_BTN1_RX0_RAW0_VALUE                        (capsense_dsRam.snsList.btn1[0u].raw[0u])
#define capsense_BTN1_RX0_RAW0_OFFSET                       (108u)
#define capsense_BTN1_RX0_RAW0_SIZE                         (2u)
#define capsense_BTN1_RX0_RAW0_PARAM_ID                     (0x8300006Cu)

#define capsense_BTN1_RX0_BSLN0_VALUE                       (capsense_dsRam.snsList.btn1[0u].bsln[0u])
#define capsense_BTN1_RX0_BSLN0_OFFSET                      (110u)
#define capsense_BTN1_RX0_BSLN0_SIZE                        (2u)
#define capsense_BTN1_RX0_BSLN0_PARAM_ID                    (0x8F00006Eu)

#define capsense_BTN1_RX0_BSLN_EXT0_VALUE                   (capsense_dsRam.snsList.btn1[0u].bslnExt[0u])
#define capsense_BTN1_RX0_BSLN_EXT0_OFFSET                  (112u)
#define capsense_BTN1_RX0_BSLN_EXT0_SIZE                    (1u)
#define capsense_BTN1_RX0_BSLN_EXT0_PARAM_ID                (0x4D000070u)

#define capsense_BTN1_RX0_DIFF_VALUE                        (capsense_dsRam.snsList.btn1[0u].diff)
#define capsense_BTN1_RX0_DIFF_OFFSET                       (114u)
#define capsense_BTN1_RX0_DIFF_SIZE                         (2u)
#define capsense_BTN1_RX0_DIFF_PARAM_ID                     (0x89000072u)

#define capsense_BTN1_RX0_NEG_BSLN_RST_CNT0_VALUE           (capsense_dsRam.snsList.btn1[0u].negBslnRstCnt[0u])
#define capsense_BTN1_RX0_NEG_BSLN_RST_CNT0_OFFSET          (116u)
#define capsense_BTN1_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define capsense_BTN1_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4C000074u)

#define capsense_BTN1_RX0_IDAC_COMP0_VALUE                  (capsense_dsRam.snsList.btn1[0u].idacComp[0u])
#define capsense_BTN1_RX0_IDAC_COMP0_OFFSET                 (117u)
#define capsense_BTN1_RX0_IDAC_COMP0_SIZE                   (1u)
#define capsense_BTN1_RX0_IDAC_COMP0_PARAM_ID               (0x4A000075u)

#define capsense_BTN2_RX0_RAW0_VALUE                        (capsense_dsRam.snsList.btn2[0u].raw[0u])
#define capsense_BTN2_RX0_RAW0_OFFSET                       (118u)
#define capsense_BTN2_RX0_RAW0_SIZE                         (2u)
#define capsense_BTN2_RX0_RAW0_PARAM_ID                     (0x88000076u)

#define capsense_BTN2_RX0_BSLN0_VALUE                       (capsense_dsRam.snsList.btn2[0u].bsln[0u])
#define capsense_BTN2_RX0_BSLN0_OFFSET                      (120u)
#define capsense_BTN2_RX0_BSLN0_SIZE                        (2u)
#define capsense_BTN2_RX0_BSLN0_PARAM_ID                    (0x87000078u)

#define capsense_BTN2_RX0_BSLN_EXT0_VALUE                   (capsense_dsRam.snsList.btn2[0u].bslnExt[0u])
#define capsense_BTN2_RX0_BSLN_EXT0_OFFSET                  (122u)
#define capsense_BTN2_RX0_BSLN_EXT0_SIZE                    (1u)
#define capsense_BTN2_RX0_BSLN_EXT0_PARAM_ID                (0x4300007Au)

#define capsense_BTN2_RX0_DIFF_VALUE                        (capsense_dsRam.snsList.btn2[0u].diff)
#define capsense_BTN2_RX0_DIFF_OFFSET                       (124u)
#define capsense_BTN2_RX0_DIFF_SIZE                         (2u)
#define capsense_BTN2_RX0_DIFF_PARAM_ID                     (0x8600007Cu)

#define capsense_BTN2_RX0_NEG_BSLN_RST_CNT0_VALUE           (capsense_dsRam.snsList.btn2[0u].negBslnRstCnt[0u])
#define capsense_BTN2_RX0_NEG_BSLN_RST_CNT0_OFFSET          (126u)
#define capsense_BTN2_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define capsense_BTN2_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4200007Eu)

#define capsense_BTN2_RX0_IDAC_COMP0_VALUE                  (capsense_dsRam.snsList.btn2[0u].idacComp[0u])
#define capsense_BTN2_RX0_IDAC_COMP0_OFFSET                 (127u)
#define capsense_BTN2_RX0_IDAC_COMP0_SIZE                   (1u)
#define capsense_BTN2_RX0_IDAC_COMP0_PARAM_ID               (0x4400007Fu)

#define capsense_LINEARSLIDER_SNS0_RAW0_VALUE               (capsense_dsRam.snsList.linearslider[0u].raw[0u])
#define capsense_LINEARSLIDER_SNS0_RAW0_OFFSET              (128u)
#define capsense_LINEARSLIDER_SNS0_RAW0_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS0_RAW0_PARAM_ID            (0x84000080u)

#define capsense_LINEARSLIDER_SNS0_BSLN0_VALUE              (capsense_dsRam.snsList.linearslider[0u].bsln[0u])
#define capsense_LINEARSLIDER_SNS0_BSLN0_OFFSET             (130u)
#define capsense_LINEARSLIDER_SNS0_BSLN0_SIZE               (2u)
#define capsense_LINEARSLIDER_SNS0_BSLN0_PARAM_ID           (0x88000082u)

#define capsense_LINEARSLIDER_SNS0_BSLN_EXT0_VALUE          (capsense_dsRam.snsList.linearslider[0u].bslnExt[0u])
#define capsense_LINEARSLIDER_SNS0_BSLN_EXT0_OFFSET         (132u)
#define capsense_LINEARSLIDER_SNS0_BSLN_EXT0_SIZE           (1u)
#define capsense_LINEARSLIDER_SNS0_BSLN_EXT0_PARAM_ID       (0x4D000084u)

#define capsense_LINEARSLIDER_SNS0_DIFF_VALUE               (capsense_dsRam.snsList.linearslider[0u].diff)
#define capsense_LINEARSLIDER_SNS0_DIFF_OFFSET              (134u)
#define capsense_LINEARSLIDER_SNS0_DIFF_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS0_DIFF_PARAM_ID            (0x89000086u)

#define capsense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_VALUE  (capsense_dsRam.snsList.linearslider[0u].negBslnRstCnt[0u])
#define capsense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_OFFSET (136u)
#define capsense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define capsense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID (0x4E000088u)

#define capsense_LINEARSLIDER_SNS0_IDAC_COMP0_VALUE         (capsense_dsRam.snsList.linearslider[0u].idacComp[0u])
#define capsense_LINEARSLIDER_SNS0_IDAC_COMP0_OFFSET        (137u)
#define capsense_LINEARSLIDER_SNS0_IDAC_COMP0_SIZE          (1u)
#define capsense_LINEARSLIDER_SNS0_IDAC_COMP0_PARAM_ID      (0x48000089u)

#define capsense_LINEARSLIDER_SNS1_RAW0_VALUE               (capsense_dsRam.snsList.linearslider[1u].raw[0u])
#define capsense_LINEARSLIDER_SNS1_RAW0_OFFSET              (138u)
#define capsense_LINEARSLIDER_SNS1_RAW0_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS1_RAW0_PARAM_ID            (0x8A00008Au)

#define capsense_LINEARSLIDER_SNS1_BSLN0_VALUE              (capsense_dsRam.snsList.linearslider[1u].bsln[0u])
#define capsense_LINEARSLIDER_SNS1_BSLN0_OFFSET             (140u)
#define capsense_LINEARSLIDER_SNS1_BSLN0_SIZE               (2u)
#define capsense_LINEARSLIDER_SNS1_BSLN0_PARAM_ID           (0x8700008Cu)

#define capsense_LINEARSLIDER_SNS1_BSLN_EXT0_VALUE          (capsense_dsRam.snsList.linearslider[1u].bslnExt[0u])
#define capsense_LINEARSLIDER_SNS1_BSLN_EXT0_OFFSET         (142u)
#define capsense_LINEARSLIDER_SNS1_BSLN_EXT0_SIZE           (1u)
#define capsense_LINEARSLIDER_SNS1_BSLN_EXT0_PARAM_ID       (0x4300008Eu)

#define capsense_LINEARSLIDER_SNS1_DIFF_VALUE               (capsense_dsRam.snsList.linearslider[1u].diff)
#define capsense_LINEARSLIDER_SNS1_DIFF_OFFSET              (144u)
#define capsense_LINEARSLIDER_SNS1_DIFF_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS1_DIFF_PARAM_ID            (0x81000090u)

#define capsense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_VALUE  (capsense_dsRam.snsList.linearslider[1u].negBslnRstCnt[0u])
#define capsense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_OFFSET (146u)
#define capsense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define capsense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_PARAM_ID (0x45000092u)

#define capsense_LINEARSLIDER_SNS1_IDAC_COMP0_VALUE         (capsense_dsRam.snsList.linearslider[1u].idacComp[0u])
#define capsense_LINEARSLIDER_SNS1_IDAC_COMP0_OFFSET        (147u)
#define capsense_LINEARSLIDER_SNS1_IDAC_COMP0_SIZE          (1u)
#define capsense_LINEARSLIDER_SNS1_IDAC_COMP0_PARAM_ID      (0x43000093u)

#define capsense_LINEARSLIDER_SNS2_RAW0_VALUE               (capsense_dsRam.snsList.linearslider[2u].raw[0u])
#define capsense_LINEARSLIDER_SNS2_RAW0_OFFSET              (148u)
#define capsense_LINEARSLIDER_SNS2_RAW0_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS2_RAW0_PARAM_ID            (0x80000094u)

#define capsense_LINEARSLIDER_SNS2_BSLN0_VALUE              (capsense_dsRam.snsList.linearslider[2u].bsln[0u])
#define capsense_LINEARSLIDER_SNS2_BSLN0_OFFSET             (150u)
#define capsense_LINEARSLIDER_SNS2_BSLN0_SIZE               (2u)
#define capsense_LINEARSLIDER_SNS2_BSLN0_PARAM_ID           (0x8C000096u)

#define capsense_LINEARSLIDER_SNS2_BSLN_EXT0_VALUE          (capsense_dsRam.snsList.linearslider[2u].bslnExt[0u])
#define capsense_LINEARSLIDER_SNS2_BSLN_EXT0_OFFSET         (152u)
#define capsense_LINEARSLIDER_SNS2_BSLN_EXT0_SIZE           (1u)
#define capsense_LINEARSLIDER_SNS2_BSLN_EXT0_PARAM_ID       (0x4B000098u)

#define capsense_LINEARSLIDER_SNS2_DIFF_VALUE               (capsense_dsRam.snsList.linearslider[2u].diff)
#define capsense_LINEARSLIDER_SNS2_DIFF_OFFSET              (154u)
#define capsense_LINEARSLIDER_SNS2_DIFF_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS2_DIFF_PARAM_ID            (0x8F00009Au)

#define capsense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_VALUE  (capsense_dsRam.snsList.linearslider[2u].negBslnRstCnt[0u])
#define capsense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_OFFSET (156u)
#define capsense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define capsense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_PARAM_ID (0x4A00009Cu)

#define capsense_LINEARSLIDER_SNS2_IDAC_COMP0_VALUE         (capsense_dsRam.snsList.linearslider[2u].idacComp[0u])
#define capsense_LINEARSLIDER_SNS2_IDAC_COMP0_OFFSET        (157u)
#define capsense_LINEARSLIDER_SNS2_IDAC_COMP0_SIZE          (1u)
#define capsense_LINEARSLIDER_SNS2_IDAC_COMP0_PARAM_ID      (0x4C00009Du)

#define capsense_LINEARSLIDER_SNS3_RAW0_VALUE               (capsense_dsRam.snsList.linearslider[3u].raw[0u])
#define capsense_LINEARSLIDER_SNS3_RAW0_OFFSET              (158u)
#define capsense_LINEARSLIDER_SNS3_RAW0_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS3_RAW0_PARAM_ID            (0x8E00009Eu)

#define capsense_LINEARSLIDER_SNS3_BSLN0_VALUE              (capsense_dsRam.snsList.linearslider[3u].bsln[0u])
#define capsense_LINEARSLIDER_SNS3_BSLN0_OFFSET             (160u)
#define capsense_LINEARSLIDER_SNS3_BSLN0_SIZE               (2u)
#define capsense_LINEARSLIDER_SNS3_BSLN0_PARAM_ID           (0x8E0000A0u)

#define capsense_LINEARSLIDER_SNS3_BSLN_EXT0_VALUE          (capsense_dsRam.snsList.linearslider[3u].bslnExt[0u])
#define capsense_LINEARSLIDER_SNS3_BSLN_EXT0_OFFSET         (162u)
#define capsense_LINEARSLIDER_SNS3_BSLN_EXT0_SIZE           (1u)
#define capsense_LINEARSLIDER_SNS3_BSLN_EXT0_PARAM_ID       (0x4A0000A2u)

#define capsense_LINEARSLIDER_SNS3_DIFF_VALUE               (capsense_dsRam.snsList.linearslider[3u].diff)
#define capsense_LINEARSLIDER_SNS3_DIFF_OFFSET              (164u)
#define capsense_LINEARSLIDER_SNS3_DIFF_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS3_DIFF_PARAM_ID            (0x8F0000A4u)

#define capsense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_VALUE  (capsense_dsRam.snsList.linearslider[3u].negBslnRstCnt[0u])
#define capsense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_OFFSET (166u)
#define capsense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define capsense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_PARAM_ID (0x4B0000A6u)

#define capsense_LINEARSLIDER_SNS3_IDAC_COMP0_VALUE         (capsense_dsRam.snsList.linearslider[3u].idacComp[0u])
#define capsense_LINEARSLIDER_SNS3_IDAC_COMP0_OFFSET        (167u)
#define capsense_LINEARSLIDER_SNS3_IDAC_COMP0_SIZE          (1u)
#define capsense_LINEARSLIDER_SNS3_IDAC_COMP0_PARAM_ID      (0x4D0000A7u)

#define capsense_LINEARSLIDER_SNS4_RAW0_VALUE               (capsense_dsRam.snsList.linearslider[4u].raw[0u])
#define capsense_LINEARSLIDER_SNS4_RAW0_OFFSET              (168u)
#define capsense_LINEARSLIDER_SNS4_RAW0_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS4_RAW0_PARAM_ID            (0x8C0000A8u)

#define capsense_LINEARSLIDER_SNS4_BSLN0_VALUE              (capsense_dsRam.snsList.linearslider[4u].bsln[0u])
#define capsense_LINEARSLIDER_SNS4_BSLN0_OFFSET             (170u)
#define capsense_LINEARSLIDER_SNS4_BSLN0_SIZE               (2u)
#define capsense_LINEARSLIDER_SNS4_BSLN0_PARAM_ID           (0x800000AAu)

#define capsense_LINEARSLIDER_SNS4_BSLN_EXT0_VALUE          (capsense_dsRam.snsList.linearslider[4u].bslnExt[0u])
#define capsense_LINEARSLIDER_SNS4_BSLN_EXT0_OFFSET         (172u)
#define capsense_LINEARSLIDER_SNS4_BSLN_EXT0_SIZE           (1u)
#define capsense_LINEARSLIDER_SNS4_BSLN_EXT0_PARAM_ID       (0x450000ACu)

#define capsense_LINEARSLIDER_SNS4_DIFF_VALUE               (capsense_dsRam.snsList.linearslider[4u].diff)
#define capsense_LINEARSLIDER_SNS4_DIFF_OFFSET              (174u)
#define capsense_LINEARSLIDER_SNS4_DIFF_SIZE                (2u)
#define capsense_LINEARSLIDER_SNS4_DIFF_PARAM_ID            (0x810000AEu)

#define capsense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_VALUE  (capsense_dsRam.snsList.linearslider[4u].negBslnRstCnt[0u])
#define capsense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_OFFSET (176u)
#define capsense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define capsense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_PARAM_ID (0x430000B0u)

#define capsense_LINEARSLIDER_SNS4_IDAC_COMP0_VALUE         (capsense_dsRam.snsList.linearslider[4u].idacComp[0u])
#define capsense_LINEARSLIDER_SNS4_IDAC_COMP0_OFFSET        (177u)
#define capsense_LINEARSLIDER_SNS4_IDAC_COMP0_SIZE          (1u)
#define capsense_LINEARSLIDER_SNS4_IDAC_COMP0_PARAM_ID      (0x450000B1u)

#define capsense_SNR_TEST_WIDGET_ID_VALUE                   (capsense_dsRam.snrTestWidgetId)
#define capsense_SNR_TEST_WIDGET_ID_OFFSET                  (178u)
#define capsense_SNR_TEST_WIDGET_ID_SIZE                    (1u)
#define capsense_SNR_TEST_WIDGET_ID_PARAM_ID                (0x640000B2u)

#define capsense_SNR_TEST_SENSOR_ID_VALUE                   (capsense_dsRam.snrTestSensorId)
#define capsense_SNR_TEST_SENSOR_ID_OFFSET                  (179u)
#define capsense_SNR_TEST_SENSOR_ID_SIZE                    (1u)
#define capsense_SNR_TEST_SENSOR_ID_PARAM_ID                (0x620000B3u)

#define capsense_SNR_TEST_SCAN_COUNTER_VALUE                (capsense_dsRam.snrTestScanCounter)
#define capsense_SNR_TEST_SCAN_COUNTER_OFFSET               (180u)
#define capsense_SNR_TEST_SCAN_COUNTER_SIZE                 (2u)
#define capsense_SNR_TEST_SCAN_COUNTER_PARAM_ID             (0x8A0000B4u)

#define capsense_SNR_TEST_RAW_COUNT0_VALUE                  (capsense_dsRam.snrTestRawCount[0u])
#define capsense_SNR_TEST_RAW_COUNT0_OFFSET                 (182u)
#define capsense_SNR_TEST_RAW_COUNT0_SIZE                   (2u)
#define capsense_SNR_TEST_RAW_COUNT0_PARAM_ID               (0x860000B6u)

#define capsense_SCAN_CSD_ISC_VALUE                         (capsense_dsRam.scanCsdISC)
#define capsense_SCAN_CSD_ISC_OFFSET                        (184u)
#define capsense_SCAN_CSD_ISC_SIZE                          (1u)
#define capsense_SCAN_CSD_ISC_PARAM_ID                      (0x410000B8u)

#define capsense_SCAN_CSX_ISC_VALUE                         (capsense_dsRam.scanCsxISC)
#define capsense_SCAN_CSX_ISC_OFFSET                        (185u)
#define capsense_SCAN_CSX_ISC_SIZE                          (1u)
#define capsense_SCAN_CSX_ISC_PARAM_ID                      (0x470000B9u)

#define capsense_SCAN_CURRENT_ISC_VALUE                     (capsense_dsRam.scanCurrentISC)
#define capsense_SCAN_CURRENT_ISC_OFFSET                    (186u)
#define capsense_SCAN_CURRENT_ISC_SIZE                      (1u)
#define capsense_SCAN_CURRENT_ISC_PARAM_ID                  (0x4D0000BAu)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define capsense_BTN0_PTR2SNS_FLASH_VALUE                   (capsense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define capsense_BTN0_PTR2SNS_FLASH_OFFSET                  (0u)
#define capsense_BTN0_PTR2SNS_FLASH_SIZE                    (4u)
#define capsense_BTN0_PTR2SNS_FLASH_PARAM_ID                (0xD1000000u)

#define capsense_BTN0_PTR2WD_RAM_VALUE                      (capsense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define capsense_BTN0_PTR2WD_RAM_OFFSET                     (4u)
#define capsense_BTN0_PTR2WD_RAM_SIZE                       (4u)
#define capsense_BTN0_PTR2WD_RAM_PARAM_ID                   (0xD0000004u)

#define capsense_BTN0_PTR2SNS_RAM_VALUE                     (capsense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define capsense_BTN0_PTR2SNS_RAM_OFFSET                    (8u)
#define capsense_BTN0_PTR2SNS_RAM_SIZE                      (4u)
#define capsense_BTN0_PTR2SNS_RAM_PARAM_ID                  (0xD3000008u)

#define capsense_BTN0_PTR2FLTR_HISTORY_VALUE                (capsense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define capsense_BTN0_PTR2FLTR_HISTORY_OFFSET               (12u)
#define capsense_BTN0_PTR2FLTR_HISTORY_SIZE                 (4u)
#define capsense_BTN0_PTR2FLTR_HISTORY_PARAM_ID             (0xD200000Cu)

#define capsense_BTN0_PTR2DEBOUNCE_VALUE                    (capsense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define capsense_BTN0_PTR2DEBOUNCE_OFFSET                   (16u)
#define capsense_BTN0_PTR2DEBOUNCE_SIZE                     (4u)
#define capsense_BTN0_PTR2DEBOUNCE_PARAM_ID                 (0xD4000010u)

#define capsense_BTN0_STATIC_CONFIG_VALUE                   (capsense_dsFlash.wdgtArray[0].staticConfig)
#define capsense_BTN0_STATIC_CONFIG_OFFSET                  (20u)
#define capsense_BTN0_STATIC_CONFIG_SIZE                    (4u)
#define capsense_BTN0_STATIC_CONFIG_PARAM_ID                (0xD5000014u)

#define capsense_BTN0_TOTAL_NUM_SNS_VALUE                   (capsense_dsFlash.wdgtArray[0].totalNumSns)
#define capsense_BTN0_TOTAL_NUM_SNS_OFFSET                  (24u)
#define capsense_BTN0_TOTAL_NUM_SNS_SIZE                    (2u)
#define capsense_BTN0_TOTAL_NUM_SNS_PARAM_ID                (0x99000018u)

#define capsense_BTN0_TYPE_VALUE                            (capsense_dsFlash.wdgtArray[0].wdgtType)
#define capsense_BTN0_TYPE_OFFSET                           (26u)
#define capsense_BTN0_TYPE_SIZE                             (1u)
#define capsense_BTN0_TYPE_PARAM_ID                         (0x5D00001Au)

#define capsense_BTN0_SENSE_METHOD_VALUE                    (capsense_dsFlash.wdgtArray[0].senseMethod)
#define capsense_BTN0_SENSE_METHOD_OFFSET                   (27u)
#define capsense_BTN0_SENSE_METHOD_SIZE                     (1u)
#define capsense_BTN0_SENSE_METHOD_PARAM_ID                 (0x5B00001Bu)

#define capsense_BTN0_NUM_COLS_VALUE                        (capsense_dsFlash.wdgtArray[0].numCols)
#define capsense_BTN0_NUM_COLS_OFFSET                       (28u)
#define capsense_BTN0_NUM_COLS_SIZE                         (1u)
#define capsense_BTN0_NUM_COLS_PARAM_ID                     (0x5000001Cu)

#define capsense_BTN0_NUM_ROWS_VALUE                        (capsense_dsFlash.wdgtArray[0].numRows)
#define capsense_BTN0_NUM_ROWS_OFFSET                       (29u)
#define capsense_BTN0_NUM_ROWS_SIZE                         (1u)
#define capsense_BTN0_NUM_ROWS_PARAM_ID                     (0x5600001Du)

#define capsense_BTN0_X_RESOLUTION_VALUE                    (capsense_dsFlash.wdgtArray[0].xResolution)
#define capsense_BTN0_X_RESOLUTION_OFFSET                   (30u)
#define capsense_BTN0_X_RESOLUTION_SIZE                     (2u)
#define capsense_BTN0_X_RESOLUTION_PARAM_ID                 (0x9400001Eu)

#define capsense_BTN0_X_CENT_MULT_VALUE                     (capsense_dsFlash.wdgtArray[0].xCentroidMultiplier)
#define capsense_BTN0_X_CENT_MULT_OFFSET                    (32u)
#define capsense_BTN0_X_CENT_MULT_SIZE                      (4u)
#define capsense_BTN0_X_CENT_MULT_PARAM_ID                  (0xDB000020u)

#define capsense_BTN0_IIR_FILTER_COEFF_VALUE                (capsense_dsFlash.wdgtArray[0].iirFilterCoeff)
#define capsense_BTN0_IIR_FILTER_COEFF_OFFSET               (36u)
#define capsense_BTN0_IIR_FILTER_COEFF_SIZE                 (1u)
#define capsense_BTN0_IIR_FILTER_COEFF_PARAM_ID             (0x5D000024u)

#define capsense_BTN1_PTR2SNS_FLASH_VALUE                   (capsense_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define capsense_BTN1_PTR2SNS_FLASH_OFFSET                  (40u)
#define capsense_BTN1_PTR2SNS_FLASH_SIZE                    (4u)
#define capsense_BTN1_PTR2SNS_FLASH_PARAM_ID                (0xDA010028u)

#define capsense_BTN1_PTR2WD_RAM_VALUE                      (capsense_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define capsense_BTN1_PTR2WD_RAM_OFFSET                     (44u)
#define capsense_BTN1_PTR2WD_RAM_SIZE                       (4u)
#define capsense_BTN1_PTR2WD_RAM_PARAM_ID                   (0xDB01002Cu)

#define capsense_BTN1_PTR2SNS_RAM_VALUE                     (capsense_dsFlash.wdgtArray[1].ptr2SnsRam)
#define capsense_BTN1_PTR2SNS_RAM_OFFSET                    (48u)
#define capsense_BTN1_PTR2SNS_RAM_SIZE                      (4u)
#define capsense_BTN1_PTR2SNS_RAM_PARAM_ID                  (0xDD010030u)

#define capsense_BTN1_PTR2FLTR_HISTORY_VALUE                (capsense_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define capsense_BTN1_PTR2FLTR_HISTORY_OFFSET               (52u)
#define capsense_BTN1_PTR2FLTR_HISTORY_SIZE                 (4u)
#define capsense_BTN1_PTR2FLTR_HISTORY_PARAM_ID             (0xDC010034u)

#define capsense_BTN1_PTR2DEBOUNCE_VALUE                    (capsense_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define capsense_BTN1_PTR2DEBOUNCE_OFFSET                   (56u)
#define capsense_BTN1_PTR2DEBOUNCE_SIZE                     (4u)
#define capsense_BTN1_PTR2DEBOUNCE_PARAM_ID                 (0xDF010038u)

#define capsense_BTN1_STATIC_CONFIG_VALUE                   (capsense_dsFlash.wdgtArray[1].staticConfig)
#define capsense_BTN1_STATIC_CONFIG_OFFSET                  (60u)
#define capsense_BTN1_STATIC_CONFIG_SIZE                    (4u)
#define capsense_BTN1_STATIC_CONFIG_PARAM_ID                (0xDE01003Cu)

#define capsense_BTN1_TOTAL_NUM_SNS_VALUE                   (capsense_dsFlash.wdgtArray[1].totalNumSns)
#define capsense_BTN1_TOTAL_NUM_SNS_OFFSET                  (64u)
#define capsense_BTN1_TOTAL_NUM_SNS_SIZE                    (2u)
#define capsense_BTN1_TOTAL_NUM_SNS_PARAM_ID                (0x90010040u)

#define capsense_BTN1_TYPE_VALUE                            (capsense_dsFlash.wdgtArray[1].wdgtType)
#define capsense_BTN1_TYPE_OFFSET                           (66u)
#define capsense_BTN1_TYPE_SIZE                             (1u)
#define capsense_BTN1_TYPE_PARAM_ID                         (0x54010042u)

#define capsense_BTN1_SENSE_METHOD_VALUE                    (capsense_dsFlash.wdgtArray[1].senseMethod)
#define capsense_BTN1_SENSE_METHOD_OFFSET                   (67u)
#define capsense_BTN1_SENSE_METHOD_SIZE                     (1u)
#define capsense_BTN1_SENSE_METHOD_PARAM_ID                 (0x52010043u)

#define capsense_BTN1_NUM_COLS_VALUE                        (capsense_dsFlash.wdgtArray[1].numCols)
#define capsense_BTN1_NUM_COLS_OFFSET                       (68u)
#define capsense_BTN1_NUM_COLS_SIZE                         (1u)
#define capsense_BTN1_NUM_COLS_PARAM_ID                     (0x59010044u)

#define capsense_BTN1_NUM_ROWS_VALUE                        (capsense_dsFlash.wdgtArray[1].numRows)
#define capsense_BTN1_NUM_ROWS_OFFSET                       (69u)
#define capsense_BTN1_NUM_ROWS_SIZE                         (1u)
#define capsense_BTN1_NUM_ROWS_PARAM_ID                     (0x5F010045u)

#define capsense_BTN1_X_RESOLUTION_VALUE                    (capsense_dsFlash.wdgtArray[1].xResolution)
#define capsense_BTN1_X_RESOLUTION_OFFSET                   (70u)
#define capsense_BTN1_X_RESOLUTION_SIZE                     (2u)
#define capsense_BTN1_X_RESOLUTION_PARAM_ID                 (0x9D010046u)

#define capsense_BTN1_X_CENT_MULT_VALUE                     (capsense_dsFlash.wdgtArray[1].xCentroidMultiplier)
#define capsense_BTN1_X_CENT_MULT_OFFSET                    (72u)
#define capsense_BTN1_X_CENT_MULT_SIZE                      (4u)
#define capsense_BTN1_X_CENT_MULT_PARAM_ID                  (0xDD010048u)

#define capsense_BTN1_IIR_FILTER_COEFF_VALUE                (capsense_dsFlash.wdgtArray[1].iirFilterCoeff)
#define capsense_BTN1_IIR_FILTER_COEFF_OFFSET               (76u)
#define capsense_BTN1_IIR_FILTER_COEFF_SIZE                 (1u)
#define capsense_BTN1_IIR_FILTER_COEFF_PARAM_ID             (0x5B01004Cu)

#define capsense_BTN2_PTR2SNS_FLASH_VALUE                   (capsense_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define capsense_BTN2_PTR2SNS_FLASH_OFFSET                  (80u)
#define capsense_BTN2_PTR2SNS_FLASH_SIZE                    (4u)
#define capsense_BTN2_PTR2SNS_FLASH_PARAM_ID                (0xDF020050u)

#define capsense_BTN2_PTR2WD_RAM_VALUE                      (capsense_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define capsense_BTN2_PTR2WD_RAM_OFFSET                     (84u)
#define capsense_BTN2_PTR2WD_RAM_SIZE                       (4u)
#define capsense_BTN2_PTR2WD_RAM_PARAM_ID                   (0xDE020054u)

#define capsense_BTN2_PTR2SNS_RAM_VALUE                     (capsense_dsFlash.wdgtArray[2].ptr2SnsRam)
#define capsense_BTN2_PTR2SNS_RAM_OFFSET                    (88u)
#define capsense_BTN2_PTR2SNS_RAM_SIZE                      (4u)
#define capsense_BTN2_PTR2SNS_RAM_PARAM_ID                  (0xDD020058u)

#define capsense_BTN2_PTR2FLTR_HISTORY_VALUE                (capsense_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define capsense_BTN2_PTR2FLTR_HISTORY_OFFSET               (92u)
#define capsense_BTN2_PTR2FLTR_HISTORY_SIZE                 (4u)
#define capsense_BTN2_PTR2FLTR_HISTORY_PARAM_ID             (0xDC02005Cu)

#define capsense_BTN2_PTR2DEBOUNCE_VALUE                    (capsense_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define capsense_BTN2_PTR2DEBOUNCE_OFFSET                   (96u)
#define capsense_BTN2_PTR2DEBOUNCE_SIZE                     (4u)
#define capsense_BTN2_PTR2DEBOUNCE_PARAM_ID                 (0xD0020060u)

#define capsense_BTN2_STATIC_CONFIG_VALUE                   (capsense_dsFlash.wdgtArray[2].staticConfig)
#define capsense_BTN2_STATIC_CONFIG_OFFSET                  (100u)
#define capsense_BTN2_STATIC_CONFIG_SIZE                    (4u)
#define capsense_BTN2_STATIC_CONFIG_PARAM_ID                (0xD1020064u)

#define capsense_BTN2_TOTAL_NUM_SNS_VALUE                   (capsense_dsFlash.wdgtArray[2].totalNumSns)
#define capsense_BTN2_TOTAL_NUM_SNS_OFFSET                  (104u)
#define capsense_BTN2_TOTAL_NUM_SNS_SIZE                    (2u)
#define capsense_BTN2_TOTAL_NUM_SNS_PARAM_ID                (0x9D020068u)

#define capsense_BTN2_TYPE_VALUE                            (capsense_dsFlash.wdgtArray[2].wdgtType)
#define capsense_BTN2_TYPE_OFFSET                           (106u)
#define capsense_BTN2_TYPE_SIZE                             (1u)
#define capsense_BTN2_TYPE_PARAM_ID                         (0x5902006Au)

#define capsense_BTN2_SENSE_METHOD_VALUE                    (capsense_dsFlash.wdgtArray[2].senseMethod)
#define capsense_BTN2_SENSE_METHOD_OFFSET                   (107u)
#define capsense_BTN2_SENSE_METHOD_SIZE                     (1u)
#define capsense_BTN2_SENSE_METHOD_PARAM_ID                 (0x5F02006Bu)

#define capsense_BTN2_NUM_COLS_VALUE                        (capsense_dsFlash.wdgtArray[2].numCols)
#define capsense_BTN2_NUM_COLS_OFFSET                       (108u)
#define capsense_BTN2_NUM_COLS_SIZE                         (1u)
#define capsense_BTN2_NUM_COLS_PARAM_ID                     (0x5402006Cu)

#define capsense_BTN2_NUM_ROWS_VALUE                        (capsense_dsFlash.wdgtArray[2].numRows)
#define capsense_BTN2_NUM_ROWS_OFFSET                       (109u)
#define capsense_BTN2_NUM_ROWS_SIZE                         (1u)
#define capsense_BTN2_NUM_ROWS_PARAM_ID                     (0x5202006Du)

#define capsense_BTN2_X_RESOLUTION_VALUE                    (capsense_dsFlash.wdgtArray[2].xResolution)
#define capsense_BTN2_X_RESOLUTION_OFFSET                   (110u)
#define capsense_BTN2_X_RESOLUTION_SIZE                     (2u)
#define capsense_BTN2_X_RESOLUTION_PARAM_ID                 (0x9002006Eu)

#define capsense_BTN2_X_CENT_MULT_VALUE                     (capsense_dsFlash.wdgtArray[2].xCentroidMultiplier)
#define capsense_BTN2_X_CENT_MULT_OFFSET                    (112u)
#define capsense_BTN2_X_CENT_MULT_SIZE                      (4u)
#define capsense_BTN2_X_CENT_MULT_PARAM_ID                  (0xD5020070u)

#define capsense_BTN2_IIR_FILTER_COEFF_VALUE                (capsense_dsFlash.wdgtArray[2].iirFilterCoeff)
#define capsense_BTN2_IIR_FILTER_COEFF_OFFSET               (116u)
#define capsense_BTN2_IIR_FILTER_COEFF_SIZE                 (1u)
#define capsense_BTN2_IIR_FILTER_COEFF_PARAM_ID             (0x53020074u)

#define capsense_LINEARSLIDER_PTR2SNS_FLASH_VALUE           (capsense_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define capsense_LINEARSLIDER_PTR2SNS_FLASH_OFFSET          (120u)
#define capsense_LINEARSLIDER_PTR2SNS_FLASH_SIZE            (4u)
#define capsense_LINEARSLIDER_PTR2SNS_FLASH_PARAM_ID        (0xD4030078u)

#define capsense_LINEARSLIDER_PTR2WD_RAM_VALUE              (capsense_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define capsense_LINEARSLIDER_PTR2WD_RAM_OFFSET             (124u)
#define capsense_LINEARSLIDER_PTR2WD_RAM_SIZE               (4u)
#define capsense_LINEARSLIDER_PTR2WD_RAM_PARAM_ID           (0xD503007Cu)

#define capsense_LINEARSLIDER_PTR2SNS_RAM_VALUE             (capsense_dsFlash.wdgtArray[3].ptr2SnsRam)
#define capsense_LINEARSLIDER_PTR2SNS_RAM_OFFSET            (128u)
#define capsense_LINEARSLIDER_PTR2SNS_RAM_SIZE              (4u)
#define capsense_LINEARSLIDER_PTR2SNS_RAM_PARAM_ID          (0xD7030080u)

#define capsense_LINEARSLIDER_PTR2FLTR_HISTORY_VALUE        (capsense_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define capsense_LINEARSLIDER_PTR2FLTR_HISTORY_OFFSET       (132u)
#define capsense_LINEARSLIDER_PTR2FLTR_HISTORY_SIZE         (4u)
#define capsense_LINEARSLIDER_PTR2FLTR_HISTORY_PARAM_ID     (0xD6030084u)

#define capsense_LINEARSLIDER_PTR2DEBOUNCE_VALUE            (capsense_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define capsense_LINEARSLIDER_PTR2DEBOUNCE_OFFSET           (136u)
#define capsense_LINEARSLIDER_PTR2DEBOUNCE_SIZE             (4u)
#define capsense_LINEARSLIDER_PTR2DEBOUNCE_PARAM_ID         (0xD5030088u)

#define capsense_LINEARSLIDER_STATIC_CONFIG_VALUE           (capsense_dsFlash.wdgtArray[3].staticConfig)
#define capsense_LINEARSLIDER_STATIC_CONFIG_OFFSET          (140u)
#define capsense_LINEARSLIDER_STATIC_CONFIG_SIZE            (4u)
#define capsense_LINEARSLIDER_STATIC_CONFIG_PARAM_ID        (0xD403008Cu)

#define capsense_LINEARSLIDER_TOTAL_NUM_SNS_VALUE           (capsense_dsFlash.wdgtArray[3].totalNumSns)
#define capsense_LINEARSLIDER_TOTAL_NUM_SNS_OFFSET          (144u)
#define capsense_LINEARSLIDER_TOTAL_NUM_SNS_SIZE            (2u)
#define capsense_LINEARSLIDER_TOTAL_NUM_SNS_PARAM_ID        (0x9D030090u)

#define capsense_LINEARSLIDER_TYPE_VALUE                    (capsense_dsFlash.wdgtArray[3].wdgtType)
#define capsense_LINEARSLIDER_TYPE_OFFSET                   (146u)
#define capsense_LINEARSLIDER_TYPE_SIZE                     (1u)
#define capsense_LINEARSLIDER_TYPE_PARAM_ID                 (0x59030092u)

#define capsense_LINEARSLIDER_SENSE_METHOD_VALUE            (capsense_dsFlash.wdgtArray[3].senseMethod)
#define capsense_LINEARSLIDER_SENSE_METHOD_OFFSET           (147u)
#define capsense_LINEARSLIDER_SENSE_METHOD_SIZE             (1u)
#define capsense_LINEARSLIDER_SENSE_METHOD_PARAM_ID         (0x5F030093u)

#define capsense_LINEARSLIDER_NUM_COLS_VALUE                (capsense_dsFlash.wdgtArray[3].numCols)
#define capsense_LINEARSLIDER_NUM_COLS_OFFSET               (148u)
#define capsense_LINEARSLIDER_NUM_COLS_SIZE                 (1u)
#define capsense_LINEARSLIDER_NUM_COLS_PARAM_ID             (0x54030094u)

#define capsense_LINEARSLIDER_NUM_ROWS_VALUE                (capsense_dsFlash.wdgtArray[3].numRows)
#define capsense_LINEARSLIDER_NUM_ROWS_OFFSET               (149u)
#define capsense_LINEARSLIDER_NUM_ROWS_SIZE                 (1u)
#define capsense_LINEARSLIDER_NUM_ROWS_PARAM_ID             (0x52030095u)

#define capsense_LINEARSLIDER_X_RESOLUTION_VALUE            (capsense_dsFlash.wdgtArray[3].xResolution)
#define capsense_LINEARSLIDER_X_RESOLUTION_OFFSET           (150u)
#define capsense_LINEARSLIDER_X_RESOLUTION_SIZE             (2u)
#define capsense_LINEARSLIDER_X_RESOLUTION_PARAM_ID         (0x90030096u)

#define capsense_LINEARSLIDER_X_CENT_MULT_VALUE             (capsense_dsFlash.wdgtArray[3].xCentroidMultiplier)
#define capsense_LINEARSLIDER_X_CENT_MULT_OFFSET            (152u)
#define capsense_LINEARSLIDER_X_CENT_MULT_SIZE              (4u)
#define capsense_LINEARSLIDER_X_CENT_MULT_PARAM_ID          (0xD0030098u)

#define capsense_LINEARSLIDER_IIR_FILTER_COEFF_VALUE        (capsense_dsFlash.wdgtArray[3].iirFilterCoeff)
#define capsense_LINEARSLIDER_IIR_FILTER_COEFF_OFFSET       (156u)
#define capsense_LINEARSLIDER_IIR_FILTER_COEFF_SIZE         (1u)
#define capsense_LINEARSLIDER_IIR_FILTER_COEFF_PARAM_ID     (0x5603009Cu)


#endif /* End CY_SENSE_capsense_REGISTER_MAP_H */


/* [] END OF FILE */
