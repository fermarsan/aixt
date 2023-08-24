/***************************************************************************//**
* \file CapSense_SensingCSX_LL.c
* \version 7.10
*
* \brief
*   This file defines the data structure global variables and provides
*   implementation for the low-level APIs of the CSX part of
*   the Sensing module. The file contains the APIs used for the CSD block
*   initialization, calibration and scanning.
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
#include <cytypes.h>
#include "CyLib.h"

#include "CapSense_Structure.h"
#include "CapSense_Configuration.h"
#include "CapSense_SensingCSX_LL.h"
#include "CapSense_Sensing.h"
#if (CapSense_ENABLE == CapSense_SELF_TEST_EN)
    #include "CapSense_SelfTest.h"
#endif

#include "cyapicallbacks.h"

#if (CapSense_ENABLE == CapSense_CSX_EN)

/*******************************************************************************
* Function constants
*******************************************************************************/

#define  CapSense_NUM_HALF_CYCLES                       (2u)


/*******************************************************************************
* Defines module variables
*******************************************************************************/

/* Local variable used to store the Scan period */
volatile uint16 CapSense_csxScanPeriod = 0u;
/* Local variable used to return raw count from the post scan ISR */
volatile uint16 CapSense_csxRawCount = 0u;

#if(CapSense_ENABLE != CapSense_CSDV2)
    volatile uint32 CapSense_csxRawGarbage = 0u;
#endif /* (CapSense_ENABLE != CapSense_CSDV2) */

/* Pointer to Flash structure to hold Tx electrode that was connected previously */
static CapSense_FLASH_IO_STRUCT const *CapSense_curTxIOPtr;
/* Pointer to Flash structure to hold Rx electrode that was connected previously */
static CapSense_FLASH_IO_STRUCT const *CapSense_curRxIOPtr;
/* Local variable to hold total Tx in widget, while scanning all the sensors in widget */
static uint16 CapSense_curWdgtTotalRx = 0u;
/* Local variable to hold total Rx in widget, while scanning all the sensors in widget */
static uint16 CapSense_curWdgtTotalTx = 0u;
/* Flag to indicate that electrodes were connected previously */
static uint16 CapSense_eleCsxDisconnectFlag = 0u;
/* Pointer to Flash structure holding info of sensor to be scanned */
#if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
    static CapSense_FLASH_SNS_STRUCT const *CapSense_curGangRxPtr = 0u;
    static CapSense_FLASH_SNS_STRUCT const *CapSense_curGangTxPtr = 0u;
#endif

/*******************************************************************************
* Module local function declarations
*******************************************************************************/
/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

static void CapSense_SsCSXStartSample(void);
static void CapSense_SsCSXPostMultiScan(void);
static void CapSense_SsCSXPostSingleScan(void);
static uint16 CapSense_SsCalcCsxScanPeriod(CapSense_RAM_WD_BASE_STRUCT const *wdgtPtr);

#if(CapSense_ENABLE == CapSense_CSDV2)
    CY_INLINE static void CapSense_SsCSXStartSampleExt(void);
#endif

#if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
    static uint32 CapSense_SsCSXOversample(void);
#endif

#if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
    static void CapSense_SsCSXPostMultiScanGanged(void);
#endif

#if (CapSense_CSX_IDAC_AUTOCAL_EN == CapSense_ENABLE)
    static cystatus CapSense_SsCSXCalibrateCheck(uint32 widgetId, uint32 scanPeriod, uint32 target);
#endif

/* Pointer to Pointer to function used to register callback in ISR */
void (*CapSense_CSXPostScanApiPtr)(void) = &CapSense_SsCSXPostMultiScan;
/** \}
* \endcond */

