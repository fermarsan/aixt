/*******************************************************************************
* \file capsense_Configuration.h
* \version 7.10
*
* \brief
*   This file provides the customizer parameters definitions.
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

#if !defined(CY_SENSE_capsense_CONFIGURATION_H)
#define CY_SENSE_capsense_CONFIGURATION_H

#include <cytypes.h>
#include <cyfitter.h>

/*******************************************************************************
* Customizer-generated defines
*******************************************************************************/
#define capsense_ENABLE                             (1u)
#define capsense_DISABLE                            (0u)

#define capsense_THIRD_GENERATION_BLOCK             (1u)
#define capsense_FOURTH_GENERATION_BLOCK            (2u)

#define capsense_GENERATION_BLOCK_VERSION           (2u)

/*******************************************************************************
* HW IP block global defines
*******************************************************************************/

#if (capsense_GENERATION_BLOCK_VERSION == capsense_THIRD_GENERATION_BLOCK)
    #define capsense_CSDV1                          (capsense_ENABLE)

    #ifdef CYIPBLOCK_m0s8csd_VERSION
        #if (0u == CYIPBLOCK_m0s8csd_VERSION)
            #define capsense_CSDV1_VER1             (capsense_ENABLE)
            #define capsense_CSDV1_VER2             (capsense_DISABLE)
        #else
            #define capsense_CSDV1_VER1             (capsense_DISABLE)
            #define capsense_CSDV1_VER2             (capsense_ENABLE)
        #endif
    #else
        #error "HW IP block version is not specified"
    #endif
#else
    #define capsense_CSDV1                          (capsense_DISABLE)
    #define capsense_CSDV1_VER1                     (capsense_DISABLE)
    #define capsense_CSDV1_VER2                     (capsense_DISABLE)
#endif

#if (capsense_GENERATION_BLOCK_VERSION == capsense_FOURTH_GENERATION_BLOCK)
    #define capsense_CSDV2                          (capsense_ENABLE)

    #ifdef CYIPBLOCK_m0s8csdv2_VERSION
        #if (1u == CYIPBLOCK_m0s8csdv2_VERSION)
            #define capsense_CSDV2_VER1             (capsense_ENABLE)
        #else
            #define capsense_CSDV2_VER1             (capsense_DISABLE)
        #endif
        #if (2u == CYIPBLOCK_m0s8csdv2_VERSION)
            #define capsense_CSDV2_VER2             (capsense_ENABLE)
        #else
            #define capsense_CSDV2_VER2             (capsense_DISABLE)
        #endif
    #else
        #error "HW IP block version is not specified"
    #endif
#else
    #define capsense_CSDV2                          (capsense_DISABLE)
    #define capsense_CSDV2_VER1                     (capsense_DISABLE)
    #define capsense_CSDV2_VER2                     (capsense_DISABLE)
#endif

/*******************************************************************************
* Project-global defines
*******************************************************************************/

#define capsense_2000_MV                            (2000u)

#ifdef CYDEV_VDDA_MV
    #define capsense_CYDEV_VDDA_MV                  (CYDEV_VDDA_MV)
#else
    #ifdef CYDEV_VDD_MV
        #define capsense_CYDEV_VDDA_MV              (CYDEV_VDD_MV)
    #endif
#endif

#define capsense_BAD_CONVERSIONS_NUM                (1u)
#define capsense_RESAMPLING_CYCLES_MAX_NUMBER       (1u)


/*******************************************************************************
* Enabled Scan Methods
*******************************************************************************/
#define capsense_CSD_EN                             (1u)
#define capsense_CSX_EN                             (1u)
#define capsense_ISX_EN                             (0u)
#define capsense_CSD_CSX_EN                         (capsense_CSD_EN && capsense_CSX_EN)

#define capsense_MANY_SENSE_MODES_EN                ((capsense_CSD_EN && capsense_CSX_EN) || \
                                                             (capsense_CSD_EN && capsense_ISX_EN) || \
                                                             (capsense_CSX_EN && capsense_ISX_EN) || \
                                                             (capsense_SELF_TEST_EN))

#define capsense_MANY_WIDGET_METHODS_EN             ((capsense_CSD_EN && capsense_CSX_EN) || \
                                                             (capsense_CSD_EN && capsense_ISX_EN) || \
                                                             (capsense_CSX_EN && capsense_ISX_EN))

#define capsense_CSD2X_EN                           (0u)
#define capsense_CSX2X_EN                           (0u)

/*******************************************************************************
* Definitions for number of widgets and sensors
*******************************************************************************/
#define capsense_TOTAL_WIDGETS                      (4u)
#define capsense_TOTAL_CSD_WIDGETS                  (1u)
#define capsense_TOTAL_CSD_SENSORS                  (5u)
#define capsense_TOTAL_CSX_WIDGETS                  (3u)
#define capsense_TOTAL_ISX_WIDGETS                  (0u)
#define capsense_TOTAL_CSX_NODES                    (3u)
#define capsense_TOTAL_ISX_NODES                    (0u)

/*******************************************************************************
* Total number of CSD sensors + CSX nodes
*******************************************************************************/
#define capsense_TOTAL_SENSORS            (capsense_TOTAL_CSD_SENSORS + \
                                                   capsense_TOTAL_CSX_NODES+ \
                                                   capsense_TOTAL_ISX_NODES)

