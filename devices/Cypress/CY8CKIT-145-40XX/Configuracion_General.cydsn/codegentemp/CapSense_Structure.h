/***************************************************************************//**
* \file CapSense_Structure.h
* \version 7.10
*
* \brief
*   This file provides the top level declarations of the Component data structure.
*   Also, the file declares the high-level and low-level APIs for data access.
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

#if !defined(CY_SENSE_CapSense_STRUCTURE_H)
#define CY_SENSE_CapSense_STRUCTURE_H

#include <cytypes.h>
#include "cyfitter.h"
#include "CapSense_Configuration.h"
#if (CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE)
    #include "CapSense_SmartSense_LL.h"
#endif

#if (CapSense_ENABLE == CapSense_ALP_FILTER_EN)
    #include "CapSense_AlpFilter_LL.h"
#endif

#if ((CapSense_ENABLE == CapSense_GES_GLOBAL_EN) ||\
     (CapSense_ENABLE == CapSense_BALLISTIC_MULTIPLIER_EN))
    #include "CapSense_TMG.h"
#endif

#if (CapSense_ENABLE == CapSense_CENTROID_5X5_CSD_EN)
    #include "CapSense_AdvancedCentroid_LL.h"
#endif

#if (CapSense_ENABLE == CapSense_POS_ADAPTIVE_IIR_FILTER_EN)
    #include "CapSense_AdaptiveFilter_LL.h"
#endif

/*******************************************************************************
* Constant Definitions
*******************************************************************************/

/* Defines size of Sensor Status Register in Data Structure */
#define CapSense_SNS_STS_TYPE               uint8

/* No touch condition for slider position report */
#define CapSense_SLIDER_NO_TOUCH            (0xFFFFu)
#define CapSense_TOUCHPAD_NO_TOUCH          (0xFFFFFFFFLu)

#define CapSense_SLIDER_POS_NONE            (0xFFFFu)
#define CapSense_TOUCHPAD_POS_NONE          (0xFFFFu)

#define CapSense_MATRIX_POS_NONE            (0xFFu)
#define CapSense_MATRIX_POS_MULTI           (0xFEu)

#define CapSense_PROX_STS_MASK              (3Lu)
#define CapSense_PROX_STS_OFFSET(proxId)    ((proxId) << 1u)

#define CapSense_MATRIX_BUTTONS_TOUCHED     (0x80000000Lu)

/*******************************************************************************
* Enumeration types definition
*******************************************************************************/

/***************************************************************************//**
* \brief Defines widget types
*******************************************************************************/
typedef enum
{
    CapSense_WD_BUTTON_E        = 0x01u,
    CapSense_WD_LINEAR_SLIDER_E = 0x02u,
    CapSense_WD_RADIAL_SLIDER_E = 0x03u,
    CapSense_WD_MATRIX_BUTTON_E = 0x04u,
    CapSense_WD_TOUCHPAD_E      = 0x05u,
    CapSense_WD_PROXIMITY_E     = 0x06u,
    CapSense_WD_ENCODERDIAL_E   = 0x07u
} CapSense_WD_TYPE_ENUM;


/***************************************************************************//**
* \brief Defines sensing methods types
*******************************************************************************/
typedef enum
{
    CapSense_UNDEFINED_E            = 0x00u,
    CapSense_SENSE_METHOD_CSD_E     = 0x01u,
    CapSense_SENSE_METHOD_CSX_E     = 0x02u,
    CapSense_SENSE_METHOD_BIST_E    = 0x03u,
    CapSense_SENSE_METHOD_ISX_E     = 0x04u,
} CapSense_SENSE_METHOD_ENUM;

/***************************************************************************//**
* \brief Defines electrode types
*******************************************************************************/
typedef enum
{
    CapSense_ELTD_TYPE_SELF_E   = 0x01u,
    CapSense_ELTD_TYPE_MUT_TX_E = 0x02u,
    CapSense_ELTD_TYPE_MUT_RX_E = 0x03u
} CapSense_ELTD_TYPE_ENUM;


/***************************************************************************//**
* \brief Built-in Self-test measurement functions return status enumeration type
*******************************************************************************/
typedef enum
{
  CapSense_TST_MEASUREMENT_SUCCESS = 0x00uL,
/* function complete successfully, a measurement result is valid */
  CapSense_TST_MEASUREMENT_BAD_PARAM = 0x01uL,
/* any of input parameters (widgetID, electrodeId, shieldId, integrationCapId) is invalid or any of pointers
   are null, function incomplete, a measurement result is invalid */
  CapSense_TST_MEASUREMENT_BAD_DATA = 0x02uL,
/* a measurement result is invalid */
  CapSense_TST_MEASUREMENT_ERROR = 0x03uL,
/* some fault occurred during the measurement, for instance a sensor short, a measurement result is invalid */
  CapSense_TST_MEASUREMENT_LOW_LIMIT = 0x04uL,
/* Raw count is equal to a minimum value (FilterDelay * NumberOfConversions). A measurement result is invalid.
   A sensor or Cmod should be shorted to VDD */
  CapSense_TST_MEASUREMENT_HIGH_LIMIT = 0x05uL,
/* Raw count is above 45% of the maximum value (2^Resolution – 1). A measurement result is invalid.
   A possible root cause: sensor or Cmod are shorted to GND */
  CapSense_TST_MEASUREMENT_OVERFLOW = 0x06uL,
/* Raw count is above the maximum value (2^Resolution – 1). A measurement result is invalid.
   A possible root cause: a sensor or Cmod are shorted to GND */
  CapSense_TST_MEASUREMENT_TIMEOUT = 0x07uL,
/* Any of measurement scan is not complete. A measurement result is invalid.
   A possible root cause: BIST measurement is not configured properly (CSD HW block is not configured properly: PeriClk, SnsClk, Vref,
   IDAC Gain/Code are not valid. ISR is not configured properly */
}CapSense_TST_MEASUREMENT_STATUS_ENUM;


/**
* \cond SECTION_STRUCTURES
* \addtogroup group_structures
* \{
*/
/*******************************************************************************
* Declares RAM structures for all used widgets
*******************************************************************************/

