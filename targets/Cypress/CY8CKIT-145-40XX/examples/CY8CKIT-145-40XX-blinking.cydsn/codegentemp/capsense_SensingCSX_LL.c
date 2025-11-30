/***************************************************************************//**
* \file capsense_SensingCSX_LL.c
* \version 7.10
*
* \brief
*   This file defines the data structure global variables and provides
*   implementation for the low-level APIs of the CSX part of
*   the Sensing module. The file contains the APIs used for the CSD block
*   initialization, calibration and scanning.
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
#include <cytypes.h>
#include "CyLib.h"

#include "capsense_Structure.h"
#include "capsense_Configuration.h"
#include "capsense_SensingCSX_LL.h"
#include "capsense_Sensing.h"
#if (capsense_ENABLE == capsense_SELF_TEST_EN)
    #include "capsense_SelfTest.h"
#endif

#include "cyapicallbacks.h"

#if (capsense_ENABLE == capsense_CSX_EN)

/*******************************************************************************
* Function constants
*******************************************************************************/

#define  capsense_NUM_HALF_CYCLES                       (2u)


/*******************************************************************************
* Defines module variables
*******************************************************************************/

/* Local variable used to store the Scan period */
volatile uint16 capsense_csxScanPeriod = 0u;
/* Local variable used to return raw count from the post scan ISR */
volatile uint16 capsense_csxRawCount = 0u;

#if(capsense_ENABLE != capsense_CSDV2)
    volatile uint32 capsense_csxRawGarbage = 0u;
#endif /* (capsense_ENABLE != capsense_CSDV2) */

/* Pointer to Flash structure to hold Tx electrode that was connected previously */
static capsense_FLASH_IO_STRUCT const *capsense_curTxIOPtr;
/* Pointer to Flash structure to hold Rx electrode that was connected previously */
static capsense_FLASH_IO_STRUCT const *capsense_curRxIOPtr;
/* Local variable to hold total Tx in widget, while scanning all the sensors in widget */
static uint16 capsense_curWdgtTotalRx = 0u;
/* Local variable to hold total Rx in widget, while scanning all the sensors in widget */
static uint16 capsense_curWdgtTotalTx = 0u;
/* Flag to indicate that electrodes were connected previously */
static uint16 capsense_eleCsxDisconnectFlag = 0u;
/* Pointer to Flash structure holding info of sensor to be scanned */
#if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
    static capsense_FLASH_SNS_STRUCT const *capsense_curGangRxPtr = 0u;
    static capsense_FLASH_SNS_STRUCT const *capsense_curGangTxPtr = 0u;
#endif

/*******************************************************************************
* Module local function declarations
*******************************************************************************/
/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

static void capsense_SsCSXStartSample(void);
static void capsense_SsCSXPostMultiScan(void);
static void capsense_SsCSXPostSingleScan(void);
static uint16 capsense_SsCalcCsxScanPeriod(capsense_RAM_WD_BASE_STRUCT const *wdgtPtr);

#if(capsense_ENABLE == capsense_CSDV2)
    CY_INLINE static void capsense_SsCSXStartSampleExt(void);
#endif

#if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
    static uint32 capsense_SsCSXOversample(void);
#endif

#if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
    static void capsense_SsCSXPostMultiScanGanged(void);
#endif

#if (capsense_CSX_IDAC_AUTOCAL_EN == capsense_ENABLE)
    static cystatus capsense_SsCSXCalibrateCheck(uint32 widgetId, uint32 scanPeriod, uint32 target);
#endif

/* Pointer to Pointer to function used to register callback in ISR */
void (*capsense_CSXPostScanApiPtr)(void) = &capsense_SsCSXPostMultiScan;
/** \}
* \endcond */