/*******************************************************************************
* Total number of scan slots (used only when dual-channel scan is enabled)
*******************************************************************************/
#define capsense_TOTAL_SCAN_SLOTS         (11u)

/*******************************************************************************
* Defines widget IDs
*******************************************************************************/
#define capsense_BTN0_WDGT_ID                   (0u)
#define capsense_BTN1_WDGT_ID                   (1u)
#define capsense_BTN2_WDGT_ID                   (2u)
#define capsense_LINEARSLIDER_WDGT_ID           (3u)

/*******************************************************************************
* Defines sensor IDs
*******************************************************************************/

/* BTN0 sensor names */
#define capsense_BTN0_SNS0_ID                   (0u)

/* BTN0 node names */
#define capsense_BTN0_RX0_TX0_ID                (0u)

/* BTN0 sensor element IDs */
#define capsense_BTN0_RX0_ID                    (0u)
#define capsense_BTN0_TX0_ID                    (1u)

/* BTN1 sensor names */
#define capsense_BTN1_SNS0_ID                   (0u)

/* BTN1 node names */
#define capsense_BTN1_RX0_TX0_ID                (0u)

/* BTN1 sensor element IDs */
#define capsense_BTN1_RX0_ID                    (0u)
#define capsense_BTN1_TX0_ID                    (1u)

/* BTN2 sensor names */
#define capsense_BTN2_SNS0_ID                   (0u)

/* BTN2 node names */
#define capsense_BTN2_RX0_TX0_ID                (0u)

/* BTN2 sensor element IDs */
#define capsense_BTN2_RX0_ID                    (0u)
#define capsense_BTN2_TX0_ID                    (1u)

/* LinearSlider sensor names */
#define capsense_LINEARSLIDER_SNS0_ID           (0u)
#define capsense_LINEARSLIDER_SNS1_ID           (1u)
#define capsense_LINEARSLIDER_SNS2_ID           (2u)
#define capsense_LINEARSLIDER_SNS3_ID           (3u)
#define capsense_LINEARSLIDER_SNS4_ID           (4u)



/*******************************************************************************
* Enabled widget types
*******************************************************************************/
#define capsense_BUTTON_WIDGET_EN         (1u)
#define capsense_SLIDER_WIDGET_EN         (1u)
#define capsense_MATRIX_WIDGET_EN         (0u)
#define capsense_PROXIMITY_WIDGET_EN      (0u)
#define capsense_TOUCHPAD_WIDGET_EN       (0u)
#define capsense_ENCODERDIAL_WIDGET_EN    (0u)

#define capsense_CSD_MATRIX_WIDGET_EN     (0u)
#define capsense_CSD_TOUCHPAD_WIDGET_EN   (0u)

#define capsense_CSX_MATRIX_WIDGET_EN     (0u)
#define capsense_CSX_TOUCHPAD_WIDGET_EN   (0u)

/*******************************************************************************
* Centroid APIs
*******************************************************************************/
#define capsense_CENTROID_EN              (1u)
#define capsense_TOTAL_DIPLEXED_SLIDERS   (0u)
#define capsense_TOTAL_LINEAR_SLIDERS     (1u)
#define capsense_TOTAL_RADIAL_SLIDERS     (0u)
#define capsense_TOTAL_TOUCHPADS          (0u)
#define capsense_MAX_CENTROID_LENGTH      (5u)
#define capsense_SLIDER_MULT_METHOD       (0u)
#define capsense_TOUCHPAD_MULT_METHOD     (0u)

/*******************************************************************************
* Enabled sensor types
*******************************************************************************/
#define capsense_REGULAR_SENSOR_EN        (1u)
#define capsense_PROXIMITY_SENSOR_EN      (0u)

/*******************************************************************************
* Sensor ganging
*******************************************************************************/
#define capsense_GANGED_SNS_EN            (0u)
#define capsense_CSD_GANGED_SNS_EN        (0u)
#define capsense_CSX_GANGED_SNS_EN        (0u)

/*******************************************************************************
* Max number of sensors used among all the widgets
*******************************************************************************/
#define capsense_MAX_SENSORS_PER_WIDGET   (5u)
#define capsense_MAX_SENSORS_PER_5X5_TOUCHPAD (1u)

/*******************************************************************************
* Total number of all used electrodes (NOT unique)
*******************************************************************************/
#define capsense_TOTAL_ELECTRODES         (11u)
/* Obsolete */
#define capsense_TOTAL_SENSOR_IOS         capsense_TOTAL_ELECTRODES

/*******************************************************************************
* Total number of used physical IOs (unique)
*******************************************************************************/
#define capsense_TOTAL_IO_CNT             (9u)

/*******************************************************************************
* Array length for widget status registers
*******************************************************************************/
#define capsense_WDGT_STATUS_WORDS        \
                        (((uint8)((capsense_TOTAL_WIDGETS - 1u) / 32u)) + 1u)


/*******************************************************************************
* Auto-tuning mode selection
*******************************************************************************/
#define capsense_CSD_SS_DIS         (0x00ul)
#define capsense_CSD_SS_HW_EN       (0x01ul)
#define capsense_CSD_SS_TH_EN       (0x02ul)
#define capsense_CSD_SS_HWTH_EN     (capsense_CSD_SS_HW_EN | \
                                             capsense_CSD_SS_TH_EN)