/***************************************************************************//**
* \brief Declares common widget RAM parameters
*******************************************************************************/
typedef struct
{
    /**
     *  Provides scan resolution or number of sub-conversions.
     */
    uint16 resolution;

    /**
     *  Widget Finger Threshold.
     */
    CapSense_THRESHOLD_TYPE fingerTh;

    /**
     *  Widget Noise Threshold.
     */
    uint8  noiseTh;

    /**
     *  Widget Negative Noise Threshold.
     */
    uint8  nNoiseTh;

    /**
     *  Widget Hysteresis for the signal crossing finger or touch/proximity 
     *  threshold.
     */
    uint8  hysteresis;

    /**
     *  Widget Debounce for the signal above the finger or touch/proximity 
     *  threshold. OFF to ON.
     */
    uint8  onDebounce;

    /**
     *  The widget low baseline reset count. Specifies the number of 
     *  samples the sensor has to be below the Negative Noise 
     *  Threshold to trigger a baseline reset.
     */
    CapSense_LOW_BSLN_RST_TYPE lowBslnRst;

    /**
     *  Sets the current of the modulation IDAC for the widgets. 
     *  For the CSD Touchpad and Matrix Button widgets, sets 
     *  the current of the modulation IDAC for the column sensors.
     */
    uint8  idacMod [CapSense_NUM_SCAN_FREQS];

    /**
     *  The index of the IDAC gain in the IDAC gain table structure for the widgets.
     */
    uint8  idacGainIndex;

    /**
     *  Specifies the sense clock divider. Present only if individual 
     *  clock dividers are enabled. Specifies the sense clock divider 
     *  for the Column sensors for the Matrix Buttons and Touchpad 
     *  widgets. Sets Tx clock divider for CSX Widgets.
     */
    uint16 snsClk;

    /**
     *  Register for internal use
     */
    uint8  snsClkSource;
} CapSense_RAM_WD_BASE_STRUCT;

/***************************************************************************//**
* \brief Declares RAM parameters for the CSX Button
*******************************************************************************/
typedef struct
{
    /**
     *  Provides scan resolution or number of sub-conversions.
     */
    uint16 resolution;

    /**
     *  Widget Finger Threshold.
     */
    CapSense_THRESHOLD_TYPE fingerTh;

    /**
     *  Widget Noise Threshold.
     */
    uint8  noiseTh;

    /**
     *  Widget Negative Noise Threshold.
     */
    uint8  nNoiseTh;

    /**
     *  Widget Hysteresis for the signal crossing finger or touch/proximity 
     *  threshold.
     */
    uint8  hysteresis;

    /**
     *  Widget Debounce for the signal above the finger or touch/proximity 
     *  threshold. OFF to ON.
     */
    uint8  onDebounce;

    /**
     *  The widget low baseline reset count. Specifies the number of 
     *  samples the sensor has to be below the Negative Noise 
     *  Threshold to trigger a baseline reset.
     */
    CapSense_LOW_BSLN_RST_TYPE lowBslnRst;

    /**
     *  Sets the current of the modulation IDAC for the widgets. 
     *  For the CSD Touchpad and Matrix Button widgets, sets 
     *  the current of the modulation IDAC for the column sensors.
     */
    uint8  idacMod [CapSense_NUM_SCAN_FREQS];

    /**
     *  The index of the IDAC gain in the IDAC gain table structure for the widgets.
     */
    uint8  idacGainIndex;

    /**
     *  Specifies the sense clock divider. Present only if individual 
     *  clock dividers are enabled. Specifies the sense clock divider 
     *  for the Column sensors for the Matrix Buttons and Touchpad 
     *  widgets. Sets Tx clock divider for CSX Widgets.
     */
    uint16 snsClk;

    /**
     *  Register for internal use
     */
    uint8  snsClkSource;
} CapSense_RAM_WD_BUTTON_STRUCT;

/***************************************************************************//**
* \brief Declares RAM parameters for the Slider
*******************************************************************************/
typedef struct
{
    /**
     *  Provides scan resolution or number of sub-conversions.
     */
    uint16 resolution;

    /**
     *  Widget Finger Threshold.
     */
    CapSense_THRESHOLD_TYPE fingerTh;

    /**
     *  Widget Noise Threshold.
     */
    uint8  noiseTh;

    /**
     *  Widget Negative Noise Threshold.
     */
    uint8  nNoiseTh;

    /**
     *  Widget Hysteresis for the signal crossing finger or touch/proximity 
     *  threshold.
     */
    uint8  hysteresis;

    /**
     *  Widget Debounce for the signal above the finger or touch/proximity 
     *  threshold. OFF to ON.
     */
    uint8  onDebounce;

    /**
     *  The widget low baseline reset count. Specifies the number of 
     *  samples the sensor has to be below the Negative Noise 
     *  Threshold to trigger a baseline reset.
     */
    CapSense_LOW_BSLN_RST_TYPE lowBslnRst;

    /**
     *  Sets the current of the modulation IDAC for the widgets. 
     *  For the CSD Touchpad and Matrix Button widgets, sets 
     *  the current of the modulation IDAC for the column sensors.
     */
    uint8  idacMod [CapSense_NUM_SCAN_FREQS];

    /**
     *  The index of the IDAC gain in the IDAC gain table structure for the widgets.
     */
    uint8  idacGainIndex;

    /**
     *  Specifies the sense clock divider. Present only if individual 
     *  clock dividers are enabled. Specifies the sense clock divider 
     *  for the Column sensors for the Matrix Buttons and Touchpad 
     *  widgets. Sets Tx clock divider for CSX Widgets.
     */
    uint16 snsClk;

    /**
     *  Register for internal use
     */
    uint8  snsClkSource;

    /**
     *  Reports the widget position.
     */
    uint16 position [CapSense_NUM_CENTROIDS];
} CapSense_RAM_WD_SLIDER_STRUCT;