/*******************************************************************************
* Function Name: capsense_CSXInitialize
****************************************************************************//**
*
* \brief
*   Performs hardware and firmware initialization required for the CSX operation
*   of the capsense Component.
*
* \details
*   This function initializes hardware to perform the CSX sensing operation. This
*   function is called by the capsense_Start() API during the Component
*   initialization. If both CSX and CSD sensing methods are used in the Component,
*   this function is called by the capsense_SetupWidget() API to change hardware
*   configured for CSD to re-initialize for the CSX sensing.
*
*   If the CSD and CSX widgets are used in the Component, it is recommended not to
*   mix the CSD widgets between the CSX widgets, instead, place all CSX widgets in
*   the required scanning order and then place the CSD widgets in the customizer.
*   For the Component API, this action will eliminate the need for changing the hardware
*   configuration for every widget scan and will increase the execution speed
*   in the capsense_ScanAllWidgets() when the API is called.
*
*   Similarly, it is recommended to set up and scan all the CSX widgets in such
*   a sequence that the capsense_SetupWidget() API  shouldn't need
*   hardware  sensing-configuration change.
*
*   It is highly not recommended to call this API directly from the application layer.
*
*******************************************************************************/
void capsense_CSXInitialize(void)
{
    #if(capsense_ENABLE == capsense_CSDV2)
        uint8  interruptState;
        uint32 tmpRegVal;

        /* Set all the sensors to inactive state */
        if(capsense_dsRam.scanCurrentISC != capsense_dsRam.scanCsxISC)
        {
            capsense_SsSetAllIOsState((uint32)capsense_dsRam.scanCsxISC);
            capsense_dsRam.scanCurrentISC = capsense_dsRam.scanCsxISC;
        }

        CY_SET_REG32(capsense_INTR_PTR,             capsense_DEFAULT_CSD_INTR_CFG);
        CY_SET_REG32(capsense_INTR_SET_PTR,         capsense_DEFAULT_CSD_INTR_SET_CFG);
        CY_SET_REG32(capsense_INTR_MASK_PTR,        capsense_DEFAULT_CSD_INTR_MASK_CFG);
        CY_SET_REG32(capsense_HSCMP_PTR,            capsense_DEFAULT_CSD_HSCMP_CFG);
        CY_SET_REG32(capsense_AMBUF_PTR,            capsense_DEFAULT_CSD_AMBUF_CFG);
        CY_SET_REG32(capsense_REFGEN_PTR,           capsense_DEFAULT_CSD_REFGEN_CFG);
        CY_SET_REG32(capsense_CSDCMP_PTR,           capsense_DEFAULT_CSD_CSDCMP_CFG);
        CY_SET_REG32(capsense_CSD_IDACA_PTR,         capsense_DEFAULT_CSD_IDACA_CFG);

        #if((0u != capsense_ADC_EN) || (0u != capsense_CSD_IDAC_COMP_EN))
            CY_SET_REG32(capsense_CSD_IDACB_PTR,    capsense_DEFAULT_CSD_IDACB_CFG);
        #endif /* (0u != capsense_ADC_EN) || (0u != capsense_CSD_IDAC_COMP_EN) */

        CY_SET_REG32(capsense_SW_RES_PTR,           capsense_DEFAULT_CSD_SW_RES_CFG);
        CY_SET_REG32(capsense_SENSE_PERIOD_PTR,     capsense_DEFAULT_CSD_SENSE_PERIOD_CFG);
        CY_SET_REG32(capsense_SENSE_DUTY_PTR,       capsense_DEFAULT_CSD_SENSE_DUTY_CFG);
        CY_SET_REG32(capsense_SW_HS_P_SEL_PTR,      capsense_DEFAULT_CSD_SW_HS_P_SEL_CFG);
        CY_SET_REG32(capsense_SW_HS_N_SEL_PTR,      capsense_DEFAULT_CSD_SW_HS_N_SEL_CFG);
        CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR,    capsense_DEFAULT_CSD_SW_SHIELD_SEL_CFG);
        CY_SET_REG32(capsense_SW_AMUXBUF_SEL_PTR,   capsense_DEFAULT_CSD_SW_AMUXBUF_SEL_CFG);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(capsense_SW_BYP_SEL_PTR);
        tmpRegVal &= ~(capsense_SW_BYP_SEL_SW_BYA_MASK);
        tmpRegVal |= capsense_DEFAULT_CSD_SW_BYP_SEL_CFG;
        CY_SET_REG32(capsense_SW_BYP_SEL_PTR,       tmpRegVal);
        CyExitCriticalSection(interruptState);

        CY_SET_REG32(capsense_SW_CMP_P_SEL_PTR,     capsense_DEFAULT_CSD_SW_CMP_P_SEL_CFG);
        CY_SET_REG32(capsense_SW_CMP_N_SEL_PTR,     capsense_DEFAULT_CSD_SW_CMP_N_SEL_CFG);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(capsense_SW_REFGEN_SEL_PTR);
        tmpRegVal &= ~capsense_SW_REFGEN_SEL_SW_MASK;
        tmpRegVal |= capsense_DEFAULT_CSD_SW_REFGEN_SEL_CFG;
        CY_SET_REG32(capsense_SW_REFGEN_SEL_PTR,    tmpRegVal);
        CyExitCriticalSection(interruptState);

        CY_SET_REG32(capsense_SW_FW_MOD_SEL_PTR,    capsense_DEFAULT_CSD_SW_FW_MOD_SEL_CFG);
        CY_SET_REG32(capsense_SW_FW_TANK_SEL_PTR,   capsense_DEFAULT_CSD_SW_FW_TANK_SEL_CFG);
        CY_SET_REG32(capsense_SW_DSI_SEL_PTR,       capsense_DEFAULT_CSD_SW_DSI_SEL_CFG);
        CY_SET_REG32(capsense_SEQ_TIME_PTR,         capsense_DEFAULT_CSD_SEQ_TIME_CFG);
        CY_SET_REG32(capsense_SEQ_INIT_CNT_PTR,     capsense_DEFAULT_CSD_SEQ_INIT_CNT_CFG);
        CY_SET_REG32(capsense_SEQ_NORM_CNT_PTR,     capsense_DEFAULT_CSD_SEQ_NORM_CNT_CFG);
        CY_SET_REG32(capsense_ADC_CTL_PTR,          capsense_DEFAULT_CSD_ADC_CTL_CFG);
        CY_SET_REG32(capsense_SEQ_START_PTR,        capsense_DEFAULT_CSD_SEQ_START_CFG);
        CY_SET_REG32(capsense_CONFIG_PTR,           capsense_DEFAULT_CSD_CONFIG_CFG);

        capsense_DischargeExtCapacitors(capsense_EXT_CAP_DISCHARGE_TIME);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(capsense_CintA_PC_PTR);
        tmpRegVal &= (~(capsense_GPIO_PC_MASK << (capsense_CintA_SHIFT * capsense_GPIO_PC_BIT_SIZE)));
        CY_SET_REG32(capsense_CintA_PC_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(capsense_CintB_PC_PTR);
        tmpRegVal &= (~(capsense_GPIO_PC_MASK << (capsense_CintB__SHIFT * capsense_GPIO_PC_BIT_SIZE)));
        CY_SET_REG32(capsense_CintB_PC_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        /* Connect CintA_tank pin to AMUXBUS-A using HSIOM registers. */
        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(capsense_CintA_HSIOM_PTR);
        tmpRegVal &= ~capsense_CintA_HSIOM_MASK;
        tmpRegVal |= (capsense_HSIOM_SEL_AMUXA << capsense_CintA_HSIOM_SHIFT);
        CY_SET_REG32(capsense_CintA_HSIOM_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        /* Connect CintB to AMUXBUS-A using HSIOM registers. */
        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(capsense_CintB_HSIOM_PTR);
        tmpRegVal &= ~capsense_CintB_HSIOM_MASK;
        tmpRegVal |= (capsense_HSIOM_SEL_AMUXA << capsense_CintB_HSIOM_SHIFT);
        CY_SET_REG32(capsense_CintB_HSIOM_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        capsense_SsSetModClkClockDivider((uint32)capsense_dsRam.modCsxClk);

        #if (capsense_ENABLE == capsense_CSX_COMMON_TX_CLK_EN)
            capsense_SsSetSnsClockDivider((uint32)capsense_dsRam.snsCsxClk);
        #endif

    #else
        uint32 trimValue;

        /* Set all the sensors to inactive state */
        if(capsense_dsRam.scanCurrentISC != capsense_dsRam.scanCsxISC)
        {
            capsense_SsSetAllIOsState((uint32)capsense_dsRam.scanCsxISC);
            capsense_dsRam.scanCurrentISC = capsense_dsRam.scanCsxISC;
        }

        #if(capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            trimValue = CY_GET_REG32(capsense_IDAC_PTR);
            trimValue &= ~(capsense_IDAC_COMP_CFG_MASK | capsense_IDAC_FEEDBACK_MODE_MASK);
            CY_SET_REG32(capsense_IDAC_PTR, trimValue);
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */

        /* Connect CintB to AMUXBUS-A using HSIOM registers. */
        capsense_WriteBitsSafe(capsense_CintB_HSIOM_PTR, capsense_CintB_HSIOM_MASK,
                    (uint32)(capsense_HSIOM_SEL_AMUXA << capsense_CintB_HSIOM_SHIFT));
        capsense_WriteBitsSafe(capsense_CintB_PC_PTR,
                    (uint32)(capsense_GPIO_PC_MASK << (capsense_CintB__SHIFT * capsense_GPIO_PC_BIT_SIZE )), 0u);
        capsense_WriteBitsSafe(capsense_CintB_DR_PTR, (uint32)(0x01uL << capsense_CintB__SHIFT), 0u);

        /* Connect CintA_tank pin to AMUXBUS-A using HSIOM registers. */
        capsense_WriteBitsSafe(capsense_CintA_HSIOM_PTR, capsense_CintA_HSIOM_MASK,
                    (uint32)(capsense_HSIOM_SEL_AMUXA << capsense_CintA_HSIOM_SHIFT));
        capsense_WriteBitsSafe(capsense_CintA_PC_PTR,
                    (uint32)(capsense_GPIO_PC_MASK << (capsense_CintA_SHIFT * capsense_GPIO_PC_BIT_SIZE )), 0u);
        capsense_WriteBitsSafe(capsense_CintA_DR_PTR, (uint32)(0x01uL << capsense_CintA_SHIFT), 0u);

        /* Connect CSD comparator to CintB via AMUXBUS-A */
        trimValue = CY_GET_REG32(capsense_CONFIG_PTR);
        trimValue |= capsense_CONFIG_SENSE_INSEL_MASK;
        CY_SET_REG32(capsense_CONFIG_PTR, trimValue);

        /* If common clocks are enabled for Component, set clock
            divider for sensor and modulator clocks and start/restart them */
        #if (capsense_CSX_COMMON_TX_CLK_EN == capsense_ENABLE)
            capsense_SsSetClockDividers((uint32)capsense_dsRam.snsCsxClk, (uint32)capsense_dsRam.modCsxClk);
        #endif
    #endif /* (capsense_ENABLE == capsense_CSDV2) */

    /* Enable capsense ISR and set ISR for CSX sensing */
    capsense_SsIsrInitialize(&capsense_CSXScanISR);
}


/*******************************************************************************
* Function Name: capsense_CSXElectrodeCheck
****************************************************************************//**
*
* \brief
*   Check if electrodes were previously connected using
*   the capsense_CSXSetupWidgetExt() API and if yes, disconnect them.
*
* \details
*   This function checks if capsense_eleCsxDisconnectFlag is set.
*   If it is set, the function disconnects the previously connected electrode.
*
*******************************************************************************/
void capsense_CSXElectrodeCheck(void)
{
    #if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
        uint32 numElectrodes;
    #endif /* (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN) */

    if (0u != capsense_eleCsxDisconnectFlag)
    {
       /* Disconnect if electrodes were previous connected by SetupWidgetExt() API */
        #if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
            /* Check ganged sns flag */
            if (capsense_GANGED_SNS_MASK == (capsense_curFlashWdgtPtr->staticConfig & capsense_GANGED_SNS_MASK))
            {
                /* 1. Get number of pins in previous connected Tx electrode
                    3. Get Tx pointer
                    4. Disconnect all Tx */
                numElectrodes = capsense_curGangTxPtr->numPins;
                capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];

                do
                {
                    capsense_CSXDisconnectTx(capsense_curTxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /* 1. Get number of pins in previous connected Rx electrode
                    3. Get Rx pointer
                    4. Disconnect all Rx */
                numElectrodes = capsense_curGangRxPtr->numPins;
                capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];

                do
                {
                    capsense_CSXDisconnectRx(capsense_curRxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);
            }
            else
            {
                /* Disconnect if electrodes were previous connected by SetupWidgetExt API */
                capsense_CSXDisconnectTx(capsense_curTxIOPtr);
                capsense_CSXDisconnectRx(capsense_curRxIOPtr);
            }
        #else
            /* Disconnect if electrodes were previous connected by SetupWidgetExt API */
            capsense_CSXDisconnectTx(capsense_curTxIOPtr);
            capsense_CSXDisconnectRx(capsense_curRxIOPtr);
        #endif
        capsense_eleCsxDisconnectFlag = 0u;
    }
}


/*******************************************************************************
* Function Name: capsense_CSXSetupWidget
****************************************************************************//**
*
* \brief
*  Performs hardware and firmware initialization required for scanning sensors
*  in a specific widget using the CSX sensing method. This function requires
*  using the capsense_CSXScan() function to start scanning.
*
* \details
*  Performs hardware and firmware initialization required for scanning sensors
*  in a specific widget using the CSX sensing method. This function requires
*  using the capsense_CSXScan() function to start scanning.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_SetupWidget() function should be used instead.
*
*  This function initializes the widgets specific common parameters to perform
*  the CSX scanning. The initialization includes the following:
*    1. The CSD_CONFIG register.
*    2. The IDAC register.
*    3. The Sense clock frequency
*    4. The phase alignment of the sense and modulator clocks.
*
*  This function does not connect any specific sensors to the scanning hardware
*  and neither does it start a scanning process. The capsense_CSXScan()
*  function must be called after initializing the widget to start scanning.
*
*  This function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status.
*
*  This function is called by the capsense_SetupWidget() API if the
*  given widget uses the CSX sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
* \param widgetId
*  Specifies the ID number of the widget to perform hardware and firmware
*  initialization required for scanning sensors in the specific widget.
*  A macro for the widget ID can be found in the capsense Configuration header
*  file defined as capsense_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void capsense_CSXSetupWidget(uint32 widgetId)
{
    /* variable to access widget details */
    capsense_RAM_WD_BASE_STRUCT * curRamWdgtBasePtr;

    #if (capsense_ENABLE == capsense_CSDV2)
        uint32 tmpRegVal;
        uint32 snsClkVal;
    #endif /* (capsense_DISABLE == capsense_CSDV2) */

    /* Save the current widget Id */
    capsense_widgetIndex = (uint8)widgetId;

    capsense_SsSwitchSensingMode(capsense_SENSE_METHOD_CSX_E);

    /*
    *  Check if CSX electrodes were previously connected using
    *  capsense_CSXSetupWidgetExt API and if yes, disconnect them
    */
    capsense_CSXElectrodeCheck();

    /* Configure hardware block */
    #if (capsense_ENABLE == capsense_CSDV2)
        capsense_curFlashWdgtPtr = &capsense_dsFlash.wdgtArray[widgetId];

        curRamWdgtBasePtr = (capsense_RAM_WD_BASE_STRUCT *)capsense_curFlashWdgtPtr->ptr2WdgtRam;

        #if (capsense_ENABLE == capsense_CSX_COMMON_TX_CLK_EN)
            snsClkVal = (uint32)capsense_dsRam.snsCsxClk;
        #else
            snsClkVal = (uint32)curRamWdgtBasePtr->snsClk;
        #endif /* (capsense_ENABLE == capsense_CSX_COMMON_TX_CLK_EN) */

        CY_SET_REG32(capsense_SEQ_NORM_CNT_PTR, (uint32)curRamWdgtBasePtr->resolution);
        capsense_csxScanPeriod  = capsense_SsCalcCsxScanPeriod(curRamWdgtBasePtr);

        tmpRegVal = (uint32)curRamWdgtBasePtr->snsClkSource;

        snsClkVal = (snsClkVal - 1uL) & capsense_SENSE_PERIOD_SENSE_DIV_MASK;
        tmpRegVal = (tmpRegVal << capsense_SENSE_PERIOD_LFSR_SIZE_SHIFT) | snsClkVal;
        CY_SET_REG32(capsense_SENSE_PERIOD_PTR, tmpRegVal);
        capsense_SsSetModClkClockDivider((uint32)capsense_dsRam.modCsxClk);
    #else
        /*
        * initialize access pointers for current:
        *    1. Pointer to widget configuration in Flash
        *    2. Widget configuration in RAM
        *    3. Make a local copy of widget index
        */
        capsense_curFlashWdgtPtr = &capsense_dsFlash.wdgtArray[widgetId];
        curRamWdgtBasePtr = (capsense_RAM_WD_BASE_STRUCT *)capsense_curFlashWdgtPtr->ptr2WdgtRam;

        CY_SET_REG32(capsense_CONFIG_PTR, capsense_CONFIG_ENABLE_MASK);
        CY_SET_REG32(capsense_CONFIG_PTR, (CY_GET_REG32(capsense_CONFIG_PTR) |
                                capsense_CONFIG_MUTUALCAP_EN_MASK     |
                                capsense_CONFIG_SENSE_COMP_BW_MASK    |
                                capsense_CONFIG_SENSE_COMP_EN_MASK    |
                                capsense_CONFIG_SENSE_INSEL_MASK      |
                                capsense_CONFIG_REFBUF_EN_MASK        |
                                capsense_CONFIG_REFBUF_DRV_MASK));

        /* If individual clocks are enabled for each widget, set clock
            divider for sensor and modulator clocks and start/restart them. */
        #if (capsense_CSX_COMMON_TX_CLK_EN == capsense_DISABLE)
            capsense_SsSetClockDividers((uint32)curRamWdgtBasePtr->snsClk, (uint32)capsense_dsRam.modCsxClk);
        #endif

        /* Find scan period */
        capsense_csxScanPeriod = capsense_SsCalcCsxScanPeriod(curRamWdgtBasePtr);
    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}

/*******************************************************************************
* Function Name: capsense_CSXSetupWidgetExt
****************************************************************************//**
*
* \brief
*  Performs extended initialization for the CSX widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the capsense_CSXScan() function to initiate a scan.
*
* \details
*  Performs extended initialization for the CSX widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the capsense_CSXScan() function to initiate a scan.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_SetupWidgetExt() function should be used instead.
*
*  This function does the same tasks as capsense_CSXSetupWidget() and
*  also connects a sensor in the widget for scanning. Once this function is
*  called to initialize a widget and a sensor, the capsense_CSXScanExt()
*  function must be called to scan the sensor.
*
*  This function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
* \param widgetId
*  Specifies the ID number of the widget to perform hardware and firmware
*  initialization required for scanning a specific sensor in a specific widget.
*  A macro for the widget ID can be found in the capsense
*  Configuration header file defined as capsense_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to perform hardware
*  and firmware initialization required for scanning a specific sensor in a
*  specific widget.
*  A macro for the sensor ID within a specified widget can be found in the
*  capsense Configuration header file defined as
*  capsense_<WidgetName>_SNS<SensorNumber>_ID.
*
*******************************************************************************/

void capsense_CSXSetupWidgetExt(uint32 widgetId, uint32 sensorId)
{
    uint32 txIndex;
    uint32 rxIndex;

    #if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
        uint16 numElectrodes;
    #endif /* (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN) */

    /* Initialize widget */
    capsense_CSXSetupWidget(widgetId);
    capsense_sensorIndex = (uint8)sensorId;

    /* initialize sensor data structure pointer to appropriate address */
    capsense_curRamSnsPtr = capsense_curFlashWdgtPtr->ptr2SnsRam;
    capsense_curRamSnsPtr = &capsense_curRamSnsPtr[sensorId];

    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        if (0u != capsense_curRamSnsPtr->subConvNum)
        {
    #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

    /*
    *  Find Tx and Rx index for given snsIndex
    *    rxIndex = sensorId / TxCount
    *    txIndex = sensorId % TxCount
    */
    rxIndex = sensorId /capsense_curFlashWdgtPtr->numRows;
    txIndex = sensorId % capsense_curFlashWdgtPtr->numRows;

    /* If widget is APA, find node (Tx/Rx) to be connected for scanning */
    #if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
        if (capsense_GANGED_SNS_MASK == (capsense_curFlashWdgtPtr->staticConfig & capsense_GANGED_SNS_MASK))
        {
            /*
            *  1. Get access to Rx sensor pointer (Rx = Base + rxIndex).
            *  2. Get number of Rx electrodes
            *  3. Get Rx pointer
            *  4. Connect all Rx
            */
            capsense_curGangRxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
            capsense_curGangRxPtr += rxIndex;
            numElectrodes = capsense_curGangRxPtr->numPins;
            capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];

            do
            {
                capsense_CSXConnectRx(capsense_curRxIOPtr++);
                numElectrodes--;
            } while (0u != numElectrodes);

            /*
            *  1. Get access to Tx sensor pointer (Tx = Base + NumberRx + TxIndex).
            *  2. Get number of Tx electrodes
            *  3. Get Tx pointer
            *  4. Connect all Tx
            */
            capsense_curGangTxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
            capsense_curGangTxPtr += (capsense_curFlashWdgtPtr->numCols + txIndex);

            numElectrodes = capsense_curGangTxPtr->numPins;
            capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];

            do
            {
                capsense_CSXConnectTx(capsense_curTxIOPtr++);
                numElectrodes--;
            }while (0u != numElectrodes);

            /* Set callback to scan connected ganged sensor only */
            capsense_CSXPostScanApiPtr = &capsense_SsCSXPostSingleScan;
        }
        else
    #endif  /* (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN) */
        {
            /*
            *  If no ganged sensor in Component OR current widget no contains ganged sns, then:
            *    1. Find Rx pointer: Rx = Base address + RxIndex
            *    2. Find Tx pointer: Tx = Base address + (total Rx + TxIndex)
            */
            capsense_curRxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
            capsense_curRxIOPtr = &capsense_curRxIOPtr[rxIndex];

            capsense_curTxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
            capsense_curTxIOPtr = &capsense_curTxIOPtr[(capsense_curFlashWdgtPtr->numCols + txIndex)];

            /* Connect Tx and Rx IOs for scan ad set flag to indicate that IOs should be disconnected */
            capsense_CSXConnectTx(capsense_curTxIOPtr);
            capsense_CSXConnectRx(capsense_curRxIOPtr);
            capsense_eleCsxDisconnectFlag = capsense_DISCONNECT_IO_FLAG;

            /* Set callback to scan all the sensors in widget */
            capsense_CSXPostScanApiPtr = &capsense_SsCSXPostSingleScan;
        }
    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        }
    #endif
}

/*******************************************************************************
* Function Name: capsense_CSXScan
****************************************************************************//**
*
* \brief
*  This function initiates a scan for the sensors of the widget initialized by
*  the capsense_CSXSetupWidget() function.
*
* \details
*  This function initiates a scan for the sensors of the widget initialized by
*  the capsense_CSXSetupWidget() function.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_Scan() function should be used instead.
*
*  This function performs scanning of all the sensors in the widget configured by
*  the capsense_CSXSetupWidget() function. It does the following tasks:
*    1. Connects the first sensor of the widget.
*    2. Initializes an interrupt callback function to initialize a scan of the
*       next sensors in a widget.
*    3. Starts scanning for the first sensor in the widget.
*
*  This function is called by the capsense_Scan() API if the given
*  widget uses the CSX sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
*  This function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status. The widget must be
*  preconfigured by the capsense_CSXSetupWidget() function if any other
*  widget was previously scanned or any other type of scan functions were used.
*
*******************************************************************************/

void capsense_CSXScan(void)
{
    #if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
        uint32 numElectrodes;
    #endif
    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        uint32 snsIndex = 0u;
        uint32 snsNum;
    #endif

    /* Set all the sensors to inactive state */
    if(capsense_dsRam.scanCurrentISC != capsense_dsRam.scanCsxISC)
    {
        capsense_SsSetAllIOsState((uint32)capsense_dsRam.scanCsxISC);
        capsense_dsRam.scanCurrentISC = capsense_dsRam.scanCsxISC;
    }

    capsense_sensorIndex = 0u;

    /* initialize pointer to access sensor RAM elements */
    capsense_curRamSnsPtr = capsense_curFlashWdgtPtr->ptr2SnsRam;

    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Loop through the sensors until non-skipped is found */
        snsNum = capsense_curFlashWdgtPtr->totalNumSns;
        while ((snsIndex < snsNum) && (capsense_curRamSnsPtr->subConvNum == 0u))
        {
            /* Increment sensor pointers */
            capsense_curRamSnsPtr++;
            capsense_sensorIndex++;
            snsIndex++;
        }
        /*
        *  Calculate total sensor to be scanned. If buttons, one Tx and an Rx for each sensor
        *  if Matrix button or Touchpad, M x N rule applies
        */
        capsense_curWdgtTotalTx = (uint16)(capsense_curFlashWdgtPtr->numRows - (snsIndex % capsense_curFlashWdgtPtr->numRows));
        capsense_curWdgtTotalRx  = (uint16)(capsense_curFlashWdgtPtr->numCols - (snsIndex / capsense_curFlashWdgtPtr->numRows));

        /* Scan sensor if it's index within a valid range otherwise do nothing as all the sensors are skipped */
        if (snsIndex < snsNum)
        {
            #if (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN)
                if ((capsense_curFlashWdgtPtr->staticConfig & capsense_GANGED_SNS_MASK) != 0u)
                {
                    /* Connect all Rx electrodes */
                    capsense_curGangRxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
                    capsense_curGangRxPtr += snsIndex /capsense_curFlashWdgtPtr->numRows;
                    numElectrodes = capsense_curGangRxPtr->numPins;
                    capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                    do
                    {
                        capsense_CSXConnectRx(capsense_curRxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);

                    /* Connect all Tx electrodes */
                    capsense_curGangTxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
                    capsense_curGangTxPtr += (capsense_curFlashWdgtPtr->numCols + snsIndex % capsense_curFlashWdgtPtr->numRows);
                    numElectrodes = capsense_curGangTxPtr->numPins;
                    capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];
                    do
                    {
                        capsense_CSXConnectTx(capsense_curTxIOPtr++);
                        numElectrodes--;
                    }while (0u != numElectrodes);
                    /* Assign callback to ISR */
                    capsense_CSXPostScanApiPtr = &capsense_SsCSXPostMultiScanGanged;
                }
                else
            #endif /* (capsense_ENABLE == capsense_CSX_GANGED_SNS_EN) */
            {
                /* Find Rx pointer: Rx = Base_address + SnsIndex / total_Tx */
                capsense_curRxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
                capsense_curRxIOPtr += (snsIndex / capsense_curFlashWdgtPtr->numRows);
                /* Find Tx pointer: Tx = Base_address + total_Rx + SnsIndex % total_Tx */
                capsense_curTxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
                capsense_curTxIOPtr += capsense_curFlashWdgtPtr->numCols;
                capsense_curTxIOPtr += (snsIndex % capsense_curFlashWdgtPtr->numRows);
                /* Connect Tx and Rx electrodes for scan */
                capsense_CSXConnectTx(capsense_curTxIOPtr);
                capsense_CSXConnectRx(capsense_curRxIOPtr);
                /* Set callback to scan all the sensors in widget */
                capsense_CSXPostScanApiPtr = &capsense_SsCSXPostMultiScan;
            }

            /* Reset multi-frequency scan channel if enabled */
            #if (capsense_MULTI_FREQ_SCAN_EN == capsense_ENABLE)
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;
            #endif

            /* Set scan status, enter critical section and initiate scan */
            capsense_dsRam.status |= capsense_SW_STS_BUSY;

            #if(capsense_ENABLE == capsense_CSDV2) &&\
               (capsense_ENABLE != capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
               (capsense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
                CyDelayUs(capsense_CSX_ANALOG_STARTUP_DELAY_US);
            #endif

            capsense_SsCSXStartSample();
        }

    #else /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

        /*
        *  Calculate total sensor to be scanned. If buttons, one Tx and an Rx for each sensor
        *  if Matrix button or Touchpad, M x N rule applies
        */
        capsense_curWdgtTotalTx = capsense_curFlashWdgtPtr->numRows;
        capsense_curWdgtTotalRx  = capsense_curFlashWdgtPtr->numCols;

        /* If Component contains CSX ganged sensor, then check if widget contains ganged sensor */
        #if (capsense_CSX_GANGED_SNS_EN == 1u)
            if ((capsense_curFlashWdgtPtr->staticConfig & capsense_GANGED_SNS_MASK) != 0u)
            {
                /*
                *  1. Get sns pointer for first Rx
                *  2. Get number of Rx pin
                *  3. Get pointer to the Rx pin
                *  4. Connect all Rx pins
                */
                capsense_curGangRxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
                numElectrodes = capsense_curGangRxPtr->numPins ;
                capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                do
                {
                    capsense_CSXConnectRx(capsense_curRxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /*
                *  1. Get sns pointer for first Tx (Tx = Base + number of Rx).
                *  2. Get number of Tx electrodes
                *  3. Get pointer the Tx electrode
                *  4. Connect all Tx
                */
                capsense_curGangTxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
                capsense_curGangTxPtr += capsense_curFlashWdgtPtr->numCols;
                numElectrodes = capsense_curGangTxPtr->numPins ;
                capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];

                do
                {
                    capsense_CSXConnectTx(capsense_curTxIOPtr++);
                    numElectrodes--;
                }while (0u != numElectrodes);

                /* Assign callback to ISR */
                capsense_CSXPostScanApiPtr = &capsense_SsCSXPostMultiScanGanged;

            }
            else
        #endif
            {
                /*
                *  If no ganged sensor in the Component OR current widget contains no ganged sns, then:
                *    1. Find Rx pointer: Rx = Base address.
                *    2. Find Tx pointer: Tx = Base address + total Rx
                */
                capsense_curRxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
                capsense_curTxIOPtr = capsense_curRxIOPtr;
                capsense_curTxIOPtr = &capsense_curTxIOPtr[(capsense_curFlashWdgtPtr->numCols)];

                /* Connect first Tx and first Rx IOs for scan */
                capsense_CSXConnectTx(capsense_curTxIOPtr);
                capsense_CSXConnectRx(capsense_curRxIOPtr);

                /* Set callback to scan all the sensors in widget */
                capsense_CSXPostScanApiPtr = &capsense_SsCSXPostMultiScan;
            }

            /* Reset multi-frequency scan channel if enabled */
            #if (capsense_MULTI_FREQ_SCAN_EN == capsense_ENABLE)
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;
            #endif

        /* Set scan status, enter critical section and initiate scan */
        capsense_dsRam.status |= capsense_SW_STS_BUSY;

        #if(capsense_ENABLE == capsense_CSDV2) &&\
           (capsense_ENABLE != capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
           (capsense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
            CyDelayUs(capsense_CSX_ANALOG_STARTUP_DELAY_US);
        #endif

        capsense_SsCSXStartSample();

    #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
}

/*******************************************************************************
* Function Name: capsense_CSXScanExt()
****************************************************************************//**
*
* \brief
*  Starts the CSX conversion on the preconfigured sensor. This function requires
*  using the capsense_CSXSetupWidgetExt() function to set up a
*  widget.
*
* \details
*  Starts the CSX conversion on the preconfigured sensor. This function requires
*  using the capsense_CSXSetupWidgetExt() function to set up a
*  widget.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_ScanExt() function should be used instead.
*
*  This function performs single scanning of one sensor in the widget configured
*  by the capsense_CSXSetupWidgetExt() function. It does the following
*  tasks:
*    1. Sets a busy flag in the capsense_dsRam structure.
*    2. Configures the Tx clock frequency.
*    3. Configures the Modulator clock frequency.
*    4. Configures the IDAC value.
*    5. Starts single scanning.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example). This
*  function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status.
*
*  The sensor must be preconfigured by using the
*  capsense_CSXSetupWidgetExt() API prior to calling this function.
*  The sensor remains ready for the next scan if a previous scan was triggered
*  by using the capsense_CSXScanExt() function. In this case, calling
*  capsense_CSXSetupWidgetExt() is not required every time before the
*  capsense_CSXScanExt() function. If a previous scan was triggered in
*  any other way - capsense_Scan(), capsense_ScanAllWidgets()
*  or capsense_RunTuner() - (see the capsense_RunTuner() function
*  description for more details), the sensor must be preconfigured again by
*  using the capsense_CSXSetupWidgetExt() API prior to calling the
*  capsense_CSXScanExt() function.
*
*  If disconnection of the sensors is required after calling
*  capsense_CSXScanExt(), the capsense_CSXDisconnectTx() and
*  capsense_CSXDisconnectRx() APIs can be used.
*
*******************************************************************************/

void capsense_CSXScanExt(void)
{
    /* Reset multi-frequency scan channel if enabled */
    #if (capsense_MULTI_FREQ_SCAN_EN == capsense_ENABLE)
        capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;
    #endif

    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        if (0u != capsense_curRamSnsPtr->subConvNum)
        {
            /* Set busy flag and start conversion */
            capsense_dsRam.status |= capsense_SW_STS_BUSY;

            #if(capsense_ENABLE == capsense_CSDV2) &&\
               (capsense_ENABLE != capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
               (capsense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
                        CyDelayUs(capsense_CSX_ANALOG_STARTUP_DELAY_US);
            #endif
            capsense_SsCSXStartSample();
        }
    #else
        /* Set busy flag and start conversion */
        capsense_dsRam.status |= capsense_SW_STS_BUSY;

        #if(capsense_ENABLE == capsense_CSDV2) &&\
           (capsense_ENABLE != capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
           (capsense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
            CyDelayUs(capsense_CSX_ANALOG_STARTUP_DELAY_US);
        #endif
        capsense_SsCSXStartSample();
    #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
}


/*******************************************************************************
* Function Name: capsense_SsCSXPostMultiScan
****************************************************************************//**
*
* \brief
*   ISR function implements the multiple-sensor scanning for un-ganged CSX widgets.
*   This function is called by the Component ISR only, it should not be used by
*   the application layer.
*
*******************************************************************************/

static void capsense_SsCSXPostMultiScan(void)
{
    #ifdef capsense_ENTRY_CALLBACK
        capsense_EntryCallback();
    #endif /* capsense_ENTRY_CALLBACK */

    /* Copy scan result into sensor raw count array */
    capsense_curRamSnsPtr->raw[capsense_scanFreqIndex] = \
                             (capsense_csxScanPeriod - capsense_csxRawCount);

    #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
        /* Increment multi frequency scan index if all channels are not scanned */
        if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
        {
            /* Change multi-frequency channel and start sample */
            capsense_scanFreqIndex++;

            #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                capsense_SsChangeImoFreq((uint32)capsense_scanFreqIndex);
            #else
                capsense_SsChangeClkFreq((uint32)capsense_scanFreqIndex);
            #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

            capsense_SsCSXStartSample();
        }
        else
    #endif
        {
            #if (capsense_MULTI_FREQ_SCAN_EN == capsense_ENABLE)
                /* All channels are scanned. Reset the multi frequency scan channel */
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                    capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                #else
                    capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

            #endif

            #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
                /* Disconnect Tx/Rx electrodes of previously scanned sensor as preparation for next sensor scan */
                capsense_CSXDisconnectTx(capsense_curTxIOPtr);
                capsense_CSXDisconnectRx(capsense_curRxIOPtr);

                /* Increment sensor until non-skipped is found */
                do
                {
                    /* Increment sensor index to configure next sensor in widget */
                    capsense_sensorIndex++;

                    /* Increment sensor pointers */
                    capsense_curRamSnsPtr++;
                    capsense_curWdgtTotalTx--;
                    if (capsense_curWdgtTotalTx > 0u)
                    {
                        capsense_curTxIOPtr++;
                    }
                    else
                    {
                        capsense_curWdgtTotalRx--;
                        if (capsense_curWdgtTotalRx > 0u)
                        {
                            capsense_curRxIOPtr++;
                            capsense_curWdgtTotalTx  = capsense_curFlashWdgtPtr->numRows;
                            capsense_curTxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
                            capsense_curTxIOPtr = & capsense_curTxIOPtr[(capsense_curFlashWdgtPtr->numCols)];
                        }
                    }
                } while ((capsense_curWdgtTotalRx != 0u) && (capsense_curRamSnsPtr->subConvNum == 0u));

                /* Perform the next scan or switch to the next widget */
                if(capsense_curWdgtTotalRx != 0u)
                {
                    /* Connect Tx/Rx electrodes for the next scan */
                    capsense_CSXConnectTx(capsense_curTxIOPtr);
                    capsense_CSXConnectRx(capsense_curRxIOPtr);
                    /* Reset scan result holder, and initiate scan */
                    capsense_SsCSXStartSample();
                }
                else
                {
                    /* Call scan next widget API if requested, if not, complete scan */
                    if (capsense_requestScanAllWidget != 0u)
                    {
                        capsense_SsPostAllWidgetsScan();
                    }
                    else
                    {
                        capsense_dsRam.scanCounter++;
                        capsense_dsRam.status &= ~capsense_SW_STS_BUSY;
                    }
                }
            #else /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

                /*
                *  Disconnect Tx electrodes of previously scanned sensor as
                *  preparation for next sensor scan
                */
                capsense_CSXDisconnectTx (capsense_curTxIOPtr);

                /* Increment sensor index to configure next sensor in widget */
                capsense_sensorIndex++;

                /*
                *  Initiate scan for next sensor in widget, if all the sensors in
                *  widget are not scanned
                */
                capsense_curWdgtTotalTx--;
                if (capsense_curWdgtTotalTx > 0u)
                {
                    /*
                    *  1. Increment pointer to next Tx
                    *  2. Connect next Rx for scan
                    *  3. Increment pointer to sns data
                    */
                    capsense_curTxIOPtr++;
                    capsense_CSXConnectTx (capsense_curTxIOPtr);
                    capsense_curRamSnsPtr++;

                    /* Reset scan result holder, and initiate scan */
                    capsense_SsCSXStartSample();
                }

                /* Check if all Rx are looped through */
                else
                {
                    capsense_curWdgtTotalRx--;
                    if (capsense_curWdgtTotalRx > 0u)
                    {
                        /*
                        *  1. Disconnect current Rx electrode
                        *  2. Connect next Rx electrode
                        *  3. Re-initialize total Tx to be scanned per Rx
                        *  4. Find first Tx electrode again
                        *  5. Connect first Tx electrode
                        */
                        capsense_CSXDisconnectRx(capsense_curRxIOPtr);
                        capsense_curRxIOPtr++;
                        capsense_CSXConnectRx(capsense_curRxIOPtr);
                        capsense_curWdgtTotalTx  = capsense_curFlashWdgtPtr->numRows;
                        capsense_curTxIOPtr = (capsense_FLASH_IO_STRUCT const *)capsense_curFlashWdgtPtr->ptr2SnsFlash;
                        capsense_curTxIOPtr = & capsense_curTxIOPtr[(capsense_curFlashWdgtPtr->numCols)];
                        capsense_CSXConnectTx(capsense_curTxIOPtr);

                        /* Increment RAM sensor pointer pointer */
                        capsense_curRamSnsPtr++;

                        /* Initiate sample */
                        capsense_SsCSXStartSample();
                    }
                    else
                    {
                        /* If all the sensors are scanned, disconnect Tx */
                        capsense_CSXDisconnectRx(capsense_curRxIOPtr);

                        /* Call scan next widget API if requested, if not, complete scan */
                        if (capsense_requestScanAllWidget != 0u)
                        {
                            capsense_SsPostAllWidgetsScan();
                        }
                        else
                        {
                            /*
                            *  All pending scans completed,
                            *    1. update the counter to indicat same
                            *    2. Clear busy state as scanning is completed
                            */
                            capsense_dsRam.scanCounter++;
                            capsense_dsRam.status &= ~capsense_SW_STS_BUSY;
                        }
                    }
                }
            #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
        }

    #ifdef capsense_EXIT_CALLBACK
        capsense_ExitCallback();
    #endif /* capsense_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: capsense_SsCSXPostMultiScanGanged
****************************************************************************//**
*
* \brief
*   The ISR function implements the multiple-sensor scanning for ganged CSX widgets.
*   This function is called by the Component ISR only, should not be used by
*   the application layer.
*
* \details
*   The ISR function implements the multiple-sensor scanning for ganged CSX widgets.
*   This function is called by the Component ISR only, should not be used by
*   the application layer.
*
*******************************************************************************/
#if (capsense_CSX_GANGED_SNS_EN == 1u)

static void capsense_SsCSXPostMultiScanGanged(void)
{
    uint32 numElectrodes;

    #ifdef capsense_ENTRY_CALLBACK
        capsense_EntryCallback();
    #endif /* capsense_ENTRY_CALLBACK */

    /* Copy scan result into sensor raw count array */
    capsense_curRamSnsPtr->raw[capsense_scanFreqIndex] = \
                    (capsense_csxScanPeriod - capsense_csxRawCount);

    #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
        /* Increment multi frequency scan index if all channels are not scanned */
        if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
        {
            /* Change multi-frequency channel and start sample */
            capsense_scanFreqIndex++;

            #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                capsense_SsChangeImoFreq((uint32)capsense_scanFreqIndex);
            #else
                capsense_SsChangeClkFreq((uint32)capsense_scanFreqIndex);
            #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

            capsense_SsCSXStartSample();
        }
        else
    #endif
        {
            #if (capsense_MULTI_FREQ_SCAN_EN == capsense_ENABLE)
                /* All channels are scanned. Reset the multi frequency scan channel */
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                    capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                #else
                    capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

            #endif

            #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
                /* Disconnect Tx electrodes of previously scanned sensor as preparation for next sensor scan */
                numElectrodes = capsense_curGangTxPtr->numPins;
                capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];
                do
                {
                    capsense_CSXDisconnectTx(capsense_curTxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);
                /* Disconnect Rx electrodes of previously scanned sensor as preparation for next sensor scan */
                numElectrodes = capsense_curGangRxPtr->numPins;
                capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                do
                {
                    capsense_CSXDisconnectRx(capsense_curRxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /* Increment sensor until non-skipped is found */
                do
                {
                    /* Increment sensor index to configure next sensor in widget */
                    capsense_sensorIndex++;

                    /* Increment RAM sensor pointer */
                    capsense_curRamSnsPtr++;
                    capsense_curWdgtTotalTx--;
                    if (capsense_curWdgtTotalTx > 0u)
                    {
                        capsense_curGangTxPtr++;
                    }
                    else
                    {
                        /* Check if all Rx are scanned, if not, initiate scan for next Rx */
                        capsense_curWdgtTotalRx--;
                        if (capsense_curWdgtTotalRx > 0u)
                        {
                            capsense_curGangRxPtr++;
                            capsense_curWdgtTotalTx = capsense_curFlashWdgtPtr->numRows;
                            capsense_curGangTxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
                            capsense_curGangTxPtr += capsense_curFlashWdgtPtr->numCols;
                        }
                    }
                } while ((capsense_curWdgtTotalRx != 0u) && (capsense_curRamSnsPtr->subConvNum == 0u));

                if(capsense_curWdgtTotalRx != 0u)
                {
                    /* Connect Tx electrodes for the next scan */
                    numElectrodes = capsense_curGangTxPtr->numPins;
                    capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];
                    do
                    {
                        capsense_CSXConnectTx(capsense_curTxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);
                    /* Connect Tx electrodes for the next scan */
                    numElectrodes = capsense_curGangRxPtr->numPins ;
                    capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                    do
                    {
                        capsense_CSXConnectRx(capsense_curRxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);
                    /* Reset scan result holder, and initiate scan */
                    capsense_SsCSXStartSample();
                }
                else
                {
                    /* Call scan next widget API if requested, if not, complete scan */
                    if (capsense_requestScanAllWidget != 0u)
                    {
                        capsense_SsPostAllWidgetsScan();
                    }
                    else
                    {
                        capsense_dsRam.scanCounter++;
                        capsense_dsRam.status &= ~capsense_SW_STS_BUSY;
                    }
                }
            #else /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

                /* Disconnect ALL pins of previously scanned Tx */
                numElectrodes = capsense_curGangTxPtr->numPins ;
                capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];
                do
                {
                    capsense_CSXDisconnectTx (capsense_curTxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /* Increment sensor index to configure next sensor in widget */
                capsense_sensorIndex++;

                /* Check if all Tx are scanned, if not, initiate scan for next Tx */
                capsense_curWdgtTotalTx--;
                if (capsense_curWdgtTotalTx > 0u)
                {
                    /*
                    *  1. Find pointer of next Tx (ganged)
                    *  2. Connect all Tx pins
                    */
                    capsense_curGangTxPtr++;
                    numElectrodes = capsense_curGangTxPtr->numPins ;
                    capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];
                    do
                    {
                        capsense_CSXConnectTx(capsense_curTxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);

                    /* Increment RAM pointer to next sensor */
                    capsense_curRamSnsPtr++;

                    /* Reset scan result holder and initiate scan */
                    capsense_SsCSXStartSample();
                }
                else
                {
                    /* Check if all Rx are scanned, if not, initiate scan for next Rx */
                    capsense_curWdgtTotalRx--;
                    if (capsense_curWdgtTotalRx > 0u)
                    {
                        /* 1. Disconnect current Rx ALL pins */
                        numElectrodes = capsense_curGangRxPtr->numPins ;
                        capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                        do
                        {
                            capsense_CSXDisconnectRx(capsense_curRxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /* 2. Connect next Rx ALL pins */
                        capsense_curGangRxPtr++;
                        numElectrodes = capsense_curGangRxPtr->numPins ;
                        capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                        do
                        {
                            capsense_CSXConnectRx(capsense_curRxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /*
                        *  3. Re-initialize total Tx to be scanned per Rx
                        *  4. Find first Tx  again
                        *  5. Connect first Tx ALL pins
                        */
                        capsense_curWdgtTotalTx = capsense_curFlashWdgtPtr->numRows;
                        capsense_curGangTxPtr = capsense_curFlashWdgtPtr->ptr2SnsFlash;
                        capsense_curGangTxPtr += capsense_curFlashWdgtPtr->numCols;

                        /* 6. Connect Tx ALL pins */
                        numElectrodes = capsense_curGangTxPtr->numPins ;
                        capsense_curTxIOPtr = &capsense_ioList[capsense_curGangTxPtr->firstPinId];
                        do
                        {
                            capsense_CSXConnectTx(capsense_curTxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /* Increment RAM pointer to next sensor */
                        capsense_curRamSnsPtr++;

                        /* Reset scan result holder and initiate scan */
                        capsense_SsCSXStartSample();
                    }
                    else
                    {
                        /* Disconnect ALL electrodes of previously scanned Rx */
                        numElectrodes = capsense_curGangRxPtr->numPins ;
                        capsense_curRxIOPtr = &capsense_ioList[capsense_curGangRxPtr->firstPinId];
                        do
                        {
                            capsense_CSXDisconnectRx(capsense_curRxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /* Call scan next widget API if requested, if not, complete scan */
                        if (capsense_requestScanAllWidget != 0u)
                        {
                            capsense_SsPostAllWidgetsScan();
                        }
                        else
                        {
                            /*
                            *  All pending scans completed,
                            *    1. update the counter to indicate same
                            *    2. Clear busy state as scanning is completed
                            */
                            capsense_dsRam.scanCounter++;
                            capsense_dsRam.status &= ~capsense_SW_STS_BUSY;
                        }
                    }
                }
            #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
        }

    #ifdef capsense_EXIT_CALLBACK
        capsense_ExitCallback();
    #endif /* capsense_EXIT_CALLBACK */
}

#endif  /* (capsense_CSX_GANGED_SNS_EN == 1u) */

/*******************************************************************************
* Function Name: capsense_SsCSXPostSingleScan
****************************************************************************//**
*
* \brief
*   The ISR function for single-sensor scanning implementation.
*
* \details
*   This function is used by capsense ISR in the CSX scanning mode to implement
*   the single-sensor scanning.
*   This function should not be used by the application layer.
*
*******************************************************************************/

static void capsense_SsCSXPostSingleScan(void)
{
    #ifdef capsense_ENTRY_CALLBACK
        capsense_EntryCallback();
    #endif /* capsense_ENTRY_CALLBACK */

    /*
    * Copy scan result into sensor raw count array and clear busy flag
    *    No sensor is connected or disconnected in this function
    *    Calling capsense_ScanExt from application would perform
    *    one more scan of same sensor. Specifically for low-power mode.
    */
    capsense_curRamSnsPtr->raw[capsense_scanFreqIndex] =
                        (capsense_csxScanPeriod - capsense_csxRawCount);

    #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
        /* Increment multi frequency scan index if all channels are not scanned */
        if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
        {
            /* Change multi-frequency channel and start sample */
            capsense_scanFreqIndex++;

            #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                capsense_SsChangeImoFreq((uint32)capsense_scanFreqIndex);
            #else
                capsense_SsChangeClkFreq((uint32)capsense_scanFreqIndex);
            #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

            capsense_SsCSXStartSample();
        }
        else
    #endif
        {
            #if (capsense_MULTI_FREQ_SCAN_EN == capsense_ENABLE)
                /* All channels are scanned. Reset the multi frequency scan channel */
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                    capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                #else
                    capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

            #endif
            /*
            * All pending scans completed,
            *   1. Update the counter to indicate same
            *   2. Clear busy state as scanning is completed
            */
            capsense_dsRam.scanCounter++;
            capsense_dsRam.status &= ~capsense_SW_STS_BUSY;
        }

    #ifdef capsense_EXIT_CALLBACK
        capsense_ExitCallback();
    #endif /* capsense_EXIT_CALLBACK */
}

/*******************************************************************************
* Function Name: capsense_CSXCalibrateWidget
****************************************************************************//**
*
* \brief
*  Calibrates the raw count values of all the sensors/nodes in a CSX widget.
*
* \details
*  Calibrates the raw count values of all the sensors/nodes in a CSX widget.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_CalibrateWidget() function should be used instead.
*
*  Performs a successive approximation search algorithm to find appropriate
*  IDAC values for sensors in the specified widget that provides a raw count
*  to the level specified by the target parameter.
*
*  This function is available when the CSX Enable IDAC auto-calibration
*  parameter is enabled.
*
* \param widgetId
*  Specifies the ID number of the CSX widget to calibrate its raw count.
*  A macro for the widget ID can be found in the
*  capsense Configuration header file defined as
*  capsense_<WidgetName>_WDGT_ID.
*
* \param target
*  Specifies the calibration target in percentages of the maximum raw count.
*
* \return Returns the status of the operation:
*   - Zero     - All the sensors in the widget are calibrated successfully.
*   - Non-Zero - Calibration failed for any sensor in the widget.
*
*******************************************************************************/
#if (capsense_ENABLE == capsense_CSX_IDAC_AUTOCAL_EN)

cystatus capsense_CSXCalibrateWidget(uint32 widgetId, uint16 target)
{
    /* Variable to calculate raw count target */
    uint32 rawTarget;
    /* Counter for loop execution */
    uint32 totalSns;
    /* Counter for loop execution */
    uint32 calibrationIndex;

    uint32 watchdogCounter;

    cystatus calibrateStatus = CYRET_SUCCESS;

    /* Currently used IDAC-bit */
    uint8 curIdacMask = (1u << (capsense_CSX_IDAC_BITS_USED - 1u));
    /* Next used IDAC-bit */
    uint8 nextIdacMask = (curIdacMask >> 1u);

    /* initialize ptr to sensor structures */
    capsense_curRamSnsPtr = (capsense_RAM_SNS_STRUCT *)capsense_dsFlash.wdgtArray[widgetId].ptr2SnsRam;

    #if (capsense_DISABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Calculate target raw count */
        capsense_csxScanPeriod  = capsense_SsCalcCsxScanPeriod(
            (capsense_RAM_WD_BASE_STRUCT *)capsense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam);
        rawTarget = capsense_csxScanPeriod;
        rawTarget = (rawTarget * target) / capsense_PERCENTAGE_100;
    #endif /* (capsense_DISABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */


    /* Find out total sensors/nodes in widget */
    totalSns = ((uint32)capsense_dsFlash.wdgtArray[widgetId].numCols *
                (uint32)capsense_dsFlash.wdgtArray[widgetId].numRows);

    /* Clear raw count registers and IDAC registers of all the sensors/nodes */
    for (calibrationIndex = 0u; calibrationIndex < totalSns; calibrationIndex++)
    {
        capsense_curRamSnsPtr->raw[capsense_FREQ_CHANNEL_0] = 0u;
        capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_0] = curIdacMask;
        #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
            capsense_curRamSnsPtr->raw[capsense_FREQ_CHANNEL_1] = 0u;
            capsense_curRamSnsPtr->raw[capsense_FREQ_CHANNEL_2] = 0u;
            capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_1] = curIdacMask;
            capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_2] = curIdacMask;
        #endif
        capsense_curRamSnsPtr++;
    }

    /* Perform binary search for accurate IDAC value for each sensor/node */
    do
    {
        /* Scan all the sensors/nodes in widget */
        (void)capsense_SetupWidget(widgetId);
        (void)capsense_Scan();

        watchdogCounter = capsense_CSX_MEASURE_WATCHDOG_CYCLES_NUM;
        while ((capsense_dsRam.status & capsense_SW_STS_BUSY) != 0u)
        {
            if(0uL == watchdogCounter)
            {
                calibrateStatus = CYRET_TIMEOUT;
                break;
            }
            watchdogCounter--;
        }

        /* Get access to sensor data */
        capsense_curRamSnsPtr = (capsense_RAM_SNS_STRUCT *)capsense_dsFlash.wdgtArray[widgetId].ptr2SnsRam;

        /* Check raw count and adjust IDAC, loop through all the sensors/nodes */
        for (calibrationIndex = 0u; calibrationIndex < totalSns; calibrationIndex++)
        {
            /* Calculate raw count target for specified node */
            #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
                rawTarget = (capsense_SsCSXOversample() * target) / capsense_PERCENTAGE_100;
            #endif

            /* Check if current raw count is above target,
            *   if yes, clear the MS bit of bit
            *   if no, keep the MS bit and set next bit
            */
            if (capsense_curRamSnsPtr->raw[capsense_FREQ_CHANNEL_0] > rawTarget)
            {
                capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_0] &= (uint8)(~curIdacMask);
            }
            capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_0] |= nextIdacMask;

            #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
                if (capsense_curRamSnsPtr->raw[capsense_FREQ_CHANNEL_1] > rawTarget)
                {
                    capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_1] &= (uint8)(~curIdacMask);
                }

                if (capsense_curRamSnsPtr->raw[capsense_FREQ_CHANNEL_2] > rawTarget)
                {
                    capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_2] &= (uint8)(~curIdacMask);
                }

                capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_1] |= nextIdacMask;
                capsense_curRamSnsPtr->idacComp[capsense_FREQ_CHANNEL_2] |= nextIdacMask;
            #endif
            capsense_curRamSnsPtr++;
        }

        /* Shift both current idac and pre Idac values to right by 1 */
        curIdacMask = nextIdacMask;
        nextIdacMask = nextIdacMask >> 1u;
    }
    while ((curIdacMask != 0u) && (calibrateStatus == CYRET_SUCCESS));

    /* Perform specified widget scan to check calibration result */
    (void)capsense_SetupWidget(widgetId);
    (void)capsense_Scan();

    if (calibrateStatus == CYRET_SUCCESS)
    {
        watchdogCounter = capsense_CSX_MEASURE_WATCHDOG_CYCLES_NUM;
        while ((capsense_dsRam.status & capsense_SW_STS_BUSY) != 0u)
        {
            if(0uL == watchdogCounter)
            {
                calibrateStatus = CYRET_TIMEOUT;
                break;
            }

            watchdogCounter--;
        }

        if (calibrateStatus == CYRET_SUCCESS)
        {
            calibrateStatus = capsense_SsCSXCalibrateCheck(widgetId, (uint32)capsense_csxScanPeriod, (uint32)target);
        }
    }

     /* Update CRC */
    #if (capsense_ENABLE ==capsense_TST_WDGT_CRC_EN)
        capsense_DsUpdateWidgetCrc(widgetId);
    #endif

    return(calibrateStatus);
}


/*******************************************************************************
* Function Name: capsense_SsCSXCalibrateCheck
****************************************************************************//**
*
* \brief
*  This internal function checks if the calibration is performed successfully.
*
* \details
*  The function verifies that raw counts are within acceptable range
*  defined by target and calibration error parameters.
*
* \param widgetId
*  The desired widget ID.
*
* \param scanPeriod
*  CSX scan period for the specified widget.
*
* \param target
*  Raw count target in percentage.
*
* \return Returns the status of the operation:
*   - Zero     - All the sensors in the widget are calibrated successfully.
*   - Non-Zero - Calibration failed for any sensor in the widget.
*
*******************************************************************************/
static cystatus capsense_SsCSXCalibrateCheck(uint32 widgetId, uint32 scanPeriod, uint32 target)
{
    uint32 rawcount;
    uint32 snsIndex;
    uint32 freqChannel;
    uint32 upperLimit;
    uint32 lowerLimit;
    cystatus calibrateStatus = CYRET_SUCCESS;

    capsense_FLASH_WD_STRUCT const *ptrFlashWidget = &capsense_dsFlash.wdgtArray[widgetId];
    capsense_RAM_SNS_STRUCT *ptrRamSensor = ptrFlashWidget->ptr2SnsRam;

    lowerLimit = 0u;
    if (target > capsense_CSX_CALIBRATION_ERROR)
    {
        lowerLimit = target - capsense_CSX_CALIBRATION_ERROR;
    }
    upperLimit = target + capsense_CSX_CALIBRATION_ERROR;
    if (upperLimit > capsense_PERCENTAGE_100)
    {
        upperLimit = capsense_PERCENTAGE_100;
    }
    lowerLimit = (scanPeriod * lowerLimit) / capsense_PERCENTAGE_100;
    upperLimit = (scanPeriod * upperLimit) / capsense_PERCENTAGE_100;

    /* Check if raw count is in the defined range */
    for(snsIndex = 0u; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
    {
        for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
        {
            rawcount = ptrRamSensor->raw[freqChannel];
            if ((rawcount < lowerLimit) || (rawcount > upperLimit))
            {
                calibrateStatus = CYRET_BAD_DATA;
                break;
            }
        }
        ptrRamSensor++;
    }
    return (calibrateStatus);
}

#endif /* (capsense_CSX_IDAC_AUTOCAL_EN == capsense_ENABLE) */

#if(capsense_ENABLE == capsense_CSDV2)
/*******************************************************************************
* Function Name: capsense_SsCSXStartSample
****************************************************************************//**
*
* \brief
*   Starts scanning for the CSX widget.
*
* \details
*   Starts scanning for the CSX widget.
*
*******************************************************************************/
static void capsense_SsCSXStartSample(void)
{
    uint32 tmpRegVal;
    uint32 idacGainIndex;

    /* Configuring IDAC register */
    idacGainIndex = ((capsense_RAM_WD_BASE_STRUCT *)capsense_curFlashWdgtPtr->ptr2WdgtRam)->idacGainIndex;
    tmpRegVal = capsense_DEFAULT_CSD_IDACA_CFG & ~capsense_IDAC_GAIN_MASK;
    tmpRegVal |= ((uint32)capsense_curRamSnsPtr->idacComp[capsense_scanFreqIndex] & capsense_IDAC_MOD_VAL_MASK);
    tmpRegVal |= capsense_idacGainTable[idacGainIndex].gainReg;
    CY_SET_REG32(capsense_CSD_IDACA_PTR, tmpRegVal);

    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Configure node-specific number of sub-conversion */
        capsense_csxScanPeriod = (uint16)capsense_SsCSXOversample();
        CY_SET_REG32(capsense_SEQ_NORM_CNT_PTR, (uint32)capsense_curRamSnsPtr->subConvNum);
    #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

    /* Clear scan result holder */
    capsense_csxRawCount = 0u;

    #ifdef capsense_START_SAMPLE_CALLBACK
        capsense_StartSampleCallback(capsense_widgetIndex, capsense_sensorIndex);
    #endif /* capsense_START_SAMPLE_CALLBACK */

    capsense_SsCSXStartSampleExt();
}
#else

/*******************************************************************************
* Function Name: capsense_SsCSXStartSample
****************************************************************************//**
*
* \brief
*   Starts scanning for the CSX widget.
*
* \param widgetIndex The ID of the widget to be calibrated.
*
* \details
*
*******************************************************************************/
static void capsense_SsCSXStartSample(void)
{
    uint8 critSect;
    uint32 tmpRegVal;
    uint32 idacGainIndex;

    idacGainIndex = ((capsense_RAM_WD_BASE_STRUCT *)capsense_curFlashWdgtPtr->ptr2WdgtRam)->idacGainIndex;
    critSect = CyEnterCriticalSection();
    tmpRegVal = CY_GET_REG32(capsense_IDAC_PTR);
    tmpRegVal &= ~capsense_IDAC_MOD_MASK;
    tmpRegVal &= ~capsense_IDAC_GAIN_MASK;
    tmpRegVal |= capsense_IDAC_MOD_MODE_VARIABLE | (uint32)capsense_curRamSnsPtr->idacComp[capsense_scanFreqIndex];
    tmpRegVal |= capsense_idacGainTable[idacGainIndex].gainReg;

    CY_SET_REG32(capsense_IDAC_PTR, tmpRegVal);
    CyExitCriticalSection(critSect);

    /* Clear scan result holder */
    capsense_csxRawCount = 0u;

    #ifdef capsense_START_SAMPLE_CALLBACK
        capsense_StartSampleCallback(capsense_widgetIndex, capsense_sensorIndex);
    #endif /* capsense_START_SAMPLE_CALLBACK */

    #if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Configure node-specific number of sub-conversion */
        capsense_csxScanPeriod = (uint16)capsense_SsCSXOversample();
    #endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

    /* Disable interrupts and initiate scan */
    critSect = CyEnterCriticalSection();
    capsense_SsCSXStartSampleExt();
    CyExitCriticalSection(critSect);
}
#endif /* (capsense_ENABLE == capsense_CSDV2) */

/*******************************************************************************
* Function Name: capsense_CSXConnectTx
****************************************************************************//**
*
* \brief
*  Connects a Tx electrode to the CSX scanning hardware.
*
* \details
*  This function connects a port pin (Tx electrode) to the CSD_SENSE signal.
*  It is assumed that drive mode of the port pin is already set to STRONG
*  in the HSIOM_PORT_SELx register.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time when there is only one port pin for an
*  electrode for example).
*
* \param txPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a sensor
*  to be connected to the sensing HW block as a Tx pin.
*
*******************************************************************************/
void capsense_CSXConnectTx(capsense_FLASH_IO_STRUCT const *txPtr)
{
    capsense_WriteBitsSafe(txPtr->pcPtr, (uint32)(capsense_GPIO_PC_MASK << txPtr->shift),
            (uint32)(capsense_GPIO_STRGDRV << txPtr->shift));
    capsense_WriteBitsSafe(txPtr->hsiomPtr, (capsense_HSIOM_SEL_MASK << txPtr->hsiomShift),
            (uint32)(capsense_HSIOM_SEL_CSD_SENSE << txPtr->hsiomShift));
}

/*******************************************************************************
* Function Name: capsense_CSXConnectRx
****************************************************************************//**
*
* \brief
*  Connects an Rx electrode to the CSX scanning hardware.
*
* \details
*  This function connects a port pin (Rx electrode) to AMUXBUS-A and sets
*  drive mode of the port pin to High-Z in the GPIO_PRT_PCx register.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time when there is only one port pin for an
*  electrode for example).
*
* \param rxPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a sensor
*  to be connected to the sensing HW block as an Rx pin.
*
*******************************************************************************/
void capsense_CSXConnectRx(capsense_FLASH_IO_STRUCT const *rxPtr)
{
    capsense_WriteBitsSafe(rxPtr->pcPtr, (uint32)(capsense_GPIO_PC_MASK << rxPtr->shift), 0u);
    capsense_WriteBitsSafe(rxPtr->hsiomPtr, (capsense_HSIOM_SEL_MASK << rxPtr->hsiomShift), (uint32)(capsense_HSIOM_SEL_AMUXA << rxPtr->hsiomShift));
}

/*******************************************************************************
* Function Name: capsense_CSXDisconnectTx
****************************************************************************//**
*
* \brief
*  Disconnects a Tx electrode from the CSX scanning hardware.
*
* \details
*  This function disconnects a port pin (Tx electrode) from the CSD_SENSE
*  signal and configures the port pin to the strong drive mode. It is assumed
*  that the data register (GPIO_PRTx_DR) of the port pin is already 0.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time when there is only one port pin for an
*  electrode for example).
*
* \param txPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a Tx pin
*  sensor to be disconnected from the sensing HW block.
*
*******************************************************************************/
void capsense_CSXDisconnectTx(capsense_FLASH_IO_STRUCT const *txPtr)
{
    uint32 regValue;
    uint8  interruptState;

    interruptState = CyEnterCriticalSection();
    regValue = CY_GET_REG32 (txPtr->hsiomPtr);
    regValue &= ~(txPtr->hsiomMask);
    CY_SET_REG32 (txPtr->hsiomPtr, regValue);
    CyExitCriticalSection(interruptState);

    interruptState = CyEnterCriticalSection();
    /* Update port configuration register (drive mode) for sensor */
    regValue = CY_GET_REG32(txPtr->pcPtr);
    regValue &= ~(capsense_GPIO_PC_MASK << txPtr->shift);

    if(capsense_SNS_CONNECTION_GROUND == capsense_dsRam.scanCurrentISC)
    {
        regValue |= (CY_SYS_PINS_DM_STRONG << txPtr->shift);
    }
    else
    {
        regValue |= (CY_SYS_PINS_DM_ALG_HIZ << txPtr->shift);
    }

    CY_SET_REG32(txPtr->pcPtr, regValue);
    CyExitCriticalSection(interruptState);
}

/*******************************************************************************
* Function Name: capsense_CSXDisconnectRx
****************************************************************************//**
*
* \brief
*  Disconnects an Rx electrode from the CSX scanning hardware.
*
* \details
*  This function disconnects a port pin (Rx electrode) from AMUXBUS_A and
*  configures the port pin to the strong drive mode. It is assumed that the
*  data register (GPIO_PRTx_DR) of the port pin is already 0.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time when there is only one port pin for
*  an electrode for example).
*
* \param rxPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to an Rx pin
*  sensor to be disconnected from the sensing HW block.
*
*******************************************************************************/
void capsense_CSXDisconnectRx(capsense_FLASH_IO_STRUCT const *rxPtr)
{
    uint32 regValue;
    uint8  interruptState;

    interruptState = CyEnterCriticalSection();
    regValue = CY_GET_REG32 (rxPtr->hsiomPtr);
    regValue &= ~(rxPtr->hsiomMask);
    CY_SET_REG32 (rxPtr->hsiomPtr, regValue);
    CyExitCriticalSection(interruptState);

    interruptState = CyEnterCriticalSection();
    /* Update port configuration register (drive mode) for sensor */
    regValue = CY_GET_REG32(rxPtr->pcPtr);
    regValue &= ~(capsense_GPIO_PC_MASK << rxPtr->shift);

    if(capsense_SNS_CONNECTION_GROUND == capsense_dsRam.scanCurrentISC)
    {
        regValue |= (CY_SYS_PINS_DM_STRONG << rxPtr->shift);
    }
    else
    {
        regValue |= (CY_SYS_PINS_DM_ALG_HIZ << rxPtr->shift);
    }

    CY_SET_REG32(rxPtr->pcPtr, regValue);
    regValue = CY_GET_REG32(rxPtr->drPtr);
    regValue &=  ~(rxPtr->mask);
    CY_SET_REG32 (rxPtr->drPtr, regValue);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: capsense_SsCSXGetTxClkDivider
****************************************************************************//**
*
* \brief
*  This function gets the Sense Clock Divider value for one-dimension widgets
*  and the Column Sense Clock divider value for two-dimension widgets.
*
* \details
*  This function gets the Sense Clock Divider value based on the Component
*  configuration. The function is applicable for one-dimension widgets and for
*  two-dimension widgets.
*
* \param
*  widgetId Specifies the ID of the widget.
*
* \return The Sense Clock Divider value for one-dimension widgets
*         and the Column Sense Clock divider value for two-dimension widgets.
*
*******************************************************************************/
uint32 capsense_SsCSXGetTxClkDivider(uint32 widgetId)
{
    uint32 retVal;

    /* Get sense divider based on configuration */
    #if (capsense_DISABLE == capsense_CSX_COMMON_TX_CLK_EN)
        capsense_RAM_WD_BASE_STRUCT *ptrWdgt;

        ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
        capsense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;

        retVal = (uint32)(ptrWdgt->snsClk);
    #else
        retVal = (uint32)capsense_dsRam.snsCsxClk;
    #endif /* (capsense_DISABLE == capsense_CSX_COMMON_TX_CLK_EN) */

    if(widgetId == 0uL)
    {
        ;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: capsense_SsCalcCsxScanPeriod
****************************************************************************//**
*
* \brief
*  Calculates scan period for a desired CSX widget.
*
* \details
*  This function calculates a scan period for a desired CSX widget considering
*  common Tx clock option.
*
* \param wdgtPtr
*  The pointer to a register map object that contains widget information.
*
* \return
*  Returns the CSX scan period for the widget.
*
*******************************************************************************/
static uint16 capsense_SsCalcCsxScanPeriod(capsense_RAM_WD_BASE_STRUCT const *wdgtPtr)
{
    uint32 temp;

    #if(capsense_DISABLE == capsense_CSX_COMMON_TX_CLK_EN)
        temp = (uint32)(wdgtPtr->snsClk);
    #else
        temp = (uint32)(capsense_dsRam.snsCsxClk);
    #endif /* (capsense_DISABLE == capsense_CSX_COMMON_TX_CLK_EN) */

    #if(capsense_ENABLE == capsense_CSDV2)
        temp  = LO16((uint32)wdgtPtr->resolution * (temp - capsense_CSX_DEADBAND_CYCLES_NUMBER));
    #else
        #if(capsense_ENABLE == capsense_IS_M0S8PERI_BLOCK)
            temp = (temp / (uint32)capsense_dsRam.modCsxClk);
        #endif /* (capsense_ENABLE == capsense_IS_M0S8PERI_BLOCK) */

        temp = ((uint32)wdgtPtr->resolution * capsense_NUM_HALF_CYCLES * temp);
    #endif /* (capsense_ENABLE == capsense_CSDV2) */

    /* return the scan period */
    return ((uint16)temp);
}


#if (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
/*******************************************************************************
* Function Name: capsense_SsCSXOversample
****************************************************************************//**
*
* \brief
*   Calculates the scan period of specific node.
*
* \details
*   Calculates the scan period of specific node that is used as maximum
*   raw count at raw count inversion (capsense_csxScanPeriod variable).
*   The capsense_curFlashWdgtPtr and capsense_curRamSnsPtr
*   must be configured to proper widget/sensor before calling this function.
*
* \return
*   Returns the scan period of specific node (used as maximum raw count)
*
*******************************************************************************/
static uint32 capsense_SsCSXOversample(void)
{
    uint32 temp;

    #if(capsense_DISABLE == capsense_CSX_COMMON_TX_CLK_EN)
        capsense_RAM_WD_BASE_STRUCT * curRamWdgtBasePtr;
        curRamWdgtBasePtr = (capsense_RAM_WD_BASE_STRUCT *)capsense_curFlashWdgtPtr->ptr2WdgtRam;
        temp = (uint32)(curRamWdgtBasePtr->snsClk);
    #else
        temp = (uint32)(capsense_dsRam.snsCsxClk);
    #endif /* (capsense_DISABLE == capsense_CSX_COMMON_TX_CLK_EN) */

    #if(capsense_ENABLE == capsense_CSDV2)
        temp  = LO16((uint32)capsense_curRamSnsPtr->subConvNum * (temp - capsense_CSX_DEADBAND_CYCLES_NUMBER));
    #else
        #if(capsense_ENABLE == capsense_IS_M0S8PERI_BLOCK)
            temp = (temp / (uint32)capsense_dsRam.modCsxClk);
        #endif /* (capsense_ENABLE == capsense_IS_M0S8PERI_BLOCK) */

        temp = ((uint32)capsense_curRamSnsPtr->subConvNum * capsense_NUM_HALF_CYCLES * temp);
    #endif /* (capsense_ENABLE == capsense_CSDV2) */

    /* return the scan period */
    return (temp);
}
#endif /* (capsense_ENABLE == capsense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */


#if(capsense_ENABLE == capsense_CSDV2)
/**
* \cond SECTION_C_INTERRUPT
* \addtogroup group_c_interrupt
* \{
*/
/*******************************************************************************
* Function Name: capsense_CSXScanISR
****************************************************************************//**
*
* \brief
*  This is an internal ISR function to handle the CSX sensing method operation.
*
* \details
*  This handler covers the following functionality:
*   - Read the result of the measurement and store it into the corresponding register of
*     the data structure.
*   - If the Noise Metric functionality is enabled, then check the number of bad
*     conversions and repeat the scan of the current sensor of the number of bad
*     conversions is greater than the Noise Metric Threshold.
*   - Initiate the scan of the next sensor for multiple sensor scanning mode.
*   - Update the Status register in the data structure.
*   - Switch the HW block to the default state if scanning of all the sensors is
*     completed.
*
*******************************************************************************/
CY_ISR(capsense_CSXScanISR)
{
#if(0u != capsense_CSX_NOISE_METRIC_EN)
    uint32 tmpRegVal;
#endif /* (0u != capsense_CSX_NOISE_METRIC_EN) */
#if(0u != capsense_CSX_NOISE_METRIC_EN)
    static uint32 capsense_resamplingCyclesCnt = capsense_RESAMPLING_CYCLES_MAX_NUMBER;
#endif /* (0u != capsense_CSX_NOISE_METRIC_EN) */

    CyIntDisable(capsense_ISR_NUMBER);

    CY_SET_REG32(capsense_INTR_PTR, capsense_DEFAULT_CSD_INTR_CFG);

    capsense_csxRawCount  = (uint16)(CY_GET_REG32(capsense_RESULT_VAL1_PTR) &\
                                                         capsense_RESULT_VAL1_VALUE_MASK);

    capsense_csxRawCount += (uint16)(CY_GET_REG32(capsense_RESULT_VAL2_PTR) &\
                                                         capsense_RESULT_VAL2_VALUE_MASK);

    /* This workaround neded to prevent overflow in the SW register map. Cypress ID #234358 */
    if(capsense_csxRawCount > capsense_csxScanPeriod)
    {
        capsense_csxRawCount = capsense_csxScanPeriod;
    }

#if(0u != capsense_CSX_NOISE_METRIC_EN)
    tmpRegVal = CY_GET_REG32(capsense_RESULT_VAL1_PTR) >> capsense_RESULT_VAL1_BAD_CONVS_SHIFT;

    if((tmpRegVal > capsense_CSX_NOISE_METRIC_TH) && (capsense_resamplingCyclesCnt > 0uL))
    {
        CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SCAN_CSD_SEQ_START_CFG);
        capsense_resamplingCyclesCnt--;
    }
    else
    {
        capsense_CSXPostScanApiPtr();
        capsense_resamplingCyclesCnt = capsense_RESAMPLING_CYCLES_MAX_NUMBER;
    }
#else
    capsense_CSXPostScanApiPtr();
#endif /* (0u != capsense_CSX_NOISE_METRIC_EN) */

    if(capsense_NOT_BUSY == (capsense_dsRam.status & capsense_SW_STS_BUSY))
    {
        CY_SET_REG32(capsense_CONFIG_PTR, capsense_DEFAULT_CSD_CONFIG_CFG);
        CY_SET_REG32(capsense_CSDCMP_PTR, capsense_DEFAULT_CSD_CSDCMP_CFG);
        CY_SET_REG32(capsense_CSD_IDACA_PTR, capsense_DEFAULT_CSD_IDACA_CFG);
    }

    CyIntEnable(capsense_ISR_NUMBER);
}

/** \}
* \endcond */

/*******************************************************************************
* Function Name: capsense_SsCSXStartSampleExt
****************************************************************************//**
*
* \brief
*   Starts the HW sequencer to perform the CSX conversion.
*   specific widget.
*
* \details
*   This function covers the following functionality:
*      1. Configures the HW sequencer to perform the coarse initialization.
*      2. Waiting for completion of the coarse initialization.
*      3. Configures the HW sequencer to perform the normal conversion.
*      4. Starts the normal conversion
*
*******************************************************************************/
static CY_INLINE void capsense_SsCSXStartSampleExt(void)
{
    uint32 filterDelay;
    uint32 watchdogCounter;
    #if (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
        uint32 sampleClkFreqHz;
    #endif /* (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */

/* Configure the HW sequencer to perform the coarse initialization. */
    CY_SET_REG32(capsense_CONFIG_PTR,           capsense_DEFAULT_CSD_CONFIG_CFG);
    CY_SET_REG32(capsense_HSCMP_PTR,            capsense_PRECHARGE_CSD_HSCMP_CFG);
    CY_SET_REG32(capsense_SW_HS_P_SEL_PTR,      capsense_PRECHARGE_CSD_SW_HS_P_SEL_CFG);
    CY_SET_REG32(capsense_SW_HS_N_SEL_PTR,      capsense_PRECHARGE_CSD_SW_HS_N_SEL_CFG);
    CY_SET_REG32(capsense_SW_DSI_SEL_PTR,       capsense_PRECHARGE_CSD_SW_DSI_SEL_CFG);
    CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR,    capsense_PRECHARGE_CSD_SW_SHIELD_SEL_CFG);
    CY_SET_REG32(capsense_SW_FW_MOD_SEL_PTR,    capsense_PRECHARGE_CSD_SW_FW_MOD_SEL_CFG);
    CY_SET_REG32(capsense_SW_FW_TANK_SEL_PTR,   capsense_PRECHARGE_CSD_SW_FW_TANK_SEL_CFG);

    #if(capsense_ENABLE == capsense_CSDV2) &&\
       (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
       (capsense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
                CyDelayUs(capsense_CSX_ANALOG_STARTUP_DELAY_US);
    #endif

    CY_SET_REG32(capsense_SEQ_START_PTR,        capsense_PRECHARGE_CSD_SEQ_START_CFG);

    /* Wait for the HSCMP trigger and retutn the sequencer to the IDLE state. */
    watchdogCounter = capsense_CSX_PRECHARGE_WATCHDOG_CYCLES_NUM;
    while((0u != (capsense_SEQ_START_START_MASK & CY_GET_REG32(capsense_SEQ_START_PTR))) && (0u != watchdogCounter))
    {
        watchdogCounter--;
    }

    /* Reset the sequencer to the IDLE state if HSCMP not triggered till watchdog period is out. */
    if(0u != (capsense_SEQ_START_START_MASK & CY_GET_REG32(capsense_SEQ_START_PTR)))
    {
        CY_SET_REG32(capsense_SEQ_START_PTR,  capsense_DEFAULT_CSD_SEQ_START_CFG);
    }

    #if (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
        sampleClkFreqHz = CYDEV_BCLK__HFCLK__HZ / (uint32)capsense_dsRam.modCsxClk;
        if(sampleClkFreqHz <= capsense_MOD_CSD_CLK_12MHZ)
        {
            filterDelay = capsense_CONFIG_FILTER_DELAY_12MHZ;
        }
        else if(sampleClkFreqHz <= capsense_MOD_CSD_CLK_24MHZ)
        {
            filterDelay = capsense_CONFIG_FILTER_DELAY_24MHZ;
        }
        else
        {
            filterDelay = capsense_CONFIG_FILTER_DELAY_48MHZ;
        }
    #else
        filterDelay = capsense_CONFIG_FILTER_DELAY_12MHZ;
    #endif /* (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */

    /* Configure the HW sequencer to perform the normal conversion. */
    CY_SET_REG32(capsense_CONFIG_PTR, capsense_PRESCAN_CSD_CONFIG_CFG | filterDelay);
    CY_SET_REG32(capsense_CSDCMP_PTR, capsense_PRESCAN_CSD_CSDCMP_CFG);
    CY_SET_REG32(capsense_HSCMP_PTR, capsense_DEFAULT_CSD_HSCMP_CFG);
    CY_SET_REG32(capsense_SW_HS_P_SEL_PTR, capsense_DEFAULT_CSD_SW_HS_P_SEL_CFG);
    CY_SET_REG32(capsense_SW_HS_N_SEL_PTR, capsense_DEFAULT_CSD_SW_HS_N_SEL_CFG);
    CY_SET_REG32(capsense_SW_DSI_SEL_PTR, capsense_DEFAULT_CSD_SW_DSI_SEL_CFG);
    CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR, capsense_DEFAULT_CSD_SW_SHIELD_SEL_CFG);
    CY_SET_REG32(capsense_SW_FW_MOD_SEL_PTR, capsense_DEFAULT_CSD_SW_FW_MOD_SEL_CFG);
    CY_SET_REG32(capsense_SW_FW_TANK_SEL_PTR, capsense_DEFAULT_CSD_SW_FW_TANK_SEL_CFG);

    /* Clear all pending interrupts of CSD block */
    CY_SET_REG32(capsense_INTR_PTR, capsense_DEFAULT_CSD_INTR_CFG);

    /* Start the normal conversion. */
    CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SCAN_CSD_SEQ_START_CFG);
}

#endif /* (capsense_ENABLE == capsense_CSDV2) */
#endif  /* (0u != capsense_CSX_EN) */


/* [] END OF FILE */