#define capsense_CSD_AUTOTUNE       capsense_CSD_SS_DIS


/*******************************************************************************
* General settings
*******************************************************************************/

#define capsense_AUTO_RESET_METHOD_LEGACY (0u)
#define capsense_AUTO_RESET_METHOD_SAMPLE (1u)

#define capsense_MULTI_FREQ_SCAN_EN       (0u)
#define capsense_SENSOR_AUTO_RESET_EN     (0u)
#define capsense_SENSOR_AUTO_RESET_METHOD (0u)
#define capsense_NUM_CENTROIDS            (1u)
#define capsense_4PTS_LOCAL_MAX_EN        (0u)
#define capsense_OFF_DEBOUNCE_EN          (0u)
#define capsense_CUSTOM_DS_RAM_SIZE       (0u)

/* Defines power status of HW block after scanning */
#define capsense_BLOCK_OFF_AFTER_SCAN_EN  (0u)

/* Defines number of scan frequencies */
#if (capsense_DISABLE != capsense_MULTI_FREQ_SCAN_EN)
    #define capsense_NUM_SCAN_FREQS       (3u)
#else
    #define capsense_NUM_SCAN_FREQS       (1u)
#endif /* #if (capsense_DISABLE != capsense_MULTI_FREQ_SCAN_EN) */

/* Data size for thresholds / low baseline reset */
#define capsense_SIZE_8BITS               (8u)
#define capsense_SIZE_16BITS              (16u)

#define capsense_THRESHOLD_SIZE           capsense_SIZE_16BITS
typedef uint16 capsense_THRESHOLD_TYPE;

#if (capsense_AUTO_RESET_METHOD_LEGACY == capsense_SENSOR_AUTO_RESET_METHOD)
    #define capsense_LOW_BSLN_RST_SIZE        capsense_SIZE_8BITS
    typedef uint8 capsense_LOW_BSLN_RST_TYPE;
#else
    #define capsense_LOW_BSLN_RST_SIZE    (16u)
    typedef uint16 capsense_LOW_BSLN_RST_TYPE;
#endif /* #if (capsense_AUTO_RESET_METHOD_LEGACY == capsense_SENSOR_AUTO_RESET_METHOD) */

/* Coefficient to define touch threshold for proximity sensors */
#define capsense_PROX_TOUCH_COEFF         (300u)

/*******************************************************************************
* General Filter Constants
*******************************************************************************/

/* Baseline algorithm options */
#define capsense_IIR_BASELINE                 (0u)
#define capsense_BUCKET_BASELINE              (1u)

#define capsense_BASELINE_TYPE                capsense_IIR_BASELINE

/* IIR baseline filter algorithm for regular sensors*/
#define capsense_REGULAR_IIR_BL_TYPE          capsense_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for regular sensors */
#define capsense_REGULAR_IIR_BL_N             (1u)
#define capsense_REGULAR_IIR_BL_SHIFT         (8u)

/* IIR baseline filter algorithm for proximity sensors*/
#define capsense_PROX_IIR_BL_TYPE             capsense_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for proximity sensors */
#define capsense_PROX_IIR_BL_N                (1u)
#define capsense_PROX_IIR_BL_SHIFT            (8u)


/* IIR filter constants */
#define capsense_IIR_COEFFICIENT_K            (256u)

/* IIR filter type */
#define capsense_IIR_FILTER_STANDARD          (1u)
#define capsense_IIR_FILTER_PERFORMANCE       (2u)
#define capsense_IIR_FILTER_MEMORY            (3u)

/* Regular sensor raw count filters */
#define capsense_REGULAR_RC_FILTER_EN         (0u)
#define capsense_REGULAR_RC_IIR_FILTER_EN     (0u)
#define capsense_REGULAR_RC_MEDIAN_FILTER_EN  (0u)
#define capsense_REGULAR_RC_AVERAGE_FILTER_EN (0u)
#define capsense_REGULAR_RC_CUSTOM_FILTER_EN  (0u)
#define capsense_REGULAR_RC_ALP_FILTER_EN     (0u)

/* Proximity sensor raw count filters */
#define capsense_PROX_RC_FILTER_EN            (0u)
#define capsense_PROX_RC_IIR_FILTER_EN        (0u)
#define capsense_PROX_RC_MEDIAN_FILTER_EN     (0u)
#define capsense_PROX_RC_AVERAGE_FILTER_EN    (0u)
#define capsense_PROX_RC_CUSTOM_FILTER_EN     (0u)
#define capsense_PROX_RC_ALP_FILTER_EN        (0u)

#define capsense_ALP_FILTER_EN                (0u)
#define capsense_REGULAR_RC_ALP_FILTER_COEFF  (2u)
#define capsense_PROX_RC_ALP_FILTER_COEFF     (2u)

/* Raw count filters */
#define capsense_RC_FILTER_EN                 (capsense_REGULAR_RC_FILTER_EN || capsense_PROX_RC_FILTER_EN)

/* IIR raw count filter algorithm for regular sensors */
#define capsense_REGULAR_IIR_RC_TYPE          (capsense_IIR_FILTER_STANDARD)