/***************************************************************************//**
* \brief Declares RAM structure with all defined widgets
*******************************************************************************/
typedef struct
{
    /**
     *  BTN0 widget RAM structure
     */
    CapSense_RAM_WD_BUTTON_STRUCT btn0;

    /**
     *  BTN1 widget RAM structure
     */
    CapSense_RAM_WD_BUTTON_STRUCT btn1;

    /**
     *  BTN2 widget RAM structure
     */
    CapSense_RAM_WD_BUTTON_STRUCT btn2;

    /**
     *  LinearSlider widget RAM structure
     */
    CapSense_RAM_WD_SLIDER_STRUCT linearslider;
} CapSense_RAM_WD_LIST_STRUCT;


/***************************************************************************//**
* \brief Declares RAM structure for sensors
*******************************************************************************/
typedef struct
{
    /**
     *  The sensor raw counts.
     */
    uint16 raw [CapSense_NUM_SCAN_FREQS];

    /**
     *  The sensor baseline.
     */
    uint16 bsln [CapSense_NUM_SCAN_FREQS];

    /**
     *  For the bucket baseline algorithm holds the bucket state, 
     *  For the IIR baseline keeps LSB of the baseline value.
     */
    uint8  bslnExt [CapSense_NUM_SCAN_FREQS];

    /**
     *  Sensor differences.
     */
    CapSense_THRESHOLD_TYPE diff;

    /**
     *  The baseline reset counter for the low baseline reset function.
     */
    CapSense_LOW_BSLN_RST_TYPE negBslnRstCnt [CapSense_NUM_SCAN_FREQS];

    /**
     *  The compensation IDAC value or the balancing IDAC value.
     */
    uint8  idacComp [CapSense_NUM_SCAN_FREQS];
} CapSense_RAM_SNS_STRUCT;


/***************************************************************************//**
* \brief Declares RAM structure with all defined sensors
*******************************************************************************/
typedef struct
{
    /**
     *  BTN0 sensors RAM structures array
     */
    CapSense_RAM_SNS_STRUCT btn0         [CapSense_BTN0_NUM_SENSORS];

    /**
     *  BTN1 sensors RAM structures array
     */
    CapSense_RAM_SNS_STRUCT btn1         [CapSense_BTN1_NUM_SENSORS];

    /**
     *  BTN2 sensors RAM structures array
     */
    CapSense_RAM_SNS_STRUCT btn2         [CapSense_BTN2_NUM_SENSORS];

    /**
     *  LinearSlider sensors RAM structures array
     */
    CapSense_RAM_SNS_STRUCT linearslider [CapSense_LINEARSLIDER_NUM_SENSORS];
} CapSense_RAM_SNS_LIST_STRUCT;


/***************************************************************************//**
* \brief Declares the top-level RAM Data Structure
*******************************************************************************/
typedef struct
{
    /**
     *  16-bit CRC calculated by the customizer for the component 
     *  configuration. Used by the Tuner application to identify if 
     *  the FW corresponds to the specific user configuration.
     */
    uint16 configId;

    /**
     *  Used by the Tuner application to identify device-specific configuration.
     */
    uint16 deviceId;

    /**
     *  Used by the Tuner application to identify the system clock frequency.
     */
    uint16 hwClock;

    /**
     *  Tuner Command Register. Used for the communication 
     *  between the Tuner GUI and the component.
     */
    uint16 tunerCmd;

    /**
     *  This counter gets incremented after each scan.
     */
    uint16 scanCounter;

    /**
     *  Status information: Current Widget, Scan active, Error code.
     */
    volatile uint32 status;

    /**
     *  The bitmask that sets which Widgets are enabled and 
     *  scanned, each bit corresponds to one widget.
     */
    uint32 wdgtEnable [CapSense_WDGT_STATUS_WORDS];

    /**
     *  The bitmask that reports activated Widgets (widgets that 
     *  detect a touch signal above the threshold), each bit 
     *  corresponds to one widget.
     */
    uint32 wdgtStatus [CapSense_WDGT_STATUS_WORDS];

    /**
     *  For Buttons, Sliders, Matrix Buttons and CSD Touchpad each bit 
     *  reports status of the individual sensor of the widget: 1 - active 
     *  (above the finger threshold); 0 - inactive; For the CSD Touchpad 
     *  and CSD Matrix Buttons, the column sensors occupy the least 
     *  significant bits. For the Proximity widget, each sensor uses two 
     *  bits with the following meaning: 00 - Not active; 01 - Proximity 
     *  detected (signal above finger threshold); 11 - A finger touch 
     *  detected (signal above the touch threshold); For the CSX Touchpad 
     *  Widget, this register provides a number of the detected touches. 
     *  The array size is equal to the total number of widgets. The size of 
     *  the array element depends on the max number of sensors per 
     *  widget used in the current design. It could be 1, 2 or 4 bytes.
     */
    CapSense_SNS_STS_TYPE snsStatus [CapSense_TOTAL_WIDGETS];

    /**
     *  The configuration register for global parameters of the 
     *  SENSE_HW0 block.
     */
    uint16 csd0Config;

    /**
     *  The modulator clock divider for the CSD widgets.
     */
    uint8  modCsdClk;

    /**
     *  The modulator clock divider for the CSX widgets.
     */
    uint8  modCsxClk;

    /**
     *  RAM Widget Objects.
     */
    CapSense_RAM_WD_LIST_STRUCT wdgtList;

    /**
     *  RAM Sensor Objects.
     */
    CapSense_RAM_SNS_LIST_STRUCT snsList;

    /**
     *  The selected widget ID.
     */
    uint8  snrTestWidgetId;

    /**
     *  The selected sensor ID.
     */
    uint8  snrTestSensorId;

    /**
     *  The scan counter.
     */
    uint16 snrTestScanCounter;

    /**
     *  The sensor raw counts.
     */
    uint16 snrTestRawCount [CapSense_NUM_SCAN_FREQS];

    /**
     *  The inactive sensor connection state for the CSD sensors.
     */
    uint8  scanCsdISC;

    /**
     *  The inactive sensor connection state for the CSX sensors.
     */
    uint8  scanCsxISC;

    /**
     *  The current inactive sensor connection state for the sensors.
     */
    uint8  scanCurrentISC;
} CapSense_RAM_STRUCT;


