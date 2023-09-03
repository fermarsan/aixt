/***************************************************************************//**
* \file CapSense_RegisterMap.h
* \version 7.10
*
* \brief
*   This file provides the definitions for the Component data structure register.
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

#if !defined(CY_SENSE_CapSense_REGISTER_MAP_H)
#define CY_SENSE_CapSense_REGISTER_MAP_H

#include <cytypes.h>
#include "CapSense_Configuration.h"
#include "CapSense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define CapSense_CONFIG_ID_VALUE                            (CapSense_dsRam.configId)
#define CapSense_CONFIG_ID_OFFSET                           (0u)
#define CapSense_CONFIG_ID_SIZE                             (2u)
#define CapSense_CONFIG_ID_PARAM_ID                         (0x87000000u)

#define CapSense_DEVICE_ID_VALUE                            (CapSense_dsRam.deviceId)
#define CapSense_DEVICE_ID_OFFSET                           (2u)
#define CapSense_DEVICE_ID_SIZE                             (2u)
#define CapSense_DEVICE_ID_PARAM_ID                         (0x8B000002u)

#define CapSense_HW_CLOCK_VALUE                             (CapSense_dsRam.hwClock)
#define CapSense_HW_CLOCK_OFFSET                            (4u)
#define CapSense_HW_CLOCK_SIZE                              (2u)
#define CapSense_HW_CLOCK_PARAM_ID                          (0x86000004u)

#define CapSense_TUNER_CMD_VALUE                            (CapSense_dsRam.tunerCmd)
#define CapSense_TUNER_CMD_OFFSET                           (6u)
#define CapSense_TUNER_CMD_SIZE                             (2u)
#define CapSense_TUNER_CMD_PARAM_ID                         (0xA1000006u)

#define CapSense_SCAN_COUNTER_VALUE                         (CapSense_dsRam.scanCounter)
#define CapSense_SCAN_COUNTER_OFFSET                        (8u)
#define CapSense_SCAN_COUNTER_SIZE                          (2u)
#define CapSense_SCAN_COUNTER_PARAM_ID                      (0x85000008u)

#define CapSense_STATUS_VALUE                               (CapSense_dsRam.status)
#define CapSense_STATUS_OFFSET                              (12u)
#define CapSense_STATUS_SIZE                                (4u)
#define CapSense_STATUS_PARAM_ID                            (0xCB00000Cu)

#define CapSense_WDGT_ENABLE0_VALUE                         (CapSense_dsRam.wdgtEnable[0u])
#define CapSense_WDGT_ENABLE0_OFFSET                        (16u)
#define CapSense_WDGT_ENABLE0_SIZE                          (4u)
#define CapSense_WDGT_ENABLE0_PARAM_ID                      (0xE6000010u)

#define CapSense_WDGT_STATUS0_VALUE                         (CapSense_dsRam.wdgtStatus[0u])
#define CapSense_WDGT_STATUS0_OFFSET                        (20u)
#define CapSense_WDGT_STATUS0_SIZE                          (4u)
#define CapSense_WDGT_STATUS0_PARAM_ID                      (0xCC000014u)

#define CapSense_SNS_STATUS0_VALUE                          (CapSense_dsRam.snsStatus[0u])
#define CapSense_SNS_STATUS0_OFFSET                         (24u)
#define CapSense_SNS_STATUS0_SIZE                           (1u)
#define CapSense_SNS_STATUS0_PARAM_ID                       (0x48000018u)

#define CapSense_SNS_STATUS1_VALUE                          (CapSense_dsRam.snsStatus[1u])
#define CapSense_SNS_STATUS1_OFFSET                         (25u)
#define CapSense_SNS_STATUS1_SIZE                           (1u)
#define CapSense_SNS_STATUS1_PARAM_ID                       (0x4E000019u)

#define CapSense_SNS_STATUS2_VALUE                          (CapSense_dsRam.snsStatus[2u])
#define CapSense_SNS_STATUS2_OFFSET                         (26u)
#define CapSense_SNS_STATUS2_SIZE                           (1u)
#define CapSense_SNS_STATUS2_PARAM_ID                       (0x4400001Au)

#define CapSense_SNS_STATUS3_VALUE                          (CapSense_dsRam.snsStatus[3u])
#define CapSense_SNS_STATUS3_OFFSET                         (27u)
#define CapSense_SNS_STATUS3_SIZE                           (1u)
#define CapSense_SNS_STATUS3_PARAM_ID                       (0x4200001Bu)

#define CapSense_CSD0_CONFIG_VALUE                          (CapSense_dsRam.csd0Config)
#define CapSense_CSD0_CONFIG_OFFSET                         (28u)
#define CapSense_CSD0_CONFIG_SIZE                           (2u)
#define CapSense_CSD0_CONFIG_PARAM_ID                       (0xA780001Cu)

#define CapSense_MOD_CSD_CLK_VALUE                          (CapSense_dsRam.modCsdClk)
#define CapSense_MOD_CSD_CLK_OFFSET                         (30u)
#define CapSense_MOD_CSD_CLK_SIZE                           (1u)
#define CapSense_MOD_CSD_CLK_PARAM_ID                       (0x6380001Eu)

#define CapSense_MOD_CSX_CLK_VALUE                          (CapSense_dsRam.modCsxClk)
#define CapSense_MOD_CSX_CLK_OFFSET                         (31u)
#define CapSense_MOD_CSX_CLK_SIZE                           (1u)
#define CapSense_MOD_CSX_CLK_PARAM_ID                       (0x6580001Fu)

#define CapSense_BTN0_RESOLUTION_VALUE                      (CapSense_dsRam.wdgtList.btn0.resolution)
#define CapSense_BTN0_RESOLUTION_OFFSET                     (32u)
#define CapSense_BTN0_RESOLUTION_SIZE                       (2u)
#define CapSense_BTN0_RESOLUTION_PARAM_ID                   (0xAB800020u)

#define CapSense_BTN0_FINGER_TH_VALUE                       (CapSense_dsRam.wdgtList.btn0.fingerTh)
#define CapSense_BTN0_FINGER_TH_OFFSET                      (34u)
#define CapSense_BTN0_FINGER_TH_SIZE                        (2u)
#define CapSense_BTN0_FINGER_TH_PARAM_ID                    (0xA7800022u)

#define CapSense_BTN0_NOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.btn0.noiseTh)
#define CapSense_BTN0_NOISE_TH_OFFSET                       (36u)
#define CapSense_BTN0_NOISE_TH_SIZE                         (1u)
#define CapSense_BTN0_NOISE_TH_PARAM_ID                     (0x62800024u)

#define CapSense_BTN0_NNOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btn0.nNoiseTh)
#define CapSense_BTN0_NNOISE_TH_OFFSET                      (37u)
#define CapSense_BTN0_NNOISE_TH_SIZE                        (1u)
#define CapSense_BTN0_NNOISE_TH_PARAM_ID                    (0x64800025u)

#define CapSense_BTN0_HYSTERESIS_VALUE                      (CapSense_dsRam.wdgtList.btn0.hysteresis)
#define CapSense_BTN0_HYSTERESIS_OFFSET                     (38u)
#define CapSense_BTN0_HYSTERESIS_SIZE                       (1u)
#define CapSense_BTN0_HYSTERESIS_PARAM_ID                   (0x6E800026u)

#define CapSense_BTN0_ON_DEBOUNCE_VALUE                     (CapSense_dsRam.wdgtList.btn0.onDebounce)
#define CapSense_BTN0_ON_DEBOUNCE_OFFSET                    (39u)
#define CapSense_BTN0_ON_DEBOUNCE_SIZE                      (1u)
#define CapSense_BTN0_ON_DEBOUNCE_PARAM_ID                  (0x68800027u)

#define CapSense_BTN0_LOW_BSLN_RST_VALUE                    (CapSense_dsRam.wdgtList.btn0.lowBslnRst)
#define CapSense_BTN0_LOW_BSLN_RST_OFFSET                   (40u)
#define CapSense_BTN0_LOW_BSLN_RST_SIZE                     (1u)
#define CapSense_BTN0_LOW_BSLN_RST_PARAM_ID                 (0x61800028u)

#define CapSense_BTN0_IDAC_MOD0_VALUE                       (CapSense_dsRam.wdgtList.btn0.idacMod[0u])
#define CapSense_BTN0_IDAC_MOD0_OFFSET                      (41u)
#define CapSense_BTN0_IDAC_MOD0_SIZE                        (1u)
#define CapSense_BTN0_IDAC_MOD0_PARAM_ID                    (0x41000029u)

#define CapSense_BTN0_IDAC_GAIN_INDEX_VALUE                 (CapSense_dsRam.wdgtList.btn0.idacGainIndex)
#define CapSense_BTN0_IDAC_GAIN_INDEX_OFFSET                (42u)
#define CapSense_BTN0_IDAC_GAIN_INDEX_SIZE                  (1u)
#define CapSense_BTN0_IDAC_GAIN_INDEX_PARAM_ID              (0x6D80002Au)

#define CapSense_BTN0_SNS_CLK_VALUE                         (CapSense_dsRam.wdgtList.btn0.snsClk)
#define CapSense_BTN0_SNS_CLK_OFFSET                        (44u)
#define CapSense_BTN0_SNS_CLK_SIZE                          (2u)
#define CapSense_BTN0_SNS_CLK_PARAM_ID                      (0xA880002Cu)

#define CapSense_BTN0_SNS_CLK_SOURCE_VALUE                  (CapSense_dsRam.wdgtList.btn0.snsClkSource)
#define CapSense_BTN0_SNS_CLK_SOURCE_OFFSET                 (46u)
#define CapSense_BTN0_SNS_CLK_SOURCE_SIZE                   (1u)
#define CapSense_BTN0_SNS_CLK_SOURCE_PARAM_ID               (0x4780002Eu)

#define CapSense_BTN1_RESOLUTION_VALUE                      (CapSense_dsRam.wdgtList.btn1.resolution)
#define CapSense_BTN1_RESOLUTION_OFFSET                     (48u)
#define CapSense_BTN1_RESOLUTION_SIZE                       (2u)
#define CapSense_BTN1_RESOLUTION_PARAM_ID                   (0xAD810030u)

#define CapSense_BTN1_FINGER_TH_VALUE                       (CapSense_dsRam.wdgtList.btn1.fingerTh)
#define CapSense_BTN1_FINGER_TH_OFFSET                      (50u)
#define CapSense_BTN1_FINGER_TH_SIZE                        (2u)
#define CapSense_BTN1_FINGER_TH_PARAM_ID                    (0xA1810032u)

#define CapSense_BTN1_NOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.btn1.noiseTh)
#define CapSense_BTN1_NOISE_TH_OFFSET                       (52u)
#define CapSense_BTN1_NOISE_TH_SIZE                         (1u)
#define CapSense_BTN1_NOISE_TH_PARAM_ID                     (0x64810034u)

#define CapSense_BTN1_NNOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btn1.nNoiseTh)
#define CapSense_BTN1_NNOISE_TH_OFFSET                      (53u)
#define CapSense_BTN1_NNOISE_TH_SIZE                        (1u)
#define CapSense_BTN1_NNOISE_TH_PARAM_ID                    (0x62810035u)

#define CapSense_BTN1_HYSTERESIS_VALUE                      (CapSense_dsRam.wdgtList.btn1.hysteresis)
#define CapSense_BTN1_HYSTERESIS_OFFSET                     (54u)
#define CapSense_BTN1_HYSTERESIS_SIZE                       (1u)
#define CapSense_BTN1_HYSTERESIS_PARAM_ID                   (0x68810036u)

#define CapSense_BTN1_ON_DEBOUNCE_VALUE                     (CapSense_dsRam.wdgtList.btn1.onDebounce)
#define CapSense_BTN1_ON_DEBOUNCE_OFFSET                    (55u)
#define CapSense_BTN1_ON_DEBOUNCE_SIZE                      (1u)
#define CapSense_BTN1_ON_DEBOUNCE_PARAM_ID                  (0x6E810037u)

#define CapSense_BTN1_LOW_BSLN_RST_VALUE                    (CapSense_dsRam.wdgtList.btn1.lowBslnRst)
#define CapSense_BTN1_LOW_BSLN_RST_OFFSET                   (56u)
#define CapSense_BTN1_LOW_BSLN_RST_SIZE                     (1u)
#define CapSense_BTN1_LOW_BSLN_RST_PARAM_ID                 (0x67810038u)

#define CapSense_BTN1_IDAC_MOD0_VALUE                       (CapSense_dsRam.wdgtList.btn1.idacMod[0u])
#define CapSense_BTN1_IDAC_MOD0_OFFSET                      (57u)
#define CapSense_BTN1_IDAC_MOD0_SIZE                        (1u)
#define CapSense_BTN1_IDAC_MOD0_PARAM_ID                    (0x47010039u)

#define CapSense_BTN1_IDAC_GAIN_INDEX_VALUE                 (CapSense_dsRam.wdgtList.btn1.idacGainIndex)
#define CapSense_BTN1_IDAC_GAIN_INDEX_OFFSET                (58u)
#define CapSense_BTN1_IDAC_GAIN_INDEX_SIZE                  (1u)
#define CapSense_BTN1_IDAC_GAIN_INDEX_PARAM_ID              (0x6B81003Au)

#define CapSense_BTN1_SNS_CLK_VALUE                         (CapSense_dsRam.wdgtList.btn1.snsClk)
#define CapSense_BTN1_SNS_CLK_OFFSET                        (60u)
#define CapSense_BTN1_SNS_CLK_SIZE                          (2u)
#define CapSense_BTN1_SNS_CLK_PARAM_ID                      (0xAE81003Cu)

#define CapSense_BTN1_SNS_CLK_SOURCE_VALUE                  (CapSense_dsRam.wdgtList.btn1.snsClkSource)
#define CapSense_BTN1_SNS_CLK_SOURCE_OFFSET                 (62u)
#define CapSense_BTN1_SNS_CLK_SOURCE_SIZE                   (1u)
#define CapSense_BTN1_SNS_CLK_SOURCE_PARAM_ID               (0x4181003Eu)

#define CapSense_BTN2_RESOLUTION_VALUE                      (CapSense_dsRam.wdgtList.btn2.resolution)
#define CapSense_BTN2_RESOLUTION_OFFSET                     (64u)
#define CapSense_BTN2_RESOLUTION_SIZE                       (2u)
#define CapSense_BTN2_RESOLUTION_PARAM_ID                   (0xAA820040u)

#define CapSense_BTN2_FINGER_TH_VALUE                       (CapSense_dsRam.wdgtList.btn2.fingerTh)
#define CapSense_BTN2_FINGER_TH_OFFSET                      (66u)
#define CapSense_BTN2_FINGER_TH_SIZE                        (2u)
#define CapSense_BTN2_FINGER_TH_PARAM_ID                    (0xA6820042u)

#define CapSense_BTN2_NOISE_TH_VALUE                        (CapSense_dsRam.wdgtList.btn2.noiseTh)
#define CapSense_BTN2_NOISE_TH_OFFSET                       (68u)
#define CapSense_BTN2_NOISE_TH_SIZE                         (1u)
#define CapSense_BTN2_NOISE_TH_PARAM_ID                     (0x63820044u)

#define CapSense_BTN2_NNOISE_TH_VALUE                       (CapSense_dsRam.wdgtList.btn2.nNoiseTh)
#define CapSense_BTN2_NNOISE_TH_OFFSET                      (69u)
#define CapSense_BTN2_NNOISE_TH_SIZE                        (1u)
#define CapSense_BTN2_NNOISE_TH_PARAM_ID                    (0x65820045u)

#define CapSense_BTN2_HYSTERESIS_VALUE                      (CapSense_dsRam.wdgtList.btn2.hysteresis)
#define CapSense_BTN2_HYSTERESIS_OFFSET                     (70u)
#define CapSense_BTN2_HYSTERESIS_SIZE                       (1u)
#define CapSense_BTN2_HYSTERESIS_PARAM_ID                   (0x6F820046u)

#define CapSense_BTN2_ON_DEBOUNCE_VALUE                     (CapSense_dsRam.wdgtList.btn2.onDebounce)
#define CapSense_BTN2_ON_DEBOUNCE_OFFSET                    (71u)
#define CapSense_BTN2_ON_DEBOUNCE_SIZE                      (1u)
#define CapSense_BTN2_ON_DEBOUNCE_PARAM_ID                  (0x69820047u)

#define CapSense_BTN2_LOW_BSLN_RST_VALUE                    (CapSense_dsRam.wdgtList.btn2.lowBslnRst)
#define CapSense_BTN2_LOW_BSLN_RST_OFFSET                   (72u)
#define CapSense_BTN2_LOW_BSLN_RST_SIZE                     (1u)
#define CapSense_BTN2_LOW_BSLN_RST_PARAM_ID                 (0x60820048u)

#define CapSense_BTN2_IDAC_MOD0_VALUE                       (CapSense_dsRam.wdgtList.btn2.idacMod[0u])
#define CapSense_BTN2_IDAC_MOD0_OFFSET                      (73u)
#define CapSense_BTN2_IDAC_MOD0_SIZE                        (1u)
#define CapSense_BTN2_IDAC_MOD0_PARAM_ID                    (0x40020049u)

#define CapSense_BTN2_IDAC_GAIN_INDEX_VALUE                 (CapSense_dsRam.wdgtList.btn2.idacGainIndex)
#define CapSense_BTN2_IDAC_GAIN_INDEX_OFFSET                (74u)
#define CapSense_BTN2_IDAC_GAIN_INDEX_SIZE                  (1u)
#define CapSense_BTN2_IDAC_GAIN_INDEX_PARAM_ID              (0x6C82004Au)

#define CapSense_BTN2_SNS_CLK_VALUE                         (CapSense_dsRam.wdgtList.btn2.snsClk)
#define CapSense_BTN2_SNS_CLK_OFFSET                        (76u)
#define CapSense_BTN2_SNS_CLK_SIZE                          (2u)
#define CapSense_BTN2_SNS_CLK_PARAM_ID                      (0xA982004Cu)

#define CapSense_BTN2_SNS_CLK_SOURCE_VALUE                  (CapSense_dsRam.wdgtList.btn2.snsClkSource)
#define CapSense_BTN2_SNS_CLK_SOURCE_OFFSET                 (78u)
#define CapSense_BTN2_SNS_CLK_SOURCE_SIZE                   (1u)
#define CapSense_BTN2_SNS_CLK_SOURCE_PARAM_ID               (0x4682004Eu)

#define CapSense_LINEARSLIDER_RESOLUTION_VALUE              (CapSense_dsRam.wdgtList.linearslider.resolution)
#define CapSense_LINEARSLIDER_RESOLUTION_OFFSET             (80u)
#define CapSense_LINEARSLIDER_RESOLUTION_SIZE               (2u)
#define CapSense_LINEARSLIDER_RESOLUTION_PARAM_ID           (0xAC830050u)

#define CapSense_LINEARSLIDER_FINGER_TH_VALUE               (CapSense_dsRam.wdgtList.linearslider.fingerTh)
#define CapSense_LINEARSLIDER_FINGER_TH_OFFSET              (82u)
#define CapSense_LINEARSLIDER_FINGER_TH_SIZE                (2u)
#define CapSense_LINEARSLIDER_FINGER_TH_PARAM_ID            (0xA0830052u)

#define CapSense_LINEARSLIDER_NOISE_TH_VALUE                (CapSense_dsRam.wdgtList.linearslider.noiseTh)
#define CapSense_LINEARSLIDER_NOISE_TH_OFFSET               (84u)
#define CapSense_LINEARSLIDER_NOISE_TH_SIZE                 (1u)
#define CapSense_LINEARSLIDER_NOISE_TH_PARAM_ID             (0x65830054u)

#define CapSense_LINEARSLIDER_NNOISE_TH_VALUE               (CapSense_dsRam.wdgtList.linearslider.nNoiseTh)
#define CapSense_LINEARSLIDER_NNOISE_TH_OFFSET              (85u)
#define CapSense_LINEARSLIDER_NNOISE_TH_SIZE                (1u)
#define CapSense_LINEARSLIDER_NNOISE_TH_PARAM_ID            (0x63830055u)

#define CapSense_LINEARSLIDER_HYSTERESIS_VALUE              (CapSense_dsRam.wdgtList.linearslider.hysteresis)
#define CapSense_LINEARSLIDER_HYSTERESIS_OFFSET             (86u)
#define CapSense_LINEARSLIDER_HYSTERESIS_SIZE               (1u)
#define CapSense_LINEARSLIDER_HYSTERESIS_PARAM_ID           (0x69830056u)

#define CapSense_LINEARSLIDER_ON_DEBOUNCE_VALUE             (CapSense_dsRam.wdgtList.linearslider.onDebounce)
#define CapSense_LINEARSLIDER_ON_DEBOUNCE_OFFSET            (87u)
#define CapSense_LINEARSLIDER_ON_DEBOUNCE_SIZE              (1u)
#define CapSense_LINEARSLIDER_ON_DEBOUNCE_PARAM_ID          (0x6F830057u)

#define CapSense_LINEARSLIDER_LOW_BSLN_RST_VALUE            (CapSense_dsRam.wdgtList.linearslider.lowBslnRst)
#define CapSense_LINEARSLIDER_LOW_BSLN_RST_OFFSET           (88u)
#define CapSense_LINEARSLIDER_LOW_BSLN_RST_SIZE             (1u)
#define CapSense_LINEARSLIDER_LOW_BSLN_RST_PARAM_ID         (0x66830058u)

#define CapSense_LINEARSLIDER_IDAC_MOD0_VALUE               (CapSense_dsRam.wdgtList.linearslider.idacMod[0u])
#define CapSense_LINEARSLIDER_IDAC_MOD0_OFFSET              (89u)
#define CapSense_LINEARSLIDER_IDAC_MOD0_SIZE                (1u)
#define CapSense_LINEARSLIDER_IDAC_MOD0_PARAM_ID            (0x46030059u)

#define CapSense_LINEARSLIDER_IDAC_GAIN_INDEX_VALUE         (CapSense_dsRam.wdgtList.linearslider.idacGainIndex)
#define CapSense_LINEARSLIDER_IDAC_GAIN_INDEX_OFFSET        (90u)
#define CapSense_LINEARSLIDER_IDAC_GAIN_INDEX_SIZE          (1u)
#define CapSense_LINEARSLIDER_IDAC_GAIN_INDEX_PARAM_ID      (0x4183005Au)

#define CapSense_LINEARSLIDER_SNS_CLK_VALUE                 (CapSense_dsRam.wdgtList.linearslider.snsClk)
#define CapSense_LINEARSLIDER_SNS_CLK_OFFSET                (92u)
#define CapSense_LINEARSLIDER_SNS_CLK_SIZE                  (2u)
#define CapSense_LINEARSLIDER_SNS_CLK_PARAM_ID              (0xAF83005Cu)

#define CapSense_LINEARSLIDER_SNS_CLK_SOURCE_VALUE          (CapSense_dsRam.wdgtList.linearslider.snsClkSource)
#define CapSense_LINEARSLIDER_SNS_CLK_SOURCE_OFFSET         (94u)
#define CapSense_LINEARSLIDER_SNS_CLK_SOURCE_SIZE           (1u)
#define CapSense_LINEARSLIDER_SNS_CLK_SOURCE_PARAM_ID       (0x4083005Eu)

#define CapSense_LINEARSLIDER_POSITION0_VALUE               (CapSense_dsRam.wdgtList.linearslider.position[0u])
#define CapSense_LINEARSLIDER_POSITION0_OFFSET              (96u)
#define CapSense_LINEARSLIDER_POSITION0_SIZE                (2u)
#define CapSense_LINEARSLIDER_POSITION0_PARAM_ID            (0x85030060u)

#define CapSense_BTN0_RX0_RAW0_VALUE                        (CapSense_dsRam.snsList.btn0[0u].raw[0u])
#define CapSense_BTN0_RX0_RAW0_OFFSET                       (98u)
#define CapSense_BTN0_RX0_RAW0_SIZE                         (2u)
#define CapSense_BTN0_RX0_RAW0_PARAM_ID                     (0x8C000062u)

#define CapSense_BTN0_RX0_BSLN0_VALUE                       (CapSense_dsRam.snsList.btn0[0u].bsln[0u])
#define CapSense_BTN0_RX0_BSLN0_OFFSET                      (100u)
#define CapSense_BTN0_RX0_BSLN0_SIZE                        (2u)
#define CapSense_BTN0_RX0_BSLN0_PARAM_ID                    (0x81000064u)

#define CapSense_BTN0_RX0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.btn0[0u].bslnExt[0u])
#define CapSense_BTN0_RX0_BSLN_EXT0_OFFSET                  (102u)
#define CapSense_BTN0_RX0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_BTN0_RX0_BSLN_EXT0_PARAM_ID                (0x45000066u)

#define CapSense_BTN0_RX0_DIFF_VALUE                        (CapSense_dsRam.snsList.btn0[0u].diff)
#define CapSense_BTN0_RX0_DIFF_OFFSET                       (104u)
#define CapSense_BTN0_RX0_DIFF_SIZE                         (2u)
#define CapSense_BTN0_RX0_DIFF_PARAM_ID                     (0x82000068u)

#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.btn0[0u].negBslnRstCnt[0u])
#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_OFFSET          (106u)
#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_BTN0_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4600006Au)

#define CapSense_BTN0_RX0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.btn0[0u].idacComp[0u])
#define CapSense_BTN0_RX0_IDAC_COMP0_OFFSET                 (107u)
#define CapSense_BTN0_RX0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_BTN0_RX0_IDAC_COMP0_PARAM_ID               (0x4000006Bu)

#define CapSense_BTN1_RX0_RAW0_VALUE                        (CapSense_dsRam.snsList.btn1[0u].raw[0u])
#define CapSense_BTN1_RX0_RAW0_OFFSET                       (108u)
#define CapSense_BTN1_RX0_RAW0_SIZE                         (2u)
#define CapSense_BTN1_RX0_RAW0_PARAM_ID                     (0x8300006Cu)

#define CapSense_BTN1_RX0_BSLN0_VALUE                       (CapSense_dsRam.snsList.btn1[0u].bsln[0u])
#define CapSense_BTN1_RX0_BSLN0_OFFSET                      (110u)
#define CapSense_BTN1_RX0_BSLN0_SIZE                        (2u)
#define CapSense_BTN1_RX0_BSLN0_PARAM_ID                    (0x8F00006Eu)

#define CapSense_BTN1_RX0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.btn1[0u].bslnExt[0u])
#define CapSense_BTN1_RX0_BSLN_EXT0_OFFSET                  (112u)
#define CapSense_BTN1_RX0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_BTN1_RX0_BSLN_EXT0_PARAM_ID                (0x4D000070u)

#define CapSense_BTN1_RX0_DIFF_VALUE                        (CapSense_dsRam.snsList.btn1[0u].diff)
#define CapSense_BTN1_RX0_DIFF_OFFSET                       (114u)
#define CapSense_BTN1_RX0_DIFF_SIZE                         (2u)
#define CapSense_BTN1_RX0_DIFF_PARAM_ID                     (0x89000072u)

#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.btn1[0u].negBslnRstCnt[0u])
#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_OFFSET          (116u)
#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_BTN1_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4C000074u)

#define CapSense_BTN1_RX0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.btn1[0u].idacComp[0u])
#define CapSense_BTN1_RX0_IDAC_COMP0_OFFSET                 (117u)
#define CapSense_BTN1_RX0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_BTN1_RX0_IDAC_COMP0_PARAM_ID               (0x4A000075u)

#define CapSense_BTN2_RX0_RAW0_VALUE                        (CapSense_dsRam.snsList.btn2[0u].raw[0u])
#define CapSense_BTN2_RX0_RAW0_OFFSET                       (118u)
#define CapSense_BTN2_RX0_RAW0_SIZE                         (2u)
#define CapSense_BTN2_RX0_RAW0_PARAM_ID                     (0x88000076u)

#define CapSense_BTN2_RX0_BSLN0_VALUE                       (CapSense_dsRam.snsList.btn2[0u].bsln[0u])
#define CapSense_BTN2_RX0_BSLN0_OFFSET                      (120u)
#define CapSense_BTN2_RX0_BSLN0_SIZE                        (2u)
#define CapSense_BTN2_RX0_BSLN0_PARAM_ID                    (0x87000078u)

#define CapSense_BTN2_RX0_BSLN_EXT0_VALUE                   (CapSense_dsRam.snsList.btn2[0u].bslnExt[0u])
#define CapSense_BTN2_RX0_BSLN_EXT0_OFFSET                  (122u)
#define CapSense_BTN2_RX0_BSLN_EXT0_SIZE                    (1u)
#define CapSense_BTN2_RX0_BSLN_EXT0_PARAM_ID                (0x4300007Au)

#define CapSense_BTN2_RX0_DIFF_VALUE                        (CapSense_dsRam.snsList.btn2[0u].diff)
#define CapSense_BTN2_RX0_DIFF_OFFSET                       (124u)
#define CapSense_BTN2_RX0_DIFF_SIZE                         (2u)
#define CapSense_BTN2_RX0_DIFF_PARAM_ID                     (0x8600007Cu)

#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_VALUE           (CapSense_dsRam.snsList.btn2[0u].negBslnRstCnt[0u])
#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_OFFSET          (126u)
#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_SIZE            (1u)
#define CapSense_BTN2_RX0_NEG_BSLN_RST_CNT0_PARAM_ID        (0x4200007Eu)

#define CapSense_BTN2_RX0_IDAC_COMP0_VALUE                  (CapSense_dsRam.snsList.btn2[0u].idacComp[0u])
#define CapSense_BTN2_RX0_IDAC_COMP0_OFFSET                 (127u)
#define CapSense_BTN2_RX0_IDAC_COMP0_SIZE                   (1u)
#define CapSense_BTN2_RX0_IDAC_COMP0_PARAM_ID               (0x4400007Fu)

#define CapSense_LINEARSLIDER_SNS0_RAW0_VALUE               (CapSense_dsRam.snsList.linearslider[0u].raw[0u])
#define CapSense_LINEARSLIDER_SNS0_RAW0_OFFSET              (128u)
#define CapSense_LINEARSLIDER_SNS0_RAW0_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS0_RAW0_PARAM_ID            (0x84000080u)

#define CapSense_LINEARSLIDER_SNS0_BSLN0_VALUE              (CapSense_dsRam.snsList.linearslider[0u].bsln[0u])
#define CapSense_LINEARSLIDER_SNS0_BSLN0_OFFSET             (130u)
#define CapSense_LINEARSLIDER_SNS0_BSLN0_SIZE               (2u)
#define CapSense_LINEARSLIDER_SNS0_BSLN0_PARAM_ID           (0x88000082u)

#define CapSense_LINEARSLIDER_SNS0_BSLN_EXT0_VALUE          (CapSense_dsRam.snsList.linearslider[0u].bslnExt[0u])
#define CapSense_LINEARSLIDER_SNS0_BSLN_EXT0_OFFSET         (132u)
#define CapSense_LINEARSLIDER_SNS0_BSLN_EXT0_SIZE           (1u)
#define CapSense_LINEARSLIDER_SNS0_BSLN_EXT0_PARAM_ID       (0x4D000084u)

#define CapSense_LINEARSLIDER_SNS0_DIFF_VALUE               (CapSense_dsRam.snsList.linearslider[0u].diff)
#define CapSense_LINEARSLIDER_SNS0_DIFF_OFFSET              (134u)
#define CapSense_LINEARSLIDER_SNS0_DIFF_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS0_DIFF_PARAM_ID            (0x89000086u)

#define CapSense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_VALUE  (CapSense_dsRam.snsList.linearslider[0u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_OFFSET (136u)
#define CapSense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define CapSense_LINEARSLIDER_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID (0x4E000088u)

#define CapSense_LINEARSLIDER_SNS0_IDAC_COMP0_VALUE         (CapSense_dsRam.snsList.linearslider[0u].idacComp[0u])
#define CapSense_LINEARSLIDER_SNS0_IDAC_COMP0_OFFSET        (137u)
#define CapSense_LINEARSLIDER_SNS0_IDAC_COMP0_SIZE          (1u)
#define CapSense_LINEARSLIDER_SNS0_IDAC_COMP0_PARAM_ID      (0x48000089u)

#define CapSense_LINEARSLIDER_SNS1_RAW0_VALUE               (CapSense_dsRam.snsList.linearslider[1u].raw[0u])
#define CapSense_LINEARSLIDER_SNS1_RAW0_OFFSET              (138u)
#define CapSense_LINEARSLIDER_SNS1_RAW0_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS1_RAW0_PARAM_ID            (0x8A00008Au)

#define CapSense_LINEARSLIDER_SNS1_BSLN0_VALUE              (CapSense_dsRam.snsList.linearslider[1u].bsln[0u])
#define CapSense_LINEARSLIDER_SNS1_BSLN0_OFFSET             (140u)
#define CapSense_LINEARSLIDER_SNS1_BSLN0_SIZE               (2u)
#define CapSense_LINEARSLIDER_SNS1_BSLN0_PARAM_ID           (0x8700008Cu)

#define CapSense_LINEARSLIDER_SNS1_BSLN_EXT0_VALUE          (CapSense_dsRam.snsList.linearslider[1u].bslnExt[0u])
#define CapSense_LINEARSLIDER_SNS1_BSLN_EXT0_OFFSET         (142u)
#define CapSense_LINEARSLIDER_SNS1_BSLN_EXT0_SIZE           (1u)
#define CapSense_LINEARSLIDER_SNS1_BSLN_EXT0_PARAM_ID       (0x4300008Eu)

#define CapSense_LINEARSLIDER_SNS1_DIFF_VALUE               (CapSense_dsRam.snsList.linearslider[1u].diff)
#define CapSense_LINEARSLIDER_SNS1_DIFF_OFFSET              (144u)
#define CapSense_LINEARSLIDER_SNS1_DIFF_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS1_DIFF_PARAM_ID            (0x81000090u)

#define CapSense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_VALUE  (CapSense_dsRam.snsList.linearslider[1u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_OFFSET (146u)
#define CapSense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define CapSense_LINEARSLIDER_SNS1_NEG_BSLN_RST_CNT0_PARAM_ID (0x45000092u)

#define CapSense_LINEARSLIDER_SNS1_IDAC_COMP0_VALUE         (CapSense_dsRam.snsList.linearslider[1u].idacComp[0u])
#define CapSense_LINEARSLIDER_SNS1_IDAC_COMP0_OFFSET        (147u)
#define CapSense_LINEARSLIDER_SNS1_IDAC_COMP0_SIZE          (1u)
#define CapSense_LINEARSLIDER_SNS1_IDAC_COMP0_PARAM_ID      (0x43000093u)

#define CapSense_LINEARSLIDER_SNS2_RAW0_VALUE               (CapSense_dsRam.snsList.linearslider[2u].raw[0u])
#define CapSense_LINEARSLIDER_SNS2_RAW0_OFFSET              (148u)
#define CapSense_LINEARSLIDER_SNS2_RAW0_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS2_RAW0_PARAM_ID            (0x80000094u)

#define CapSense_LINEARSLIDER_SNS2_BSLN0_VALUE              (CapSense_dsRam.snsList.linearslider[2u].bsln[0u])
#define CapSense_LINEARSLIDER_SNS2_BSLN0_OFFSET             (150u)
#define CapSense_LINEARSLIDER_SNS2_BSLN0_SIZE               (2u)
#define CapSense_LINEARSLIDER_SNS2_BSLN0_PARAM_ID           (0x8C000096u)

#define CapSense_LINEARSLIDER_SNS2_BSLN_EXT0_VALUE          (CapSense_dsRam.snsList.linearslider[2u].bslnExt[0u])
#define CapSense_LINEARSLIDER_SNS2_BSLN_EXT0_OFFSET         (152u)
#define CapSense_LINEARSLIDER_SNS2_BSLN_EXT0_SIZE           (1u)
#define CapSense_LINEARSLIDER_SNS2_BSLN_EXT0_PARAM_ID       (0x4B000098u)

#define CapSense_LINEARSLIDER_SNS2_DIFF_VALUE               (CapSense_dsRam.snsList.linearslider[2u].diff)
#define CapSense_LINEARSLIDER_SNS2_DIFF_OFFSET              (154u)
#define CapSense_LINEARSLIDER_SNS2_DIFF_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS2_DIFF_PARAM_ID            (0x8F00009Au)

#define CapSense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_VALUE  (CapSense_dsRam.snsList.linearslider[2u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_OFFSET (156u)
#define CapSense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define CapSense_LINEARSLIDER_SNS2_NEG_BSLN_RST_CNT0_PARAM_ID (0x4A00009Cu)

#define CapSense_LINEARSLIDER_SNS2_IDAC_COMP0_VALUE         (CapSense_dsRam.snsList.linearslider[2u].idacComp[0u])
#define CapSense_LINEARSLIDER_SNS2_IDAC_COMP0_OFFSET        (157u)
#define CapSense_LINEARSLIDER_SNS2_IDAC_COMP0_SIZE          (1u)
#define CapSense_LINEARSLIDER_SNS2_IDAC_COMP0_PARAM_ID      (0x4C00009Du)

#define CapSense_LINEARSLIDER_SNS3_RAW0_VALUE               (CapSense_dsRam.snsList.linearslider[3u].raw[0u])
#define CapSense_LINEARSLIDER_SNS3_RAW0_OFFSET              (158u)
#define CapSense_LINEARSLIDER_SNS3_RAW0_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS3_RAW0_PARAM_ID            (0x8E00009Eu)

#define CapSense_LINEARSLIDER_SNS3_BSLN0_VALUE              (CapSense_dsRam.snsList.linearslider[3u].bsln[0u])
#define CapSense_LINEARSLIDER_SNS3_BSLN0_OFFSET             (160u)
#define CapSense_LINEARSLIDER_SNS3_BSLN0_SIZE               (2u)
#define CapSense_LINEARSLIDER_SNS3_BSLN0_PARAM_ID           (0x8E0000A0u)

#define CapSense_LINEARSLIDER_SNS3_BSLN_EXT0_VALUE          (CapSense_dsRam.snsList.linearslider[3u].bslnExt[0u])
#define CapSense_LINEARSLIDER_SNS3_BSLN_EXT0_OFFSET         (162u)
#define CapSense_LINEARSLIDER_SNS3_BSLN_EXT0_SIZE           (1u)
#define CapSense_LINEARSLIDER_SNS3_BSLN_EXT0_PARAM_ID       (0x4A0000A2u)

#define CapSense_LINEARSLIDER_SNS3_DIFF_VALUE               (CapSense_dsRam.snsList.linearslider[3u].diff)
#define CapSense_LINEARSLIDER_SNS3_DIFF_OFFSET              (164u)
#define CapSense_LINEARSLIDER_SNS3_DIFF_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS3_DIFF_PARAM_ID            (0x8F0000A4u)

#define CapSense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_VALUE  (CapSense_dsRam.snsList.linearslider[3u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_OFFSET (166u)
#define CapSense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define CapSense_LINEARSLIDER_SNS3_NEG_BSLN_RST_CNT0_PARAM_ID (0x4B0000A6u)

#define CapSense_LINEARSLIDER_SNS3_IDAC_COMP0_VALUE         (CapSense_dsRam.snsList.linearslider[3u].idacComp[0u])
#define CapSense_LINEARSLIDER_SNS3_IDAC_COMP0_OFFSET        (167u)
#define CapSense_LINEARSLIDER_SNS3_IDAC_COMP0_SIZE          (1u)
#define CapSense_LINEARSLIDER_SNS3_IDAC_COMP0_PARAM_ID      (0x4D0000A7u)

#define CapSense_LINEARSLIDER_SNS4_RAW0_VALUE               (CapSense_dsRam.snsList.linearslider[4u].raw[0u])
#define CapSense_LINEARSLIDER_SNS4_RAW0_OFFSET              (168u)
#define CapSense_LINEARSLIDER_SNS4_RAW0_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS4_RAW0_PARAM_ID            (0x8C0000A8u)

#define CapSense_LINEARSLIDER_SNS4_BSLN0_VALUE              (CapSense_dsRam.snsList.linearslider[4u].bsln[0u])
#define CapSense_LINEARSLIDER_SNS4_BSLN0_OFFSET             (170u)
#define CapSense_LINEARSLIDER_SNS4_BSLN0_SIZE               (2u)
#define CapSense_LINEARSLIDER_SNS4_BSLN0_PARAM_ID           (0x800000AAu)

#define CapSense_LINEARSLIDER_SNS4_BSLN_EXT0_VALUE          (CapSense_dsRam.snsList.linearslider[4u].bslnExt[0u])
#define CapSense_LINEARSLIDER_SNS4_BSLN_EXT0_OFFSET         (172u)
#define CapSense_LINEARSLIDER_SNS4_BSLN_EXT0_SIZE           (1u)
#define CapSense_LINEARSLIDER_SNS4_BSLN_EXT0_PARAM_ID       (0x450000ACu)

#define CapSense_LINEARSLIDER_SNS4_DIFF_VALUE               (CapSense_dsRam.snsList.linearslider[4u].diff)
#define CapSense_LINEARSLIDER_SNS4_DIFF_OFFSET              (174u)
#define CapSense_LINEARSLIDER_SNS4_DIFF_SIZE                (2u)
#define CapSense_LINEARSLIDER_SNS4_DIFF_PARAM_ID            (0x810000AEu)

#define CapSense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_VALUE  (CapSense_dsRam.snsList.linearslider[4u].negBslnRstCnt[0u])
#define CapSense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_OFFSET (176u)
#define CapSense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_SIZE   (1u)
#define CapSense_LINEARSLIDER_SNS4_NEG_BSLN_RST_CNT0_PARAM_ID (0x430000B0u)

#define CapSense_LINEARSLIDER_SNS4_IDAC_COMP0_VALUE         (CapSense_dsRam.snsList.linearslider[4u].idacComp[0u])
#define CapSense_LINEARSLIDER_SNS4_IDAC_COMP0_OFFSET        (177u)
#define CapSense_LINEARSLIDER_SNS4_IDAC_COMP0_SIZE          (1u)
#define CapSense_LINEARSLIDER_SNS4_IDAC_COMP0_PARAM_ID      (0x450000B1u)

#define CapSense_SNR_TEST_WIDGET_ID_VALUE                   (CapSense_dsRam.snrTestWidgetId)
#define CapSense_SNR_TEST_WIDGET_ID_OFFSET                  (178u)
#define CapSense_SNR_TEST_WIDGET_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_WIDGET_ID_PARAM_ID                (0x640000B2u)

#define CapSense_SNR_TEST_SENSOR_ID_VALUE                   (CapSense_dsRam.snrTestSensorId)
#define CapSense_SNR_TEST_SENSOR_ID_OFFSET                  (179u)
#define CapSense_SNR_TEST_SENSOR_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_SENSOR_ID_PARAM_ID                (0x620000B3u)

#define CapSense_SNR_TEST_SCAN_COUNTER_VALUE                (CapSense_dsRam.snrTestScanCounter)
#define CapSense_SNR_TEST_SCAN_COUNTER_OFFSET               (180u)
#define CapSense_SNR_TEST_SCAN_COUNTER_SIZE                 (2u)
#define CapSense_SNR_TEST_SCAN_COUNTER_PARAM_ID             (0x8A0000B4u)

#define CapSense_SNR_TEST_RAW_COUNT0_VALUE                  (CapSense_dsRam.snrTestRawCount[0u])
#define CapSense_SNR_TEST_RAW_COUNT0_OFFSET                 (182u)
#define CapSense_SNR_TEST_RAW_COUNT0_SIZE                   (2u)
#define CapSense_SNR_TEST_RAW_COUNT0_PARAM_ID               (0x860000B6u)

#define CapSense_SCAN_CSD_ISC_VALUE                         (CapSense_dsRam.scanCsdISC)
#define CapSense_SCAN_CSD_ISC_OFFSET                        (184u)
#define CapSense_SCAN_CSD_ISC_SIZE                          (1u)
#define CapSense_SCAN_CSD_ISC_PARAM_ID                      (0x410000B8u)

#define CapSense_SCAN_CSX_ISC_VALUE                         (CapSense_dsRam.scanCsxISC)
#define CapSense_SCAN_CSX_ISC_OFFSET                        (185u)
#define CapSense_SCAN_CSX_ISC_SIZE                          (1u)
#define CapSense_SCAN_CSX_ISC_PARAM_ID                      (0x470000B9u)

#define CapSense_SCAN_CURRENT_ISC_VALUE                     (CapSense_dsRam.scanCurrentISC)
#define CapSense_SCAN_CURRENT_ISC_OFFSET                    (186u)
#define CapSense_SCAN_CURRENT_ISC_SIZE                      (1u)
#define CapSense_SCAN_CURRENT_ISC_PARAM_ID                  (0x4D0000BAu)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define CapSense_BTN0_PTR2SNS_FLASH_VALUE                   (CapSense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define CapSense_BTN0_PTR2SNS_FLASH_OFFSET                  (0u)
#define CapSense_BTN0_PTR2SNS_FLASH_SIZE                    (4u)
#define CapSense_BTN0_PTR2SNS_FLASH_PARAM_ID                (0xD1000000u)

#define CapSense_BTN0_PTR2WD_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define CapSense_BTN0_PTR2WD_RAM_OFFSET                     (4u)
#define CapSense_BTN0_PTR2WD_RAM_SIZE                       (4u)
#define CapSense_BTN0_PTR2WD_RAM_PARAM_ID                   (0xD0000004u)

#define CapSense_BTN0_PTR2SNS_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define CapSense_BTN0_PTR2SNS_RAM_OFFSET                    (8u)
#define CapSense_BTN0_PTR2SNS_RAM_SIZE                      (4u)
#define CapSense_BTN0_PTR2SNS_RAM_PARAM_ID                  (0xD3000008u)

#define CapSense_BTN0_PTR2FLTR_HISTORY_VALUE                (CapSense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define CapSense_BTN0_PTR2FLTR_HISTORY_OFFSET               (12u)
#define CapSense_BTN0_PTR2FLTR_HISTORY_SIZE                 (4u)
#define CapSense_BTN0_PTR2FLTR_HISTORY_PARAM_ID             (0xD200000Cu)

#define CapSense_BTN0_PTR2DEBOUNCE_VALUE                    (CapSense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define CapSense_BTN0_PTR2DEBOUNCE_OFFSET                   (16u)
#define CapSense_BTN0_PTR2DEBOUNCE_SIZE                     (4u)
#define CapSense_BTN0_PTR2DEBOUNCE_PARAM_ID                 (0xD4000010u)

#define CapSense_BTN0_STATIC_CONFIG_VALUE                   (CapSense_dsFlash.wdgtArray[0].staticConfig)
#define CapSense_BTN0_STATIC_CONFIG_OFFSET                  (20u)
#define CapSense_BTN0_STATIC_CONFIG_SIZE                    (4u)
#define CapSense_BTN0_STATIC_CONFIG_PARAM_ID                (0xD5000014u)

#define CapSense_BTN0_TOTAL_NUM_SNS_VALUE                   (CapSense_dsFlash.wdgtArray[0].totalNumSns)
#define CapSense_BTN0_TOTAL_NUM_SNS_OFFSET                  (24u)
#define CapSense_BTN0_TOTAL_NUM_SNS_SIZE                    (2u)
#define CapSense_BTN0_TOTAL_NUM_SNS_PARAM_ID                (0x99000018u)

#define CapSense_BTN0_TYPE_VALUE                            (CapSense_dsFlash.wdgtArray[0].wdgtType)
#define CapSense_BTN0_TYPE_OFFSET                           (26u)
#define CapSense_BTN0_TYPE_SIZE                             (1u)
#define CapSense_BTN0_TYPE_PARAM_ID                         (0x5D00001Au)

#define CapSense_BTN0_SENSE_METHOD_VALUE                    (CapSense_dsFlash.wdgtArray[0].senseMethod)
#define CapSense_BTN0_SENSE_METHOD_OFFSET                   (27u)
#define CapSense_BTN0_SENSE_METHOD_SIZE                     (1u)
#define CapSense_BTN0_SENSE_METHOD_PARAM_ID                 (0x5B00001Bu)

#define CapSense_BTN0_NUM_COLS_VALUE                        (CapSense_dsFlash.wdgtArray[0].numCols)
#define CapSense_BTN0_NUM_COLS_OFFSET                       (28u)
#define CapSense_BTN0_NUM_COLS_SIZE                         (1u)
#define CapSense_BTN0_NUM_COLS_PARAM_ID                     (0x5000001Cu)

#define CapSense_BTN0_NUM_ROWS_VALUE                        (CapSense_dsFlash.wdgtArray[0].numRows)
#define CapSense_BTN0_NUM_ROWS_OFFSET                       (29u)
#define CapSense_BTN0_NUM_ROWS_SIZE                         (1u)
#define CapSense_BTN0_NUM_ROWS_PARAM_ID                     (0x5600001Du)

#define CapSense_BTN0_X_RESOLUTION_VALUE                    (CapSense_dsFlash.wdgtArray[0].xResolution)
#define CapSense_BTN0_X_RESOLUTION_OFFSET                   (30u)
#define CapSense_BTN0_X_RESOLUTION_SIZE                     (2u)
#define CapSense_BTN0_X_RESOLUTION_PARAM_ID                 (0x9400001Eu)

#define CapSense_BTN0_X_CENT_MULT_VALUE                     (CapSense_dsFlash.wdgtArray[0].xCentroidMultiplier)
#define CapSense_BTN0_X_CENT_MULT_OFFSET                    (32u)
#define CapSense_BTN0_X_CENT_MULT_SIZE                      (4u)
#define CapSense_BTN0_X_CENT_MULT_PARAM_ID                  (0xDB000020u)

#define CapSense_BTN0_IIR_FILTER_COEFF_VALUE                (CapSense_dsFlash.wdgtArray[0].iirFilterCoeff)
#define CapSense_BTN0_IIR_FILTER_COEFF_OFFSET               (36u)
#define CapSense_BTN0_IIR_FILTER_COEFF_SIZE                 (1u)
#define CapSense_BTN0_IIR_FILTER_COEFF_PARAM_ID             (0x5D000024u)

#define CapSense_BTN1_PTR2SNS_FLASH_VALUE                   (CapSense_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define CapSense_BTN1_PTR2SNS_FLASH_OFFSET                  (40u)
#define CapSense_BTN1_PTR2SNS_FLASH_SIZE                    (4u)
#define CapSense_BTN1_PTR2SNS_FLASH_PARAM_ID                (0xDA010028u)

#define CapSense_BTN1_PTR2WD_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define CapSense_BTN1_PTR2WD_RAM_OFFSET                     (44u)
#define CapSense_BTN1_PTR2WD_RAM_SIZE                       (4u)
#define CapSense_BTN1_PTR2WD_RAM_PARAM_ID                   (0xDB01002Cu)

#define CapSense_BTN1_PTR2SNS_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[1].ptr2SnsRam)
#define CapSense_BTN1_PTR2SNS_RAM_OFFSET                    (48u)
#define CapSense_BTN1_PTR2SNS_RAM_SIZE                      (4u)
#define CapSense_BTN1_PTR2SNS_RAM_PARAM_ID                  (0xDD010030u)

#define CapSense_BTN1_PTR2FLTR_HISTORY_VALUE                (CapSense_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define CapSense_BTN1_PTR2FLTR_HISTORY_OFFSET               (52u)
#define CapSense_BTN1_PTR2FLTR_HISTORY_SIZE                 (4u)
#define CapSense_BTN1_PTR2FLTR_HISTORY_PARAM_ID             (0xDC010034u)

#define CapSense_BTN1_PTR2DEBOUNCE_VALUE                    (CapSense_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define CapSense_BTN1_PTR2DEBOUNCE_OFFSET                   (56u)
#define CapSense_BTN1_PTR2DEBOUNCE_SIZE                     (4u)
#define CapSense_BTN1_PTR2DEBOUNCE_PARAM_ID                 (0xDF010038u)

#define CapSense_BTN1_STATIC_CONFIG_VALUE                   (CapSense_dsFlash.wdgtArray[1].staticConfig)
#define CapSense_BTN1_STATIC_CONFIG_OFFSET                  (60u)
#define CapSense_BTN1_STATIC_CONFIG_SIZE                    (4u)
#define CapSense_BTN1_STATIC_CONFIG_PARAM_ID                (0xDE01003Cu)

#define CapSense_BTN1_TOTAL_NUM_SNS_VALUE                   (CapSense_dsFlash.wdgtArray[1].totalNumSns)
#define CapSense_BTN1_TOTAL_NUM_SNS_OFFSET                  (64u)
#define CapSense_BTN1_TOTAL_NUM_SNS_SIZE                    (2u)
#define CapSense_BTN1_TOTAL_NUM_SNS_PARAM_ID                (0x90010040u)

#define CapSense_BTN1_TYPE_VALUE                            (CapSense_dsFlash.wdgtArray[1].wdgtType)
#define CapSense_BTN1_TYPE_OFFSET                           (66u)
#define CapSense_BTN1_TYPE_SIZE                             (1u)
#define CapSense_BTN1_TYPE_PARAM_ID                         (0x54010042u)

#define CapSense_BTN1_SENSE_METHOD_VALUE                    (CapSense_dsFlash.wdgtArray[1].senseMethod)
#define CapSense_BTN1_SENSE_METHOD_OFFSET                   (67u)
#define CapSense_BTN1_SENSE_METHOD_SIZE                     (1u)
#define CapSense_BTN1_SENSE_METHOD_PARAM_ID                 (0x52010043u)

#define CapSense_BTN1_NUM_COLS_VALUE                        (CapSense_dsFlash.wdgtArray[1].numCols)
#define CapSense_BTN1_NUM_COLS_OFFSET                       (68u)
#define CapSense_BTN1_NUM_COLS_SIZE                         (1u)
#define CapSense_BTN1_NUM_COLS_PARAM_ID                     (0x59010044u)

#define CapSense_BTN1_NUM_ROWS_VALUE                        (CapSense_dsFlash.wdgtArray[1].numRows)
#define CapSense_BTN1_NUM_ROWS_OFFSET                       (69u)
#define CapSense_BTN1_NUM_ROWS_SIZE                         (1u)
#define CapSense_BTN1_NUM_ROWS_PARAM_ID                     (0x5F010045u)

#define CapSense_BTN1_X_RESOLUTION_VALUE                    (CapSense_dsFlash.wdgtArray[1].xResolution)
#define CapSense_BTN1_X_RESOLUTION_OFFSET                   (70u)
#define CapSense_BTN1_X_RESOLUTION_SIZE                     (2u)
#define CapSense_BTN1_X_RESOLUTION_PARAM_ID                 (0x9D010046u)

#define CapSense_BTN1_X_CENT_MULT_VALUE                     (CapSense_dsFlash.wdgtArray[1].xCentroidMultiplier)
#define CapSense_BTN1_X_CENT_MULT_OFFSET                    (72u)
#define CapSense_BTN1_X_CENT_MULT_SIZE                      (4u)
#define CapSense_BTN1_X_CENT_MULT_PARAM_ID                  (0xDD010048u)

#define CapSense_BTN1_IIR_FILTER_COEFF_VALUE                (CapSense_dsFlash.wdgtArray[1].iirFilterCoeff)
#define CapSense_BTN1_IIR_FILTER_COEFF_OFFSET               (76u)
#define CapSense_BTN1_IIR_FILTER_COEFF_SIZE                 (1u)
#define CapSense_BTN1_IIR_FILTER_COEFF_PARAM_ID             (0x5B01004Cu)

#define CapSense_BTN2_PTR2SNS_FLASH_VALUE                   (CapSense_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define CapSense_BTN2_PTR2SNS_FLASH_OFFSET                  (80u)
#define CapSense_BTN2_PTR2SNS_FLASH_SIZE                    (4u)
#define CapSense_BTN2_PTR2SNS_FLASH_PARAM_ID                (0xDF020050u)

#define CapSense_BTN2_PTR2WD_RAM_VALUE                      (CapSense_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define CapSense_BTN2_PTR2WD_RAM_OFFSET                     (84u)
#define CapSense_BTN2_PTR2WD_RAM_SIZE                       (4u)
#define CapSense_BTN2_PTR2WD_RAM_PARAM_ID                   (0xDE020054u)

#define CapSense_BTN2_PTR2SNS_RAM_VALUE                     (CapSense_dsFlash.wdgtArray[2].ptr2SnsRam)
#define CapSense_BTN2_PTR2SNS_RAM_OFFSET                    (88u)
#define CapSense_BTN2_PTR2SNS_RAM_SIZE                      (4u)
#define CapSense_BTN2_PTR2SNS_RAM_PARAM_ID                  (0xDD020058u)

#define CapSense_BTN2_PTR2FLTR_HISTORY_VALUE                (CapSense_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define CapSense_BTN2_PTR2FLTR_HISTORY_OFFSET               (92u)
#define CapSense_BTN2_PTR2FLTR_HISTORY_SIZE                 (4u)
#define CapSense_BTN2_PTR2FLTR_HISTORY_PARAM_ID             (0xDC02005Cu)

#define CapSense_BTN2_PTR2DEBOUNCE_VALUE                    (CapSense_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define CapSense_BTN2_PTR2DEBOUNCE_OFFSET                   (96u)
#define CapSense_BTN2_PTR2DEBOUNCE_SIZE                     (4u)
#define CapSense_BTN2_PTR2DEBOUNCE_PARAM_ID                 (0xD0020060u)

#define CapSense_BTN2_STATIC_CONFIG_VALUE                   (CapSense_dsFlash.wdgtArray[2].staticConfig)
#define CapSense_BTN2_STATIC_CONFIG_OFFSET                  (100u)
#define CapSense_BTN2_STATIC_CONFIG_SIZE                    (4u)
#define CapSense_BTN2_STATIC_CONFIG_PARAM_ID                (0xD1020064u)

#define CapSense_BTN2_TOTAL_NUM_SNS_VALUE                   (CapSense_dsFlash.wdgtArray[2].totalNumSns)
#define CapSense_BTN2_TOTAL_NUM_SNS_OFFSET                  (104u)
#define CapSense_BTN2_TOTAL_NUM_SNS_SIZE                    (2u)
#define CapSense_BTN2_TOTAL_NUM_SNS_PARAM_ID                (0x9D020068u)

#define CapSense_BTN2_TYPE_VALUE                            (CapSense_dsFlash.wdgtArray[2].wdgtType)
#define CapSense_BTN2_TYPE_OFFSET                           (106u)
#define CapSense_BTN2_TYPE_SIZE                             (1u)
#define CapSense_BTN2_TYPE_PARAM_ID                         (0x5902006Au)

#define CapSense_BTN2_SENSE_METHOD_VALUE                    (CapSense_dsFlash.wdgtArray[2].senseMethod)
#define CapSense_BTN2_SENSE_METHOD_OFFSET                   (107u)
#define CapSense_BTN2_SENSE_METHOD_SIZE                     (1u)
#define CapSense_BTN2_SENSE_METHOD_PARAM_ID                 (0x5F02006Bu)

#define CapSense_BTN2_NUM_COLS_VALUE                        (CapSense_dsFlash.wdgtArray[2].numCols)
#define CapSense_BTN2_NUM_COLS_OFFSET                       (108u)
#define CapSense_BTN2_NUM_COLS_SIZE                         (1u)
#define CapSense_BTN2_NUM_COLS_PARAM_ID                     (0x5402006Cu)

#define CapSense_BTN2_NUM_ROWS_VALUE                        (CapSense_dsFlash.wdgtArray[2].numRows)
#define CapSense_BTN2_NUM_ROWS_OFFSET                       (109u)
#define CapSense_BTN2_NUM_ROWS_SIZE                         (1u)
#define CapSense_BTN2_NUM_ROWS_PARAM_ID                     (0x5202006Du)

#define CapSense_BTN2_X_RESOLUTION_VALUE                    (CapSense_dsFlash.wdgtArray[2].xResolution)
#define CapSense_BTN2_X_RESOLUTION_OFFSET                   (110u)
#define CapSense_BTN2_X_RESOLUTION_SIZE                     (2u)
#define CapSense_BTN2_X_RESOLUTION_PARAM_ID                 (0x9002006Eu)

#define CapSense_BTN2_X_CENT_MULT_VALUE                     (CapSense_dsFlash.wdgtArray[2].xCentroidMultiplier)
#define CapSense_BTN2_X_CENT_MULT_OFFSET                    (112u)
#define CapSense_BTN2_X_CENT_MULT_SIZE                      (4u)
#define CapSense_BTN2_X_CENT_MULT_PARAM_ID                  (0xD5020070u)

#define CapSense_BTN2_IIR_FILTER_COEFF_VALUE                (CapSense_dsFlash.wdgtArray[2].iirFilterCoeff)
#define CapSense_BTN2_IIR_FILTER_COEFF_OFFSET               (116u)
#define CapSense_BTN2_IIR_FILTER_COEFF_SIZE                 (1u)
#define CapSense_BTN2_IIR_FILTER_COEFF_PARAM_ID             (0x53020074u)

#define CapSense_LINEARSLIDER_PTR2SNS_FLASH_VALUE           (CapSense_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define CapSense_LINEARSLIDER_PTR2SNS_FLASH_OFFSET          (120u)
#define CapSense_LINEARSLIDER_PTR2SNS_FLASH_SIZE            (4u)
#define CapSense_LINEARSLIDER_PTR2SNS_FLASH_PARAM_ID        (0xD4030078u)

#define CapSense_LINEARSLIDER_PTR2WD_RAM_VALUE              (CapSense_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define CapSense_LINEARSLIDER_PTR2WD_RAM_OFFSET             (124u)
#define CapSense_LINEARSLIDER_PTR2WD_RAM_SIZE               (4u)
#define CapSense_LINEARSLIDER_PTR2WD_RAM_PARAM_ID           (0xD503007Cu)

#define CapSense_LINEARSLIDER_PTR2SNS_RAM_VALUE             (CapSense_dsFlash.wdgtArray[3].ptr2SnsRam)
#define CapSense_LINEARSLIDER_PTR2SNS_RAM_OFFSET            (128u)
#define CapSense_LINEARSLIDER_PTR2SNS_RAM_SIZE              (4u)
#define CapSense_LINEARSLIDER_PTR2SNS_RAM_PARAM_ID          (0xD7030080u)

#define CapSense_LINEARSLIDER_PTR2FLTR_HISTORY_VALUE        (CapSense_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define CapSense_LINEARSLIDER_PTR2FLTR_HISTORY_OFFSET       (132u)
#define CapSense_LINEARSLIDER_PTR2FLTR_HISTORY_SIZE         (4u)
#define CapSense_LINEARSLIDER_PTR2FLTR_HISTORY_PARAM_ID     (0xD6030084u)

#define CapSense_LINEARSLIDER_PTR2DEBOUNCE_VALUE            (CapSense_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define CapSense_LINEARSLIDER_PTR2DEBOUNCE_OFFSET           (136u)
#define CapSense_LINEARSLIDER_PTR2DEBOUNCE_SIZE             (4u)
#define CapSense_LINEARSLIDER_PTR2DEBOUNCE_PARAM_ID         (0xD5030088u)

#define CapSense_LINEARSLIDER_STATIC_CONFIG_VALUE           (CapSense_dsFlash.wdgtArray[3].staticConfig)
#define CapSense_LINEARSLIDER_STATIC_CONFIG_OFFSET          (140u)
#define CapSense_LINEARSLIDER_STATIC_CONFIG_SIZE            (4u)
#define CapSense_LINEARSLIDER_STATIC_CONFIG_PARAM_ID        (0xD403008Cu)

#define CapSense_LINEARSLIDER_TOTAL_NUM_SNS_VALUE           (CapSense_dsFlash.wdgtArray[3].totalNumSns)
#define CapSense_LINEARSLIDER_TOTAL_NUM_SNS_OFFSET          (144u)
#define CapSense_LINEARSLIDER_TOTAL_NUM_SNS_SIZE            (2u)
#define CapSense_LINEARSLIDER_TOTAL_NUM_SNS_PARAM_ID        (0x9D030090u)

#define CapSense_LINEARSLIDER_TYPE_VALUE                    (CapSense_dsFlash.wdgtArray[3].wdgtType)
#define CapSense_LINEARSLIDER_TYPE_OFFSET                   (146u)
#define CapSense_LINEARSLIDER_TYPE_SIZE                     (1u)
#define CapSense_LINEARSLIDER_TYPE_PARAM_ID                 (0x59030092u)

#define CapSense_LINEARSLIDER_SENSE_METHOD_VALUE            (CapSense_dsFlash.wdgtArray[3].senseMethod)
#define CapSense_LINEARSLIDER_SENSE_METHOD_OFFSET           (147u)
#define CapSense_LINEARSLIDER_SENSE_METHOD_SIZE             (1u)
#define CapSense_LINEARSLIDER_SENSE_METHOD_PARAM_ID         (0x5F030093u)

#define CapSense_LINEARSLIDER_NUM_COLS_VALUE                (CapSense_dsFlash.wdgtArray[3].numCols)
#define CapSense_LINEARSLIDER_NUM_COLS_OFFSET               (148u)
#define CapSense_LINEARSLIDER_NUM_COLS_SIZE                 (1u)
#define CapSense_LINEARSLIDER_NUM_COLS_PARAM_ID             (0x54030094u)

#define CapSense_LINEARSLIDER_NUM_ROWS_VALUE                (CapSense_dsFlash.wdgtArray[3].numRows)
#define CapSense_LINEARSLIDER_NUM_ROWS_OFFSET               (149u)
#define CapSense_LINEARSLIDER_NUM_ROWS_SIZE                 (1u)
#define CapSense_LINEARSLIDER_NUM_ROWS_PARAM_ID             (0x52030095u)

#define CapSense_LINEARSLIDER_X_RESOLUTION_VALUE            (CapSense_dsFlash.wdgtArray[3].xResolution)
#define CapSense_LINEARSLIDER_X_RESOLUTION_OFFSET           (150u)
#define CapSense_LINEARSLIDER_X_RESOLUTION_SIZE             (2u)
#define CapSense_LINEARSLIDER_X_RESOLUTION_PARAM_ID         (0x90030096u)

#define CapSense_LINEARSLIDER_X_CENT_MULT_VALUE             (CapSense_dsFlash.wdgtArray[3].xCentroidMultiplier)
#define CapSense_LINEARSLIDER_X_CENT_MULT_OFFSET            (152u)
#define CapSense_LINEARSLIDER_X_CENT_MULT_SIZE              (4u)
#define CapSense_LINEARSLIDER_X_CENT_MULT_PARAM_ID          (0xD0030098u)

#define CapSense_LINEARSLIDER_IIR_FILTER_COEFF_VALUE        (CapSense_dsFlash.wdgtArray[3].iirFilterCoeff)
#define CapSense_LINEARSLIDER_IIR_FILTER_COEFF_OFFSET       (156u)
#define CapSense_LINEARSLIDER_IIR_FILTER_COEFF_SIZE         (1u)
#define CapSense_LINEARSLIDER_IIR_FILTER_COEFF_PARAM_ID     (0x5603009Cu)


#endif /* End CY_SENSE_CapSense_REGISTER_MAP_H */


/* [] END OF FILE */