/* IIR raw count filter coefficients for regular sensors */
#define capsense_REGULAR_IIR_RC_N             (128u)
#define capsense_REGULAR_IIR_RC_SHIFT         (0u)

/* IIR raw count filter algorithm for proximity sensors*/
#define capsense_PROX_IIR_RC_TYPE             (capsense_IIR_FILTER_STANDARD)

/* IIR raw count filter coefficients for proximity sensors */
#define capsense_PROX_IIR_RC_N                (128u)
#define capsense_PROX_IIR_RC_SHIFT            (0u)

/* Median filter constants */

/* Order of regular sensor median filter */
#define capsense_REGULAR_MEDIAN_LEN           (2u)

/* Order of proximity sensor median filter */
#define capsense_PROX_MEDIAN_LEN              (2u)

/* Average filter constants*/
#define capsense_AVERAGE_FILTER_LEN_2         (1u)
#define capsense_AVERAGE_FILTER_LEN_4         (3u)

/* Order of regular sensor average filter */
#define capsense_REGULAR_AVERAGE_LEN          (capsense_AVERAGE_FILTER_LEN_4)

/* Order of proximity sensor average filter */
#define capsense_PROX_AVERAGE_LEN             (capsense_AVERAGE_FILTER_LEN_4)

/* Widget baseline coefficient enable */
#define capsense_WD_BSLN_COEFF_EN             (0u)

/* Centroid position filters */
#define capsense_POSITION_FILTER_EN           (0u)
#define capsense_POS_MEDIAN_FILTER_EN         (0u)
#define capsense_POS_IIR_FILTER_EN            (0u)
#define capsense_POS_ADAPTIVE_IIR_FILTER_EN   (0u)
#define capsense_POS_AVERAGE_FILTER_EN        (0u)
#define capsense_POS_JITTER_FILTER_EN         (0u)
#define capsense_BALLISTIC_MULTIPLIER_EN      (0u)
#define capsense_CENTROID_3X3_CSD_EN          (0u)
#define capsense_CENTROID_5X5_CSD_EN          (0u)
#define capsense_CSD_5X5_MAX_FINGERS          (1u)

#define capsense_POS_IIR_COEFF                (128u)
#define capsense_POS_IIR_RESET_RADIAL_SLIDER  (35u)

#define capsense_CSX_TOUCHPAD_UNDEFINED       (40u)

/* IDAC options */

/* Third-generation HW block IDAC gain */
#define capsense_IDAC_GAIN_4X                 (4u)
#define capsense_IDAC_GAIN_8X                 (8u)

/* Fourth-generation HW block IDAC gain */
#define capsense_IDAC_GAIN_LOW                (0uL)
#define capsense_IDAC_GAIN_MEDIUM             (1uL)
#define capsense_IDAC_GAIN_HIGH               (2uL)

#define capsense_IDAC_SOURCING                (0u)
#define capsense_IDAC_SINKING                 (1u)

/* Shield tank capacitor precharge source */
#define capsense_CSH_PRECHARGE_VREF           (0u)
#define capsense_CSH_PRECHARGE_IO_BUF         (1u)

/* Shield electrode delay */
#define capsense_NO_DELAY                     (0u)

#if(capsense_ENABLE == capsense_CSDV2)
    #define capsense_SH_DELAY_5NS             (1u)
    #define capsense_SH_DELAY_10NS            (2u)
    #define capsense_SH_DELAY_20NS            (3u)
#else
    #if(capsense_ENABLE == capsense_CSDV1_VER2)
        #define capsense_SH_DELAY_10NS        (3u)
        #define capsense_SH_DELAY_50NS        (2u)
    #else
        #define capsense_SH_DELAY_1CYCLES     (1u)
        #define capsense_SH_DELAY_2CYCLES     (2u)
    #endif /* (capsense_ENABLE == capsense_CSDV1_VER2) */
#endif /* (capsense_ENABLE == capsense_CSDV2) */

/* Inactive sensor connection options */
#define capsense_SNS_CONNECTION_GROUND        (0x00000000u)
#define capsense_SNS_CONNECTION_HIGHZ         (0x00000001u)
#define capsense_SNS_CONNECTION_SHIELD        (0x00000002u)
#define capsense_SNS_CONNECTION_UNDEFINED     (0x00000003u)

/* Sense clock selection options */
#if defined(capsense_TAPEOUT_STAR_USED)
    #define capsense_CSDV2_REF9P6UA_EN            (0u)
#else
    #define capsense_CSDV2_REF9P6UA_EN            (1u)
#endif /* defined(capsense_TAPEOUT_STAR_USED) */

#define capsense_CLK_SOURCE_DIRECT            (0x00000000Lu)

#define capsense_CLK_SOURCE_SSC1              (0x01u)
#define capsense_CLK_SOURCE_SSC2              (0x02u)
#define capsense_CLK_SOURCE_SSC3              (0x03u)
#define capsense_CLK_SOURCE_SSC4              (0x04u)

#define capsense_CLK_SOURCE_PRS8              (0x05u)
#define capsense_CLK_SOURCE_PRS12             (0x06u)
#define capsense_CLK_SOURCE_PRSAUTO           (0xFFu)

#define capsense_MFS_IMO                      (0u)
#define capsense_MFS_SNS_CLK                  (1u)