/***************************************************************************//**
* \brief Declares the Flash IO object
*******************************************************************************/
typedef struct
{
    /**
     *  Pointer to the HSIOM configuration register of the IO.
     */
    reg32  * hsiomPtr;

    /**
     *  Pointer to the port configuration register of the IO.
     */
    reg32  * pcPtr;

    /**
     *  Pointer to the port data register of the IO.
     */
    reg32  * drPtr;

    /**
     *  Pointer to the pin state data register of the IO.
     */
    reg32  * psPtr;

    /**
     *  IO mask in the HSIOM configuration register.
     */
    uint32   hsiomMask;

    /**
     *  IO mask in the DR and PS registers.
     */
    uint32   mask;

    /**
     *  Position of the IO configuration bits in the HSIOM register.
     */
    uint8    hsiomShift;

    /**
     *  Position of the IO configuration bits in the DR and PS registers.
     */
    uint8    drShift;

    /**
     *  Position of the IO configuration bits in the PC register.
     */
    uint8    shift;
} CapSense_FLASH_IO_STRUCT;


/***************************************************************************//**
* \brief Declares the Flash Electrode object
*******************************************************************************/
typedef struct
{
    /**
     *  Index of the first IO in the Flash IO Object Array.
     */
    uint16 firstPinId;

    /**
     *  Total number of IOs in this sensor.
     */
    uint8  numPins;

    /**
     * Sensor type:
     * \if SECTION_C_DS
     * - ELTD_TYPE_SELF_E - CSD sensor;
     * - ELTD_TYPE_MUT_TX_E - CSX Tx;
     * - ELTD_TYPE_MUT_RX_E - CSX Rx;
     * \endif
     * \if SECTION_I_DS
     * - ELTD_TYPE_MUT_TX_E - ISX Lx sensor;
     * - ELTD_TYPE_MUT_RX_E - ISX Rx sensor;
     * \endif
     */
    uint8  type;
} CapSense_FLASH_SNS_STRUCT;


/***************************************************************************//**
* \brief Declares the structure with all Flash electrode objects
*******************************************************************************/
typedef struct
{
    /**
     *  No ganged sensors available
     */
    uint8 notUsed;
} CapSense_FLASH_SNS_LIST_STRUCT;




/***************************************************************************//**
* \brief Declares Flash widget object
*******************************************************************************/
typedef struct
{
    /**
     *  Points to the array of the FLASH Sensor Objects or FLASH IO 
     *  Objects that belong to this widget. Sensing block uses this 
     *  pointer to access and configure IOs for the scanning. Bit #2 in 
     *  WD_STATIC_CONFIG field indicates the type of array: 
     *  1 - Sensor Object; 0 - IO Object.
     */
    void const * ptr2SnsFlash;

    /**
     *  Points to the Widget Object in RAM. Sensing block uses it to 
     *  access scan parameters. Processing uses it to access threshold 
     *  and widget specific data.
     */
    void * ptr2WdgtRam;

    /**
     *  Points to the array of Sensor Objects in RAM. The sensing and 
     *  processing blocks use it to access the scan data.
     */
    CapSense_RAM_SNS_STRUCT * ptr2SnsRam;

    /**
     *  Points to the array of the Filter History Objects in RAM that 
     *  belongs to this widget.
     */
    void * ptr2FltrHistory;

    /**
     *  Points to the array of the debounce counters. The size of the 
     *  debounce counter is 8 bits. These arrays are not part of the 
     *  data structure.
     */
    uint8 * ptr2DebounceArr;

    /**
     *  Miscellaneous configuration flags.
     */
    uint32 staticConfig;

    /**
     *  The total number of sensors. 
     *  For CSD widgets: WD_NUM_ROWS + WD_NUM_COLS. 
     *  For CSX widgets: WD_NUM_ROWS * WD_NUM_COLS.
     */
    uint16 totalNumSns;

    /**
     *  Specifies one of the following widget types: 
     *  WD_BUTTON_E, WD_LINEAR_SLIDER_E, WD_RADIAL_SLIDER_E, 
     *  WD_MATRIX_BUTTON_E, WD_TOUCHPAD_E, WD_PROXIMITY_E
     */
    uint8  wdgtType;

    /**
     *  Specifies the widget sensing method that could be either 
     *  WD_CSD_SENSE_METHOD or WD_CSX_SENSE_METHOD
     */
    uint8  senseMethod;

    /**
     *  For CSD Button and Proximity Widgets, the number of sensors. 
     *  For CSD Slider Widget, the number of segments. 
     *  For CSD Touchpad and Matrix Button, the number of the 
     *  column sensors. 
     *  For CSX Button, Touchpad and Matrix Button, the number 
     *  of the Rx electrodes.
     */
    uint8  numCols;

    /**
     *  For CSD Touchpad and Matrix Buttons, the number of the row 
     *  sensors. For the CSX Button, the number of the Tx electrodes 
     *  (constant 1u). For CSX Touchpad and Matrix Button, the 
     *  number of the Tx electrodes.
     */
    uint8  numRows;

    /**
     *  Sliders: The Linear/Angular resolution. Touchpad: The X-Axis resolution.
     */
    uint16 xResolution;

    /**
     *  The pre-calculated X resolution centroid multiplier used for 
     *  the X-axis position calculation. Calculated as follows: 
     *  RADIAL: (WD_X_RESOLUTION * 256) / WD_NUM_COLS; 
     *  LINEAR and TOUCHPAD: (WD_X_RESOLUTION * 256) / (WD_NUM_COLS - CONFIG); 
     *  where CONFIG is 0 or 1 depends on CentroidMultiplerMethod parameter
     */
    uint32 xCentroidMultiplier;

    /**
     *  The position IIR filter coefficient.
     */
    uint8  iirFilterCoeff;
} CapSense_FLASH_WD_STRUCT;