/*******************************************************************************
* Function Name: CapSense_CSXInitialize
****************************************************************************//**
*
* \brief
*   Performs hardware and firmware initialization required for the CSX operation
*   of the CapSense Component.
*
* \details
*   This function initializes hardware to perform the CSX sensing operation. This
*   function is called by the CapSense_Start() API during the Component
*   initialization. If both CSX and CSD sensing methods are used in the Component,
*   this function is called by the CapSense_SetupWidget() API to change hardware
*   configured for CSD to re-initialize for the CSX sensing.
*
*   If the CSD and CSX widgets are used in the Component, it is recommended not to
*   mix the CSD widgets between the CSX widgets, instead, place all CSX widgets in
*   the required scanning order and then place the CSD widgets in the customizer.
*   For the Component API, this action will eliminate the need for changing the hardware
*   configuration for every widget scan and will increase the execution speed
*   in the CapSense_ScanAllWidgets() when the API is called.
*
*   Similarly, it is recommended to set up and scan all the CSX widgets in such
*   a sequence that the CapSense_SetupWidget() API  shouldn't need
*   hardware  sensing-configuration change.
*
*   It is highly not recommended to call this API directly from the application layer.
*
*******************************************************************************/
void CapSense_CSXInitialize(void)
{
    #if(CapSense_ENABLE == CapSense_CSDV2)
        uint8  interruptState;
        uint32 tmpRegVal;

        /* Set all the sensors to inactive state */
        if(CapSense_dsRam.scanCurrentISC != CapSense_dsRam.scanCsxISC)
        {
            CapSense_SsSetAllIOsState((uint32)CapSense_dsRam.scanCsxISC);
            CapSense_dsRam.scanCurrentISC = CapSense_dsRam.scanCsxISC;
        }

        CY_SET_REG32(CapSense_INTR_PTR,             CapSense_DEFAULT_CSD_INTR_CFG);
        CY_SET_REG32(CapSense_INTR_SET_PTR,         CapSense_DEFAULT_CSD_INTR_SET_CFG);
        CY_SET_REG32(CapSense_INTR_MASK_PTR,        CapSense_DEFAULT_CSD_INTR_MASK_CFG);
        CY_SET_REG32(CapSense_HSCMP_PTR,            CapSense_DEFAULT_CSD_HSCMP_CFG);
        CY_SET_REG32(CapSense_AMBUF_PTR,            CapSense_DEFAULT_CSD_AMBUF_CFG);
        CY_SET_REG32(CapSense_REFGEN_PTR,           CapSense_DEFAULT_CSD_REFGEN_CFG);
        CY_SET_REG32(CapSense_CSDCMP_PTR,           CapSense_DEFAULT_CSD_CSDCMP_CFG);
        CY_SET_REG32(CapSense_CSD_IDACA_PTR,         CapSense_DEFAULT_CSD_IDACA_CFG);

        #if((0u != CapSense_ADC_EN) || (0u != CapSense_CSD_IDAC_COMP_EN))
            CY_SET_REG32(CapSense_CSD_IDACB_PTR,    CapSense_DEFAULT_CSD_IDACB_CFG);
        #endif /* (0u != CapSense_ADC_EN) || (0u != CapSense_CSD_IDAC_COMP_EN) */

        CY_SET_REG32(CapSense_SW_RES_PTR,           CapSense_DEFAULT_CSD_SW_RES_CFG);
        CY_SET_REG32(CapSense_SENSE_PERIOD_PTR,     CapSense_DEFAULT_CSD_SENSE_PERIOD_CFG);
        CY_SET_REG32(CapSense_SENSE_DUTY_PTR,       CapSense_DEFAULT_CSD_SENSE_DUTY_CFG);
        CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR,      CapSense_DEFAULT_CSD_SW_HS_P_SEL_CFG);
        CY_SET_REG32(CapSense_SW_HS_N_SEL_PTR,      CapSense_DEFAULT_CSD_SW_HS_N_SEL_CFG);
        CY_SET_REG32(CapSense_SW_SHIELD_SEL_PTR,    CapSense_DEFAULT_CSD_SW_SHIELD_SEL_CFG);
        CY_SET_REG32(CapSense_SW_AMUXBUF_SEL_PTR,   CapSense_DEFAULT_CSD_SW_AMUXBUF_SEL_CFG);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(CapSense_SW_BYP_SEL_PTR);
        tmpRegVal &= ~(CapSense_SW_BYP_SEL_SW_BYA_MASK);
        tmpRegVal |= CapSense_DEFAULT_CSD_SW_BYP_SEL_CFG;
        CY_SET_REG32(CapSense_SW_BYP_SEL_PTR,       tmpRegVal);
        CyExitCriticalSection(interruptState);

        CY_SET_REG32(CapSense_SW_CMP_P_SEL_PTR,     CapSense_DEFAULT_CSD_SW_CMP_P_SEL_CFG);
        CY_SET_REG32(CapSense_SW_CMP_N_SEL_PTR,     CapSense_DEFAULT_CSD_SW_CMP_N_SEL_CFG);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(CapSense_SW_REFGEN_SEL_PTR);
        tmpRegVal &= ~CapSense_SW_REFGEN_SEL_SW_MASK;
        tmpRegVal |= CapSense_DEFAULT_CSD_SW_REFGEN_SEL_CFG;
        CY_SET_REG32(CapSense_SW_REFGEN_SEL_PTR,    tmpRegVal);
        CyExitCriticalSection(interruptState);

        CY_SET_REG32(CapSense_SW_FW_MOD_SEL_PTR,    CapSense_DEFAULT_CSD_SW_FW_MOD_SEL_CFG);
        CY_SET_REG32(CapSense_SW_FW_TANK_SEL_PTR,   CapSense_DEFAULT_CSD_SW_FW_TANK_SEL_CFG);
        CY_SET_REG32(CapSense_SW_DSI_SEL_PTR,       CapSense_DEFAULT_CSD_SW_DSI_SEL_CFG);
        CY_SET_REG32(CapSense_SEQ_TIME_PTR,         CapSense_DEFAULT_CSD_SEQ_TIME_CFG);
        CY_SET_REG32(CapSense_SEQ_INIT_CNT_PTR,     CapSense_DEFAULT_CSD_SEQ_INIT_CNT_CFG);
        CY_SET_REG32(CapSense_SEQ_NORM_CNT_PTR,     CapSense_DEFAULT_CSD_SEQ_NORM_CNT_CFG);
        CY_SET_REG32(CapSense_ADC_CTL_PTR,          CapSense_DEFAULT_CSD_ADC_CTL_CFG);
        CY_SET_REG32(CapSense_SEQ_START_PTR,        CapSense_DEFAULT_CSD_SEQ_START_CFG);
        CY_SET_REG32(CapSense_CONFIG_PTR,           CapSense_DEFAULT_CSD_CONFIG_CFG);

        CapSense_DischargeExtCapacitors(CapSense_EXT_CAP_DISCHARGE_TIME);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(CapSense_CintA_PC_PTR);
        tmpRegVal &= (~(CapSense_GPIO_PC_MASK << (CapSense_CintA_SHIFT * CapSense_GPIO_PC_BIT_SIZE)));
        CY_SET_REG32(CapSense_CintA_PC_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(CapSense_CintB_PC_PTR);
        tmpRegVal &= (~(CapSense_GPIO_PC_MASK << (CapSense_CintB__SHIFT * CapSense_GPIO_PC_BIT_SIZE)));
        CY_SET_REG32(CapSense_CintB_PC_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        /* Connect CintA_tank pin to AMUXBUS-A using HSIOM registers. */
        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(CapSense_CintA_HSIOM_PTR);
        tmpRegVal &= ~CapSense_CintA_HSIOM_MASK;
        tmpRegVal |= (CapSense_HSIOM_SEL_AMUXA << CapSense_CintA_HSIOM_SHIFT);
        CY_SET_REG32(CapSense_CintA_HSIOM_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        /* Connect CintB to AMUXBUS-A using HSIOM registers. */
        interruptState = CyEnterCriticalSection();
        tmpRegVal = CY_GET_REG32(CapSense_CintB_HSIOM_PTR);
        tmpRegVal &= ~CapSense_CintB_HSIOM_MASK;
        tmpRegVal |= (CapSense_HSIOM_SEL_AMUXA << CapSense_CintB_HSIOM_SHIFT);
        CY_SET_REG32(CapSense_CintB_HSIOM_PTR, tmpRegVal);
        CyExitCriticalSection(interruptState);

        CapSense_SsSetModClkClockDivider((uint32)CapSense_dsRam.modCsxClk);

        #if (CapSense_ENABLE == CapSense_CSX_COMMON_TX_CLK_EN)
            CapSense_SsSetSnsClockDivider((uint32)CapSense_dsRam.snsCsxClk);
        #endif

    #else
        uint32 trimValue;

        /* Set all the sensors to inactive state */
        if(CapSense_dsRam.scanCurrentISC != CapSense_dsRam.scanCsxISC)
        {
            CapSense_SsSetAllIOsState((uint32)CapSense_dsRam.scanCsxISC);
            CapSense_dsRam.scanCurrentISC = CapSense_dsRam.scanCsxISC;
        }

        #if(CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            trimValue = CY_GET_REG32(CapSense_IDAC_PTR);
            trimValue &= ~(CapSense_IDAC_COMP_CFG_MASK | CapSense_IDAC_FEEDBACK_MODE_MASK);
            CY_SET_REG32(CapSense_IDAC_PTR, trimValue);
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

        /* Connect CintB to AMUXBUS-A using HSIOM registers. */
        CapSense_WriteBitsSafe(CapSense_CintB_HSIOM_PTR, CapSense_CintB_HSIOM_MASK,
                    (uint32)(CapSense_HSIOM_SEL_AMUXA << CapSense_CintB_HSIOM_SHIFT));
        CapSense_WriteBitsSafe(CapSense_CintB_PC_PTR,
                    (uint32)(CapSense_GPIO_PC_MASK << (CapSense_CintB__SHIFT * CapSense_GPIO_PC_BIT_SIZE )), 0u);
        CapSense_WriteBitsSafe(CapSense_CintB_DR_PTR, (uint32)(0x01uL << CapSense_CintB__SHIFT), 0u);

        /* Connect CintA_tank pin to AMUXBUS-A using HSIOM registers. */
        CapSense_WriteBitsSafe(CapSense_CintA_HSIOM_PTR, CapSense_CintA_HSIOM_MASK,
                    (uint32)(CapSense_HSIOM_SEL_AMUXA << CapSense_CintA_HSIOM_SHIFT));
        CapSense_WriteBitsSafe(CapSense_CintA_PC_PTR,
                    (uint32)(CapSense_GPIO_PC_MASK << (CapSense_CintA_SHIFT * CapSense_GPIO_PC_BIT_SIZE )), 0u);
        CapSense_WriteBitsSafe(CapSense_CintA_DR_PTR, (uint32)(0x01uL << CapSense_CintA_SHIFT), 0u);

        /* Connect CSD comparator to CintB via AMUXBUS-A */
        trimValue = CY_GET_REG32(CapSense_CONFIG_PTR);
        trimValue |= CapSense_CONFIG_SENSE_INSEL_MASK;
        CY_SET_REG32(CapSense_CONFIG_PTR, trimValue);

        /* If common clocks are enabled for Component, set clock
            divider for sensor and modulator clocks and start/restart them */
        #if (CapSense_CSX_COMMON_TX_CLK_EN == CapSense_ENABLE)
            CapSense_SsSetClockDividers((uint32)CapSense_dsRam.snsCsxClk, (uint32)CapSense_dsRam.modCsxClk);
        #endif
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */

    /* Enable CapSense ISR and set ISR for CSX sensing */
    CapSense_SsIsrInitialize(&CapSense_CSXScanISR);
}


/*******************************************************************************
* Function Name: CapSense_CSXElectrodeCheck
****************************************************************************//**
*
* \brief
*   Check if electrodes were previously connected using
*   the CapSense_CSXSetupWidgetExt() API and if yes, disconnect them.
*
* \details
*   This function checks if CapSense_eleCsxDisconnectFlag is set.
*   If it is set, the function disconnects the previously connected electrode.
*
*******************************************************************************/
void CapSense_CSXElectrodeCheck(void)
{
    #if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
        uint32 numElectrodes;
    #endif /* (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN) */

    if (0u != CapSense_eleCsxDisconnectFlag)
    {
       /* Disconnect if electrodes were previous connected by SetupWidgetExt() API */
        #if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
            /* Check ganged sns flag */
            if (CapSense_GANGED_SNS_MASK == (CapSense_curFlashWdgtPtr->staticConfig & CapSense_GANGED_SNS_MASK))
            {
                /* 1. Get number of pins in previous connected Tx electrode
                    3. Get Tx pointer
                    4. Disconnect all Tx */
                numElectrodes = CapSense_curGangTxPtr->numPins;
                CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];

                do
                {
                    CapSense_CSXDisconnectTx(CapSense_curTxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /* 1. Get number of pins in previous connected Rx electrode
                    3. Get Rx pointer
                    4. Disconnect all Rx */
                numElectrodes = CapSense_curGangRxPtr->numPins;
                CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];

                do
                {
                    CapSense_CSXDisconnectRx(CapSense_curRxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);
            }
            else
            {
                /* Disconnect if electrodes were previous connected by SetupWidgetExt API */
                CapSense_CSXDisconnectTx(CapSense_curTxIOPtr);
                CapSense_CSXDisconnectRx(CapSense_curRxIOPtr);
            }
        #else
            /* Disconnect if electrodes were previous connected by SetupWidgetExt API */
            CapSense_CSXDisconnectTx(CapSense_curTxIOPtr);
            CapSense_CSXDisconnectRx(CapSense_curRxIOPtr);
        #endif
        CapSense_eleCsxDisconnectFlag = 0u;
    }
}


/*******************************************************************************
* Function Name: CapSense_CSXSetupWidget
****************************************************************************//**
*
* \brief
*  Performs hardware and firmware initialization required for scanning sensors
*  in a specific widget using the CSX sensing method. This function requires
*  using the CapSense_CSXScan() function to start scanning.
*
* \details
*  Performs hardware and firmware initialization required for scanning sensors
*  in a specific widget using the CSX sensing method. This function requires
*  using the CapSense_CSXScan() function to start scanning.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_SetupWidget() function should be used instead.
*
*  This function initializes the widgets specific common parameters to perform
*  the CSX scanning. The initialization includes the following:
*    1. The CSD_CONFIG register.
*    2. The IDAC register.
*    3. The Sense clock frequency
*    4. The phase alignment of the sense and modulator clocks.
*
*  This function does not connect any specific sensors to the scanning hardware
*  and neither does it start a scanning process. The CapSense_CSXScan()
*  function must be called after initializing the widget to start scanning.
*
*  This function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status.
*
*  This function is called by the CapSense_SetupWidget() API if the
*  given widget uses the CSX sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
* \param widgetId
*  Specifies the ID number of the widget to perform hardware and firmware
*  initialization required for scanning sensors in the specific widget.
*  A macro for the widget ID can be found in the CapSense Configuration header
*  file defined as CapSense_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void CapSense_CSXSetupWidget(uint32 widgetId)
{
    /* variable to access widget details */
    CapSense_RAM_WD_BASE_STRUCT * curRamWdgtBasePtr;

    #if (CapSense_ENABLE == CapSense_CSDV2)
        uint32 tmpRegVal;
        uint32 snsClkVal;
    #endif /* (CapSense_DISABLE == CapSense_CSDV2) */

    /* Save the current widget Id */
    CapSense_widgetIndex = (uint8)widgetId;

    CapSense_SsSwitchSensingMode(CapSense_SENSE_METHOD_CSX_E);

    /*
    *  Check if CSX electrodes were previously connected using
    *  CapSense_CSXSetupWidgetExt API and if yes, disconnect them
    */
    CapSense_CSXElectrodeCheck();

    /* Configure hardware block */
    #if (CapSense_ENABLE == CapSense_CSDV2)
        CapSense_curFlashWdgtPtr = &CapSense_dsFlash.wdgtArray[widgetId];

        curRamWdgtBasePtr = (CapSense_RAM_WD_BASE_STRUCT *)CapSense_curFlashWdgtPtr->ptr2WdgtRam;

        #if (CapSense_ENABLE == CapSense_CSX_COMMON_TX_CLK_EN)
            snsClkVal = (uint32)CapSense_dsRam.snsCsxClk;
        #else
            snsClkVal = (uint32)curRamWdgtBasePtr->snsClk;
        #endif /* (CapSense_ENABLE == CapSense_CSX_COMMON_TX_CLK_EN) */

        CY_SET_REG32(CapSense_SEQ_NORM_CNT_PTR, (uint32)curRamWdgtBasePtr->resolution);
        CapSense_csxScanPeriod  = CapSense_SsCalcCsxScanPeriod(curRamWdgtBasePtr);

        tmpRegVal = (uint32)curRamWdgtBasePtr->snsClkSource;

        snsClkVal = (snsClkVal - 1uL) & CapSense_SENSE_PERIOD_SENSE_DIV_MASK;
        tmpRegVal = (tmpRegVal << CapSense_SENSE_PERIOD_LFSR_SIZE_SHIFT) | snsClkVal;
        CY_SET_REG32(CapSense_SENSE_PERIOD_PTR, tmpRegVal);
        CapSense_SsSetModClkClockDivider((uint32)CapSense_dsRam.modCsxClk);
    #else
        /*
        * initialize access pointers for current:
        *    1. Pointer to widget configuration in Flash
        *    2. Widget configuration in RAM
        *    3. Make a local copy of widget index
        */
        CapSense_curFlashWdgtPtr = &CapSense_dsFlash.wdgtArray[widgetId];
        curRamWdgtBasePtr = (CapSense_RAM_WD_BASE_STRUCT *)CapSense_curFlashWdgtPtr->ptr2WdgtRam;

        CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_CONFIG_ENABLE_MASK);
        CY_SET_REG32(CapSense_CONFIG_PTR, (CY_GET_REG32(CapSense_CONFIG_PTR) |
                                CapSense_CONFIG_MUTUALCAP_EN_MASK     |
                                CapSense_CONFIG_SENSE_COMP_BW_MASK    |
                                CapSense_CONFIG_SENSE_COMP_EN_MASK    |
                                CapSense_CONFIG_SENSE_INSEL_MASK      |
                                CapSense_CONFIG_REFBUF_EN_MASK        |
                                CapSense_CONFIG_REFBUF_DRV_MASK));

        /* If individual clocks are enabled for each widget, set clock
            divider for sensor and modulator clocks and start/restart them. */
        #if (CapSense_CSX_COMMON_TX_CLK_EN == CapSense_DISABLE)
            CapSense_SsSetClockDividers((uint32)curRamWdgtBasePtr->snsClk, (uint32)CapSense_dsRam.modCsxClk);
        #endif

        /* Find scan period */
        CapSense_csxScanPeriod = CapSense_SsCalcCsxScanPeriod(curRamWdgtBasePtr);
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}

/*******************************************************************************
* Function Name: CapSense_CSXSetupWidgetExt
****************************************************************************//**
*
* \brief
*  Performs extended initialization for the CSX widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the CapSense_CSXScan() function to initiate a scan.
*
* \details
*  Performs extended initialization for the CSX widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the CapSense_CSXScan() function to initiate a scan.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_SetupWidgetExt() function should be used instead.
*
*  This function does the same tasks as CapSense_CSXSetupWidget() and
*  also connects a sensor in the widget for scanning. Once this function is
*  called to initialize a widget and a sensor, the CapSense_CSXScanExt()
*  function must be called to scan the sensor.
*
*  This function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
* \param widgetId
*  Specifies the ID number of the widget to perform hardware and firmware
*  initialization required for scanning a specific sensor in a specific widget.
*  A macro for the widget ID can be found in the CapSense
*  Configuration header file defined as CapSense_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to perform hardware
*  and firmware initialization required for scanning a specific sensor in a
*  specific widget.
*  A macro for the sensor ID within a specified widget can be found in the
*  CapSense Configuration header file defined as
*  CapSense_<WidgetName>_SNS<SensorNumber>_ID.
*
*******************************************************************************/

void CapSense_CSXSetupWidgetExt(uint32 widgetId, uint32 sensorId)
{
    uint32 txIndex;
    uint32 rxIndex;

    #if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
        uint16 numElectrodes;
    #endif /* (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN) */

    /* Initialize widget */
    CapSense_CSXSetupWidget(widgetId);
    CapSense_sensorIndex = (uint8)sensorId;

    /* initialize sensor data structure pointer to appropriate address */
    CapSense_curRamSnsPtr = CapSense_curFlashWdgtPtr->ptr2SnsRam;
    CapSense_curRamSnsPtr = &CapSense_curRamSnsPtr[sensorId];

    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        if (0u != CapSense_curRamSnsPtr->subConvNum)
        {
    #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

    /*
    *  Find Tx and Rx index for given snsIndex
    *    rxIndex = sensorId / TxCount
    *    txIndex = sensorId % TxCount
    */
    rxIndex = sensorId /CapSense_curFlashWdgtPtr->numRows;
    txIndex = sensorId % CapSense_curFlashWdgtPtr->numRows;

    /* If widget is APA, find node (Tx/Rx) to be connected for scanning */
    #if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
        if (CapSense_GANGED_SNS_MASK == (CapSense_curFlashWdgtPtr->staticConfig & CapSense_GANGED_SNS_MASK))
        {
            /*
            *  1. Get access to Rx sensor pointer (Rx = Base + rxIndex).
            *  2. Get number of Rx electrodes
            *  3. Get Rx pointer
            *  4. Connect all Rx
            */
            CapSense_curGangRxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
            CapSense_curGangRxPtr += rxIndex;
            numElectrodes = CapSense_curGangRxPtr->numPins;
            CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];

            do
            {
                CapSense_CSXConnectRx(CapSense_curRxIOPtr++);
                numElectrodes--;
            } while (0u != numElectrodes);

            /*
            *  1. Get access to Tx sensor pointer (Tx = Base + NumberRx + TxIndex).
            *  2. Get number of Tx electrodes
            *  3. Get Tx pointer
            *  4. Connect all Tx
            */
            CapSense_curGangTxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
            CapSense_curGangTxPtr += (CapSense_curFlashWdgtPtr->numCols + txIndex);

            numElectrodes = CapSense_curGangTxPtr->numPins;
            CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];

            do
            {
                CapSense_CSXConnectTx(CapSense_curTxIOPtr++);
                numElectrodes--;
            }while (0u != numElectrodes);

            /* Set callback to scan connected ganged sensor only */
            CapSense_CSXPostScanApiPtr = &CapSense_SsCSXPostSingleScan;
        }
        else
    #endif  /* (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN) */
        {
            /*
            *  If no ganged sensor in Component OR current widget no contains ganged sns, then:
            *    1. Find Rx pointer: Rx = Base address + RxIndex
            *    2. Find Tx pointer: Tx = Base address + (total Rx + TxIndex)
            */
            CapSense_curRxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
            CapSense_curRxIOPtr = &CapSense_curRxIOPtr[rxIndex];

            CapSense_curTxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
            CapSense_curTxIOPtr = &CapSense_curTxIOPtr[(CapSense_curFlashWdgtPtr->numCols + txIndex)];

            /* Connect Tx and Rx IOs for scan ad set flag to indicate that IOs should be disconnected */
            CapSense_CSXConnectTx(CapSense_curTxIOPtr);
            CapSense_CSXConnectRx(CapSense_curRxIOPtr);
            CapSense_eleCsxDisconnectFlag = CapSense_DISCONNECT_IO_FLAG;

            /* Set callback to scan all the sensors in widget */
            CapSense_CSXPostScanApiPtr = &CapSense_SsCSXPostSingleScan;
        }
    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        }
    #endif
}