/* Defines scan resolutions */
#define capsense_RES6BIT                      (6u)
#define capsense_RES7BIT                      (7u)
#define capsense_RES8BIT                      (8u)
#define capsense_RES9BIT                      (9u)
#define capsense_RES10BIT                     (10u)
#define capsense_RES11BIT                     (11u)
#define capsense_RES12BIT                     (12u)
#define capsense_RES13BIT                     (13u)
#define capsense_RES14BIT                     (14u)
#define capsense_RES15BIT                     (15u)
#define capsense_RES16BIT                     (16u)

/* Fourth-generation HW block: Initialization switch resistance */
#define capsense_INIT_SW_RES_LOW              (0x00000000Lu)
#define capsense_INIT_SW_RES_MEDIUM           (0x00000001Lu)
#define capsense_INIT_SW_RES_HIGH             (0x00000002Lu)

/* Fourth-generation HW block: Initialization switch resistance */
#define capsense_SCAN_SW_RES_LOW              (0x00000000Lu)
#define capsense_SCAN_SW_RES_MEDIUM           (0x00000001Lu)
#define capsense_SCAN_SW_RES_HIGH             (0x00000002Lu)

/* Fourth-generation HW block: CSD shield switch resistance */
#define capsense_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define capsense_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define capsense_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define capsense_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/* Fourth-generation HW block: CSD shield switch resistance */
#define capsense_INIT_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define capsense_INIT_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define capsense_INIT_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define capsense_INIT_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* Fourth-generation HW block: CSD shield switch resistance */
#define capsense_SCAN_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define capsense_SCAN_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define capsense_SCAN_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define capsense_SCAN_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* Sensing method */
#define capsense_SENSING_LEGACY               (0x00000000Lu)
#define capsense_SENSING_LOW_EMI              (0x00000001Lu)
#define capsense_SENSING_FULL_WAVE            (0x00000002Lu)


/*******************************************************************************
* CSD/CSX Common Settings
*******************************************************************************/

#define capsense_BLOCK_ANALOG_WAKEUP_DELAY_US (0u)

#define capsense_MFS_METHOD                   (0u)
#define capsense_IMO_FREQUENCY_OFFSET_F1      (20u)
#define capsense_IMO_FREQUENCY_OFFSET_F2      (20u)

/*******************************************************************************
* CSD Specific Settings
*******************************************************************************/

/* CSD scan method settings */
#define capsense_CSD_IDAC_AUTOCAL_EN          (1u)
#define capsense_CSD_IDAC_GAIN                (capsense_IDAC_GAIN_HIGH)
#define capsense_CSD_SHIELD_EN                (0u)
#define capsense_CSD_SHIELD_TANK_EN           (0u)
#define capsense_CSD_CSH_PRECHARGE_SRC        (capsense_CSH_PRECHARGE_VREF)
#define capsense_CSD_SHIELD_DELAY             (capsense_NO_DELAY)
#define capsense_CSD_TOTAL_SHIELD_COUNT       (0u)
#define capsense_CSD_SCANSPEED_DIVIDER        (1u)
#define capsense_CSD_COMMON_SNS_CLK_EN        (0u)
#define capsense_CSD_SNS_CLK_SOURCE           (capsense_CLK_SOURCE_PRSAUTO)
#define capsense_CSD_SNS_CLK_DIVIDER          (8u)
#define capsense_CSD_INACTIVE_SNS_CONNECTION  (capsense_SNS_CONNECTION_GROUND)
#define capsense_CSD_IDAC_COMP_EN             (1u)
#define capsense_CSD_IDAC_CONFIG              (capsense_IDAC_SOURCING)
#define capsense_CSD_RAWCOUNT_CAL_LEVEL       (85u)
#define capsense_CSD_DUALIDAC_LEVEL           (50u)
#define capsense_CSD_PRESCAN_SETTLING_TIME    (5u)
#define capsense_CSD_SNSCLK_R_CONST           (1000u)
#define capsense_CSD_VREF_MV                  (2743u)

#define capsense_CSD_CALIBRATION_ERROR        (10u)
#define capsense_CSD_IDAC_AUTO_GAIN_EN        (1u)
#define capsense_CSD_IDAC_GAIN_INDEX_DEFAULT  (4u)
#define capsense_CSD_IDAC_MIN                 (20u)
#define capsense_CSD_COL_ROW_IDAC_ALIGNMENT_EN      (1u)

/* The macro is obsolete and should not be used */
#define capsense_CSD_DEDICATED_IDAC_COMP_EN   (1u)
/* CSD settings - Fourth-generation HW block */
#define capsense_CSD_ANALOG_STARTUP_DELAY_US  (10u)
#define capsense_CSD_FINE_INIT_TIME           (10u)
#define capsense_CSD_AUTO_ZERO_EN             (0u)
#define capsense_CSD_AUTO_ZERO_TIME           (15Lu)
#define capsense_CSD_NOISE_METRIC_EN          (0u)
#define capsense_CSD_NOISE_METRIC_TH          (1Lu)
#define capsense_CSD_INIT_SWITCH_RES          (capsense_INIT_SW_RES_MEDIUM)
#define capsense_CSD_SENSING_METHOD           (0)
#define capsense_CSD_SHIELD_SWITCH_RES        (capsense_SHIELD_SW_RES_MEDIUM)
#define capsense_CSD_GAIN                     (13Lu)