/***************************************************************************//**
* \brief Declares top-level Flash Data Structure
*******************************************************************************/
typedef struct
{
    /**
     *  Array of flash widget objects
     */
    CapSense_FLASH_WD_STRUCT wdgtArray[CapSense_TOTAL_WIDGETS];
} CapSense_FLASH_STRUCT;


#if (CapSense_ENABLE == CapSense_TST_BSLN_RAW_OUT_RANGE_EN)
    /***************************************************************************//**
    * \brief Defines the structure for test of baseline and raw count limits which
    * will be determined by user for every sensor grounding on the
    * manufacturing specific data
    *******************************************************************************/
    typedef struct
    {
        /**
         *  Upper limit of a sensor baseline.
         */
        uint16 bslnHiLim;
        /**
         *  Lower limit of a sensor baseline.
         */
        uint16 bslnLoLim;
        /**
         *  Upper limit of a sensor raw count.
         */
        uint16 rawHiLim;
        /**
         *  Lower limit of a sensor raw count.
         */
        uint16 rawLoLim;
    } CapSense_BSLN_RAW_RANGE_STRUCT;
#endif /* (CapSense_ENABLE == CapSense_TST_BSLN_RAW_OUT_RANGE_EN) */

/** \}
* \endcond */


/***************************************************************************//**
* Declares Dual-channel scan structure
*******************************************************************************/
typedef struct
{
    uint8 csd0WidgetId;
    uint8 csd0SensorId;
    uint8 csd1WidgetId;
    uint8 csd1SensorId;
} CapSense_SCAN_SLOT_STRUCT;


/***************************************************************************//**
* Declares Filter module structures
*******************************************************************************/

/***************************************************************************//**
* \brief Declares filter channel structure for regular sensors
*******************************************************************************/
typedef struct
{
    uint16 notUsed;
} CapSense_REGULAR_FLTR_CHANNEL_STRUCT;

/***************************************************************************//**
* \brief Declares filter structure for regular sensors
*******************************************************************************/
typedef struct
{
    /**
     *  Array of CapSense_REGULAR_FLTR_CHANNEL_STRUCT for each available scan frequency
     */
    CapSense_REGULAR_FLTR_CHANNEL_STRUCT regularChannel[CapSense_NUM_SCAN_FREQS];
} CapSense_REGULAR_FLTR_STRUCT;

/***************************************************************************//**
* \brief Declares union for filter structure variants
*******************************************************************************/
typedef union
{
    /**
     *  Pointer to void type
     */
    void *ptr;

    /**
     *  Pointer to CapSense_REGULAR_FLTR_STRUCT type
     */
    CapSense_REGULAR_FLTR_STRUCT *ptrRegular;
} CapSense_PTR_FILTER_VARIANT;


#if (0u != CapSense_POSITION_FILTER_EN)
typedef struct
{
    #if (0u != CapSense_POS_MEDIAN_FILTER_EN)
        uint16 posMedianZ1;
        uint16 posMedianZ2;
    #endif /* #if (0u != CapSense_POS_MEDIAN_FILTER_EN) */

    #if (0u != CapSense_POS_IIR_FILTER_EN)
        uint16 posIIR;
    #endif /* #if (0u != CapSense_POS_IIR_FILTER_EN) */

    #if (0u != CapSense_POS_ADAPTIVE_IIR_FILTER_EN)
        uint16 posAIIR;
    #endif /* (0u != CapSense_POS_ADAPTIVE_IIR_FILTER_EN) */

    #if (0u != CapSense_POS_AVERAGE_FILTER_EN)
        uint16 posAverage;
    #endif /* #if (0u != CapSense_POS_AVERAGE_FILTER_EN) */

    #if (0u != CapSense_POS_JITTER_FILTER_EN)
        uint16 posJitter;
    #endif /* #if (0u != CapSense_POS_JITTER_FILTER_EN) */

    #if (0u != CapSense_POS_ADAPTIVE_IIR_FILTER_EN)
        uint8 posAIIRCoeff;
    #endif /* (0u != CapSense_POS_ADAPTIVE_IIR_FILTER_EN) */
} CapSense_SLIDER_POS_HISTORY_STRUCT;

typedef struct
{
    CapSense_SLIDER_POS_HISTORY_STRUCT xPos;
    CapSense_SLIDER_POS_HISTORY_STRUCT yPos;
} CapSense_TOUCHPAD_POS_HISTORY_STRUCT;
#endif /* (0u != CapSense_POSITION_FILTER_EN) */

/*******************************************************************************
* API Constants
*******************************************************************************/

/*******************************************************************************
* Defines shift/mask values for data structure register bit fields
*******************************************************************************/

/* CSD0_CONFIG bit fields */

/* Bit 0: The multi-frequency scan enable/disable at runtime. This bit 
 * is functional only if the multi-frequency scan functionality 
 * has been activated in general component configuration. */
#define CapSense_MULTI_FREQ_EN_SIZE       (0x00000001Lu)
#define CapSense_MULTI_FREQ_EN_SHIFT      (0u)
#define CapSense_MULTI_FREQ_EN_MASK       (CapSense_MULTI_FREQ_EN_SIZE << CapSense_MULTI_FREQ_EN_SHIFT)

/* Bit 1: The sensor auto-reset is enabled */
#define CapSense_SNS_ARST_SIZE            (0x00000001Lu)
#define CapSense_SNS_ARST_SHIFT           (1u)
#define CapSense_SNS_ARST_MASK            (CapSense_SNS_ARST_SIZE << CapSense_SNS_ARST_SHIFT)

/* Bits 2-3: The IDAC range setting (4x/8x) */
#define CapSense_IDAC_RANGE_SIZE          (0x00000003Lu)
#define CapSense_IDAC_RANGE_SHIFT         (2u)
#define CapSense_IDAC_RANGE_MASK          (CapSense_IDAC_RANGE_SIZE << CapSense_IDAC_RANGE_SHIFT)

/* Bits 4-7: Reserved */

/* Bit 8: The shield electrode signal Enable/Disable */
#define CapSense_SHLD_EN_SIZE             (0x00000001Lu)
#define CapSense_SHLD_EN_SHIFT            (8u)
#define CapSense_SHLD_EN_MASK             (CapSense_SHLD_EN_SIZE << CapSense_SHLD_EN_SHIFT)