/*******************************************************************************
* Function Name: CapSense_CSXScan
****************************************************************************//**
*
* \brief
*  This function initiates a scan for the sensors of the widget initialized by
*  the CapSense_CSXSetupWidget() function.
*
* \details
*  This function initiates a scan for the sensors of the widget initialized by
*  the CapSense_CSXSetupWidget() function.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_Scan() function should be used instead.
*
*  This function performs scanning of all the sensors in the widget configured by
*  the CapSense_CSXSetupWidget() function. It does the following tasks:
*    1. Connects the first sensor of the widget.
*    2. Initializes an interrupt callback function to initialize a scan of the
*       next sensors in a widget.
*    3. Starts scanning for the first sensor in the widget.
*
*  This function is called by the CapSense_Scan() API if the given
*  widget uses the CSX sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
*  This function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status. The widget must be
*  preconfigured by the CapSense_CSXSetupWidget() function if any other
*  widget was previously scanned or any other type of scan functions were used.
*
*******************************************************************************/

void CapSense_CSXScan(void)
{
    #if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
        uint32 numElectrodes;
    #endif
    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        uint32 snsIndex = 0u;
        uint32 snsNum;
    #endif

    /* Set all the sensors to inactive state */
    if(CapSense_dsRam.scanCurrentISC != CapSense_dsRam.scanCsxISC)
    {
        CapSense_SsSetAllIOsState((uint32)CapSense_dsRam.scanCsxISC);
        CapSense_dsRam.scanCurrentISC = CapSense_dsRam.scanCsxISC;
    }

    CapSense_sensorIndex = 0u;

    /* initialize pointer to access sensor RAM elements */
    CapSense_curRamSnsPtr = CapSense_curFlashWdgtPtr->ptr2SnsRam;

    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Loop through the sensors until non-skipped is found */
        snsNum = CapSense_curFlashWdgtPtr->totalNumSns;
        while ((snsIndex < snsNum) && (CapSense_curRamSnsPtr->subConvNum == 0u))
        {
            /* Increment sensor pointers */
            CapSense_curRamSnsPtr++;
            CapSense_sensorIndex++;
            snsIndex++;
        }
        /*
        *  Calculate total sensor to be scanned. If buttons, one Tx and an Rx for each sensor
        *  if Matrix button or Touchpad, M x N rule applies
        */
        CapSense_curWdgtTotalTx = (uint16)(CapSense_curFlashWdgtPtr->numRows - (snsIndex % CapSense_curFlashWdgtPtr->numRows));
        CapSense_curWdgtTotalRx  = (uint16)(CapSense_curFlashWdgtPtr->numCols - (snsIndex / CapSense_curFlashWdgtPtr->numRows));

        /* Scan sensor if it's index within a valid range otherwise do nothing as all the sensors are skipped */
        if (snsIndex < snsNum)
        {
            #if (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN)
                if ((CapSense_curFlashWdgtPtr->staticConfig & CapSense_GANGED_SNS_MASK) != 0u)
                {
                    /* Connect all Rx electrodes */
                    CapSense_curGangRxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                    CapSense_curGangRxPtr += snsIndex /CapSense_curFlashWdgtPtr->numRows;
                    numElectrodes = CapSense_curGangRxPtr->numPins;
                    CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                    do
                    {
                        CapSense_CSXConnectRx(CapSense_curRxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);

                    /* Connect all Tx electrodes */
                    CapSense_curGangTxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                    CapSense_curGangTxPtr += (CapSense_curFlashWdgtPtr->numCols + snsIndex % CapSense_curFlashWdgtPtr->numRows);
                    numElectrodes = CapSense_curGangTxPtr->numPins;
                    CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];
                    do
                    {
                        CapSense_CSXConnectTx(CapSense_curTxIOPtr++);
                        numElectrodes--;
                    }while (0u != numElectrodes);
                    /* Assign callback to ISR */
                    CapSense_CSXPostScanApiPtr = &CapSense_SsCSXPostMultiScanGanged;
                }
                else
            #endif /* (CapSense_ENABLE == CapSense_CSX_GANGED_SNS_EN) */
            {
                /* Find Rx pointer: Rx = Base_address + SnsIndex / total_Tx */
                CapSense_curRxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                CapSense_curRxIOPtr += (snsIndex / CapSense_curFlashWdgtPtr->numRows);
                /* Find Tx pointer: Tx = Base_address + total_Rx + SnsIndex % total_Tx */
                CapSense_curTxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                CapSense_curTxIOPtr += CapSense_curFlashWdgtPtr->numCols;
                CapSense_curTxIOPtr += (snsIndex % CapSense_curFlashWdgtPtr->numRows);
                /* Connect Tx and Rx electrodes for scan */
                CapSense_CSXConnectTx(CapSense_curTxIOPtr);
                CapSense_CSXConnectRx(CapSense_curRxIOPtr);
                /* Set callback to scan all the sensors in widget */
                CapSense_CSXPostScanApiPtr = &CapSense_SsCSXPostMultiScan;
            }

            /* Reset multi-frequency scan channel if enabled */
            #if (CapSense_MULTI_FREQ_SCAN_EN == CapSense_ENABLE)
                CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;
            #endif

            /* Set scan status, enter critical section and initiate scan */
            CapSense_dsRam.status |= CapSense_SW_STS_BUSY;

            #if(CapSense_ENABLE == CapSense_CSDV2) &&\
               (CapSense_ENABLE != CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
               (CapSense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
                CyDelayUs(CapSense_CSX_ANALOG_STARTUP_DELAY_US);
            #endif

            CapSense_SsCSXStartSample();
        }

    #else /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

        /*
        *  Calculate total sensor to be scanned. If buttons, one Tx and an Rx for each sensor
        *  if Matrix button or Touchpad, M x N rule applies
        */
        CapSense_curWdgtTotalTx = CapSense_curFlashWdgtPtr->numRows;
        CapSense_curWdgtTotalRx  = CapSense_curFlashWdgtPtr->numCols;

        /* If Component contains CSX ganged sensor, then check if widget contains ganged sensor */
        #if (CapSense_CSX_GANGED_SNS_EN == 1u)
            if ((CapSense_curFlashWdgtPtr->staticConfig & CapSense_GANGED_SNS_MASK) != 0u)
            {
                /*
                *  1. Get sns pointer for first Rx
                *  2. Get number of Rx pin
                *  3. Get pointer to the Rx pin
                *  4. Connect all Rx pins
                */
                CapSense_curGangRxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                numElectrodes = CapSense_curGangRxPtr->numPins ;
                CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                do
                {
                    CapSense_CSXConnectRx(CapSense_curRxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /*
                *  1. Get sns pointer for first Tx (Tx = Base + number of Rx).
                *  2. Get number of Tx electrodes
                *  3. Get pointer the Tx electrode
                *  4. Connect all Tx
                */
                CapSense_curGangTxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                CapSense_curGangTxPtr += CapSense_curFlashWdgtPtr->numCols;
                numElectrodes = CapSense_curGangTxPtr->numPins ;
                CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];

                do
                {
                    CapSense_CSXConnectTx(CapSense_curTxIOPtr++);
                    numElectrodes--;
                }while (0u != numElectrodes);

                /* Assign callback to ISR */
                CapSense_CSXPostScanApiPtr = &CapSense_SsCSXPostMultiScanGanged;

            }
            else
        #endif
            {
                /*
                *  If no ganged sensor in the Component OR current widget contains no ganged sns, then:
                *    1. Find Rx pointer: Rx = Base address.
                *    2. Find Tx pointer: Tx = Base address + total Rx
                */
                CapSense_curRxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                CapSense_curTxIOPtr = CapSense_curRxIOPtr;
                CapSense_curTxIOPtr = &CapSense_curTxIOPtr[(CapSense_curFlashWdgtPtr->numCols)];

                /* Connect first Tx and first Rx IOs for scan */
                CapSense_CSXConnectTx(CapSense_curTxIOPtr);
                CapSense_CSXConnectRx(CapSense_curRxIOPtr);

                /* Set callback to scan all the sensors in widget */
                CapSense_CSXPostScanApiPtr = &CapSense_SsCSXPostMultiScan;
            }

            /* Reset multi-frequency scan channel if enabled */
            #if (CapSense_MULTI_FREQ_SCAN_EN == CapSense_ENABLE)
                CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;
            #endif

        /* Set scan status, enter critical section and initiate scan */
        CapSense_dsRam.status |= CapSense_SW_STS_BUSY;

        #if(CapSense_ENABLE == CapSense_CSDV2) &&\
           (CapSense_ENABLE != CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
           (CapSense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
            CyDelayUs(CapSense_CSX_ANALOG_STARTUP_DELAY_US);
        #endif

        CapSense_SsCSXStartSample();

    #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
}

/*******************************************************************************
* Function Name: CapSense_CSXScanExt()
****************************************************************************//**
*
* \brief
*  Starts the CSX conversion on the preconfigured sensor. This function requires
*  using the CapSense_CSXSetupWidgetExt() function to set up a
*  widget.
*
* \details
*  Starts the CSX conversion on the preconfigured sensor. This function requires
*  using the CapSense_CSXSetupWidgetExt() function to set up a
*  widget.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_ScanExt() function should be used instead.
*
*  This function performs single scanning of one sensor in the widget configured
*  by the CapSense_CSXSetupWidgetExt() function. It does the following
*  tasks:
*    1. Sets a busy flag in the CapSense_dsRam structure.
*    2. Configures the Tx clock frequency.
*    3. Configures the Modulator clock frequency.
*    4. Configures the IDAC value.
*    5. Starts single scanning.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example). This
*  function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status.
*
*  The sensor must be preconfigured by using the
*  CapSense_CSXSetupWidgetExt() API prior to calling this function.
*  The sensor remains ready for the next scan if a previous scan was triggered
*  by using the CapSense_CSXScanExt() function. In this case, calling
*  CapSense_CSXSetupWidgetExt() is not required every time before the
*  CapSense_CSXScanExt() function. If a previous scan was triggered in
*  any other way - CapSense_Scan(), CapSense_ScanAllWidgets()
*  or CapSense_RunTuner() - (see the CapSense_RunTuner() function
*  description for more details), the sensor must be preconfigured again by
*  using the CapSense_CSXSetupWidgetExt() API prior to calling the
*  CapSense_CSXScanExt() function.
*
*  If disconnection of the sensors is required after calling
*  CapSense_CSXScanExt(), the CapSense_CSXDisconnectTx() and
*  CapSense_CSXDisconnectRx() APIs can be used.
*
*******************************************************************************/

void CapSense_CSXScanExt(void)
{
    /* Reset multi-frequency scan channel if enabled */
    #if (CapSense_MULTI_FREQ_SCAN_EN == CapSense_ENABLE)
        CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;
    #endif

    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        if (0u != CapSense_curRamSnsPtr->subConvNum)
        {
            /* Set busy flag and start conversion */
            CapSense_dsRam.status |= CapSense_SW_STS_BUSY;

            #if(CapSense_ENABLE == CapSense_CSDV2) &&\
               (CapSense_ENABLE != CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
               (CapSense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
                        CyDelayUs(CapSense_CSX_ANALOG_STARTUP_DELAY_US);
            #endif
            CapSense_SsCSXStartSample();
        }
    #else
        /* Set busy flag and start conversion */
        CapSense_dsRam.status |= CapSense_SW_STS_BUSY;

        #if(CapSense_ENABLE == CapSense_CSDV2) &&\
           (CapSense_ENABLE != CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
           (CapSense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
            CyDelayUs(CapSense_CSX_ANALOG_STARTUP_DELAY_US);
        #endif
        CapSense_SsCSXStartSample();
    #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
}


/*******************************************************************************
* Function Name: CapSense_SsCSXPostMultiScan
****************************************************************************//**
*
* \brief
*   ISR function implements the multiple-sensor scanning for un-ganged CSX widgets.
*   This function is called by the Component ISR only, it should not be used by
*   the application layer.
*
*******************************************************************************/

static void CapSense_SsCSXPostMultiScan(void)
{
    #ifdef CapSense_ENTRY_CALLBACK
        CapSense_EntryCallback();
    #endif /* CapSense_ENTRY_CALLBACK */

    /* Copy scan result into sensor raw count array */
    CapSense_curRamSnsPtr->raw[CapSense_scanFreqIndex] = \
                             (CapSense_csxScanPeriod - CapSense_csxRawCount);

    #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
        /* Increment multi frequency scan index if all channels are not scanned */
        if (CapSense_FREQ_CHANNEL_2 > CapSense_scanFreqIndex)
        {
            /* Change multi-frequency channel and start sample */
            CapSense_scanFreqIndex++;

            #if (CapSense_MFS_IMO == CapSense_MFS_METHOD)
                CapSense_SsChangeImoFreq((uint32)CapSense_scanFreqIndex);
            #else
                CapSense_SsChangeClkFreq((uint32)CapSense_scanFreqIndex);
            #endif /* (CapSense_MFS_IMO == CapSense_MFS_METHOD) */

            CapSense_SsCSXStartSample();
        }
        else
    #endif
        {
            #if (CapSense_MULTI_FREQ_SCAN_EN == CapSense_ENABLE)
                /* All channels are scanned. Reset the multi frequency scan channel */
                CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;

                #if (CapSense_MFS_IMO == CapSense_MFS_METHOD)
                    CapSense_SsChangeImoFreq(CapSense_FREQ_CHANNEL_0);
                #else
                    CapSense_SsChangeClkFreq(CapSense_FREQ_CHANNEL_0);
                #endif /* (CapSense_MFS_IMO == CapSense_MFS_METHOD) */

            #endif

            #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
                /* Disconnect Tx/Rx electrodes of previously scanned sensor as preparation for next sensor scan */
                CapSense_CSXDisconnectTx(CapSense_curTxIOPtr);
                CapSense_CSXDisconnectRx(CapSense_curRxIOPtr);

                /* Increment sensor until non-skipped is found */
                do
                {
                    /* Increment sensor index to configure next sensor in widget */
                    CapSense_sensorIndex++;

                    /* Increment sensor pointers */
                    CapSense_curRamSnsPtr++;
                    CapSense_curWdgtTotalTx--;
                    if (CapSense_curWdgtTotalTx > 0u)
                    {
                        CapSense_curTxIOPtr++;
                    }
                    else
                    {
                        CapSense_curWdgtTotalRx--;
                        if (CapSense_curWdgtTotalRx > 0u)
                        {
                            CapSense_curRxIOPtr++;
                            CapSense_curWdgtTotalTx  = CapSense_curFlashWdgtPtr->numRows;
                            CapSense_curTxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                            CapSense_curTxIOPtr = & CapSense_curTxIOPtr[(CapSense_curFlashWdgtPtr->numCols)];
                        }
                    }
                } while ((CapSense_curWdgtTotalRx != 0u) && (CapSense_curRamSnsPtr->subConvNum == 0u));

                /* Perform the next scan or switch to the next widget */
                if(CapSense_curWdgtTotalRx != 0u)
                {
                    /* Connect Tx/Rx electrodes for the next scan */
                    CapSense_CSXConnectTx(CapSense_curTxIOPtr);
                    CapSense_CSXConnectRx(CapSense_curRxIOPtr);
                    /* Reset scan result holder, and initiate scan */
                    CapSense_SsCSXStartSample();
                }
                else
                {
                    /* Call scan next widget API if requested, if not, complete scan */
                    if (CapSense_requestScanAllWidget != 0u)
                    {
                        CapSense_SsPostAllWidgetsScan();
                    }
                    else
                    {
                        CapSense_dsRam.scanCounter++;
                        CapSense_dsRam.status &= ~CapSense_SW_STS_BUSY;
                    }
                }
            #else /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

                /*
                *  Disconnect Tx electrodes of previously scanned sensor as
                *  preparation for next sensor scan
                */
                CapSense_CSXDisconnectTx (CapSense_curTxIOPtr);

                /* Increment sensor index to configure next sensor in widget */
                CapSense_sensorIndex++;

                /*
                *  Initiate scan for next sensor in widget, if all the sensors in
                *  widget are not scanned
                */
                CapSense_curWdgtTotalTx--;
                if (CapSense_curWdgtTotalTx > 0u)
                {
                    /*
                    *  1. Increment pointer to next Tx
                    *  2. Connect next Rx for scan
                    *  3. Increment pointer to sns data
                    */
                    CapSense_curTxIOPtr++;
                    CapSense_CSXConnectTx (CapSense_curTxIOPtr);
                    CapSense_curRamSnsPtr++;

                    /* Reset scan result holder, and initiate scan */
                    CapSense_SsCSXStartSample();
                }

                /* Check if all Rx are looped through */
                else
                {
                    CapSense_curWdgtTotalRx--;
                    if (CapSense_curWdgtTotalRx > 0u)
                    {
                        /*
                        *  1. Disconnect current Rx electrode
                        *  2. Connect next Rx electrode
                        *  3. Re-initialize total Tx to be scanned per Rx
                        *  4. Find first Tx electrode again
                        *  5. Connect first Tx electrode
                        */
                        CapSense_CSXDisconnectRx(CapSense_curRxIOPtr);
                        CapSense_curRxIOPtr++;
                        CapSense_CSXConnectRx(CapSense_curRxIOPtr);
                        CapSense_curWdgtTotalTx  = CapSense_curFlashWdgtPtr->numRows;
                        CapSense_curTxIOPtr = (CapSense_FLASH_IO_STRUCT const *)CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                        CapSense_curTxIOPtr = & CapSense_curTxIOPtr[(CapSense_curFlashWdgtPtr->numCols)];
                        CapSense_CSXConnectTx(CapSense_curTxIOPtr);

                        /* Increment RAM sensor pointer pointer */
                        CapSense_curRamSnsPtr++;

                        /* Initiate sample */
                        CapSense_SsCSXStartSample();
                    }
                    else
                    {
                        /* If all the sensors are scanned, disconnect Tx */
                        CapSense_CSXDisconnectRx(CapSense_curRxIOPtr);

                        /* Call scan next widget API if requested, if not, complete scan */
                        if (CapSense_requestScanAllWidget != 0u)
                        {
                            CapSense_SsPostAllWidgetsScan();
                        }
                        else
                        {
                            /*
                            *  All pending scans completed,
                            *    1. update the counter to indicat same
                            *    2. Clear busy state as scanning is completed
                            */
                            CapSense_dsRam.scanCounter++;
                            CapSense_dsRam.status &= ~CapSense_SW_STS_BUSY;
                        }
                    }
                }
            #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
        }

    #ifdef CapSense_EXIT_CALLBACK
        CapSense_ExitCallback();
    #endif /* CapSense_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: CapSense_SsCSXPostMultiScanGanged
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
#if (CapSense_CSX_GANGED_SNS_EN == 1u)

static void CapSense_SsCSXPostMultiScanGanged(void)
{
    uint32 numElectrodes;

    #ifdef CapSense_ENTRY_CALLBACK
        CapSense_EntryCallback();
    #endif /* CapSense_ENTRY_CALLBACK */

    /* Copy scan result into sensor raw count array */
    CapSense_curRamSnsPtr->raw[CapSense_scanFreqIndex] = \
                    (CapSense_csxScanPeriod - CapSense_csxRawCount);

    #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
        /* Increment multi frequency scan index if all channels are not scanned */
        if (CapSense_FREQ_CHANNEL_2 > CapSense_scanFreqIndex)
        {
            /* Change multi-frequency channel and start sample */
            CapSense_scanFreqIndex++;

            #if (CapSense_MFS_IMO == CapSense_MFS_METHOD)
                CapSense_SsChangeImoFreq((uint32)CapSense_scanFreqIndex);
            #else
                CapSense_SsChangeClkFreq((uint32)CapSense_scanFreqIndex);
            #endif /* (CapSense_MFS_IMO == CapSense_MFS_METHOD) */

            CapSense_SsCSXStartSample();
        }
        else
    #endif
        {
            #if (CapSense_MULTI_FREQ_SCAN_EN == CapSense_ENABLE)
                /* All channels are scanned. Reset the multi frequency scan channel */
                CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;

                #if (CapSense_MFS_IMO == CapSense_MFS_METHOD)
                    CapSense_SsChangeImoFreq(CapSense_FREQ_CHANNEL_0);
                #else
                    CapSense_SsChangeClkFreq(CapSense_FREQ_CHANNEL_0);
                #endif /* (CapSense_MFS_IMO == CapSense_MFS_METHOD) */

            #endif

            #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
                /* Disconnect Tx electrodes of previously scanned sensor as preparation for next sensor scan */
                numElectrodes = CapSense_curGangTxPtr->numPins;
                CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];
                do
                {
                    CapSense_CSXDisconnectTx(CapSense_curTxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);
                /* Disconnect Rx electrodes of previously scanned sensor as preparation for next sensor scan */
                numElectrodes = CapSense_curGangRxPtr->numPins;
                CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                do
                {
                    CapSense_CSXDisconnectRx(CapSense_curRxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /* Increment sensor until non-skipped is found */
                do
                {
                    /* Increment sensor index to configure next sensor in widget */
                    CapSense_sensorIndex++;

                    /* Increment RAM sensor pointer */
                    CapSense_curRamSnsPtr++;
                    CapSense_curWdgtTotalTx--;
                    if (CapSense_curWdgtTotalTx > 0u)
                    {
                        CapSense_curGangTxPtr++;
                    }
                    else
                    {
                        /* Check if all Rx are scanned, if not, initiate scan for next Rx */
                        CapSense_curWdgtTotalRx--;
                        if (CapSense_curWdgtTotalRx > 0u)
                        {
                            CapSense_curGangRxPtr++;
                            CapSense_curWdgtTotalTx = CapSense_curFlashWdgtPtr->numRows;
                            CapSense_curGangTxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                            CapSense_curGangTxPtr += CapSense_curFlashWdgtPtr->numCols;
                        }
                    }
                } while ((CapSense_curWdgtTotalRx != 0u) && (CapSense_curRamSnsPtr->subConvNum == 0u));

                if(CapSense_curWdgtTotalRx != 0u)
                {
                    /* Connect Tx electrodes for the next scan */
                    numElectrodes = CapSense_curGangTxPtr->numPins;
                    CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];
                    do
                    {
                        CapSense_CSXConnectTx(CapSense_curTxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);
                    /* Connect Tx electrodes for the next scan */
                    numElectrodes = CapSense_curGangRxPtr->numPins ;
                    CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                    do
                    {
                        CapSense_CSXConnectRx(CapSense_curRxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);
                    /* Reset scan result holder, and initiate scan */
                    CapSense_SsCSXStartSample();
                }
                else
                {
                    /* Call scan next widget API if requested, if not, complete scan */
                    if (CapSense_requestScanAllWidget != 0u)
                    {
                        CapSense_SsPostAllWidgetsScan();
                    }
                    else
                    {
                        CapSense_dsRam.scanCounter++;
                        CapSense_dsRam.status &= ~CapSense_SW_STS_BUSY;
                    }
                }
            #else /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

                /* Disconnect ALL pins of previously scanned Tx */
                numElectrodes = CapSense_curGangTxPtr->numPins ;
                CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];
                do
                {
                    CapSense_CSXDisconnectTx (CapSense_curTxIOPtr++);
                    numElectrodes--;
                } while (0u != numElectrodes);

                /* Increment sensor index to configure next sensor in widget */
                CapSense_sensorIndex++;

                /* Check if all Tx are scanned, if not, initiate scan for next Tx */
                CapSense_curWdgtTotalTx--;
                if (CapSense_curWdgtTotalTx > 0u)
                {
                    /*
                    *  1. Find pointer of next Tx (ganged)
                    *  2. Connect all Tx pins
                    */
                    CapSense_curGangTxPtr++;
                    numElectrodes = CapSense_curGangTxPtr->numPins ;
                    CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];
                    do
                    {
                        CapSense_CSXConnectTx(CapSense_curTxIOPtr++);
                        numElectrodes--;
                    } while (0u != numElectrodes);

                    /* Increment RAM pointer to next sensor */
                    CapSense_curRamSnsPtr++;

                    /* Reset scan result holder and initiate scan */
                    CapSense_SsCSXStartSample();
                }
                else
                {
                    /* Check if all Rx are scanned, if not, initiate scan for next Rx */
                    CapSense_curWdgtTotalRx--;
                    if (CapSense_curWdgtTotalRx > 0u)
                    {
                        /* 1. Disconnect current Rx ALL pins */
                        numElectrodes = CapSense_curGangRxPtr->numPins ;
                        CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                        do
                        {
                            CapSense_CSXDisconnectRx(CapSense_curRxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /* 2. Connect next Rx ALL pins */
                        CapSense_curGangRxPtr++;
                        numElectrodes = CapSense_curGangRxPtr->numPins ;
                        CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                        do
                        {
                            CapSense_CSXConnectRx(CapSense_curRxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /*
                        *  3. Re-initialize total Tx to be scanned per Rx
                        *  4. Find first Tx  again
                        *  5. Connect first Tx ALL pins
                        */
                        CapSense_curWdgtTotalTx = CapSense_curFlashWdgtPtr->numRows;
                        CapSense_curGangTxPtr = CapSense_curFlashWdgtPtr->ptr2SnsFlash;
                        CapSense_curGangTxPtr += CapSense_curFlashWdgtPtr->numCols;

                        /* 6. Connect Tx ALL pins */
                        numElectrodes = CapSense_curGangTxPtr->numPins ;
                        CapSense_curTxIOPtr = &CapSense_ioList[CapSense_curGangTxPtr->firstPinId];
                        do
                        {
                            CapSense_CSXConnectTx(CapSense_curTxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /* Increment RAM pointer to next sensor */
                        CapSense_curRamSnsPtr++;

                        /* Reset scan result holder and initiate scan */
                        CapSense_SsCSXStartSample();
                    }
                    else
                    {
                        /* Disconnect ALL electrodes of previously scanned Rx */
                        numElectrodes = CapSense_curGangRxPtr->numPins ;
                        CapSense_curRxIOPtr = &CapSense_ioList[CapSense_curGangRxPtr->firstPinId];
                        do
                        {
                            CapSense_CSXDisconnectRx(CapSense_curRxIOPtr++);
                            numElectrodes--;
                        } while (0u != numElectrodes);

                        /* Call scan next widget API if requested, if not, complete scan */
                        if (CapSense_requestScanAllWidget != 0u)
                        {
                            CapSense_SsPostAllWidgetsScan();
                        }
                        else
                        {
                            /*
                            *  All pending scans completed,
                            *    1. update the counter to indicate same
                            *    2. Clear busy state as scanning is completed
                            */
                            CapSense_dsRam.scanCounter++;
                            CapSense_dsRam.status &= ~CapSense_SW_STS_BUSY;
                        }
                    }
                }
            #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */
        }

    #ifdef CapSense_EXIT_CALLBACK
        CapSense_ExitCallback();
    #endif /* CapSense_EXIT_CALLBACK */
}

#endif  /* (CapSense_CSX_GANGED_SNS_EN == 1u) */

/*******************************************************************************
* Function Name: CapSense_SsCSXPostSingleScan
****************************************************************************//**
*
* \brief
*   The ISR function for single-sensor scanning implementation.
*
* \details
*   This function is used by CapSense ISR in the CSX scanning mode to implement
*   the single-sensor scanning.
*   This function should not be used by the application layer.
*
*******************************************************************************/

static void CapSense_SsCSXPostSingleScan(void)
{
    #ifdef CapSense_ENTRY_CALLBACK
        CapSense_EntryCallback();
    #endif /* CapSense_ENTRY_CALLBACK */

    /*
    * Copy scan result into sensor raw count array and clear busy flag
    *    No sensor is connected or disconnected in this function
    *    Calling CapSense_ScanExt from application would perform
    *    one more scan of same sensor. Specifically for low-power mode.
    */
    CapSense_curRamSnsPtr->raw[CapSense_scanFreqIndex] =
                        (CapSense_csxScanPeriod - CapSense_csxRawCount);

    #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
        /* Increment multi frequency scan index if all channels are not scanned */
        if (CapSense_FREQ_CHANNEL_2 > CapSense_scanFreqIndex)
        {
            /* Change multi-frequency channel and start sample */
            CapSense_scanFreqIndex++;

            #if (CapSense_MFS_IMO == CapSense_MFS_METHOD)
                CapSense_SsChangeImoFreq((uint32)CapSense_scanFreqIndex);
            #else
                CapSense_SsChangeClkFreq((uint32)CapSense_scanFreqIndex);
            #endif /* (CapSense_MFS_IMO == CapSense_MFS_METHOD) */

            CapSense_SsCSXStartSample();
        }
        else
    #endif
        {
            #if (CapSense_MULTI_FREQ_SCAN_EN == CapSense_ENABLE)
                /* All channels are scanned. Reset the multi frequency scan channel */
                CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;

                #if (CapSense_MFS_IMO == CapSense_MFS_METHOD)
                    CapSense_SsChangeImoFreq(CapSense_FREQ_CHANNEL_0);
                #else
                    CapSense_SsChangeClkFreq(CapSense_FREQ_CHANNEL_0);
                #endif /* (CapSense_MFS_IMO == CapSense_MFS_METHOD) */

            #endif
            /*
            * All pending scans completed,
            *   1. Update the counter to indicate same
            *   2. Clear busy state as scanning is completed
            */
            CapSense_dsRam.scanCounter++;
            CapSense_dsRam.status &= ~CapSense_SW_STS_BUSY;
        }

    #ifdef CapSense_EXIT_CALLBACK
        CapSense_ExitCallback();
    #endif /* CapSense_EXIT_CALLBACK */
}

/*******************************************************************************
* Function Name: CapSense_CSXCalibrateWidget
****************************************************************************//**
*
* \brief
*  Calibrates the raw count values of all the sensors/nodes in a CSX widget.
*
* \details
*  Calibrates the raw count values of all the sensors/nodes in a CSX widget.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_CalibrateWidget() function should be used instead.
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
*  CapSense Configuration header file defined as
*  CapSense_<WidgetName>_WDGT_ID.
*
* \param target
*  Specifies the calibration target in percentages of the maximum raw count.
*
* \return Returns the status of the operation:
*   - Zero     - All the sensors in the widget are calibrated successfully.
*   - Non-Zero - Calibration failed for any sensor in the widget.
*
*******************************************************************************/
#if (CapSense_ENABLE == CapSense_CSX_IDAC_AUTOCAL_EN)

cystatus CapSense_CSXCalibrateWidget(uint32 widgetId, uint16 target)
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
    uint8 curIdacMask = (1u << (CapSense_CSX_IDAC_BITS_USED - 1u));
    /* Next used IDAC-bit */
    uint8 nextIdacMask = (curIdacMask >> 1u);

    /* initialize ptr to sensor structures */
    CapSense_curRamSnsPtr = (CapSense_RAM_SNS_STRUCT *)CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsRam;

    #if (CapSense_DISABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Calculate target raw count */
        CapSense_csxScanPeriod  = CapSense_SsCalcCsxScanPeriod(
            (CapSense_RAM_WD_BASE_STRUCT *)CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam);
        rawTarget = CapSense_csxScanPeriod;
        rawTarget = (rawTarget * target) / CapSense_PERCENTAGE_100;
    #endif /* (CapSense_DISABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */


    /* Find out total sensors/nodes in widget */
    totalSns = ((uint32)CapSense_dsFlash.wdgtArray[widgetId].numCols *
                (uint32)CapSense_dsFlash.wdgtArray[widgetId].numRows);

    /* Clear raw count registers and IDAC registers of all the sensors/nodes */
    for (calibrationIndex = 0u; calibrationIndex < totalSns; calibrationIndex++)
    {
        CapSense_curRamSnsPtr->raw[CapSense_FREQ_CHANNEL_0] = 0u;
        CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_0] = curIdacMask;
        #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
            CapSense_curRamSnsPtr->raw[CapSense_FREQ_CHANNEL_1] = 0u;
            CapSense_curRamSnsPtr->raw[CapSense_FREQ_CHANNEL_2] = 0u;
            CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_1] = curIdacMask;
            CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_2] = curIdacMask;
        #endif
        CapSense_curRamSnsPtr++;
    }

    /* Perform binary search for accurate IDAC value for each sensor/node */
    do
    {
        /* Scan all the sensors/nodes in widget */
        (void)CapSense_SetupWidget(widgetId);
        (void)CapSense_Scan();

        watchdogCounter = CapSense_CSX_MEASURE_WATCHDOG_CYCLES_NUM;
        while ((CapSense_dsRam.status & CapSense_SW_STS_BUSY) != 0u)
        {
            if(0uL == watchdogCounter)
            {
                calibrateStatus = CYRET_TIMEOUT;
                break;
            }
            watchdogCounter--;
        }

        /* Get access to sensor data */
        CapSense_curRamSnsPtr = (CapSense_RAM_SNS_STRUCT *)CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsRam;

        /* Check raw count and adjust IDAC, loop through all the sensors/nodes */
        for (calibrationIndex = 0u; calibrationIndex < totalSns; calibrationIndex++)
        {
            /* Calculate raw count target for specified node */
            #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
                rawTarget = (CapSense_SsCSXOversample() * target) / CapSense_PERCENTAGE_100;
            #endif

            /* Check if current raw count is above target,
            *   if yes, clear the MS bit of bit
            *   if no, keep the MS bit and set next bit
            */
            if (CapSense_curRamSnsPtr->raw[CapSense_FREQ_CHANNEL_0] > rawTarget)
            {
                CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_0] &= (uint8)(~curIdacMask);
            }
            CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_0] |= nextIdacMask;

            #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
                if (CapSense_curRamSnsPtr->raw[CapSense_FREQ_CHANNEL_1] > rawTarget)
                {
                    CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_1] &= (uint8)(~curIdacMask);
                }

                if (CapSense_curRamSnsPtr->raw[CapSense_FREQ_CHANNEL_2] > rawTarget)
                {
                    CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_2] &= (uint8)(~curIdacMask);
                }

                CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_1] |= nextIdacMask;
                CapSense_curRamSnsPtr->idacComp[CapSense_FREQ_CHANNEL_2] |= nextIdacMask;
            #endif
            CapSense_curRamSnsPtr++;
        }

        /* Shift both current idac and pre Idac values to right by 1 */
        curIdacMask = nextIdacMask;
        nextIdacMask = nextIdacMask >> 1u;
    }
    while ((curIdacMask != 0u) && (calibrateStatus == CYRET_SUCCESS));

    /* Perform specified widget scan to check calibration result */
    (void)CapSense_SetupWidget(widgetId);
    (void)CapSense_Scan();

    if (calibrateStatus == CYRET_SUCCESS)
    {
        watchdogCounter = CapSense_CSX_MEASURE_WATCHDOG_CYCLES_NUM;
        while ((CapSense_dsRam.status & CapSense_SW_STS_BUSY) != 0u)
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
            calibrateStatus = CapSense_SsCSXCalibrateCheck(widgetId, (uint32)CapSense_csxScanPeriod, (uint32)target);
        }
    }

     /* Update CRC */
    #if (CapSense_ENABLE ==CapSense_TST_WDGT_CRC_EN)
        CapSense_DsUpdateWidgetCrc(widgetId);
    #endif

    return(calibrateStatus);
}


/*******************************************************************************
* Function Name: CapSense_SsCSXCalibrateCheck
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
static cystatus CapSense_SsCSXCalibrateCheck(uint32 widgetId, uint32 scanPeriod, uint32 target)
{
    uint32 rawcount;
    uint32 snsIndex;
    uint32 freqChannel;
    uint32 upperLimit;
    uint32 lowerLimit;
    cystatus calibrateStatus = CYRET_SUCCESS;

    CapSense_FLASH_WD_STRUCT const *ptrFlashWidget = &CapSense_dsFlash.wdgtArray[widgetId];
    CapSense_RAM_SNS_STRUCT *ptrRamSensor = ptrFlashWidget->ptr2SnsRam;

    lowerLimit = 0u;
    if (target > CapSense_CSX_CALIBRATION_ERROR)
    {
        lowerLimit = target - CapSense_CSX_CALIBRATION_ERROR;
    }
    upperLimit = target + CapSense_CSX_CALIBRATION_ERROR;
    if (upperLimit > CapSense_PERCENTAGE_100)
    {
        upperLimit = CapSense_PERCENTAGE_100;
    }
    lowerLimit = (scanPeriod * lowerLimit) / CapSense_PERCENTAGE_100;
    upperLimit = (scanPeriod * upperLimit) / CapSense_PERCENTAGE_100;

    /* Check if raw count is in the defined range */
    for(snsIndex = 0u; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
    {
        for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
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

#endif /* (CapSense_CSX_IDAC_AUTOCAL_EN == CapSense_ENABLE) */

#if(CapSense_ENABLE == CapSense_CSDV2)
/*******************************************************************************
* Function Name: CapSense_SsCSXStartSample
****************************************************************************//**
*
* \brief
*   Starts scanning for the CSX widget.
*
* \details
*   Starts scanning for the CSX widget.
*
*******************************************************************************/
static void CapSense_SsCSXStartSample(void)
{
    uint32 tmpRegVal;
    uint32 idacGainIndex;

    /* Configuring IDAC register */
    idacGainIndex = ((CapSense_RAM_WD_BASE_STRUCT *)CapSense_curFlashWdgtPtr->ptr2WdgtRam)->idacGainIndex;
    tmpRegVal = CapSense_DEFAULT_CSD_IDACA_CFG & ~CapSense_IDAC_GAIN_MASK;
    tmpRegVal |= ((uint32)CapSense_curRamSnsPtr->idacComp[CapSense_scanFreqIndex] & CapSense_IDAC_MOD_VAL_MASK);
    tmpRegVal |= CapSense_idacGainTable[idacGainIndex].gainReg;
    CY_SET_REG32(CapSense_CSD_IDACA_PTR, tmpRegVal);

    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Configure node-specific number of sub-conversion */
        CapSense_csxScanPeriod = (uint16)CapSense_SsCSXOversample();
        CY_SET_REG32(CapSense_SEQ_NORM_CNT_PTR, (uint32)CapSense_curRamSnsPtr->subConvNum);
    #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

    /* Clear scan result holder */
    CapSense_csxRawCount = 0u;

    #ifdef CapSense_START_SAMPLE_CALLBACK
        CapSense_StartSampleCallback(CapSense_widgetIndex, CapSense_sensorIndex);
    #endif /* CapSense_START_SAMPLE_CALLBACK */

    CapSense_SsCSXStartSampleExt();
}
#else

/*******************************************************************************
* Function Name: CapSense_SsCSXStartSample
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
static void CapSense_SsCSXStartSample(void)
{
    uint8 critSect;
    uint32 tmpRegVal;
    uint32 idacGainIndex;

    idacGainIndex = ((CapSense_RAM_WD_BASE_STRUCT *)CapSense_curFlashWdgtPtr->ptr2WdgtRam)->idacGainIndex;
    critSect = CyEnterCriticalSection();
    tmpRegVal = CY_GET_REG32(CapSense_IDAC_PTR);
    tmpRegVal &= ~CapSense_IDAC_MOD_MASK;
    tmpRegVal &= ~CapSense_IDAC_GAIN_MASK;
    tmpRegVal |= CapSense_IDAC_MOD_MODE_VARIABLE | (uint32)CapSense_curRamSnsPtr->idacComp[CapSense_scanFreqIndex];
    tmpRegVal |= CapSense_idacGainTable[idacGainIndex].gainReg;

    CY_SET_REG32(CapSense_IDAC_PTR, tmpRegVal);
    CyExitCriticalSection(critSect);

    /* Clear scan result holder */
    CapSense_csxRawCount = 0u;

    #ifdef CapSense_START_SAMPLE_CALLBACK
        CapSense_StartSampleCallback(CapSense_widgetIndex, CapSense_sensorIndex);
    #endif /* CapSense_START_SAMPLE_CALLBACK */

    #if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
        /* Configure node-specific number of sub-conversion */
        CapSense_csxScanPeriod = (uint16)CapSense_SsCSXOversample();
    #endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */

    /* Disable interrupts and initiate scan */
    critSect = CyEnterCriticalSection();
    CapSense_SsCSXStartSampleExt();
    CyExitCriticalSection(critSect);
}
#endif /* (CapSense_ENABLE == CapSense_CSDV2) */

/*******************************************************************************
* Function Name: CapSense_CSXConnectTx
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
void CapSense_CSXConnectTx(CapSense_FLASH_IO_STRUCT const *txPtr)
{
    CapSense_WriteBitsSafe(txPtr->pcPtr, (uint32)(CapSense_GPIO_PC_MASK << txPtr->shift),
            (uint32)(CapSense_GPIO_STRGDRV << txPtr->shift));
    CapSense_WriteBitsSafe(txPtr->hsiomPtr, (CapSense_HSIOM_SEL_MASK << txPtr->hsiomShift),
            (uint32)(CapSense_HSIOM_SEL_CSD_SENSE << txPtr->hsiomShift));
}

/*******************************************************************************
* Function Name: CapSense_CSXConnectRx
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
void CapSense_CSXConnectRx(CapSense_FLASH_IO_STRUCT const *rxPtr)
{
    CapSense_WriteBitsSafe(rxPtr->pcPtr, (uint32)(CapSense_GPIO_PC_MASK << rxPtr->shift), 0u);
    CapSense_WriteBitsSafe(rxPtr->hsiomPtr, (CapSense_HSIOM_SEL_MASK << rxPtr->hsiomShift), (uint32)(CapSense_HSIOM_SEL_AMUXA << rxPtr->hsiomShift));
}

/*******************************************************************************
* Function Name: CapSense_CSXDisconnectTx
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
void CapSense_CSXDisconnectTx(CapSense_FLASH_IO_STRUCT const *txPtr)
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
    regValue &= ~(CapSense_GPIO_PC_MASK << txPtr->shift);

    if(CapSense_SNS_CONNECTION_GROUND == CapSense_dsRam.scanCurrentISC)
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
* Function Name: CapSense_CSXDisconnectRx
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
void CapSense_CSXDisconnectRx(CapSense_FLASH_IO_STRUCT const *rxPtr)
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
    regValue &= ~(CapSense_GPIO_PC_MASK << rxPtr->shift);

    if(CapSense_SNS_CONNECTION_GROUND == CapSense_dsRam.scanCurrentISC)
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
* Function Name: CapSense_SsCSXGetTxClkDivider
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
uint32 CapSense_SsCSXGetTxClkDivider(uint32 widgetId)
{
    uint32 retVal;

    /* Get sense divider based on configuration */
    #if (CapSense_DISABLE == CapSense_CSX_COMMON_TX_CLK_EN)
        CapSense_RAM_WD_BASE_STRUCT *ptrWdgt;

        ptrWdgt = (CapSense_RAM_WD_BASE_STRUCT *)
        CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;

        retVal = (uint32)(ptrWdgt->snsClk);
    #else
        retVal = (uint32)CapSense_dsRam.snsCsxClk;
    #endif /* (CapSense_DISABLE == CapSense_CSX_COMMON_TX_CLK_EN) */

    if(widgetId == 0uL)
    {
        ;
    }

    return (retVal);
}


/*******************************************************************************
* Function Name: CapSense_SsCalcCsxScanPeriod
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
static uint16 CapSense_SsCalcCsxScanPeriod(CapSense_RAM_WD_BASE_STRUCT const *wdgtPtr)
{
    uint32 temp;

    #if(CapSense_DISABLE == CapSense_CSX_COMMON_TX_CLK_EN)
        temp = (uint32)(wdgtPtr->snsClk);
    #else
        temp = (uint32)(CapSense_dsRam.snsCsxClk);
    #endif /* (CapSense_DISABLE == CapSense_CSX_COMMON_TX_CLK_EN) */

    #if(CapSense_ENABLE == CapSense_CSDV2)
        temp  = LO16((uint32)wdgtPtr->resolution * (temp - CapSense_CSX_DEADBAND_CYCLES_NUMBER));
    #else
        #if(CapSense_ENABLE == CapSense_IS_M0S8PERI_BLOCK)
            temp = (temp / (uint32)CapSense_dsRam.modCsxClk);
        #endif /* (CapSense_ENABLE == CapSense_IS_M0S8PERI_BLOCK) */

        temp = ((uint32)wdgtPtr->resolution * CapSense_NUM_HALF_CYCLES * temp);
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */

    /* return the scan period */
    return ((uint16)temp);
}


#if (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES)
/*******************************************************************************
* Function Name: CapSense_SsCSXOversample
****************************************************************************//**
*
* \brief
*   Calculates the scan period of specific node.
*
* \details
*   Calculates the scan period of specific node that is used as maximum
*   raw count at raw count inversion (CapSense_csxScanPeriod variable).
*   The CapSense_curFlashWdgtPtr and CapSense_curRamSnsPtr
*   must be configured to proper widget/sensor before calling this function.
*
* \return
*   Returns the scan period of specific node (used as maximum raw count)
*
*******************************************************************************/
static uint32 CapSense_SsCSXOversample(void)
{
    uint32 temp;

    #if(CapSense_DISABLE == CapSense_CSX_COMMON_TX_CLK_EN)
        CapSense_RAM_WD_BASE_STRUCT * curRamWdgtBasePtr;
        curRamWdgtBasePtr = (CapSense_RAM_WD_BASE_STRUCT *)CapSense_curFlashWdgtPtr->ptr2WdgtRam;
        temp = (uint32)(curRamWdgtBasePtr->snsClk);
    #else
        temp = (uint32)(CapSense_dsRam.snsCsxClk);
    #endif /* (CapSense_DISABLE == CapSense_CSX_COMMON_TX_CLK_EN) */

    #if(CapSense_ENABLE == CapSense_CSDV2)
        temp  = LO16((uint32)CapSense_curRamSnsPtr->subConvNum * (temp - CapSense_CSX_DEADBAND_CYCLES_NUMBER));
    #else
        #if(CapSense_ENABLE == CapSense_IS_M0S8PERI_BLOCK)
            temp = (temp / (uint32)CapSense_dsRam.modCsxClk);
        #endif /* (CapSense_ENABLE == CapSense_IS_M0S8PERI_BLOCK) */

        temp = ((uint32)CapSense_curRamSnsPtr->subConvNum * CapSense_NUM_HALF_CYCLES * temp);
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */

    /* return the scan period */
    return (temp);
}
#endif /* (CapSense_ENABLE == CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES) */


#if(CapSense_ENABLE == CapSense_CSDV2)
/**
* \cond SECTION_C_INTERRUPT
* \addtogroup group_c_interrupt
* \{
*/
/*******************************************************************************
* Function Name: CapSense_CSXScanISR
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
CY_ISR(CapSense_CSXScanISR)
{
#if(0u != CapSense_CSX_NOISE_METRIC_EN)
    uint32 tmpRegVal;
#endif /* (0u != CapSense_CSX_NOISE_METRIC_EN) */
#if(0u != CapSense_CSX_NOISE_METRIC_EN)
    static uint32 CapSense_resamplingCyclesCnt = CapSense_RESAMPLING_CYCLES_MAX_NUMBER;
#endif /* (0u != CapSense_CSX_NOISE_METRIC_EN) */

    CyIntDisable(CapSense_ISR_NUMBER);

    CY_SET_REG32(CapSense_INTR_PTR, CapSense_DEFAULT_CSD_INTR_CFG);

    CapSense_csxRawCount  = (uint16)(CY_GET_REG32(CapSense_RESULT_VAL1_PTR) &\
                                                         CapSense_RESULT_VAL1_VALUE_MASK);

    CapSense_csxRawCount += (uint16)(CY_GET_REG32(CapSense_RESULT_VAL2_PTR) &\
                                                         CapSense_RESULT_VAL2_VALUE_MASK);

    /* This workaround neded to prevent overflow in the SW register map. Cypress ID #234358 */
    if(CapSense_csxRawCount > CapSense_csxScanPeriod)
    {
        CapSense_csxRawCount = CapSense_csxScanPeriod;
    }

#if(0u != CapSense_CSX_NOISE_METRIC_EN)
    tmpRegVal = CY_GET_REG32(CapSense_RESULT_VAL1_PTR) >> CapSense_RESULT_VAL1_BAD_CONVS_SHIFT;

    if((tmpRegVal > CapSense_CSX_NOISE_METRIC_TH) && (CapSense_resamplingCyclesCnt > 0uL))
    {
        CY_SET_REG32(CapSense_SEQ_START_PTR, CapSense_SCAN_CSD_SEQ_START_CFG);
        CapSense_resamplingCyclesCnt--;
    }
    else
    {
        CapSense_CSXPostScanApiPtr();
        CapSense_resamplingCyclesCnt = CapSense_RESAMPLING_CYCLES_MAX_NUMBER;
    }
#else
    CapSense_CSXPostScanApiPtr();
#endif /* (0u != CapSense_CSX_NOISE_METRIC_EN) */

    if(CapSense_NOT_BUSY == (CapSense_dsRam.status & CapSense_SW_STS_BUSY))
    {
        CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_DEFAULT_CSD_CONFIG_CFG);
        CY_SET_REG32(CapSense_CSDCMP_PTR, CapSense_DEFAULT_CSD_CSDCMP_CFG);
        CY_SET_REG32(CapSense_CSD_IDACA_PTR, CapSense_DEFAULT_CSD_IDACA_CFG);
    }

    CyIntEnable(CapSense_ISR_NUMBER);
}

/** \}
* \endcond */

/*******************************************************************************
* Function Name: CapSense_SsCSXStartSampleExt
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
static CY_INLINE void CapSense_SsCSXStartSampleExt(void)
{
    uint32 filterDelay;
    uint32 watchdogCounter;
    #if (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
        uint32 sampleClkFreqHz;
    #endif /* (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */

/* Configure the HW sequencer to perform the coarse initialization. */
    CY_SET_REG32(CapSense_CONFIG_PTR,           CapSense_DEFAULT_CSD_CONFIG_CFG);
    CY_SET_REG32(CapSense_HSCMP_PTR,            CapSense_PRECHARGE_CSD_HSCMP_CFG);
    CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR,      CapSense_PRECHARGE_CSD_SW_HS_P_SEL_CFG);
    CY_SET_REG32(CapSense_SW_HS_N_SEL_PTR,      CapSense_PRECHARGE_CSD_SW_HS_N_SEL_CFG);
    CY_SET_REG32(CapSense_SW_DSI_SEL_PTR,       CapSense_PRECHARGE_CSD_SW_DSI_SEL_CFG);
    CY_SET_REG32(CapSense_SW_SHIELD_SEL_PTR,    CapSense_PRECHARGE_CSD_SW_SHIELD_SEL_CFG);
    CY_SET_REG32(CapSense_SW_FW_MOD_SEL_PTR,    CapSense_PRECHARGE_CSD_SW_FW_MOD_SEL_CFG);
    CY_SET_REG32(CapSense_SW_FW_TANK_SEL_PTR,   CapSense_PRECHARGE_CSD_SW_FW_TANK_SEL_CFG);

    #if(CapSense_ENABLE == CapSense_CSDV2) &&\
       (CapSense_ENABLE == CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
       (CapSense_CSX_ANALOG_STARTUP_DELAY_US > 0uL)
                CyDelayUs(CapSense_CSX_ANALOG_STARTUP_DELAY_US);
    #endif

    CY_SET_REG32(CapSense_SEQ_START_PTR,        CapSense_PRECHARGE_CSD_SEQ_START_CFG);

    /* Wait for the HSCMP trigger and retutn the sequencer to the IDLE state. */
    watchdogCounter = CapSense_CSX_PRECHARGE_WATCHDOG_CYCLES_NUM;
    while((0u != (CapSense_SEQ_START_START_MASK & CY_GET_REG32(CapSense_SEQ_START_PTR))) && (0u != watchdogCounter))
    {
        watchdogCounter--;
    }

    /* Reset the sequencer to the IDLE state if HSCMP not triggered till watchdog period is out. */
    if(0u != (CapSense_SEQ_START_START_MASK & CY_GET_REG32(CapSense_SEQ_START_PTR)))
    {
        CY_SET_REG32(CapSense_SEQ_START_PTR,  CapSense_DEFAULT_CSD_SEQ_START_CFG);
    }

    #if (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
        sampleClkFreqHz = CYDEV_BCLK__HFCLK__HZ / (uint32)CapSense_dsRam.modCsxClk;
        if(sampleClkFreqHz <= CapSense_MOD_CSD_CLK_12MHZ)
        {
            filterDelay = CapSense_CONFIG_FILTER_DELAY_12MHZ;
        }
        else if(sampleClkFreqHz <= CapSense_MOD_CSD_CLK_24MHZ)
        {
            filterDelay = CapSense_CONFIG_FILTER_DELAY_24MHZ;
        }
        else
        {
            filterDelay = CapSense_CONFIG_FILTER_DELAY_48MHZ;
        }
    #else
        filterDelay = CapSense_CONFIG_FILTER_DELAY_12MHZ;
    #endif /* (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */

    /* Configure the HW sequencer to perform the normal conversion. */
    CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_PRESCAN_CSD_CONFIG_CFG | filterDelay);
    CY_SET_REG32(CapSense_CSDCMP_PTR, CapSense_PRESCAN_CSD_CSDCMP_CFG);
    CY_SET_REG32(CapSense_HSCMP_PTR, CapSense_DEFAULT_CSD_HSCMP_CFG);
    CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR, CapSense_DEFAULT_CSD_SW_HS_P_SEL_CFG);
    CY_SET_REG32(CapSense_SW_HS_N_SEL_PTR, CapSense_DEFAULT_CSD_SW_HS_N_SEL_CFG);
    CY_SET_REG32(CapSense_SW_DSI_SEL_PTR, CapSense_DEFAULT_CSD_SW_DSI_SEL_CFG);
    CY_SET_REG32(CapSense_SW_SHIELD_SEL_PTR, CapSense_DEFAULT_CSD_SW_SHIELD_SEL_CFG);
    CY_SET_REG32(CapSense_SW_FW_MOD_SEL_PTR, CapSense_DEFAULT_CSD_SW_FW_MOD_SEL_CFG);
    CY_SET_REG32(CapSense_SW_FW_TANK_SEL_PTR, CapSense_DEFAULT_CSD_SW_FW_TANK_SEL_CFG);

    /* Clear all pending interrupts of CSD block */
    CY_SET_REG32(CapSense_INTR_PTR, CapSense_DEFAULT_CSD_INTR_CFG);

    /* Start the normal conversion. */
    CY_SET_REG32(CapSense_SEQ_START_PTR, CapSense_SCAN_CSD_SEQ_START_CFG);
}

#endif /* (CapSense_ENABLE == CapSense_CSDV2) */
#endif  /* (0u != CapSense_CSX_EN) */


/* [] END OF FILE */