#define capsense_CSD_MFS_DIVIDER_OFFSET_F1    (1u)
#define capsense_CSD_MFS_DIVIDER_OFFSET_F2    (2u)

/*******************************************************************************
* CSX Specific Settings
*******************************************************************************/

/* CSX scan method settings */
#define capsense_CSX_SCANSPEED_DIVIDER        (1u)
#define capsense_CSX_COMMON_TX_CLK_EN         (0u)
#define capsense_CSX_TX_CLK_SOURCE            (capsense_CLK_SOURCE_PRSAUTO)
#define capsense_CSX_TX_CLK_DIVIDER           (80u)
#define capsense_CSX_INACTIVE_SNS_CONNECTION  (capsense_SNS_CONNECTION_GROUND)
#define capsense_CSX_MAX_FINGERS              (1u)
#define capsense_CSX_MAX_LOCAL_PEAKS          (5u)
#define capsense_CSX_IDAC_AUTOCAL_EN          (1u)
#define capsense_CSX_IDAC_BITS_USED           (7u)
#define capsense_CSX_RAWCOUNT_CAL_LEVEL       (40u)
#define capsense_CSX_IDAC_GAIN                (capsense_IDAC_GAIN_MEDIUM)
#define capsense_CSX_CALIBRATION_ERROR        (20u)
#define capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define capsense_CSX_MULTIPHASE_TX_EN         (0u)
#define capsense_CSX_MAX_TX_PHASE_LENGTH      (0u)

/* CSX settings - Fourth-generation HW block */
#define capsense_CSX_ANALOG_STARTUP_DELAY_US  (10u)
#define capsense_CSX_AUTO_ZERO_EN             (0u)
#define capsense_CSX_AUTO_ZERO_TIME           (15u)
#define capsense_CSX_FINE_INIT_TIME           (4u)
#define capsense_CSX_NOISE_METRIC_EN          (0u)
#define capsense_CSX_NOISE_METRIC_TH          (1u)
#define capsense_CSX_INIT_SWITCH_RES          (capsense_INIT_SW_RES_MEDIUM)
#define capsense_CSX_SCAN_SWITCH_RES          (capsense_SCAN_SW_RES_LOW)
#define capsense_CSX_INIT_SHIELD_SWITCH_RES   (capsense_INIT_SHIELD_SW_RES_HIGH)
#define capsense_CSX_SCAN_SHIELD_SWITCH_RES   (capsense_SCAN_SHIELD_SW_RES_LOW)

#define capsense_CSX_MFS_DIVIDER_OFFSET_F1    (1u)
#define capsense_CSX_MFS_DIVIDER_OFFSET_F2    (2u)

/* Gesture parameters */
#define capsense_GES_GLOBAL_EN                (0u)

/*******************************************************************************
* ISX Specific Settings
*******************************************************************************/

/* ISX scan method settings */
#define capsense_ISX_SCANSPEED_DIVIDER        (1u)
#define capsense_ISX_LX_CLK_DIVIDER           (80u)
#define capsense_ISX_IDAC_AUTOCAL_EN          (0u)
#define capsense_ISX_IDAC_BITS_USED           (7u)
#define capsense_ISX_RAWCOUNT_CAL_LEVEL       (30u)
#define capsense_ISX_IDAC_GAIN                (capsense_IDAC_GAIN_MEDIUM)
#define capsense_ISX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define capsense_ISX_MAX_TX_PHASE_LENGTH      (0u)
#define capsense_ISX_PIN_COUNT_LX             (u)
/* ISX settings - Fourth-generation HW block */
#define capsense_ISX_AUTO_ZERO_EN             (0u)
#define capsense_ISX_AUTO_ZERO_TIME           (15u)
#define capsense_ISX_FINE_INIT_TIME           (20u)
#define capsense_ISX_NOISE_METRIC_EN          (0u)
#define capsense_ISX_NOISE_METRIC_TH          (1u)
#define capsense_ISX_INIT_SWITCH_RES          (capsense_INIT_SW_RES_MEDIUM)
#define capsense_ISX_SCAN_SWITCH_RES          (capsense_SCAN_SW_RES_LOW)
#define capsense_ISX_INIT_SHIELD_SWITCH_RES   (capsense_INIT_SHIELD_SW_RES_HIGH)
#define capsense_ISX_SCAN_SHIELD_SWITCH_RES   (capsense_SCAN_SHIELD_SW_RES_LOW)
#define capsense_ISX_SAMPLE_PHASE_DEG         (30u)

/*******************************************************************************
* Global Parameter Definitions
*******************************************************************************/

/* Compound section definitions */
#define capsense_ANY_NONSS_AUTOCAL ((0u != capsense_CSX_IDAC_AUTOCAL_EN) || \
                                       (0u != capsense_ISX_IDAC_AUTOCAL_EN) || \
                                      ((capsense_CSD_AUTOTUNE == capsense_CSD_SS_DIS) && (0u != capsense_CSD_IDAC_AUTOCAL_EN)))
#define capsense_ANYMODE_AUTOCAL (((0u != capsense_CSX_IDAC_AUTOCAL_EN) \
                                       || (0u != capsense_ISX_IDAC_AUTOCAL_EN)) \
                                       || (0u != capsense_CSD_IDAC_AUTOCAL_EN))