/* Bits 9-10: Selects the delay by which the csd_shield is delayed relative 
 * to csd_sense */
#define CapSense_SHLD_DLY_SIZE            (0x00000003Lu)
#define CapSense_SHLD_DLY_SHIFT           (9u)
#define CapSense_SHLD_DLY_MASK            (CapSense_SHLD_DLY_SIZE << CapSense_SHLD_DLY_SHIFT)


/* STATUS bit fields */

/* Bits 0-6: The widget currently selected for SENSE_HW 0 */
#define CapSense_STATUS_WDGT0_SIZE        (0x0000007FLu)
#define CapSense_STATUS_WDGT0_SHIFT       (0u)
#define CapSense_STATUS_WDGT0_MASK        (CapSense_STATUS_WDGT0_SIZE << CapSense_STATUS_WDGT0_SHIFT)

/* Bit 7: The SENSE_HW0 block status */
#define CapSense_STATUS_CSD0_SIZE         (0x00000001Lu)
#define CapSense_STATUS_CSD0_SHIFT        (7u)
#define CapSense_STATUS_CSD0_MASK         (CapSense_STATUS_CSD0_SIZE << CapSense_STATUS_CSD0_SHIFT)

/* Bits 8-14: The widget currently selected for SENSE_HW1 */
#define CapSense_STATUS_WDGT1_SIZE        (0x0000007FLu)
#define CapSense_STATUS_WDGT1_SHIFT       (8u)
#define CapSense_STATUS_WDGT1_MASK        (CapSense_STATUS_WDGT1_SIZE << CapSense_STATUS_WDGT1_SHIFT)

/* Bit 15: The SENSE_HW1 block status */
#define CapSense_STATUS_CSD1_SIZE         (0x00000001Lu)
#define CapSense_STATUS_CSD1_SHIFT        (15u)
#define CapSense_STATUS_CSD1_MASK         (CapSense_STATUS_CSD1_SIZE << CapSense_STATUS_CSD1_SHIFT)

/* Bit 16: The WIDGET BUSY flag status for SENSE_HW0 */
#define CapSense_STATUS_WDGT0_BUSY_SIZE   (0x00000001Lu)
#define CapSense_STATUS_WDGT0_BUSY_SHIFT  (16u)
#define CapSense_STATUS_WDGT0_BUSY_MASK   (CapSense_STATUS_WDGT0_BUSY_SIZE << CapSense_STATUS_WDGT0_BUSY_SHIFT)

/* Bit 17: The WIDGET BUSY flag status for SENSE_HW1 */
#define CapSense_STATUS_WDGT1_BUSY_SIZE   (0x00000001Lu)
#define CapSense_STATUS_WDGT1_BUSY_SHIFT  (17u)
#define CapSense_STATUS_WDGT1_BUSY_MASK   (CapSense_STATUS_WDGT1_BUSY_SIZE << CapSense_STATUS_WDGT1_BUSY_SHIFT)

/* Bits 18-23: Reserved */

/* Bits 24-31: Component error code */
#define CapSense_STATUS_ERR_SIZE          (0x000000FFLu)
#define CapSense_STATUS_ERR_SHIFT         (24u)
#define CapSense_STATUS_ERR_MASK          (CapSense_STATUS_ERR_SIZE << CapSense_STATUS_ERR_SHIFT)


/* WD_STATIC_CONFIG bit fields */

/* Bit 0: The sense/Tx frequency selection: 0 - Common, 1 - Individual 
 * (per widget). */
#define CapSense_SNS_FREQ_SIZE            (0x00000001Lu)
#define CapSense_SNS_FREQ_SHIFT           (0u)
#define CapSense_SNS_FREQ_MASK            (CapSense_SNS_FREQ_SIZE << CapSense_SNS_FREQ_SHIFT)

/* Bit 1: Duplexing Enable/Disable for linear sliders. */
#define CapSense_DIPLEXING_SIZE           (0x00000001Lu)
#define CapSense_DIPLEXING_SHIFT          (1u)
#define CapSense_DIPLEXING_MASK           (CapSense_DIPLEXING_SIZE << CapSense_DIPLEXING_SHIFT)

/* Bit 2: The widget contains a sensor ganged to other sensors. */
#define CapSense_GANGED_SNS_SIZE          (0x00000001Lu)
#define CapSense_GANGED_SNS_SHIFT         (2u)
#define CapSense_GANGED_SNS_MASK          (CapSense_GANGED_SNS_SIZE << CapSense_GANGED_SNS_SHIFT)

/* Bit 3: Some pin from this widget is used by other sensors to make 
 * a ganged sensor. */
#define CapSense_SHARED_IO_SIZE           (0x00000001Lu)
#define CapSense_SHARED_IO_SHIFT          (3u)
#define CapSense_SHARED_IO_MASK           (CapSense_SHARED_IO_SIZE << CapSense_SHARED_IO_SHIFT)

/* Bit 4: The centroid position IIR filter Enable/Disable. */
#define CapSense_POS_IIR_FILTER_SIZE      (0x00000001Lu)
#define CapSense_POS_IIR_FILTER_SHIFT     (4u)
#define CapSense_POS_IIR_FILTER_MASK      (CapSense_POS_IIR_FILTER_SIZE << CapSense_POS_IIR_FILTER_SHIFT)

/* Bit 5: The centroid position median filter Enable/Disable. */
#define CapSense_POS_MEDIAN_FILTER_SIZE   (0x00000001Lu)
#define CapSense_POS_MEDIAN_FILTER_SHIFT  (5u)
#define CapSense_POS_MEDIAN_FILTER_MASK   (CapSense_POS_MEDIAN_FILTER_SIZE << CapSense_POS_MEDIAN_FILTER_SHIFT)

/* Bit 6: The centroid position average filter Enable/Disable. */
#define CapSense_POS_AVERAGE_FILTER_SIZE  (0x00000001Lu)
#define CapSense_POS_AVERAGE_FILTER_SHIFT (6u)
#define CapSense_POS_AVERAGE_FILTER_MASK  (CapSense_POS_AVERAGE_FILTER_SIZE << CapSense_POS_AVERAGE_FILTER_SHIFT)