/* RAM Global Parameters Definitions */
#define capsense_CONFIG_ID                      (0x70F0u)
#define capsense_DEVICE_ID                      (0x0900u)
#define capsense_HW_CLOCK                       (0x0BB8u)
#define capsense_CSD0_CONFIG                    (0x0008u)

/*******************************************************************************
* BTN0 initialization values for FLASH data structure
*******************************************************************************/
#define capsense_BTN0_STATIC_CONFIG             (10249u)
#define capsense_BTN0_NUM_SENSORS               (1u)

/*******************************************************************************
* BTN0 initialization values for RAM data structure
*******************************************************************************/
#define capsense_BTN0_RESOLUTION                (100u)
#define capsense_BTN0_FINGER_TH                 (100u)
#define capsense_BTN0_NOISE_TH                  (40u)
#define capsense_BTN0_NNOISE_TH                 (40u)
#define capsense_BTN0_HYSTERESIS                (10u)
#define capsense_BTN0_ON_DEBOUNCE               (3u)
#define capsense_BTN0_LOW_BSLN_RST              (30u)
#define capsense_BTN0_IDAC_MOD0                 (32u)
#define capsense_BTN0_IDAC_GAIN_INDEX           (2u)
#define capsense_BTN0_SNS_CLK                   (80u)
#define capsense_BTN0_SNS_CLK_SOURCE            (0u)

/*******************************************************************************
* BTN1 initialization values for FLASH data structure
*******************************************************************************/
#define capsense_BTN1_STATIC_CONFIG             (10241u)
#define capsense_BTN1_NUM_SENSORS               (1u)

/*******************************************************************************
* BTN1 initialization values for RAM data structure
*******************************************************************************/
#define capsense_BTN1_RESOLUTION                (100u)
#define capsense_BTN1_FINGER_TH                 (100u)
#define capsense_BTN1_NOISE_TH                  (40u)
#define capsense_BTN1_NNOISE_TH                 (40u)
#define capsense_BTN1_HYSTERESIS                (10u)
#define capsense_BTN1_ON_DEBOUNCE               (3u)
#define capsense_BTN1_LOW_BSLN_RST              (30u)
#define capsense_BTN1_IDAC_MOD0                 (32u)
#define capsense_BTN1_IDAC_GAIN_INDEX           (2u)
#define capsense_BTN1_SNS_CLK                   (80u)
#define capsense_BTN1_SNS_CLK_SOURCE            (0u)

/*******************************************************************************
* BTN2 initialization values for FLASH data structure
*******************************************************************************/
#define capsense_BTN2_STATIC_CONFIG             (10241u)
#define capsense_BTN2_NUM_SENSORS               (1u)

/*******************************************************************************
* BTN2 initialization values for RAM data structure
*******************************************************************************/
#define capsense_BTN2_RESOLUTION                (100u)
#define capsense_BTN2_FINGER_TH                 (100u)
#define capsense_BTN2_NOISE_TH                  (40u)
#define capsense_BTN2_NNOISE_TH                 (40u)
#define capsense_BTN2_HYSTERESIS                (10u)
#define capsense_BTN2_ON_DEBOUNCE               (3u)
#define capsense_BTN2_LOW_BSLN_RST              (30u)
#define capsense_BTN2_IDAC_MOD0                 (32u)
#define capsense_BTN2_IDAC_GAIN_INDEX           (2u)
#define capsense_BTN2_SNS_CLK                   (80u)
#define capsense_BTN2_SNS_CLK_SOURCE            (0u)

/*******************************************************************************
* LinearSlider initialization values for FLASH data structure
*******************************************************************************/
#define capsense_LINEARSLIDER_STATIC_CONFIG     (10241u)
#define capsense_LINEARSLIDER_NUM_SENSORS       (5u)
#define capsense_LINEARSLIDER_X_RESOLUTION      (100u)
#define capsense_LINEARSLIDER_X_CENT_MULT       ((capsense_LINEARSLIDER_X_RESOLUTION * 256u) / \
                                                 (capsense_LINEARSLIDER_NUM_SENSORS - 1u))
#define capsense_LINEARSLIDER_IIR_FILTER_COEFF  (128u)

/*******************************************************************************
* LinearSlider initialization values for RAM data structure
*******************************************************************************/
#define capsense_LINEARSLIDER_RESOLUTION        (capsense_RES12BIT)
#define capsense_LINEARSLIDER_FINGER_TH         (100u)
#define capsense_LINEARSLIDER_NOISE_TH          (40u)
#define capsense_LINEARSLIDER_NNOISE_TH         (40u)
#define capsense_LINEARSLIDER_HYSTERESIS        (10u)
#define capsense_LINEARSLIDER_ON_DEBOUNCE       (3u)
#define capsense_LINEARSLIDER_LOW_BSLN_RST      (30u)
#define capsense_LINEARSLIDER_IDAC_MOD0         (32u)
#define capsense_LINEARSLIDER_IDAC_GAIN_INDEX   (4u)
#define capsense_LINEARSLIDER_SNS_CLK           (8u)
#define capsense_LINEARSLIDER_SNS_CLK_SOURCE    (0u)
#define capsense_LINEARSLIDER_POSITION          (0xFFFFu)