/* Bit 7: The centroid position jitter filter Enable/Disable. */
#define CapSense_POS_JITTER_FILTER_SIZE   (0x00000001Lu)
#define CapSense_POS_JITTER_FILTER_SHIFT  (7u)
#define CapSense_POS_JITTER_FILTER_MASK   (CapSense_POS_JITTER_FILTER_SIZE << CapSense_POS_JITTER_FILTER_SHIFT)

/* Bit 8: The multiphase Tx scan Enable (CSX widgets only). */
#define CapSense_MULTIPHASE_TX_SIZE       (0x00000001Lu)
#define CapSense_MULTIPHASE_TX_SHIFT      (8u)
#define CapSense_MULTIPHASE_TX_MASK       (CapSense_MULTIPHASE_TX_SIZE << CapSense_MULTIPHASE_TX_SHIFT)

/* Bit 9: The centroid position adaptive IIR filter Enable/Disable. */
#define CapSense_AIIR_FILTER_SIZE         (0x00000001Lu)
#define CapSense_AIIR_FILTER_SHIFT        (9u)
#define CapSense_AIIR_FILTER_MASK         (CapSense_AIIR_FILTER_SIZE << CapSense_AIIR_FILTER_SHIFT)

/* Bit 10: Ballistic multiplier Enable/Disable. */
#define CapSense_BALLISTIC_SIZE           (0x00000001Lu)
#define CapSense_BALLISTIC_SHIFT          (10u)
#define CapSense_BALLISTIC_MASK           (CapSense_BALLISTIC_SIZE << CapSense_BALLISTIC_SHIFT)

/* Bit 11: 3x3 centroid Enable/Disable. */
#define CapSense_CENTROID_3X3_SIZE        (0x00000001Lu)
#define CapSense_CENTROID_3X3_SHIFT       (11u)
#define CapSense_CENTROID_3X3_MASK        (CapSense_CENTROID_3X3_SIZE << CapSense_CENTROID_3X3_SHIFT)

/* Bit 12: 5x5 centroid Enable/Disable. */
#define CapSense_CENTROID_5X5_SIZE        (0x00000001Lu)
#define CapSense_CENTROID_5X5_SHIFT       (12u)
#define CapSense_CENTROID_5X5_MASK        (CapSense_CENTROID_5X5_SIZE << CapSense_CENTROID_5X5_SHIFT)

/* Bit 13: Edge correction Enable/Disable. */
#define CapSense_EDGE_CORRECTION_SIZE     (0x00000001Lu)
#define CapSense_EDGE_CORRECTION_SHIFT    (13u)
#define CapSense_EDGE_CORRECTION_MASK     (CapSense_EDGE_CORRECTION_SIZE << CapSense_EDGE_CORRECTION_SHIFT)

/* Bit 14: Two finger detection Enable/Disable. */
#define CapSense_TWO_FINGER_DETECTION_SIZE (0x00000001Lu)
#define CapSense_TWO_FINGER_DETECTION_SHIFT (14u)
#define CapSense_TWO_FINGER_DETECTION_MASK (CapSense_TWO_FINGER_DETECTION_SIZE << CapSense_TWO_FINGER_DETECTION_SHIFT)


/*******************************************************************************
* Defines Data Structure Macro helpers
*******************************************************************************/

/*******************************************************************************
* Determines the widget specific word in the wdgtStatus array by widget ID
*******************************************************************************/
/* Divide by 32 - size of the wdgtStatus word in bits to find the word index */
#define CapSense_GET_WDGT_STATUS_INDEX(wdgtId)  ((wdgtId) >> 5u)

/*******************************************************************************
* Determines the widget bitmask in wdgtStatus word by widget ID
*******************************************************************************/
/* Take the least 5 bits of widget id to find the bit number */
#define CapSense_GET_WDGT_STATUS_MASK(wdgtId)   (1Lu << ((wdgtId) & 0x1FLu))

/*******************************************************************************
* Determines the sense method of the widget
*******************************************************************************/
/*
* If there are multiple sensing methods, get senseMethod from flash structure,
* otherwise, hardcode it for speed.
*/
#if (CapSense_MANY_WIDGET_METHODS_EN)
    #define CapSense_GET_SENSE_METHOD(ptrFlash) ((CapSense_SENSE_METHOD_ENUM)(ptrFlash)->senseMethod)
#elif (0u != CapSense_TOTAL_CSD_WIDGETS)
    #define CapSense_GET_SENSE_METHOD(ptrFlash) CapSense_SENSE_METHOD_CSD_E
#elif (0u != CapSense_TOTAL_CSX_WIDGETS)
    #define CapSense_GET_SENSE_METHOD(ptrFlash) CapSense_SENSE_METHOD_CSX_E
#elif (0u != CapSense_TOTAL_ISX_WIDGETS)
    #define CapSense_GET_SENSE_METHOD(ptrFlash) CapSense_SENSE_METHOD_ISX_E
#endif

/*******************************************************************************
* Gets the widget type
*******************************************************************************/
#define CapSense_GET_WIDGET_TYPE(ptrFlashWdgt)  ((CapSense_WD_TYPE_ENUM)((ptrFlashWdgt)->wdgtType))

/*******************************************************************************
* Gets the number of the widget's sensors
*******************************************************************************/
#define CapSense_GET_SENSOR_COUNT(widgetId)         CapSense_dsFlash.wdgtArray[(widgetId)].totalNumSns
#define CapSense_GET_SNS_CNT_BY_PTR(ptrFlashWidget) (ptrFlashWidget)->totalNumSns

/*******************************************************************************
* Increments the pointer to the Regular Filter History Object
*******************************************************************************/
#if (0u != CapSense_REGULAR_RC_ALP_FILTER_EN)
    #define CapSense_INC_REG_FLTR_OBJ(fltrVariant)      \
        do {                                                    \
            (fltrVariant).ptrAlp++;                             \
        } while(0)