/* RAM Sensor Parameters Definitions */
#define capsense_BTN0_RX0_IDAC_COMP0            (32u)
#define capsense_BTN1_RX0_IDAC_COMP0            (32u)
#define capsense_BTN2_RX0_IDAC_COMP0            (32u)
#define capsense_LINEARSLIDER_SNS0_IDAC_COMP0   (32u)
#define capsense_LINEARSLIDER_SNS1_IDAC_COMP0   (32u)
#define capsense_LINEARSLIDER_SNS2_IDAC_COMP0   (32u)
#define capsense_LINEARSLIDER_SNS3_IDAC_COMP0   (32u)
#define capsense_LINEARSLIDER_SNS4_IDAC_COMP0   (32u)



/*******************************************************************************
* ADC Specific Macros
*******************************************************************************/
#define capsense_ADC_RES8BIT                  (8u)
#define capsense_ADC_RES10BIT                 (10u)

#define capsense_ADC_FULLRANGE_MODE           (0u)
#define capsense_ADC_VREF_MODE                (1u)

#define capsense_ADC_MIN_CHANNELS             (1u)
#define capsense_ADC_EN                       (0u)
#define capsense_ADC_STANDALONE_EN            (0u)
#define capsense_ADC_TOTAL_CHANNELS           (1u)
#define capsense_ADC_RESOLUTION               (capsense_ADC_RES10BIT)
#define capsense_ADC_AMUXB_INPUT_EN           (0u)
#define capsense_ADC_SELECT_AMUXB_CH          (0u)
#define capsense_ADC_AZ_EN                    (1Lu)
#define capsense_ADC_AZ_TIME                  (5u)
#define capsense_ADC_VREF_MV                  (3840u)
#define capsense_ADC_GAIN                     (9Lu)
#define capsense_ADC_IDAC_DEFAULT             (27u)
#define capsense_ADC_MODCLK_DIV_DEFAULT       (1u)
#define capsense_ADC_MEASURE_MODE             (capsense_ADC_FULLRANGE_MODE)
#define capsense_ADC_ANALOG_STARTUP_DELAY_US  (5u)
#define capsense_ADC_ACQUISITION_TIME_US      (10u)

/*******************************************************************************
* Built-In Self-Test Configuration
*******************************************************************************/
#define capsense_SELF_TEST_EN                   (0Lu)
#define capsense_TST_GLOBAL_CRC_EN              (0Lu)
#define capsense_TST_WDGT_CRC_EN                (0Lu)
#define capsense_TST_BSLN_DUPLICATION_EN        (0Lu)
#define capsense_TST_BSLN_RAW_OUT_RANGE_EN      (0Lu)
#define capsense_TST_SNS_SHORT_EN               (0Lu)
#define capsense_TST_SNS_CAP_EN                 (0Lu)
#define capsense_TST_SH_CAP_EN                  (0Lu)
#define capsense_TST_EXTERNAL_CAP_EN            (0Lu)
#define capsense_TST_VDDA_EN                    (0Lu)


#define capsense_GLOBAL_CRC_AREA_START          (0u)
#define capsense_GLOBAL_CRC_AREA_SIZE           (0u)
#define capsense_WIDGET_CRC_AREA_START          (0u)
#define capsense_WIDGET_CRC_AREA_SIZE           (0u)

/* The resolution for sensor capacity measurement */
#define capsense_TST_SNS_CAP_RESOLUTION         (12u)

/* VDDA measurement test configuration */
/* The resolution for VDDA measurement */
#define capsense_TST_VDDA_RESOLUTION            (10u)
/* The ModClk divider for external capacitor capacity measurement */
#define capsense_TST_VDDA_MOD_CLK_DIVIDER       (1u)

#define capsense_TST_VDDA_VREF_MV               (0u)
#define capsense_TST_VDDA_VREF_GAIN             (0u)
#define capsense_TST_VDDA_IDAC_DEFAULT          (0u)

#define capsense_TST_FINE_INIT_TIME             (10u)
#define capsense_TST_ANALOG_STARTUP_DELAY_US    (23u)

#define capsense_TST_IDAC_AUTO_GAIN_EN          (1u)
#define capsense_TST_SNS_CAP_RAW_ERROR          (10u)
#define capsense_TST_IDAC_GAIN_INDEX            (0xFFu)
#define capsense_TST_RAW_TARGET                 (85u)

#define capsense_TST_SNS_SHORT_TIME             (2u)

#define capsense_SNS_CAP_CSD_INACTIVE_CONNECTION        (capsense_SNS_CONNECTION_GROUND)
#define capsense_SNS_CAP_CSX_INACTIVE_CONNECTION        (capsense_SNS_CONNECTION_GROUND)
#define capsense_SHIELD_CAP_INACTIVE_CONNECTION         (capsense_SNS_CONNECTION_GROUND)


/*******************************************************************************
* Gesture Configuration
*******************************************************************************/
#define capsense_TIMESTAMP_INTERVAL             (1Lu)
#define capsense_GESTURE_EN_WIDGET_ID           (0Lu)
#define capsense_BALLISTIC_EN_WIDGET_ID         (0Lu)


#endif /* CY_SENSE_capsense_CONFIGURATION_H */


/* [] END OF FILE */