#elif (0u != CapSense_REGULAR_RC_FILTER_EN)
    #define CapSense_INC_REG_FLTR_OBJ(fltrVariant)      \
        do {                                                    \
            (fltrVariant).ptrRegular++;                         \
        } while(0)
#else
    #define CapSense_INC_REG_FLTR_OBJ(fltrVariant)      \
        do {                                                    \
        } while(0)
#endif

/*******************************************************************************
* Increments the pointer to the Proximity Filter History Object
*******************************************************************************/
#if (0u != CapSense_PROX_RC_ALP_FILTER_EN)
    #define CapSense_INC_PROX_FLTR_OBJ(fltrVariant)     \
        do {                                                    \
            (fltrVariant).ptrAlp++;                             \
        } while(0)
#elif (0u != CapSense_PROX_RC_FILTER_EN)
    #define CapSense_INC_PROX_FLTR_OBJ(fltrVariant)     \
        do {                                                    \
            (fltrVariant).ptrProx++;                            \
        } while(0)
#else
    #define CapSense_INC_PROX_FLTR_OBJ(fltrVariant)     \
        do {                                                    \
        } while(0)
#endif

/*******************************************************************************
* Increments the pointer to the Filter History Object Variant
*******************************************************************************/
#define CapSense_INC_FLTR_OBJ_VARIANT(isProxHistObj, fltrVariant)   \
    do {                                                                    \
        if (0u == (isProxHistObj))                                          \
        {                                                                   \
            CapSense_INC_REG_FLTR_OBJ(fltrVariant);                 \
        }                                                                   \
        else                                                                \
        {                                                                   \
            CapSense_INC_PROX_FLTR_OBJ(fltrVariant);                \
        }                                                                   \
    } while(0)

/*******************************************************************************
* Gets a widget status in the global enable register dsRam.wdgtEnable[]
*******************************************************************************/
#if (CapSense_ENABLE == CapSense_SELF_TEST_EN)
    #define CapSense_GET_WIDGET_EN_STATUS(wdId)                                                     \
                 (CapSense_GET_WDGT_STATUS_MASK(wdId) &                                             \
                  CapSense_dsRam.wdgtEnable[CapSense_GET_WDGT_STATUS_INDEX(wdId)] &         \
                  CapSense_dsRam.wdgtWorking[CapSense_GET_WDGT_STATUS_INDEX(wdId)])
#else
    #define CapSense_GET_WIDGET_EN_STATUS(wdId)                    \
                (CapSense_GET_WDGT_STATUS_MASK(wdId) &             \
                 CapSense_dsRam.wdgtEnable[CapSense_GET_WDGT_STATUS_INDEX(wdId)])
#endif /* (CapSense_ENABLE == CapSense_SELF_TEST_EN) */

/*******************************************************************************
* Gets a widget active status from the dsRam.wdgtStatus[] register
*******************************************************************************/
#define CapSense_GET_WIDGET_ACTIVE_STATUS(wdId)                    \
            (CapSense_GET_WDGT_STATUS_MASK(wdId) &                 \
             CapSense_dsRam.wdgtStatus[CapSense_GET_WDGT_STATUS_INDEX(wdId)])

/*******************************************************************************
* Declares Flash and RAM Data Structure variables
*******************************************************************************/
extern CapSense_RAM_STRUCT            CapSense_dsRam;
extern const CapSense_FLASH_STRUCT    CapSense_dsFlash;
extern const CapSense_FLASH_IO_STRUCT CapSense_ioList[CapSense_TOTAL_ELECTRODES];
extern const CapSense_RAM_WD_LIST_STRUCT CapSense_ramWidgetInit;
extern const uint8 CapSense_ramIdacInit[CapSense_TOTAL_SENSORS];






/*******************************************************************************
* Function Prototypes
*******************************************************************************/

/*******************************************************************************
* High-level API
*******************************************************************************/

/**
* \cond (SECTION_C_HIGH_LEVEL || SECTION_I_HIGH_LEVEL)
* \addtogroup group_c_high_level
* \{
*/

uint32 CapSense_IsAnyWidgetActive(void);
uint32 CapSense_IsWidgetActive(uint32 widgetId);
uint32 CapSense_IsSensorActive(uint32 widgetId, uint32 sensorId);

#if (0u != CapSense_PROXIMITY_WIDGET_EN)
    uint32 CapSense_IsProximitySensorActive(uint32 widgetId, uint32 proxId);
#endif /* #if (0u != CapSense_PROXIMITY_WIDGET_EN) */

/** \}
* \endcond
* \cond (SECTION_C_HIGH_LEVEL)
* \addtogroup group_c_high_level
* \{
*/
#if (0u != CapSense_MATRIX_WIDGET_EN)
    uint32 CapSense_IsMatrixButtonsActive(uint32 widgetId);
#endif /* #if (0u != CapSense_MATRIX_WIDGET_EN) */

#if (0u != CapSense_SLIDER_WIDGET_EN)
    uint32 CapSense_GetCentroidPos(uint32 widgetId);
#endif /* #if (0u != CapSense_SLIDER_WIDGET_EN) */

#if (0u != CapSense_TOUCHPAD_WIDGET_EN)
    uint32 CapSense_GetXYCoordinates(uint32 widgetId);
#endif /* #if (0u != CapSense_TOUCHPAD_WIDGET_EN) */

/** \}
* \endcond */

/*******************************************************************************
* Low level API
*******************************************************************************/

/**
* \cond (SECTION_C_LOW_LEVEL || SECTION_I_LOW_LEVEL)
* \addtogroup group_c_low_level
* \{
*/

cystatus CapSense_GetParam(uint32 paramId, uint32 *value);
cystatus CapSense_SetParam(uint32 paramId, uint32 value);

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



void CapSense_DsInitialize(void);
#if (0u != CapSense_ADC_EN)
    void CapSense_AdcDsInitialize(void);
#endif /* (0u != CapSense_ADC_EN) */

/** \}
* \endcond */

#endif /* End CY_SENSE_CapSense_STRUCTURE_H */


/* [] END OF FILE */
