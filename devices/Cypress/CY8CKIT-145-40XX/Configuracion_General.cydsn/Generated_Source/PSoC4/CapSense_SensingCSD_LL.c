/***************************************************************************//**
* \file CapSense_SensingCSD_LL.c
* \version 7.10
*
* \brief
*   This file defines the data structure global variables and provides
*   implementation for the low-level APIs of the CSD part of
*   the Sensing module. The file contains the APIs used for the CSD block
*   initialization, calibration, and scanning.
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
#include "CapSense_Structure.h"
#include "CapSense_Configuration.h"
#include "CapSense_SensingCSD_LL.h"
#if (CapSense_ENABLE == CapSense_SELF_TEST_EN)
    #include "CapSense_SelfTest.h"
#endif

#include "cyapicallbacks.h"

#if (CapSense_ENABLE == CapSense_CSD_EN)

/***************************************
* API Constants
***************************************/

#if (CapSense_ENABLE == CapSense_CSDV2)

    #if (CapSense_ENABLE == CapSense_CSD_AUTO_ZERO_EN)
        #define CapSense_CSD_AZ_ENABLE_CFG                  (CapSense_CSD_AZ_EN_MASK)
    #else
        #define CapSense_CSD_AZ_ENABLE_CFG                  (0uL)
    #endif /* (CapSense_ENABLE == CapSense_CSD_AUTO_ZERO_EN) */

    #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
        #define CapSense_HSCMP_SCAN_MASK                    (CapSense_HSCMP_EN_MASK | CapSense_CSD_AZ_ENABLE_CFG |\
                                                                     CapSense_HSCMP_INVERT_MASK)
    #else
        #define CapSense_HSCMP_SCAN_MASK                    (CapSense_HSCMP_EN_MASK | CapSense_CSD_AZ_ENABLE_CFG)
    #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */

    #define CapSense_HSCMP_INIT_MASK                        (CapSense_HSCMP_EN_MASK | CapSense_CSD_AZ_ENABLE_CFG)

    #define CapSense_DEFAULT_SW_SHIELD_SEL                  (0x00000000uL)
    #define CapSense_DEFAULT_CSD_SW_DSI_SEL                 (CapSense_SW_DSI_SEL_CMODPAD | CapSense_SW_DSI_SEL_TANKPAD)
    #define CapSense_DEFAULT_CSD_INTR_SET                   (0x00000000uL)
    #define CapSense_DEFAULT_SW_HS_P_SEL                    (0x00000000uL)
    #define CapSense_DEFAULT_SW_HS_N_SEL                    (0x00000000uL)
    #define CapSense_DEFAULT_CSD_SW_FW_TANK_SEL             (0x00000000uL)
    #define CapSense_DEFAULT_CSD_ADC_CTL                    (0x00000000uL)
    #define CapSense_DEFAULT_HSCMP_CFG                      (0x00000000uL)

    /* CY_ID285392 */
    #define CapSense_FILTER_DELAY_MAX                   (CapSense_CONFIG_FILTER_DELAY_4_CYCLES)
    #define CapSense_EXTRA_COUNTS_MAX                   (CapSense_FILTER_DELAY_MAX + 5u + 20u)

#else

    /* Set IDAC ranges */
    #if (CapSense_IDAC_GAIN_8X == CapSense_CSD_IDAC_GAIN)
        #define CapSense_DEFAULT_IDAC_MOD_RANGE         (CapSense_IDAC_MOD_RANGE_MASK)
        #define CapSense_DEFAULT_IDAC_COMP_RANGE        (CapSense_IDAC_COMP_RANGE_MASK)
    #else
        #define CapSense_DEFAULT_IDAC_MOD_RANGE         (0u)
        #define CapSense_DEFAULT_IDAC_COMP_RANGE        (0u)
    #endif /* (CapSense_IDAC_GAIN_8X == CapSense_CSD_IDAC_GAIN) */

    /* Defining default IDACs configuration according to settings in customizer. */
    #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
        #define CapSense_DEFAULT_CSD_IDAC_CONFIG        (CapSense_IDAC_MOD_MODE_VARIABLE |\
                                                                 CapSense_IDAC_COMP_MODE_FIXED |\
                                                                 CapSense_DEFAULT_IDAC_MOD_RANGE |\
                                                                 CapSense_DEFAULT_IDAC_COMP_RANGE)
    #else
        #define CapSense_DEFAULT_CSD_IDAC_CONFIG        (CapSense_IDAC_MOD_MODE_VARIABLE |\
                                                                 CapSense_DEFAULT_IDAC_MOD_RANGE)
    #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

#endif /* (CapSense_ENABLE == CapSense_CSDV2) */


/***************************************
* Variables
***************************************/

#if (CapSense_ENABLE == CapSense_CSDV2)
    uint32 CapSense_configCsd = CapSense_DEFAULT_CSD_CONFIG;
#else
    uint32 CapSense_configCsd = CapSense_DEFAULT_CSD_CONFIG | CapSense_DEFAULT_MODULATION_MODE;
    static uint32 CapSense_counterResolution = CapSense_CNT_RESOLUTION_12_BITS;
#endif /* (CapSense_ENABLE == CapSense_CSDV2) */

/* Flag to indicate electrodes that were connected previously */
static uint8 CapSense_eleCsdDisconnectFlag = 0u;
#if ((CapSense_ENABLE == CapSense_CSDV2) && (CapSense_ENABLE == CapSense_CSD_NOISE_METRIC_EN))
    /* Number of re-samplings when the bad conversion occurs */
    uint8 CapSense_badConversionsNum = CapSense_BAD_CONVERSIONS_NUM;
#endif /* ((CapSense_ENABLE == CapSense_CSDV2) && (CapSense_ENABLE == CapSense_CSD_NOISE_METRIC_EN)) */


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/

/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

#if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
    static void CapSense_SsSetShieldDelay(uint32 delay);
    #if (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN)
        static void CapSense_SsCSDEnableShieldTank(void);
    #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) */
#endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

#if ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
     (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN))
    static cystatus CapSense_SsCSDCalibrateCheck(uint32 widgetId, uint32 target);
    static void CapSense_SsCSDCalibrate(uint32 widgetId, uint32 target);
    #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
        static void CapSense_SsCSDNormalizeIdac(CapSense_FLASH_WD_STRUCT const *ptrFlashWidget, uint32 target);
    #endif
    #if (CapSense_ENABLE == CapSense_CSD_IDAC_AUTO_GAIN_EN)
        static uint32 CapSense_SsCSDSwitchIdacGain(CapSense_FLASH_WD_STRUCT const *ptrFlashWidget);
    #endif
#endif /* ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
           (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN))  */

#if (CapSense_ENABLE == CapSense_CSDV2)
    static void CapSense_SsCSDSetFilterDelay(void);
#else
    CY_INLINE static void CapSense_SsCSDClockRestart(void);
#endif /* (CapSense_ENABLE == CapSense_CSDV2) */
CY_INLINE static void CapSense_SsCSDCmodPrecharge(void);
CY_INLINE static void CapSense_SsCSDTriggerScan(void);
static void CapSense_SsCSDConfigIDACs(void);
static void CapSense_SsCSDSetModeSnsClockDivider(uint32 snsClkSource, uint32 snsClkDivider);

/** \}
* \endcond */


#if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
    /*******************************************************************************
    * Function Name: CapSense_SsSetShieldDelay
    ****************************************************************************//**
    *
    * \brief
    *   This is an internal function that sets a shield delay.
    *
    * \details
    *   The function updates the CSD configuration register bits that define the shield
    *   signal delay relatively to the sense signal.
    *
    * \param delay
    *   Specifies the shield delay value:
    *    PSoC 4100/4200 value interpretation:
    *         0 - no delay
    *         1 - 1 cycle of HFCLK
    *         2 - 2 cycles of HFCLK
    *    Third-generation HW block (except 4100/4200 devices):
    *         0 - no delay
    *         3 - 10ns delay
    *         2 - 50ns delay
    *    Fourth-generation HW block:
    *         0 - no delay
    *         1 - 5ns delay
    *         2 - 10ns delay
    *         3 - 20ns delay
    *
    *******************************************************************************/
    static void CapSense_SsSetShieldDelay(uint32 delay)
    {
        /* Update CSD config register shield delay bits with shield delay value */
        CapSense_configCsd &= (uint32)(~CapSense_CONFIG_SHIELD_DELAY_MASK);
        CapSense_configCsd |= (delay << CapSense_SHIELD_DELAY_SHIFT);
    }

    #if (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN)
        /*******************************************************************************
        * Function Name: CapSense_SsCSDEnableShieldTank
        ****************************************************************************//**
        *
        * \brief
        *   This function configures Csh pin
        *
        * \details
        *   The function updates the CSH_HSIOM register to connect Csh to AMUXBUS-B.
        *   For Third-generation HW block it additionally sets Strong drive mode for Csh
        *   and applies High level to Csh pin when precharge is set to IO buffer.
        *
        *******************************************************************************/
        static void CapSense_SsCSDEnableShieldTank(void)
        {
            /* Update the CSH_HSIOM register to connect Csh to AMUXBUS-B */
            CapSense_WriteBitsSafe(CapSense_CSH_HSIOM_PTR, CapSense_CSH_HSIOM_MASK,
                        (uint32)(CapSense_HSIOM_SEL_AMUXB << CapSense_CSH_HSIOM_SHIFT));

            #if ((CapSense_CSH_PRECHARGE_IO_BUF == CapSense_CSD_CSH_PRECHARGE_SRC) &&\
                 (CapSense_DISABLE == CapSense_CSDV2))
                /* Set Strong drive mode for Csh */
                CapSense_WriteBitsSafe(CapSense_CSH_PC_PTR,
                            (uint32)(CapSense_CSH_PC_MASK << CapSense_CSH_PC_SHIFT),
                            (uint32)(CapSense_CSH_PC_STRONG_MODE << CapSense_CSH_PC_SHIFT));
                /* Appliy High level to Csh pin for Csh */
                CapSense_WriteBitsSafe(CapSense_CSH_DR_PTR, (uint32)(CapSense_DR_MASK << CapSense_CSH_SHIFT), CapSense_CSH_DR_CONFIG);
            #else
                /* Set output port register to 0 to connect to GND */
                CapSense_WriteBitsSafe(CapSense_CSH_DR_PTR, (uint32)(CapSense_DR_MASK << CapSense_CSH_SHIFT), 0u);
            #endif
        }
    #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) */

    #if (0u != CapSense_CSD_TOTAL_SHIELD_COUNT)
        /*******************************************************************************
        * Function Name: CapSense_SsCSDEnableShieldElectrodes
        ****************************************************************************//**
        *
        * \brief
        *   This internal function initializes Shield Electrodes.
        *
        * \details
        *   The function sets the bit in the HSIOM register which enables the shield electrode
        *   functionality on the pin. The port and pin configurations are stored in
        *   the CapSense_shieldIoList structure.
        *
        *******************************************************************************/
        void CapSense_SsCSDEnableShieldElectrodes(void)
        {
            CapSense_SsCSDSetShieldElectrodesState(CapSense_SNS_CONNECTION_SHIELD);
        }


        /*******************************************************************************
        * Function Name: CapSense_SsCSDDisableShieldElectrodes
        ****************************************************************************//**
        *
        * \brief
        *   This internal function disables Shield Electrodes.
        *
        * \details
        *   The function resets the bit in the HSIOM register which disables the shield
        *   electrode functionality on the pin. The port and pin configurations are
        *   stored in  the CapSense_shieldIoList structure.
        *
        *******************************************************************************/
        void CapSense_SsCSDDisableShieldElectrodes(void)
        {
            CapSense_SsCSDSetShieldElectrodesState(CapSense_SNS_CONNECTION_GROUND);
        }


        /*******************************************************************************
        * Function Name: CapSense_SsCSDSetShieldElectrodesState
        ****************************************************************************//**
        *
        * \brief
        *   Sets specified shield electrode pin connection state for all dedicated
        *   shield electrodes.
        *
        * \details
        *   The function updates following registers for each shield
        *   electrode:
        *   - port configuration register
        *   - pin data register
        *   - pin HSIOM register
        *   The shield electrodes port and pin configuration registers addresses are
        *   stored in the CapSense_shieldIoList structure.
        *
        * \param state
        *   A new state of the shield electrodes. Available values:
        *   - CapSense_SNS_CONNECTION_GROUND - disconnects electrode from
        *       CSD hardware block and sets it to GPIO mode with Strong Drive
        *   - CapSense_SNS_CONNECTION_HIGHZ - disconnects electrode from
        *       CSD hardware block and sets it to GPIO mode with Analog Hi-Z
        *   - CapSense_SNS_CONNECTION_SHIELD - connects electrode to
        *       CSD hardware block
        *   - CapSense_SNS_CONNECTION_UNDEFINED - sets the same electrode
        *       connection as for CapSense_SNS_CONNECTION_GROUND
        *
        *******************************************************************************/
        void CapSense_SsCSDSetShieldElectrodesState(uint32 state)
        {
            uint8  interruptState;

            uint32 loopIndex;

            uint32 newPinPcVal;
            uint32 newPinHsiomVal;

            uint32 tmpPcDrRegValue;
            uint32 tmpHsiomRegValue;

            CapSense_SHIELD_IO_STRUCT const *shieldIoPtr;

            switch(state)
            {
                case CapSense_SNS_CONNECTION_GROUND:
                    newPinPcVal = CY_SYS_PINS_DM_STRONG;
                    newPinHsiomVal = CapSense_HSIOM_SEL_GPIO;
                    break;
                case CapSense_SNS_CONNECTION_HIGHZ:
                    newPinPcVal = CY_SYS_PINS_DM_ALG_HIZ;
                    newPinHsiomVal = CapSense_HSIOM_SEL_GPIO;
                    break;
                case CapSense_SNS_CONNECTION_SHIELD:
                    newPinPcVal = CY_SYS_PINS_DM_ALG_HIZ;
                    newPinHsiomVal = CapSense_HSIOM_SEL_CSD_SHIELD;
                    break;
                default:
                    newPinPcVal = CY_SYS_PINS_DM_STRONG;
                    newPinHsiomVal = CapSense_HSIOM_SEL_GPIO;
                    break;
            }

            shieldIoPtr = &CapSense_shieldIoList[0u];
            for (loopIndex = 0u; loopIndex < CapSense_CSD_TOTAL_SHIELD_COUNT; loopIndex++)
            {
                interruptState = CyEnterCriticalSection();

                tmpHsiomRegValue = CY_GET_REG32 (shieldIoPtr->hsiomPtr);
                tmpHsiomRegValue &= ~(shieldIoPtr->hsiomMask);
                CY_SET_REG32 (shieldIoPtr->hsiomPtr, tmpHsiomRegValue);

                tmpPcDrRegValue = CY_GET_REG32 (shieldIoPtr->pcPtr);
                tmpPcDrRegValue &= ~(CapSense_GPIO_PC_MASK << shieldIoPtr->shift);
                tmpPcDrRegValue |=  (newPinPcVal << shieldIoPtr->shift);
                CY_SET_REG32 (shieldIoPtr->pcPtr, tmpPcDrRegValue);

                tmpHsiomRegValue |=  (newPinHsiomVal << shieldIoPtr->hsiomShift);
                CY_SET_REG32 (shieldIoPtr->hsiomPtr, tmpHsiomRegValue);

                tmpPcDrRegValue = CY_GET_REG32 (shieldIoPtr->drPtr);
                tmpPcDrRegValue &= ~(1uL << shieldIoPtr->drShift);
                CY_SET_REG32 (shieldIoPtr->drPtr, tmpPcDrRegValue);

                CyExitCriticalSection(interruptState);

                /* Get next electrode */
                shieldIoPtr++;
            }
        }
    #endif /* (0u != CapSense_CSD_TOTAL_SHIELD_COUNT) */
#endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */


/*******************************************************************************
* Function Name: CapSense_SsCSDSetModeSnsClockDivider
****************************************************************************//**
*
* \brief
*   Sets sense source and Sense Clock Divider
*
* \details
*   For Fourth-generation HW block: Updates CapSense_SENSE_PERIOD register with
*   sense source and Sense Clock Divider.
*   For Third-generation HW block: Updates CapSense_configCsd variable with
*   sense source and sets sense clock divider.
*
* \param
*   snsClkSource The sense source for the sense clock.
* \param
*   snsClkDivider The divider value for the sense clock.
*
*******************************************************************************/
static void CapSense_SsCSDSetModeSnsClockDivider(uint32 snsClkSource, uint32 snsClkDivider)
{
    #if (CapSense_ENABLE == CapSense_CSDV2)
        /* Update reg value with divider and configuration */
        CY_SET_REG32(CapSense_SENSE_PERIOD_PTR, snsClkSource | (snsClkDivider - 1u));
    #else
        /* Set configuration */
        CapSense_configCsd &= ~(CapSense_CONFIG_PRS_SELECT_MASK | CapSense_CSD_PRS_12_BIT);
        CapSense_configCsd |= snsClkSource;

        /* Set sense clock divider */
        CapSense_SsSetSnsClockDivider(snsClkDivider);
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}


#if (CapSense_ENABLE == CapSense_CSDV2)
    /*******************************************************************************
    * Function Name: CapSense_SsCSDSetFilterDelay
    ****************************************************************************//**
    *
    * \brief
    *   Sets the filter delay for Fourth-generation HW block.
    *
    * \details
    *   This function updates Fourth-generation HW block configuration
    *   variable CapSense_configCsd
    *   with the filter delay which depends on the sample clock frequency.
    *   This variable is written into register during enabling
    *   Fourth-generation HW block .
    *
    *******************************************************************************/
    static void CapSense_SsCSDSetFilterDelay(void)
    {
        #if (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
            uint32 sampleClkFreqHz;
        #endif /* (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */

        CapSense_configCsd &= ~CapSense_CONFIG_FILTER_DELAY_MASK;

        #if (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
            sampleClkFreqHz = CYDEV_BCLK__HFCLK__HZ / (uint32)CapSense_dsRam.modCsdClk;
            if(sampleClkFreqHz <= CapSense_MOD_CSD_CLK_12MHZ)
            {
                CapSense_configCsd |= CapSense_CONFIG_FILTER_DELAY_12MHZ;
            }
            else if(sampleClkFreqHz <= CapSense_MOD_CSD_CLK_24MHZ)
            {
                CapSense_configCsd |= CapSense_CONFIG_FILTER_DELAY_24MHZ;
            }
            else
            {
                CapSense_configCsd |= CapSense_CONFIG_FILTER_DELAY_48MHZ;
            }
        #else
            CapSense_configCsd |= CapSense_CONFIG_FILTER_DELAY_12MHZ;
        #endif /* (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */
    }
#endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)  */


/*******************************************************************************
* Function Name: CapSense_SsCSDConfigIDACs
****************************************************************************//**
*
* \brief
*   Configures the mode for IDAC registers
*
* \details
*   This function configures the IDAC modes depend on Compensation IDAC
*   enabled or disabled.
*
*******************************************************************************/
static void CapSense_SsCSDConfigIDACs(void)
{
    #if (CapSense_ENABLE == CapSense_CSDV2)
        CY_SET_REG32(CapSense_CSD_IDACA_PTR, CapSense_IDAC_MOD_DEFAULT_CFG);
        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            CY_SET_REG32(CapSense_CSD_IDACB_PTR, CapSense_IDAC_COMP_DEFAULT_CFG);
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */
    #else
        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            CY_SET_REG32(CapSense_IDAC_PTR, CapSense_DEFAULT_CSD_IDAC_CONFIG);
        #else
            CY_SET_REG32(CapSense_IDAC_PTR, CY_GET_REG32(CapSense_IDAC_PTR) &
                                                                ~(CapSense_IDAC_MOD_MODE_MASK |
                                                                  CapSense_IDAC_MOD_MASK));
            CY_SET_REG32(CapSense_IDAC_PTR, CY_GET_REG32(CapSense_IDAC_PTR) |
                                                                 CapSense_DEFAULT_CSD_IDAC_CONFIG);
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}


/*******************************************************************************
* Function Name: CapSense_SsCSDInitialize
****************************************************************************//**
*
* \brief
*   This API initializes the CSD module.
*
* \details
*   The function performs the following steps for Fourth-generation HW block:
*   1) Sets GPIO output to "0" for all sensor pins;
*   2) Connects CMOD to AMUXBUS-A and to CSDBUS-A;
*   3) Connects CMOD to (sense path) to CSDCOMP;
*   4) Connects Csh_tank to AMUXBUS-B and to CSDBUS-B;
*   5) Connects VREF to REFGEN;
*   6) Configures REFGEN and sets the reference voltage;
*   7) Connects VREF to CSDCOMP and HSCOMP;
*   8) Configures IDAC and connect to CSDBUS-A (to drive CMOD);
*   9) Configures ModClk;
*   10) Configure SnsClk source;
*   11) Sets other CSD configurations (Csd Auto Zero time,
*       Sample Init period, interrupts,
*       CMOD and Csh_tank/shield initialization switch resistance).
*
*   The function performs the following steps for Third-generation HW block:
*   1) Sets all the sensors to the inactive state;
*   2) Enables Shield Electrodes;
*   3) Configures the CSD block and IDACs;
*   4) Connects Cmod to AMUXBUS-A;
*   5) Enables the clocks;
*   6) Sets the shield delay;
*   7) Enables the CSD block; connects Vref Buffer to the AMUX bus.
*
*******************************************************************************/
void CapSense_SsCSDInitialize(void)
{
    #if (CapSense_ENABLE == CapSense_CSDV2)
        uint32 newRegValue;
    #endif

    /* Set all the sensors to inactive state */
    if(CapSense_dsRam.scanCurrentISC != CapSense_dsRam.scanCsdISC)
    {
        CapSense_SsSetAllIOsState((uint32)CapSense_dsRam.scanCsdISC);
        CapSense_dsRam.scanCurrentISC = CapSense_dsRam.scanCsdISC;
    }

    #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
        /* Connect shields to AMUX-B bus (config HSIOM regs) */
        #if (0u != CapSense_CSD_TOTAL_SHIELD_COUNT)
            CapSense_SsCSDEnableShieldElectrodes();
        #endif /* (0u != CapSense_CSD_TOTAL_SHIELD_COUNT) */

        #if (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN)
            /* Configure Csh */
            CapSense_SsCSDEnableShieldTank();
        #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN) */
    #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

    #if (CapSense_ENABLE == CapSense_CSDV2)

        CapSense_DischargeExtCapacitors(CapSense_EXT_CAP_DISCHARGE_TIME);

        /* Initialize the unused CSD registers to defaut state */
        CY_SET_REG32(CapSense_SENSE_DUTY_PTR, CapSense_DEFAULT_SENSE_DUTY_SEL);

        /* Configure VREF */
        newRegValue = CY_GET_REG32(CapSense_SW_REFGEN_SEL_PTR);
        newRegValue |= CapSense_DEFAULT_SW_REFGEN_SEL;

        CY_SET_REG32(CapSense_SW_REFGEN_SEL_PTR, newRegValue);
        CY_SET_REG32(CapSense_INTR_SET_PTR,         CapSense_DEFAULT_CSD_INTR_SET);
        CY_SET_REG32(CapSense_SW_FW_TANK_SEL_PTR,   CapSense_DEFAULT_CSD_SW_FW_TANK_SEL);
        CY_SET_REG32(CapSense_SW_DSI_SEL_PTR,       CapSense_DEFAULT_CSD_SW_DSI_SEL);
        CY_SET_REG32(CapSense_ADC_CTL_PTR,          CapSense_DEFAULT_CSD_ADC_CTL);
        CY_SET_REG32(CapSense_AMBUF_PTR,            CapSense_AMBUF_PWR_MODE_OFF);
        CY_SET_REG32(CapSense_SW_SHIELD_SEL_PTR,    CapSense_DEFAULT_SW_SHIELD_SEL);
        CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR,      CapSense_DEFAULT_SW_HS_P_SEL);
        CY_SET_REG32(CapSense_SW_HS_N_SEL_PTR,      CapSense_DEFAULT_SW_HS_N_SEL);
        CY_SET_REG32(CapSense_HSCMP_PTR,            CapSense_DEFAULT_HSCMP_CFG);

        /* Connect CMOD to AMUXBUS-A */
        CapSense_WriteBitsSafe(CapSense_CMOD_HSIOM_PTR, CapSense_CMOD_HSIOM_MASK,
                    (uint32)(CapSense_HSIOM_SEL_AMUXA << CapSense_CMOD_HSIOM_SHIFT));

        /* Set output port register to 0 to connect to GND */
        CapSense_WriteBitsSafe(CapSense_CMOD_DR_PTR, CapSense_Cmod__0__MASK, 0u);

        /* Connect AMUXBUS-A to CSDBUS-A */
        newRegValue = CY_GET_REG32(CapSense_SW_BYP_SEL_PTR);
        newRegValue |= CapSense_SW_BYP_SEL_SW_BYA_MASK;
        CY_SET_REG32(CapSense_SW_BYP_SEL_PTR, newRegValue);

        /* Connect CMOD to (sense path) to CSDCOMP */
        #if (CapSense_CSD__CMOD_PAD == CapSense_CMOD_CONNECTION)
            CY_SET_REG32(CapSense_SW_CMP_P_SEL_PTR, CapSense_SW_CMP_P_SEL_SW_SFPM_STATIC_CLOSE);
        #elif (CapSense_CSD__CSHIELD_PAD == CapSense_CMOD_CONNECTION)
            CY_SET_REG32(CapSense_SW_CMP_P_SEL_PTR, CapSense_SW_CMP_P_SEL_SW_SFPS_STATIC_CLOSE);
        #else
            CY_SET_REG32(CapSense_SW_CMP_P_SEL_PTR, CapSense_SW_CMP_P_SEL_SW_SFPT_STATIC_CLOSE);
        #endif /* (CapSense_CSD__CMOD_PAD == CapSense_CMOD_CONNECTION) */

        /* Configure shield driving path */
        #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
            /* Connect AMUXBUS-B to CSDBUS-B (and AMUXBUS-A to CSDBUS-A ) */
            CY_SET_REG32(CapSense_SW_BYP_SEL_PTR, CapSense_SW_BYP_SEL_SW_BYA_MASK | CapSense_SW_BYP_SEL_SW_BYB_MASK);

            /* Connect AMUXBUS-B to HSCMP positive input */
            CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR, 0x00000000uL);
        #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

        /* Configure VREF */
        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            /* Connect VREF to REFGEN. Connect IDACB to CSDBUSA */
            newRegValue = CY_GET_REG32(CapSense_SW_REFGEN_SEL_PTR);
            newRegValue |= CapSense_SW_REFGEN_SEL_SW_SGR_MASK | CapSense_SW_REFGEN_SEL_SW_IAIB_MASK;
            CY_SET_REG32(CapSense_SW_REFGEN_SEL_PTR, newRegValue);
        #else
            /* Connect VREF to REFGEN (IAIB switch is open) */
            newRegValue = CY_GET_REG32(CapSense_SW_REFGEN_SEL_PTR);
            newRegValue |= CapSense_SW_REFGEN_SEL_SW_SGR_MASK;
            CY_SET_REG32(CapSense_SW_REFGEN_SEL_PTR, newRegValue);
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

        /* Connect VREFHI (from RefGen) to CSDCOMP when Vdda >= 2 V */
        CY_SET_REG32(CapSense_SW_CMP_N_SEL_PTR, CapSense_SW_CMP_N_SEL_SW_SCRH_STATIC_CLOSE);

        #if (CapSense_2000_MV > CapSense_CYDEV_VDDA_MV)

            /* Configure REFGEN. Set reference voltage when Vdda < 2 V */
            CY_SET_REG32(CapSense_REFGEN_PTR, CapSense_REFGEN_LV);

            /* Connect Vrefhi to AMUBUF positive input when Vdaa < 2V
             *  Connect AMUBUF to SCDCMP negative input when Vdaa < 2V
             */
            #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
                #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
                    CY_SET_REG32(CapSense_SW_AMUXBUF_SEL_PTR, CapSense_SW_AMUXBUF_SEL_SW_IRH_STATIC_CLOSE |
                                                                          CapSense_SW_AMUXBUF_SEL_SW_ICB_PHI2);
                #else
                    CY_SET_REG32(CapSense_SW_AMUXBUF_SEL_PTR, CapSense_SW_AMUXBUF_SEL_SW_DEFAULT);
                #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */
                CY_SET_REG32(CapSense_AMBUF_PTR, CapSense_AMBUF_PWR_MODE_NORM);
            #else
                CY_SET_REG32(CapSense_AMBUF_PTR, CapSense_AMBUF_PWR_MODE_OFF);
            #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

            /* Connect VREFHI to HSCOMP */
            CY_SET_REG32(CapSense_SW_HS_N_SEL_PTR, CapSense_SW_HS_N_SEL_SW_HCRH_STATIC_CLOSE);
        #else

            /* Configure REFGEN. Set reference voltage when Vdda >= 2 V */
            CY_SET_REG32(CapSense_REFGEN_PTR, CapSense_REFGEN_HV);

            #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
                /* Turn on CSD_AMBUF high power level when Vdaa >= 2V */
                CY_SET_REG32(CapSense_AMBUF_PTR, CapSense_AMBUF_PWR_MODE_HI);

                #if (CapSense_IDAC_SINKING != CapSense_CSD_IDAC_CONFIG)
                    CY_SET_REG32(CapSense_SW_AMUXBUF_SEL_PTR, CapSense_SW_AMUXBUF_SEL_SW_IRH_STATIC_CLOSE |
                                                                          CapSense_SW_AMUXBUF_SEL_SW_ICB_PHI2);
                #else
                    CY_SET_REG32(CapSense_SW_AMUXBUF_SEL_PTR, CapSense_SW_AMUXBUF_SEL_SW_DEFAULT);
                #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */
            #else
                CY_SET_REG32(CapSense_SW_AMUXBUF_SEL_PTR, CapSense_SW_AMUXBUF_SEL_SW_DEFAULT);
            #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

            /* Connect VREFHI to HSCOMP */
            CY_SET_REG32(CapSense_SW_HS_N_SEL_PTR, CapSense_SW_HS_N_SEL_SW_HCRH_STATIC_CLOSE);
        #endif /* (CapSense_2000_MV > CapSense_CYDEV_VDDA_MV) */

        /* Configure IDACs mode */
        CapSense_SsCSDConfigIDACs();

        /* Configure ModClk */
        CapSense_SsSetModClkClockDivider((uint32)CapSense_dsRam.modCsdClk);

        /* Set other CSD configurations */
        #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
            CapSense_SsSetShieldDelay(CapSense_CSD_SHIELD_DELAY);
        #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

        /* Configure HW block filter delay */
        CapSense_SsCSDSetFilterDelay();

        #if (CapSense_DISABLE == CapSense_BLOCK_OFF_AFTER_SCAN_EN)
            /* Enable power to sub-blocks */
            CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd |
                                                      CapSense_CONFIG_SENSE_EN_MASK |
                                                      CapSense_CONFIG_ENABLE_MASK);
        #endif /* (CapSense_ENABLE == CapSense_BLOCK_OFF_AFTER_SCAN_EN) */

        /* Set Csd Auto Zero time (set AZ_TIME bitmask) */
        CY_SET_REG32(CapSense_SEQ_TIME_PTR, CapSense_CSD_AUTO_ZERO_TIME);

        /* Select CMOD and Csh_tank/shield initialization switch resistance */
        CY_SET_REG32(CapSense_SW_RES_PTR, 0x00000000);

        /* Set the number of dummy fine initialization cycles */
        CY_SET_REG32(CapSense_SEQ_INIT_CNT_PTR, CapSense_CSD_FINE_INIT_TIME);

    #else

        /* Configure IDACs mode */
        CapSense_SsCSDConfigIDACs();

        /* Connect Cmod to AMUXBUS-A using HSIOM registers */
        CapSense_WriteBitsSafe(CapSense_CMOD_HSIOM_PTR, CapSense_CMOD_HSIOM_MASK,
                    (uint32)(CapSense_HSIOM_SEL_AMUXA << CapSense_CMOD_HSIOM_SHIFT));

        #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
            CapSense_SsSetShieldDelay(CapSense_CSD_SHIELD_DELAY);
        #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

        /* Enable CSD block. Connect Vref Buffer to AMUX bus to make sure that Cmod is charged before scanning in active mode */
        #if (CapSense_ENABLE == CapSense_BLOCK_OFF_AFTER_SCAN_EN)
            CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd);
        #else
            CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd | CapSense_CTANK_PRECHARGE_CONFIG_CSD_EN);
        #endif
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */

    #if ((CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN) &&\
         (CapSense_CLK_SOURCE_DIRECT == CapSense_CSD_SNS_CLK_SOURCE))
         /* Set clock dividers and clock source mode */
        CapSense_SsCSDConfigClock();
    #endif
}


/*******************************************************************************
* Function Name: CapSense_SsCSDElectrodeCheck
****************************************************************************//**
*
* \brief
*   Checks if electrodes were previously connected using
 * CapSense_CSDSetupWidgetExt() API and if yes disconnects them.
*
* \details
*   This function checks if CapSense_eleCsdDisconnectFlag is set.
*   If it set, the function disconnects the previously connected electrode.
*   The previous IO is contained in CapSense_curSnsIOPtr and
*   CapSense_curFlashSnsPtr contains the previous data for Ganged
*   sensors.
*
*******************************************************************************/
void CapSense_SsCSDElectrodeCheck(void)
{
    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        uint32 tempVal;
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */

    if (CapSense_ENABLE == CapSense_eleCsdDisconnectFlag)
    {
        /* Disconnect if electrodes were previous connected by CSDSetupWidgetExt() API */
        #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
            /* Check ganged sns flag  */
            if (CapSense_GANGED_SNS_MASK == (CapSense_curFlashWdgtPtr->staticConfig & CapSense_GANGED_SNS_MASK))
            {
                /* Get number of ganged pins */
                tempVal = CapSense_curFlashSnsPtr->numPins;

                /* Get IO pointer  */
                CapSense_curSnsIOPtr = &CapSense_ioList[CapSense_curFlashSnsPtr->firstPinId];

                /* Disconnect all ganged sensors */
                do
                {
                    CapSense_CSDDisconnectSns(CapSense_curSnsIOPtr);
                    CapSense_curSnsIOPtr++;
                    tempVal--;
                } while (0u != tempVal);
            }
            else
            {
                /* Disconnect ganged sensor */
                CapSense_CSDDisconnectSns(CapSense_curSnsIOPtr);
            }
        #else
            /* Disable sensor */
            CapSense_CSDDisconnectSns(CapSense_curSnsIOPtr);
        #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)  */

        CapSense_eleCsdDisconnectFlag = 0u;
    }
}


/*******************************************************************************
* Function Name: CapSense_SsCSDSetUpIdacs
****************************************************************************//**
*
* \brief
*  This internal function changes the IDACs values.
*
* \details
*  If Compensation IDAC is enabled, it updates two IDACs.
*  The Modulator IDAC is common for all the sensors of the widget.
*  The Compensation IDAC is updated for the sensor of the widget which
*  is available in the RAM_SNS_STRUCT structure.
*  If the Compensation IDAC is disabled, the function updates the Modulator IDAC
*  value only in the RAM_WD_BASE_STRUCT structure.
*
* \param
*  ptrWdgt The pointer to the RAM_WD_BASE_STRUCT structure.
*
*******************************************************************************/
void CapSense_SsCSDSetUpIdacs(CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt)
{
    uint8 interruptState;
    uint32 idacGain;

    /* Getting IDAC gain */
    idacGain = CapSense_idacGainTable[ptrWdgt->idacGainIndex].gainReg;

    #if (CapSense_ENABLE == CapSense_CSDV2)
        uint32 idacARegValue;
        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            uint32 idacBRegValue;
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

        interruptState = CyEnterCriticalSection();

        /* Get IDACA Value */
        idacARegValue = CY_GET_REG32(CapSense_CSD_IDACA_PTR);

        /* Clear IDACA value and gain */
        idacARegValue &= ~(CapSense_IDAC_MOD_VAL_MASK | CapSense_IDAC_GAIN_MASK);

        /* Set IDACA value gain */
        #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
            if (CapSense_dsFlash.wdgtArray[(CapSense_widgetIndex)].numCols <= CapSense_sensorIndex)
            {
                idacARegValue |= (uint32)ptrWdgt->rowIdacMod[CapSense_scanFreqIndex];
            }
            else
            {
                idacARegValue |= (uint32)ptrWdgt->idacMod[CapSense_scanFreqIndex];
            }
        #else
            idacARegValue |= (uint32)ptrWdgt->idacMod[CapSense_scanFreqIndex];
        #endif /* (CapSense_CSD_MATRIX_WIDGET_EN | CapSense_CSD_TOUCHPAD_WIDGET_EN) */
        idacARegValue |= idacGain;

        /* Update IDACA register with new value */
        CY_SET_REG32(CapSense_CSD_IDACA_PTR, idacARegValue);
        CyExitCriticalSection(interruptState);

        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            interruptState = CyEnterCriticalSection();
            /* Get IDACB Value */
            idacBRegValue = CY_GET_REG32(CapSense_CSD_IDACB_PTR);

            /* Clear IDACB value and gain */
            idacBRegValue &= ~(CapSense_IDAC_COMP_VAL_MASK | CapSense_IDAC_GAIN_MASK);

            /* Set IDACB value and gain */
            idacBRegValue |= (uint32)CapSense_curRamSnsPtr->idacComp[CapSense_scanFreqIndex];
            idacBRegValue |= idacGain;

            /* Update IDACA register with new value */
            CY_SET_REG32(CapSense_CSD_IDACB_PTR, idacBRegValue);
            CyExitCriticalSection(interruptState);
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

    #else

        uint32 newRegValue;
        uint8 const *ptrIdacMod = ptrWdgt->idacMod;

        #if (CapSense_CSD_MATRIX_WIDGET_EN  | CapSense_CSD_TOUCHPAD_WIDGET_EN)
            if (CapSense_dsFlash.wdgtArray[(CapSense_widgetIndex)].numCols <= CapSense_sensorIndex)
            {
                ptrIdacMod = &ptrWdgt->rowIdacMod[0u];
            }
        #endif /* (CapSense_CSD_MATRIX_WIDGET_EN  | CapSense_CSD_TOUCHPAD_WIDGET_EN) */

        interruptState = CyEnterCriticalSection();

        /* Get Idac Value */
        newRegValue = CY_GET_REG32(CapSense_IDAC_PTR);

        /* Clear Idac value and gain */
        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            newRegValue &= ~(CapSense_IDAC_MOD_MASK | CapSense_IDAC_COMP_MASK |
                CapSense_IDAC_GAIN_MASK | (CapSense_IDAC_GAIN_MASK << CapSense_IDAC_COMP_DATA_OFFSET));
        #else
            newRegValue &= ~(CapSense_IDAC_MOD_MASK | CapSense_IDAC_GAIN_MASK);
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */

        /* Set Idac value and gain */
        #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
            newRegValue |= (ptrIdacMod[CapSense_scanFreqIndex] |
                           (uint32)((uint32)CapSense_curRamSnsPtr->idacComp[CapSense_scanFreqIndex] <<
                           CapSense_IDAC_COMP_DATA_OFFSET));
            newRegValue |= idacGain;
            newRegValue |= (idacGain << CapSense_IDAC_COMP_DATA_OFFSET);
        #else
            newRegValue |= ptrIdacMod[CapSense_scanFreqIndex];
            newRegValue |= idacGain;
        #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN) */
        CY_SET_REG32(CapSense_IDAC_PTR, newRegValue);

        CyExitCriticalSection(interruptState);

    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}


#if (CapSense_ENABLE == CapSense_CSDV2)
    /*******************************************************************************
    * Function Name: CapSense_SsCSDGetNumberOfConversions
    ****************************************************************************//**
    *
    * \brief
    *  This function gets Number of conversions.
    *
    * \details
    *  This function gets Number of conversions using foll.owing equation:
    *   conversionsNum = (2^resolution - 1) / snsClkDivider.
    *
    * \param
    *  snsClkDivider The divider value for the sense clock.
    *  resolution The widget resolution.
    *  snsClkSrc The current Sense Clock Source.
    *
    * \return Returns the Number of conversions.
    *
    *******************************************************************************/
    uint32 CapSense_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc)
    {
        uint32 conversionsNum;
        #if ((CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) && (CapSense_ENABLE != CapSense_CSDV2_REF9P6UA_EN))
            uint32 sampleClkFreqHz;
        #endif /* ((CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) && (CapSense_ENABLE != CapSense_CSDV2_REF9P6UA_EN)) */

        /* Calculate scanning resolution value in register */
        conversionsNum = (uint32)(1uL << resolution);

        #if(CapSense_ENABLE != CapSense_CSDV2_REF9P6UA_EN)
            /* Apply correction to oveflow for 16 bit resolution */
            if (CapSense_RES16BIT == resolution)
            {
                conversionsNum -= ((snsClkDivider + 1u) >> 1u);

                #if (CapSense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
                    sampleClkFreqHz = CYDEV_BCLK__HFCLK__HZ / (uint32)CapSense_dsRam.modCsdClk;

                    if (sampleClkFreqHz <= CapSense_MOD_CSD_CLK_12MHZ)
                    {
                        conversionsNum -= CapSense_CONFIG_FILTER_DELAY_2_CYCLES;
                    }
                    else if (sampleClkFreqHz <= CapSense_MOD_CSD_CLK_24MHZ)
                    {
                        conversionsNum -= CapSense_CONFIG_FILTER_DELAY_3_CYCLES;
                    }
                    else
                    {
                        conversionsNum -= CapSense_CONFIG_FILTER_DELAY_4_CYCLES;
                    }
                #else
                    conversionsNum -= CapSense_CONFIG_FILTER_DELAY_2_CYCLES;
                #endif /* (INSTANCE_NAME`_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */
            }
        #else
            /* CY_ID285392: Apply correction to oveflow for 16 bit resolution */
            if (CapSense_RES16BIT == resolution)
            {
                conversionsNum -= CapSense_EXTRA_COUNTS_MAX;
            }
        #endif

        if (0u < snsClkDivider)
        {
            conversionsNum /= snsClkDivider;
        }

    #if((CapSense_CLK_SOURCE_PRS8  == CapSense_CSD_SNS_CLK_SOURCE) ||\
        (CapSense_CLK_SOURCE_PRS12 == CapSense_CSD_SNS_CLK_SOURCE) ||\
        (CapSense_CLK_SOURCE_PRSAUTO == CapSense_CSD_SNS_CLK_SOURCE))
        switch (snsClkSrc)
        {
            case CapSense_CLK_SOURCE_PRS8:
            case CapSense_CLK_SOURCE_PRS12:
                /* Divide by 2 for PRS8/PRS12 mode */
                conversionsNum >>= 1u;
                break;

            default:
                break;
        }
    #else
        (void)snsClkSrc;
    #endif

    return((conversionsNum > 0uL) ? (conversionsNum) : 1uL);
    }
#endif /* (CapSense_ENABLE == CapSense_CSDV2) */


/*******************************************************************************
* Function Name: CapSense_SsCSDConfigClock
****************************************************************************//**
*
* \brief
*  This function configure sense clock for different modes.
*
* \details
*  Function sets the clock divider and configures the mode based on configuration.
*
*******************************************************************************/
void CapSense_SsCSDConfigClock(void)
{
    uint32 snsClkDivider;
    uint32 snsClkSrc;
    uint32 newRegValue;

    CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt = (CapSense_RAM_WD_BASE_STRUCT *)
             CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2WdgtRam;

    /* Get sense divider based on configuration */
    #if (CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN)
        snsClkDivider = (uint32)CapSense_dsRam.snsCsdClk;
    #else
        #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
            /* Get SnsClck divider for rows or columns */
            if (CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].numCols <= CapSense_sensorIndex)
            {
                snsClkDivider = (uint32)(ptrWdgt->rowSnsClk);
            }
            else
            {
                snsClkDivider = (uint32)(ptrWdgt->snsClk);
            }
        #else
            snsClkDivider = (uint32)(ptrWdgt->snsClk);
        #endif /* (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN) */
    #endif /* (CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN) */

    /* Get sense clk source calculated in CapSense_SsCSDInitialize() before */
    #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
        /* Get SnsClc Source for rows or columns */
        if (CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].numCols <= CapSense_sensorIndex)
        {
            snsClkSrc = (uint32)ptrWdgt->rowSnsClkSource;
        }
        else
        {
            snsClkSrc = (uint32)ptrWdgt->snsClkSource;
        }
    #else
        snsClkSrc = (uint32)ptrWdgt->snsClkSource;
    #endif /* (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN) */

    #if (CapSense_ENABLE == CapSense_CSDV2)
        newRegValue = (snsClkSrc << CYFLD_CSD_LFSR_SIZE__OFFSET);

        /* Configuring PRS SEL_BIT */
        if ((CapSense_CLK_SOURCE_PRS8 == snsClkSrc) ||
            (CapSense_CLK_SOURCE_PRS12 == snsClkSrc))
        {
            newRegValue |= CapSense_SENSE_PERIOD_SEL_LFSR_MSB_MASK;
        }
    #else
        newRegValue = snsClkSrc;
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */

    #if (CapSense_ENABLE == CapSense_CSDV2)
        #if((CapSense_CLK_SOURCE_PRS8  == CapSense_CSD_SNS_CLK_SOURCE) ||\
            (CapSense_CLK_SOURCE_PRS12 == CapSense_CSD_SNS_CLK_SOURCE) ||\
            (CapSense_CLK_SOURCE_PRSAUTO == CapSense_CSD_SNS_CLK_SOURCE))
            switch (snsClkSrc)
            {
            case CapSense_CLK_SOURCE_PRS8:
            case CapSense_CLK_SOURCE_PRS12:
                /* Divide by 2 for PRS8/PRS12 mode */
                snsClkDivider >>= 1;
                if (snsClkDivider == 0u)
                {
                    snsClkDivider = 1u;
                }
                break;

            default:
                break;
            }
        #endif /* ((CapSense_CLK_SOURCE_PRS8  == CapSense_CSD_SNS_CLK_SOURCE) ||\
                   (CapSense_CLK_SOURCE_PRS12 == CapSense_CSD_SNS_CLK_SOURCE) ||\
                   (CapSense_CLK_SOURCE_PRSAUTO == CapSense_CSD_SNS_CLK_SOURCE)) */
    #endif
    CapSense_SsCSDSetModeSnsClockDivider(newRegValue, snsClkDivider);
}


/*******************************************************************************
* Function Name: CapSense_SsCSDCalculateScanDuration
****************************************************************************//**
*
* \brief
*   Calculates Scan Duration which is defined by scan resolution
*
* \details
*   For Fourth-generation HW block: The function calculates the number of conversions and updates
*   SEQ_NORM_CNT register. The number of conversions depends on resolution and
*   snsClk divider.
*   For Third-generation HW block: The function recalculate the resolution using following equation:
*   2^resolution - 1. The calculated value is contained in
*   CapSense_counterResolution global variable and used in
*   CapSense_SsCSDStartSample() function to trigger the scan process.
*
* \param wdgtIndex
*  ptrWdgt The pointer to the RAM_WD_BASE_STRUCT structure.
*
*******************************************************************************/
void CapSense_SsCSDCalculateScanDuration(CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt)
{
    #if (CapSense_ENABLE == CapSense_CSDV2)
        uint32 conversionsNum;
        uint32 snsClkDivider;

        /* Get Number Of Conversions */
        #if (CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN)
            snsClkDivider = CapSense_dsRam.snsCsdClk;
        #else
            #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
                /* Get SnsClck divider for rows or columns */
                if (CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].numCols <= CapSense_sensorIndex)
                {
                    snsClkDivider = (uint32)(ptrWdgt->rowSnsClk);
                }
                else
                {
                    snsClkDivider = (uint32)(ptrWdgt->snsClk);
                }
            #else
                snsClkDivider = (uint32)(ptrWdgt->snsClk);
            #endif /* (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN) */
        #endif /* (CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN) */

        conversionsNum = CapSense_SsCSDGetNumberOfConversions(snsClkDivider, (uint32)ptrWdgt->resolution, (uint32)ptrWdgt->snsClkSource);

        /* Set Number Of Conversions based on scanning resolution */
        CY_SET_REG32(CapSense_SEQ_NORM_CNT_PTR, (conversionsNum & CapSense_SEQ_NORM_CNT_CONV_CNT_MASK));
    #else
        /* Set up scanning resolution  */
        CapSense_counterResolution = (uint32)((0x00000001Lu << ptrWdgt->resolution) - 1u) << CapSense_RESOLUTION_OFFSET;
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}


/*******************************************************************************
* Function Name: CapSense_CSDSetupWidget
****************************************************************************//**
*
* \brief
*  Performs hardware and firmware initialization required for scanning sensors
*  in a specific widget using the CSD sensing method. This function requires using
*  the CapSense_CSDScan() function to start scanning.
*
* \details
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_SetupWidget() function should be used instead.
*
*  This function initializes the specific widget common parameters to perform
*  the CSD scanning. The initialization includes setting up a Modulator and
*  Sense clock frequency and scanning resolution.
*
*  This function does not connect any specific sensors to the scanning hardware,
*  neither does it start a scanning process. The CapSense_CSDScan()
*  API must be called after initializing the widget to start scanning.
*
*  This function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status.
*
*  This function is called by the CapSense_SetupWidget() API if the
*  given widget uses the CSD sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
* \param  widgetId
*  Specifies the ID number of the widget to perform hardware and firmware
*  initialization required for scanning sensors in the specific widget.
*  A macro for the widget ID can be found in the CapSense Configuration header
*  file defined as CapSense_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void CapSense_CSDSetupWidget(uint32 widgetId)
{
    CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt = (CapSense_RAM_WD_BASE_STRUCT *)
                                                CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;

    /* Save widget Id to have assess to it after scanning  */
    CapSense_widgetIndex = (uint8)widgetId;

    CapSense_SsSwitchSensingMode(CapSense_SENSE_METHOD_CSD_E);

    #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
        /* Reset the frequency scan channel if enabled */
        CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;
    #endif /* (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN) */

    /* Disconnect previous electrode if it has been connected */
    CapSense_SsCSDElectrodeCheck();

    /* Initialize IO Sns electrode structure pointer to current widget */
    CapSense_curSnsIOPtr = (CapSense_FLASH_IO_STRUCT const *)
                                    CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2SnsFlash;

    /* Update status register in Data structure */
    CapSense_dsRam.status &= ~CapSense_STATUS_WDGT0_MASK;
    CapSense_dsRam.status |= CapSense_widgetIndex;

    CapSense_SsCSDCalculateScanDuration(ptrWdgt);
    #if (((CapSense_DISABLE == CapSense_CSD_COMMON_SNS_CLK_EN) || \
          (CapSense_CLK_SOURCE_DIRECT != CapSense_CSD_SNS_CLK_SOURCE)) && \
         ((!(CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)) || \
          (CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN)))
        CapSense_SsCSDConfigClock();
    #endif
}


/*******************************************************************************
* Function Name: CapSense_CSDSetupWidgetExt
****************************************************************************//**
*
* \brief
*  Performs extended initialization for the CSD widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the CapSense_CSDScanExt() function to initiate a scan.
*
* \details
*  Performs extended initialization for the CSD widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the CapSense_CSDScanExt() function to initiate a scan.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_SetupWidgetExt() function should be used instead.
*
*  This function does the same as CapSense_CSDSetupWidget() and also
*  does the following tasks:
*    1. Connects the first sensor of the widget.
*    2. Configures the IDAC value.
*    3. Initializes an interrupt callback function to initialize a scan of the
*  next sensors in a widget.
*
*  Once this function is called to initialize a widget and a sensor, the
*  CapSense_CSDScanExt() function is called to scan the sensor.
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
*  initialization required for scanning the specific sensor in the specific
*  widget.
*  A macro for the widget ID can be found in the CapSense Configuration header
*  file defined as CapSense_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to perform hardware
*  and firmware initialization required for scanning a specific sensor in a
*  specific widget.
*  A macro for the sensor ID within a specified widget can be found in the
*  CapSense Configuration header file defined as
*  CapSense_<WidgetName>_SNS<SensorNumber>_ID
*
*******************************************************************************/
void CapSense_CSDSetupWidgetExt(uint32 widgetId, uint32 sensorId)
{
    CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt = (CapSense_RAM_WD_BASE_STRUCT *)
                                                    CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;

    /* Save widget and sensor Ids to have access to it after scanning  */
    CapSense_sensorIndex = (uint8)sensorId;

    /* Update global pointer to CapSense_RAM_SNS_STRUCT to current sensor  */
    CapSense_curRamSnsPtr = (CapSense_RAM_SNS_STRUCT *)
                                              CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsRam
                                              + CapSense_sensorIndex;

    CapSense_CSDSetupWidget(widgetId);

     /* Setup Idac Value */
    CapSense_SsCSDSetUpIdacs(ptrWdgt);

    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        /* initialize access pointers for current pointer to widget configuration in Flash */
        CapSense_curFlashWdgtPtr = &CapSense_dsFlash.wdgtArray[widgetId];
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)  */

    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        CapSense_SsCSDConnectSensorExt(widgetId, sensorId);
    #else
        /* Enable sensor */
        CapSense_curSnsIOPtr += CapSense_sensorIndex;
        CapSense_CSDConnectSns(CapSense_curSnsIOPtr);
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)  */

    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        /* Save sns pointer */
        CapSense_curFlashSnsPtr = (CapSense_FLASH_SNS_STRUCT const *)
                                           CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2SnsFlash +
                                           CapSense_sensorIndex;
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */

    CapSense_eleCsdDisconnectFlag = CapSense_DISCONNECT_IO_FLAG;

    /* Setup ISR handler to single-sensor scan function */
    CapSense_ISR_StartEx(&CapSense_CSDPostSingleScan);
}

/*******************************************************************************
* Function Name: CapSense_SsCSDStartSample
****************************************************************************//**
*
* \brief
*   Starts the CSD conversion.
*
* \details
*   This function assumes that the CSD block is already set up using
*   the CapSense_CSDSetupWidget API and the sensor port-pin is connected to the CSD
*   block using CapSense_CSDConnectSns.
*   For Third-generation HW block the function performs the following tasks:
*   1. Disconnects the Vref buffer from AMUX;
*   2. Precharges Cmod;
*   3. Makes the PreSettling delay to have a stable Vref voltage;
*   4. Sets the resolution to the Counter register to start scanning.
*
*******************************************************************************/
void CapSense_SsCSDStartSample(void)
{
    #if (CapSense_ENABLE != CapSense_CSDV2)
        uint8 interruptState;
    #endif

    #ifdef CapSense_START_SAMPLE_CALLBACK
        CapSense_StartSampleCallback(CapSense_widgetIndex, CapSense_sensorIndex);
    #endif /* CapSense_START_SAMPLE_CALLBACK */

    #if (CapSense_ENABLE == CapSense_CSDV2)
        /* Fourth-generation HW block section */

        /* Disable CSD interrupt to prevent it during coarse initialization */
        CyIntDisable(CapSense_ISR_NUMBER);

        /* Enable power to sub-blocks */
        CY_SET_REG32(CapSense_HSCMP_PTR, CapSense_HSCMP_INIT_MASK);

        #if (CapSense_ENABLE == CapSense_BLOCK_OFF_AFTER_SCAN_EN)
            CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd |
                                                      CapSense_CONFIG_SENSE_EN_MASK |
                                                      CapSense_CONFIG_ENABLE_MASK);
            #if(CapSense_CSD_ANALOG_STARTUP_DELAY_US > 0uL)
                CyDelayUs(CapSense_CSD_ANALOG_STARTUP_DELAY_US);
            #endif /* (CapSense_CSD_ANALOG_STARTUP_DELAY_US > 0uL) */
        #endif /* (CapSense_ENABLE == CapSense_BLOCK_OFF_AFTER_SCAN_EN) */

        /* Precharging Cmod and Csh */
        CapSense_SsCSDCmodPrecharge();

        /* Trigger Scan */
        CapSense_SsCSDTriggerScan();

    #else
        /* Third-generation HW block section */
        interruptState = CyEnterCriticalSection();

        /* Enable CSD block. Disconnect Vref Buffer from AMUX */
        #if ((CapSense_CSH_PRECHARGE_IO_BUF == CapSense_CSD_CSH_PRECHARGE_SRC) &&\
             (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN))
            CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd | CapSense_CMOD_PRECHARGE_CONFIG_CSD_EN);
        #else
            CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd | CapSense_CTANK_PRECHARGE_CONFIG_CSD_EN);
        #endif

        /* Restart the clocks. Scan one cycle to reset the flip-flop for Direct clock mode */
        CapSense_SsCSDClockRestart();

        /* Precharging Cmod to Vref */
        CapSense_SsCSDCmodPrecharge();

        #if (CapSense_CLK_SOURCE_DIRECT != CapSense_CSD_SNS_CLK_SOURCE)
            /* Set PreSettling delay to skip IDAC glitch before scanning */
            CyDelayCycles(CapSense_GLITCH_ELIMINATION_CYCLES);
        #endif /* (CapSense_CSD_SNS_CLK_SOURCE != CapSense_CLK_SOURCE_DIRECT) */

        /* Trigger Scan */
        CapSense_SsCSDTriggerScan();

        CyExitCriticalSection(interruptState);
    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}


/*******************************************************************************
* Function Name: CapSense_CSDScanExt
****************************************************************************//**
*
* \brief
*  Starts the CSD conversion on the preconfigured sensor. This function requires
*  using the CapSense_CSDSetupWidgetExt() function to set up the a
*  widget.
*
* \details
*  Starts the CSD conversion on the preconfigured sensor. This function requires
*  using the CapSense_CSDSetupWidgetExt() function to set up the a
*  widget.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_ScanExt() function should be used instead.
*
*  This function performs single scanning of one sensor in the widget configured
*  by the CapSense_CSDSetupWidgetExt() function. It does the following
*  tasks:
*    1. Sets the busy flag in the CapSense_dsRam structure.
*    2. Performs the clock-phase alignment of the sense and modulator clocks.
*    3. Performs the Cmod pre-charging.
*    4. Starts single scanning.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*  This function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status.
*
*  The sensor must be preconfigured by using the
*  CapSense_CSDSetupWidgetExt() API prior to calling this function.
*  The sensor remains ready for a next scan if a previous scan was triggered
*  by using the CapSense_CSDScanExt() function. In this case, calling
*  CapSense_CSDSetupWidgetExt() is not required every time before the
*  CapSense_CSDScanExt() function. If a previous scan was triggered in
*  any other way - CapSense_Scan(), CapSense_ScanAllWidgets() or
*  CapSense_RunTuner() - (see the CapSense_RunTuner() function
*  description for more details), the sensor must be preconfigured again by
*  using the CapSense_CSDSetupWidgetExt() API prior to calling the
*  CapSense_CSDScanExt() function.
*
*  If disconnection of the sensors is required after calling
*  CapSense_CSDScanExt(), the CapSense_CSDDisconnectSns()
*  function can be used.
*
*******************************************************************************/
void CapSense_CSDScanExt(void)
{
    #if ((CapSense_DISABLE == CapSense_CSD_COMMON_SNS_CLK_EN) && \
         (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN))
        CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt = (CapSense_RAM_WD_BASE_STRUCT *)
                                                        CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2WdgtRam;

        CapSense_SsCSDCalculateScanDuration(ptrWdgt);
        CapSense_SsCSDConfigClock();
    #endif

    /* Set Start of sensor scan flag */
    CapSense_dsRam.status |= (CapSense_SW_STS_BUSY | CapSense_WDGT_SW_STS_BUSY);

    #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
        /* Reset the frequency scan channel if enabled */
        CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;
    #endif /* (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN) */

    #if (CapSense_ENABLE != CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
        (CapSense_ENABLE == CapSense_CSDV2)
        #if(CapSense_CSD_ANALOG_STARTUP_DELAY_US > 0uL)
            CyDelayUs(CapSense_CSD_ANALOG_STARTUP_DELAY_US);
        #endif /* (CapSense_CSD_ANALOG_STARTUP_DELAY_US > 0uL) */
    #endif /* (CapSense_ENABLE != CapSense_BLOCK_OFF_AFTER_SCAN_EN) &&\
              (CapSense_ENABLE == CapSense_CSDV2)*/

    CapSense_SsCSDStartSample();
}


/*******************************************************************************
* Function Name: CapSense_CSDScan
****************************************************************************//**
*
* \brief
*  This function initiates a scan for the sensors of the widget initialized by the
*  CapSense_CSDSetupWidget() function.
*
* \details
*  This function initiates a scan for the sensors of the widget initialized by the
*  CapSense_CSDSetupWidget() function.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The CapSense_Scan() function should be used instead.
*
*  This function performs scanning of all the sensors in the widget configured by
*  the CapSense_CSDSetupWidget() function. It does the following tasks:
*    1. Connects the first sensor of the widget.
*    2. Configures the IDAC value.
*    3. Initializes the interrupt callback function to initialize a scan of
*       the next sensors in a widget.
*    4. Starts scanning for the first sensor in the widget.
*
*  This function is called by the CapSense_Scan() API if the given
*  widget uses the CSD sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
*  This function is called when no scanning is in progress. I.e.
*  CapSense_IsBusy() returns a non-busy status. The widget must be
*  preconfigured by the CapSense_CSDSetupWidget() function if any other
*  widget was previously scanned or any other type of the scan functions was used.
*
*******************************************************************************/
void CapSense_CSDScan(void)
{
    CapSense_RAM_WD_BASE_STRUCT const *ptrWdgt = (CapSense_RAM_WD_BASE_STRUCT *)
                                                    CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2WdgtRam;

    /* Set all the sensors to inactive state */
    if(CapSense_dsRam.scanCurrentISC != CapSense_dsRam.scanCsdISC)
    {
        CapSense_SsSetAllIOsState((uint32)CapSense_dsRam.scanCsdISC);
        CapSense_dsRam.scanCurrentISC = CapSense_dsRam.scanCsdISC;
    }

     /*
      * Update CapSense_sensorIndex with the first sensor in
      * widget to use it in ISR handler to configure the next sensor
      */
    CapSense_sensorIndex = 0u;

    /* Update global pointer to CapSense_RAM_SNS_STRUCT to current sensor  */
    CapSense_curRamSnsPtr = (CapSense_RAM_SNS_STRUCT *)
                                              CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2SnsRam
                                              + CapSense_sensorIndex;

    #if (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN)
        /* Reset the frequency scan channel if enabled */
        CapSense_scanFreqIndex = CapSense_FREQ_CHANNEL_0;
    #endif /* (CapSense_ENABLE == CapSense_MULTI_FREQ_SCAN_EN) */

    /* Setup Idac Value */
   CapSense_SsCSDSetUpIdacs(ptrWdgt);

    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if (CapSense_GANGED_SNS_MASK == (CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].staticConfig &
            CapSense_GANGED_SNS_MASK))
        {
            /* Setup ISR handler to multiple-sensor scan function with ganged sensors */
            CapSense_ISR_StartEx(&CapSense_CSDPostMultiScanGanged);
        }
        else
        {
            /* Set up ISR handler to multiple-sensor scan function without ganged sensors */
            CapSense_ISR_StartEx(&CapSense_CSDPostMultiScan);
        }

        CapSense_SsCSDConnectSensorExt((uint32)CapSense_widgetIndex, (uint32)CapSense_sensorIndex);
    #else
        /* initialize ptr to sensor IO structure to appropriate address */
        CapSense_curSnsIOPtr = (CapSense_FLASH_IO_STRUCT const *)
                                        CapSense_dsFlash.wdgtArray[CapSense_widgetIndex].ptr2SnsFlash
                                        + CapSense_sensorIndex;

        /* Enable sensor */
        CapSense_CSDConnectSns(CapSense_curSnsIOPtr);

        /* Set-up ISR handler to multiple-sensor scan function without ganged sensors */
        CapSense_ISR_StartEx(&CapSense_CSDPostMultiScan);
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)  */

    /* Start scanning */
    CapSense_CSDScanExt();
}


/*******************************************************************************
* Function Name: CapSense_SsCSDConnectSensorExt
****************************************************************************//**
*
* \brief
*  Connects a ganged sensor port-pin to the sensing HW block via the AMUX bus.
*
* \details
*   The function gets the IO configuration registers addresses, their shifts and
*   masks from the FLASH_IO_STRUCT object. Basing on this data, it updates the HSIOM and
*   PC registers.
*
* \param widgetId
*  Specifies ID of the widget.
*
* \param sensorId
*  Specifies ID of the sensor in the widget.
*
*******************************************************************************/
void CapSense_SsCSDConnectSensorExt(uint32 widgetId, uint32 sensorId)
{
    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        uint32 tempVal;
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */

    /* initialize ptr to sensor IO structure to appropriate address */
    CapSense_curSnsIOPtr = (CapSense_FLASH_IO_STRUCT const *)
                                                      CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash
                                                      + sensorId;

    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if (CapSense_GANGED_SNS_MASK ==
           (CapSense_dsFlash.wdgtArray[widgetId].staticConfig &
            CapSense_GANGED_SNS_MASK))
        {
            /* Get sns pointer */
            CapSense_curFlashSnsPtr = (CapSense_FLASH_SNS_STRUCT const *)
                                               CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash +
                                               sensorId;

            /* Get number of ganged pins */
            tempVal = CapSense_curFlashSnsPtr->numPins;

            /* Get IO pointer  */
            CapSense_curSnsIOPtr = &CapSense_ioList[CapSense_curFlashSnsPtr->firstPinId];

            /* Connect all ganged sensors  */
            do
            {
                CapSense_CSDConnectSns(CapSense_curSnsIOPtr);
                CapSense_curSnsIOPtr++;
                tempVal--;
            } while (0u != tempVal);
        }
        else
        {
            /* Connect sensor */
            CapSense_CSDConnectSns(CapSense_curSnsIOPtr);
        }
    #else
        /* Connect sensor */
        CapSense_CSDConnectSns(CapSense_curSnsIOPtr);
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */
}


/*******************************************************************************
* Function Name: CapSense_SsCSDDisconnectSnsExt
****************************************************************************//**
*
* \brief
*  Disconnects a ganged sensor port-pin from the sensing HW block and AMUX bus.
*  Sets the default state of the un-scanned sensor.
*
* \details
*   The function gets the IO configuration registers addresses, their shifts and
*   masks from the FLASH_IO_STRUCT object. Basing on this data and Inactive sensor
*   connection parameter, it updates the HSIOM, PC and DR registers.
*   The HSIOM register is updated only when the Inactive sensor connection parameter
*   is set to Shield.
*
* \param widgetId
*  Specifies ID of the widget.
*
* \param sensorId
*  Specifies ID of the sensor in the widget.
*
*******************************************************************************/
void CapSense_SsCSDDisconnectSnsExt(uint32 widgetId, uint32 sensorId)
{
    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        uint32 tempVal;
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */

    /* initialize ptr to sensor IO structure to appropriate address        */
    CapSense_curSnsIOPtr = (CapSense_FLASH_IO_STRUCT const *)
                                                      CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash
                                                      + sensorId;

    #if (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if ((CapSense_dsFlash.wdgtArray[widgetId].staticConfig &
            CapSense_GANGED_SNS_MASK) == CapSense_GANGED_SNS_MASK)
        {
            /* Get sns pointer */
            CapSense_curFlashSnsPtr = (CapSense_FLASH_SNS_STRUCT const *)
                                               CapSense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash +
                                               sensorId;

            /* Get number of ganged pins */
            tempVal = CapSense_curFlashSnsPtr->numPins;

            /* Get IO pointer  */
            CapSense_curSnsIOPtr = &CapSense_ioList[CapSense_curFlashSnsPtr->firstPinId];

            /* Disconnect all ganged sensors */
            do
            {
                CapSense_CSDDisconnectSns(CapSense_curSnsIOPtr);
                CapSense_curSnsIOPtr++;
                tempVal--;
            } while (0u != tempVal);
        }
        else
        {
            /* Disconnect ganged sensor */
            CapSense_CSDDisconnectSns(CapSense_curSnsIOPtr);
        }
    #else
        /* Disconnect ganged sensor */
        CapSense_CSDDisconnectSns(CapSense_curSnsIOPtr);
    #endif /* (CapSense_ENABLE == CapSense_CSD_GANGED_SNS_EN) */
}


/*******************************************************************************
* Function Name: CapSense_CSDConnectSns
****************************************************************************//**
*
* \brief
*  Connects a port pin used by the sensor to the AMUX bus of the sensing HW block.
*
* \details
*  Connects a port pin used by the sensor to the AMUX bus of the sensing HW block
*  while a sensor is being scanned. The function ignores the fact if
*  the sensor is a ganged sensor and connects only a specified pin.
*
*  Scanning should be completed before calling this API.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases. Functions that perform a setup and scan of a sensor/widget,
*  automatically set the required pin states and perform the sensor connection.
*  They do not take into account changes in the design made by the
*  CapSense_CSDConnectSns() function.
*
* \param  snsAddrPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a sensor
*  which to be connected to the sensing HW block.
*
*******************************************************************************/
void CapSense_CSDConnectSns(CapSense_FLASH_IO_STRUCT const *snsAddrPtr)
{
    uint32 newRegisterValue;
    uint8  interruptState;
    uint32 pinModeShift;
    uint32 pinHSIOMShift;

    /* Get offsets for sensor */
    pinModeShift = (uint32)snsAddrPtr->shift;
    pinHSIOMShift = (uint32)snsAddrPtr->hsiomShift;

    interruptState = CyEnterCriticalSection();

    /* Use temporary variable to update registers without multiple writings to them */
    newRegisterValue = CY_GET_REG32(snsAddrPtr->hsiomPtr);
    newRegisterValue &= ~(CapSense_HSIOM_SEL_MASK << pinHSIOMShift);
    newRegisterValue |= (uint32)((uint32)CapSense_HSIOM_SEL_CSD_SENSE << pinHSIOMShift);

    /* Update port configuration register (drive mode) for sensor */
    CY_SET_REG32(snsAddrPtr->pcPtr, CY_GET_REG32(snsAddrPtr->pcPtr) & (uint32)~((uint32)CapSense_GPIO_PC_MASK << pinModeShift));

    /* Update HSIOM register for sensor */
    CY_SET_REG32(snsAddrPtr->hsiomPtr, newRegisterValue);

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: CapSense_CSDDisconnectSns
****************************************************************************//**
*
* \brief
*  Disconnects a sensor port pin from the sensing HW block and the AMUX bus. Sets
*  the default state of the un-scanned sensor.
*
* \details
*  This function works identically to CapSense_CSDConnectSns() except
*  it disconnects the specified port-pin used by the sensor.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases. Functions that perform a setup and scan of sensor/widget
*  automatically set the required pin states and perform the sensor connection.
*  They ignore changes in the design made by the
*  CapSense_CSDDisconnectSns() function.
*
* \param  snsAddrPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a sensor
*  which should be disconnected from the sensing HW block.
*
*******************************************************************************/
void CapSense_CSDDisconnectSns(CapSense_FLASH_IO_STRUCT const *snsAddrPtr)
{
    uint8  interruptState;
    uint32 pinHSIOMShift;
    uint32 pinModeShift;
    uint32 newPcRegValue;
    uint32 newHsiomRegValue;

    pinHSIOMShift = (uint32)snsAddrPtr->hsiomShift;
    pinModeShift = (uint32)snsAddrPtr->shift;

    interruptState = CyEnterCriticalSection();

    newPcRegValue  = CY_GET_REG32(snsAddrPtr->pcPtr);
    newPcRegValue &= ~(CapSense_GPIO_PC_MASK << pinModeShift);

    newHsiomRegValue  = CY_GET_REG32(snsAddrPtr->hsiomPtr);
    newHsiomRegValue &= ~(CapSense_HSIOM_SEL_MASK << pinHSIOMShift);
    CY_SET_REG32(snsAddrPtr->hsiomPtr, newHsiomRegValue);

    if(CapSense_SNS_CONNECTION_GROUND == CapSense_dsRam.scanCurrentISC)
    {
        newPcRegValue |= (CY_SYS_PINS_DM_STRONG << pinModeShift);
        CY_SET_REG32(snsAddrPtr->pcPtr, newPcRegValue);
    }
    else
    {
        newPcRegValue |= (CY_SYS_PINS_DM_ALG_HIZ << pinModeShift);
        if(CapSense_SNS_CONNECTION_SHIELD == CapSense_dsRam.scanCurrentISC)
        {
            /* Connect to Shield */
            newHsiomRegValue |= (CapSense_HSIOM_SEL_CSD_SHIELD << pinHSIOMShift);
            CY_SET_REG32(snsAddrPtr->pcPtr, newPcRegValue);
            CY_SET_REG32(snsAddrPtr->hsiomPtr, newHsiomRegValue);
        }
    }
    /* Set logic 0 to port data register */
    CY_SET_REG32(snsAddrPtr->drPtr, CY_GET_REG32(snsAddrPtr->drPtr) & (uint32)~(uint32)((uint32)1u << snsAddrPtr->drShift));

    CyExitCriticalSection(interruptState);
}

#if ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE) || \
     (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN))
    /*******************************************************************************
    * Function Name: CapSense_SsCSDCalibrateCheck
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
    * \param target
    *  Raw count target in percentage.
    *
    * \return Returns the status of the operation:
    *   - Zero     - All the sensors in the widget are calibrated successfully.
    *   - Non-Zero - Calibration failed for any sensor in the widget.
    *
    *******************************************************************************/
    static cystatus CapSense_SsCSDCalibrateCheck(uint32 widgetId, uint32 target)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;
        uint32 rawcount;
        uint32 snsIndex;
        uint32 freqChannel;
        uint32 upperLimit;
        uint32 lowerLimit;

        CapSense_FLASH_WD_STRUCT const *ptrFlashWidget = &CapSense_dsFlash.wdgtArray[widgetId];
        CapSense_RAM_WD_BASE_STRUCT *ptrRamWidget = (CapSense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;
        CapSense_RAM_SNS_STRUCT *ptrRamSensor = ptrFlashWidget->ptr2SnsRam;

        /* Calculate acceptable raw count range based on the resolution, target and error */
        rawcount = (0x00000001Lu << ptrRamWidget->resolution) - 1u;
        lowerLimit = 0u;
        if (target > CapSense_CSD_CALIBRATION_ERROR)
        {
            lowerLimit = target - CapSense_CSD_CALIBRATION_ERROR;
        }
        upperLimit = target + CapSense_CSD_CALIBRATION_ERROR;
        if (upperLimit > CapSense_PERCENTAGE_100)
        {
            upperLimit = CapSense_PERCENTAGE_100;
        }
        lowerLimit = (rawcount * lowerLimit) / CapSense_PERCENTAGE_100;
        upperLimit = (rawcount * upperLimit) / CapSense_PERCENTAGE_100;

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


    #if (CapSense_ENABLE == CapSense_CSD_IDAC_AUTO_GAIN_EN)
        /*******************************************************************************
        * Function Name: CapSense_SsCSDSwitchIdacGain
        ****************************************************************************//**
        *
        * \brief
        *  This internal function switches to the lower IDAC gain is possible.
        *
        * \details
        *  This internal function switches to the lower IDAC gain is possible.
        *  Conditions of switching to the lower IDAC gains:
        *  1. The current IDAC gain is not the lowest one.
        *  2. The maximum IDAC at gain switching will not be out of range.
        *  3. The minimum IDAC is still below the acceptable range.
        *
        * \param ptrFlashWidget
        *  Specifies the pointer to a widget.
        *
        * \return Returns the status of the operation:
        *   - Zero     - Gain switching is not needed.
        *   - Non-Zero - Gain was switched to the lower one.
        *
        *******************************************************************************/
        static uint32 CapSense_SsCSDSwitchIdacGain(CapSense_FLASH_WD_STRUCT const *ptrFlashWidget)
        {
            uint32 ratio;
            uint32 maxIdac;
            uint32 minIdac;
            uint32 status = 0u;
            uint32 freqChannel;
            uint32 gainIndex;

            CapSense_RAM_WD_BASE_STRUCT *ptrRamWidget = (CapSense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;
            #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
                uint32 snsIndex;
                CapSense_RAM_SNS_STRUCT *ptrRamSensor = ptrFlashWidget->ptr2SnsRam;
            #endif

            gainIndex = ptrRamWidget->idacGainIndex;

            /* Find maximum and minimum IDACs */
            maxIdac = 0u;
            minIdac = CapSense_CSD_CAL_IDAC_MAX_VALUE;
            for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                if (maxIdac < ptrRamWidget->idacMod[freqChannel])
                {
                    maxIdac = ptrRamWidget->idacMod[freqChannel];
                }
                if (minIdac > ptrRamWidget->idacMod[freqChannel])
                {
                    minIdac = ptrRamWidget->idacMod[freqChannel];
                }
                #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
                    if ((CapSense_WD_TOUCHPAD_E == CapSense_GET_WIDGET_TYPE(ptrFlashWidget)) ||
                        (CapSense_WD_MATRIX_BUTTON_E == CapSense_GET_WIDGET_TYPE(ptrFlashWidget)))
                    {
                        if (maxIdac < ptrRamWidget->rowIdacMod[freqChannel])
                        {
                            maxIdac = ptrRamWidget->rowIdacMod[freqChannel];
                        }
                        if (minIdac > ptrRamWidget->rowIdacMod[freqChannel])
                        {
                            minIdac = ptrRamWidget->rowIdacMod[freqChannel];
                        }
                    }
                #endif
            }
            #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
                for(snsIndex = 0u; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
                {
                    for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
                    {
                        if (minIdac > ptrRamSensor->idacComp[freqChannel])
                        {
                            minIdac = ptrRamSensor->idacComp[freqChannel];
                        }
                    }
                    ptrRamSensor++;
                }
            #endif

            /* Check gain switch conditions */
            if (gainIndex != 0u)
            {
                if (minIdac < CapSense_CSD_IDAC_MIN)
                {
                    ratio = CapSense_idacGainTable[gainIndex].gainValue /
                            CapSense_idacGainTable[gainIndex - 1u].gainValue;
                    if ((maxIdac * ratio) < CapSense_CSD_CAL_IDAC_MAX_VALUE)
                    {
                        /* Switch to lower idac gain */
                        ptrRamWidget->idacGainIndex--;
                        status = 1u;
                    }
                }
            }

            return (status);
        }
    #endif /* (CapSense_ENABLE == CapSense_CSD_IDAC_AUTO_GAIN_EN) */


    #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
        /*******************************************************************************
        * Function Name: CapSense_SsCSDNormalizeIdac
        ****************************************************************************//**
        *
        * \brief
        *  This function normalizes compensation IDAC.
        *
        * \details
        *  This function normalizes compensation IDAC.
        *
        * \param ptrFlashWidget
        *  Specifies the pointer to a widget.
        *
        * \param target
        *  Raw count target in percentage.
        *
        *******************************************************************************/
        static void CapSense_SsCSDNormalizeIdac(CapSense_FLASH_WD_STRUCT const *ptrFlashWidget, uint32 target)
        {
            uint32 snsIndex;
            uint32 freqChannel;
            uint32 maxIdac;
            uint32 minIdac;
            uint32 minRaw;
            uint32 maxRawLevel;
            uint32 rawLevel;
            uint32 iMod;

            CapSense_RAM_WD_BASE_STRUCT *ptrRamWidget = (CapSense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;
            CapSense_RAM_SNS_STRUCT *ptrRamSensor;

            /* Calculate raw count level based on resolution and target */
            maxRawLevel = (0x00000001Lu << ptrRamWidget->resolution) - 1u;

            /*
            * IDAC Normalization is performed separately for each multi-frequency channel
            * and separately for row and column
            */
            for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                /* Find maximum and minimum IDACs */
                maxIdac = ptrRamWidget->idacMod[freqChannel];
                minIdac = ptrRamWidget->idacMod[freqChannel];
                ptrRamSensor = ptrFlashWidget->ptr2SnsRam;
                minRaw = ptrRamSensor->raw[freqChannel];
                for(snsIndex = 0u; snsIndex < ptrFlashWidget->numCols; snsIndex++)
                {
                    if (minIdac > ptrRamSensor->idacComp[freqChannel])
                    {
                        minIdac = ptrRamSensor->idacComp[freqChannel];
                        minRaw = ptrRamSensor->raw[freqChannel];
                    }
                    ptrRamSensor++;
                }

                /* Define new modulator IDAC */
                rawLevel = ((minRaw * CapSense_PERCENTAGE_100) / maxRawLevel) + CapSense_PERCENTAGE_100;
                iMod = (rawLevel * minIdac) / target;

                if (iMod > maxIdac)
                {
                    iMod = maxIdac;
                }
                ptrRamWidget->idacMod[freqChannel] = (uint8)iMod;

                /* Re-calculate compensation IDAC */
                ptrRamSensor = ptrFlashWidget->ptr2SnsRam;
                for(snsIndex = 0u; snsIndex < ptrFlashWidget->numCols; snsIndex++)
                {
                    rawLevel = (((ptrRamSensor->raw[freqChannel] * CapSense_PERCENTAGE_100) / maxRawLevel) +
                        CapSense_PERCENTAGE_100) * ptrRamSensor->idacComp[freqChannel];
                    if (rawLevel < (iMod * target))
                    {
                        ptrRamSensor->idacComp[freqChannel] = 0u;
                    }
                    else
                    {
                        ptrRamSensor->idacComp[freqChannel] = (uint8)(((rawLevel - (iMod * target)) +
                            (CapSense_PERCENTAGE_100 >> 1u)) / CapSense_PERCENTAGE_100);
                    }
                    ptrRamSensor++;
                }

                #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
                    if ((CapSense_WD_TOUCHPAD_E == CapSense_GET_WIDGET_TYPE(ptrFlashWidget)) ||
                        (CapSense_WD_MATRIX_BUTTON_E == CapSense_GET_WIDGET_TYPE(ptrFlashWidget)))
                    {
                        /* Find maximum and minimum IDACs */
                        maxIdac = ptrRamWidget->rowIdacMod[freqChannel];
                        minIdac = ptrRamWidget->rowIdacMod[freqChannel];
                        ptrRamSensor = &(ptrFlashWidget->ptr2SnsRam[ptrFlashWidget->numCols]);
                        minRaw = ptrRamSensor->raw[freqChannel];
                        for(snsIndex = ptrFlashWidget->numCols; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
                        {
                            if (minIdac > ptrRamSensor->idacComp[freqChannel])
                            {
                                minIdac = ptrRamSensor->idacComp[freqChannel];
                                minRaw = ptrRamSensor->raw[freqChannel];
                            }
                            ptrRamSensor++;
                        }

                        /* Define new modulator IDAC */
                        rawLevel = ((minRaw * CapSense_PERCENTAGE_100) / maxRawLevel) + CapSense_PERCENTAGE_100;
                        iMod = (rawLevel * minIdac) / target;

                        if (iMod > maxIdac)
                        {
                            iMod = maxIdac;
                        }
                        ptrRamWidget->rowIdacMod[freqChannel] = (uint8)iMod;

                        /* Re-calculate compensation IDAC */
                        ptrRamSensor = &(ptrFlashWidget->ptr2SnsRam[ptrFlashWidget->numCols]);
                        for(snsIndex = 0u; snsIndex < ptrFlashWidget->numRows; snsIndex++)
                        {
                            rawLevel = (((ptrRamSensor->raw[freqChannel] * CapSense_PERCENTAGE_100) / maxRawLevel) +
                                CapSense_PERCENTAGE_100) * ptrRamSensor->idacComp[freqChannel];
                            if (rawLevel < (iMod * target))
                            {
                                ptrRamSensor->idacComp[freqChannel] = 0u;
                            }
                            else
                            {
                                ptrRamSensor->idacComp[freqChannel] = (uint8)(((rawLevel - (iMod * target)) +
                                    (CapSense_PERCENTAGE_100 >> 1u)) / CapSense_PERCENTAGE_100);
                            }
                            ptrRamSensor++;
                        }
                    }
                #endif
            }
        }
    #endif


    /*******************************************************************************
    * Function Name: CapSense_SsCSDCalibrate
    ****************************************************************************//**
    *
    * \brief
    *  Implements IDAC calibration for a desired widget using successive
    *  approximation algorithm.
    *
    * \details
    *  Implements IDAC calibration for a desired widget using successive
    *  approximation algorithm. It supports any type of CSD widgets, and works
    *  with multi-frequency scan and compensation IDAC features enabled.
    *
    *  As result of function operation, the modulator IDAC that corresponds to the
    *  sensor with the highest capacitance (the biggest modulator IDAC) is stored
    *  into widget data structure. If it is dual-axis widget type (touchpad or matrix
    *  buttons) or if multi-frequency scan feature is enabled then the maximum
    *  modulator IDAC found separately for each multi-frequency channel and for
    *  rows/columns.
    *
    *  If compensation IDAC is enabled, then it preserves IDAC value of
    *  single-sensor calibration. In dual IDAC mode each sensor was calibrated with
    *  equal values of modulator and compensation IDAC.
    *
    *  After IDACs were found each sensor scanned again to get real raw count stored
    *  in sensor structure.
    *
    * \param widgetId
    *  Specifies the ID number of the CSD widget to calibrate its raw count.
    *  A macro for the widget ID can be found in the
    *  CapSense Configuration header file defined as
    *  CapSense_<WidgetName>_WDGT_ID.
    *
    * \param target
    *  Specifies the calibration target in percentages of the maximum raw count.
    *
    *******************************************************************************/
    static void CapSense_SsCSDCalibrate(uint32 widgetId, uint32 target)
    {
        uint32 snsIndex;
        uint32 freqChannel;
        uint32 calMask;
        uint32 temp;
        uint32 watchdogCounter;

        uint8 *ptrIdacMod;
        uint8 *ptrMaxIdac;

        uint8 maxIdac[CapSense_NUM_SCAN_FREQS];

        #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
            uint8 maxRowIdac[CapSense_NUM_SCAN_FREQS];
            uint32 dualWidgetType = 0u;
        #endif

        CapSense_RAM_SNS_STRUCT *ptrRamSensor;
        CapSense_FLASH_WD_STRUCT const *ptrFlashWidget = &CapSense_dsFlash.wdgtArray[widgetId];
        CapSense_RAM_WD_BASE_STRUCT *ptrRamWidget = (CapSense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;

        ptrIdacMod = &ptrRamWidget->idacMod[0u];
        ptrMaxIdac = &maxIdac[0u];

        for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
        {
            maxIdac[freqChannel] = 0u;
            #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
                maxRowIdac[freqChannel] = 0u;
            #endif
        }

        /* Calculate raw count level based on resolution and target */
        temp = (((0x00000001Lu << ptrRamWidget->resolution) - 1u) * target) / CapSense_PERCENTAGE_100;

        #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
            if ((CapSense_WD_TOUCHPAD_E == CapSense_GET_WIDGET_TYPE(ptrFlashWidget)) ||
                (CapSense_WD_MATRIX_BUTTON_E == CapSense_GET_WIDGET_TYPE(ptrFlashWidget)))
            {
                dualWidgetType = 1u;
            }
        #endif

        /* Loop through the widget sensors */
        for(snsIndex = 0u; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
        {
            #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
                if (snsIndex == ptrFlashWidget->numCols)
                {
                    if (0u != dualWidgetType)
                    {
                        ptrIdacMod = &ptrRamWidget->rowIdacMod[0u];
                        ptrMaxIdac = &maxRowIdac[0u];
                    }
                }
            #endif

            ptrRamSensor = &((ptrFlashWidget->ptr2SnsRam)[snsIndex]);

            /* Set default IDAC code */
            calMask = CapSense_CSD_CAL_MIDDLE_VALUE;
            for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                ptrIdacMod[freqChannel] = CapSense_CSD_CAL_MIDDLE_VALUE;
                #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
                    ptrRamSensor->idacComp[freqChannel] = ptrIdacMod[freqChannel];
                #endif
            }

            /* Loop through IDAC code */
            do
            {
                /* Need to configure HW block with each IDAC change */
                CapSense_CSDSetupWidgetExt(widgetId, snsIndex);

                #if (CapSense_ENABLE == CapSense_CSDV2)
                    CapSense_DischargeExtCapacitors(CapSense_EXT_CAP_DISCHARGE_TIME);
                #endif

                /* Scan sensor */
                CapSense_CSDScanExt();

                watchdogCounter = CapSense_CSD_CALIBR_WATCHDOG_CYCLES_NUM;
                while (((CapSense_dsRam.status & CapSense_SW_STS_BUSY) != 0u) && (0uL != watchdogCounter))
                {
                    watchdogCounter--;
                }

                /* Update IDAC based on scan result */
                for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
                {
                    if (ptrRamSensor->raw[freqChannel] < temp)
                    {
                        ptrIdacMod[freqChannel] &= (uint8)(~calMask);
                    }
                }

                /* Switch to the lower IDAC mask */
                calMask >>= 1u;
                for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
                {
                    ptrIdacMod[freqChannel] |= (uint8)calMask;
                    #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
                        ptrRamSensor->idacComp[freqChannel] = ptrIdacMod[freqChannel];
                    #endif
                    if (0u == calMask)
                    {
                        if (0u == ptrIdacMod[freqChannel])
                        {
                            ptrIdacMod[freqChannel] = 1u;
                            #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
                                ptrRamSensor->idacComp[freqChannel] = ptrIdacMod[freqChannel];
                            #endif
                        }
                    }
                }
            }
            while (calMask != 0u);

            for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                if (ptrMaxIdac[freqChannel] < ptrIdacMod[freqChannel])
                {
                    ptrMaxIdac[freqChannel] = ptrIdacMod[freqChannel];
                }
            }

            /* Perform scan again to get real raw count if IDAC was changed at the last iteration */
            CapSense_CSDSetupWidgetExt(widgetId, snsIndex);
            CapSense_CSDScanExt();

            watchdogCounter = CapSense_CSD_CALIBR_WATCHDOG_CYCLES_NUM;
            while (((CapSense_dsRam.status & CapSense_SW_STS_BUSY) != 0u) && (0uL != watchdogCounter))
            {
                watchdogCounter--;
            }
        }

        for(freqChannel = CapSense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
        {
            ptrRamWidget->idacMod[freqChannel] = maxIdac[freqChannel];
            #if (CapSense_CSD_MATRIX_WIDGET_EN || CapSense_CSD_TOUCHPAD_WIDGET_EN)
                if (0u != dualWidgetType)
                {
                    ptrRamWidget->rowIdacMod[freqChannel] = maxRowIdac[freqChannel];

                    #if (CapSense_ENABLE == CapSense_CSD_COL_ROW_IDAC_ALIGNMENT_EN)
                        #if (CapSense_ENABLE == CapSense_CSD_COMMON_SNS_CLK_EN)
                            if (ptrRamWidget->idacMod[freqChannel] < ptrRamWidget->rowIdacMod[freqChannel])
                            {
                                temp = ptrRamWidget->rowIdacMod[freqChannel];
                                if (temp > CapSense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = CapSense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->idacMod[freqChannel] = (uint8)temp;
                            }
                            else
                            {
                                temp = ptrRamWidget->idacMod[freqChannel];
                                if (temp > CapSense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = CapSense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->rowIdacMod[freqChannel] = (uint8)temp;
                            }
                        #else
                            if (((uint32)ptrRamWidget->idacMod[freqChannel] * ptrRamWidget->snsClk) <
                                ((uint32)ptrRamWidget->rowIdacMod[freqChannel] * ptrRamWidget->rowSnsClk))
                            {
                                temp = ((uint32)ptrRamWidget->rowIdacMod[freqChannel] *
                                                ptrRamWidget->rowSnsClk) / ptrRamWidget->snsClk;
                                if (temp > CapSense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = CapSense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->idacMod[freqChannel] = (uint8)temp;
                            }
                            else
                            {
                                temp = ((uint32)ptrRamWidget->idacMod[freqChannel] *
                                                ptrRamWidget->snsClk) / ptrRamWidget->rowSnsClk;
                                if (temp > CapSense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = CapSense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->rowIdacMod[freqChannel] = (uint8)temp;
                            }
                        #endif
                    #endif
                }
            #endif
        }
    }


    /*******************************************************************************
    * Function Name: CapSense_CSDCalibrateWidget
    ****************************************************************************//**
    *
    * \brief
    *  Executes the IDAC calibration for all the sensors in the widget specified in
    *  the input.
    *
    * \details
    *  Executes the IDAC calibration for all the sensors in the widget specified in
    *  the input.
    *
    *  \note This function is obsolete and kept for backward compatibility only.
    *  The CapSense_CalibrateWidget() function should be used instead.
    *
    *  Performs a successive approximation search algorithm to find appropriate
    *  IDAC values for sensors in the specified widget that provides the raw
    *  count to the level specified by the target parameter.
    *
    *  Calibration fails if the achieved raw count is outside of the range specified
    *  by the target and acceptable calibration deviation.
    *
    *  This function is available when the CSD Enable IDAC auto-calibration
    *  parameter is enabled or the  SmartSense auto-tuning mode is configured.
    *
    * \param widgetId
    *  Specifies the ID number of the CSD widget to calibrate its raw count.
    *  A macro for the widget ID can be found in the
    *  CapSense Configuration header file defined as
    *  CapSense_<WidgetName>_WDGT_ID.
    *
    * \param target
    *  Specifies the calibration target in percentages of the maximum raw count.
    *
    * \return
    *  Returns the status of the specified widget calibration:
    *    - CYRET_SUCCESS - The operation is successfully completed.
    *    - CYRET_BAD_PARAM - The input parameter is invalid.
    *    - CYRET_BAD_DATA - The calibration failed and the Component may not operate
    *      as expected.
    *    - CYRET_TIMEOUT - The calibration failed due to timeout.
    *    - CYRET_INVALID_STATE - The previous scanning is not completed and the
    *      hardware block is busy.
    *
    *******************************************************************************/
    cystatus CapSense_CSDCalibrateWidget(uint32 widgetId, uint32 target)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;
        uint32 watchdogCounter;

        #if (CapSense_ENABLE == CapSense_CSD_IDAC_AUTO_GAIN_EN)
            uint32 gainSwitch;
        #endif

        CapSense_FLASH_WD_STRUCT const *ptrFlashWidget = &CapSense_dsFlash.wdgtArray[widgetId];

        if (CapSense_WDGT_SW_STS_BUSY == (CapSense_dsRam.status & CapSense_WDGT_SW_STS_BUSY))
        {
            /* Previous widget is being scanned, return error */
            calibrateStatus = CYRET_INVALID_STATE;
        }
        else
        {
            /* Set default IDAC gain */
            ((CapSense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam)->idacGainIndex =
                CapSense_CSD_IDAC_GAIN_INDEX_DEFAULT;

            /* Perform calibration */
            #if (CapSense_ENABLE != CapSense_CSD_IDAC_AUTO_GAIN_EN)
                CapSense_SsCSDCalibrate(widgetId, target);
            #else
                do
                {
                    CapSense_SsCSDCalibrate(widgetId, target);
                    gainSwitch = CapSense_SsCSDSwitchIdacGain(ptrFlashWidget);
                } while(0u != gainSwitch);
            #endif

            #if (CapSense_ENABLE == CapSense_CSD_IDAC_COMP_EN)
                /* IDAC Normalization in Dual IDAC mode */
                CapSense_SsCSDNormalizeIdac(ptrFlashWidget, target);
            #endif

            /* Perform specified widget scan to check calibration result */
            CapSense_CSDSetupWidget(widgetId);
            CapSense_CSDScan();

            watchdogCounter = CapSense_WIDGET_MAX_SCAN_TIME;
            while (((CapSense_dsRam.status & CapSense_SW_STS_BUSY) != 0u) && (0uL != watchdogCounter))
            {
                watchdogCounter--;
            }

            /* Verification of calibration result */
            if (0u == watchdogCounter)
            {
                calibrateStatus = CYRET_TIMEOUT;
            }
            else
            {
                calibrateStatus = CapSense_SsCSDCalibrateCheck(widgetId, target);
            }

             /* Update CRC */
            #if (CapSense_ENABLE ==CapSense_TST_WDGT_CRC_EN)
                CapSense_DsUpdateWidgetCrc(widgetId);
            #endif
        }

        return calibrateStatus;
    }
#endif /* ((CapSense_CSD_SS_DIS != CapSense_CSD_AUTOTUNE)) || \
            (CapSense_ENABLE == CapSense_CSD_IDAC_AUTOCAL_EN)) */


#if (CapSense_DISABLE == CapSense_CSDV2)
    /*******************************************************************************
    * Function Name: CapSense_SsCSDClockRestart
    ****************************************************************************//**
    *
    * \brief
    *  This function restarts the clocks.
    *
    * \details
    *  The function performs following:
    *  1) Stops, sets dividers and starts ModClk clock;
    *  2) Stops and starts SnsClk clock;
    *  3) Scan one cycle to reset the flip-flop for Direct clock mode.
    *
    *******************************************************************************/
    CY_INLINE static void CapSense_SsCSDClockRestart(void)
    {
        #if (CapSense_CLK_SOURCE_DIRECT == CapSense_CSD_SNS_CLK_SOURCE)
            uint32 watchdogCounter;
        #endif /* (CapSense_CLK_SOURCE_DIRECT == CapSense_CSD_SNS_CLK_SOURCE) */

        /* Stop clocks, set dividers, and start clock to align clock phase */
        CapSense_SsSetModClkClockDivider((uint32)CapSense_dsRam.modCsdClk);

        #if (CapSense_ENABLE == CapSense_IS_M0S8PERI_BLOCK)
            /* Stop sense clock clock   */
            CY_SET_REG32(CapSense_SNSCLK_CMD_PTR,
                         ((uint32)CapSense_SnsClk__DIV_ID <<
                         CapSense_SNSCLK_CMD_DIV_SHIFT)|
                         ((uint32)CapSense_SNSCLK_CMD_DISABLE_MASK));

            /* Check whether previous sense clock start command has finished. */
            while(0u != (CY_GET_REG32(CapSense_SNSCLK_CMD_PTR) & CapSense_SNSCLK_CMD_ENABLE_MASK))
            {
                /* Wait until previous sense clock start command has finished. */
            }

            /* Start sense clock aligned to previously started modulator clock. */
            CY_SET_REG32(CapSense_SNSCLK_CMD_PTR,
                         (uint32)(((uint32)CapSense_SnsClk__DIV_ID << CapSense_SNSCLK_CMD_DIV_SHIFT) |
                          ((uint32)CapSense_ModClk__PA_DIV_ID << CapSense_SNSCLK_CMD_PA_DIV_SHIFT) |
                          CapSense_SNSCLK_CMD_ENABLE_MASK));
        #else
            /* Clear bit to disable SnsClk clock. */
            CY_SET_REG32(CapSense_SNSCLK_CMD_PTR,
                         CY_GET_REG32(CapSense_SNSCLK_CMD_PTR) &
                         (uint32)(~(uint32)CapSense_SnsClk__ENABLE_MASK));

            /* Set bit to enable SnsClk clock. */
            CY_SET_REG32(CapSense_SNSCLK_CMD_PTR,
                         CY_GET_REG32(CapSense_SNSCLK_CMD_PTR) |
                        CapSense_SnsClk__ENABLE_MASK);
        #endif /* (CapSense_ENABLE == CapSense_IS_M0S8PERI_BLOCK) */

        #if (CapSense_CLK_SOURCE_DIRECT == CapSense_CSD_SNS_CLK_SOURCE)
            /* Scan one cycle to reset the flip-flop for Direct clock mode */
            CyIntDisable(CapSense_ISR_NUMBER);
            CY_SET_REG32(CapSense_COUNTER_PTR, CapSense_ONE_CYCLE);

            watchdogCounter = CapSense_ONE_CLOCK_WATCHDOG_CYCLES_NUM;
            while((0u != (CY_GET_REG32(CapSense_COUNTER_PTR) & CapSense_RESOLUTION_16_BITS)) && (0uL != watchdogCounter))
            {
                watchdogCounter--;
            }
            CY_SET_REG32(CapSense_INTR_PTR, CapSense_INTR_SET_MASK);
            CyIntClearPending(CapSense_ISR_NUMBER);
        #endif /* (CapSense_CLK_SOURCE_DIRECT == CapSense_CSD_SNS_CLK_SOURCE) */
    }
#endif /* (CapSense_DISABLE == CapSense_CSDV2) */


/*******************************************************************************
* Function Name: CapSense_SsCSDCmodPrecharge
****************************************************************************//**
*
* \brief
*  This function initializes the Cmod charging to Vref.
*
* \details
*  For Third-generation HW block:
*  The function initializes the Cmod charging to Vref.
*  Then it waits the even when Cmod is completely charged
*  to Vref to have stable raw counts. Software Watchdog Counter is implemented to
*  prevent the project hanging.
*
*  For Fourth-generation HW block:
*  Coarse initialization for CMOD and Cch.
*  The coarse initialization is performed by HSCOMP.
*  The HSCOMP monitors the Cmod voltage via Cmod sense path
*  and charges the Cmod using HCAV switch via CSDBUS-A, AMUXBUS-A
*  and static connection of Cmod to AMUXBUS-A.
*
*******************************************************************************/
CY_INLINE static void CapSense_SsCSDCmodPrecharge(void)
{
    #if (CapSense_ENABLE == CapSense_CSDV2)
        uint32 watchdogCounter;
        /* Fourth-generation HW block section */

        CY_SET_REG32(CapSense_CSDCMP_PTR, CapSense_CSD_CSDCMP_INIT);
        CY_SET_REG32(CapSense_SW_FW_MOD_SEL_PTR,  CapSense_CSD_SW_FW_MOD_SEL_INIT);
        CY_SET_REG32(CapSense_SW_FW_TANK_SEL_PTR, CapSense_CSD_SW_FW_TANK_SEL_INIT);
        CY_SET_REG32(CapSense_SW_SHIELD_SEL_PTR,  CapSense_CSD_SW_SHIELD_SEL_INIT);
        #if (CapSense_ENABLE == CapSense_CSD_SHIELD_EN)
            /*
             * Connect CMOD to (sense path) to HSCOMP: HMPM or HMPS or HMPT switches depend on Cmod connects to certain pad
             * Connect AMUXBUS-B to HSCMP positive input
             */
            CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR, CapSense_SW_HS_P_SEL_COARSE);

            #if(0u != CapSense_CSD_SHIELD_TANK_EN)
                /* Connect CTANK to AMUXBUS-A */
                CapSense_WriteBitsSafe(CapSense_CSH_HSIOM_PTR, CapSense_CSH_HSIOM_MASK,
                    (uint32)(CapSense_HSIOM_SEL_AMUXA << CapSense_CSH_HSIOM_SHIFT));
            #endif /* (0u != CapSense_CSD_SHIELD_TANK_EN) */
        #else
            /* Connect CMOD to (sense path) to HSCOMP: HMPM or HMPS or HMPT switches depend on Cmod connects to certain pad */
            CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR, CapSense_SW_HS_P_SEL_COARSE);
        #endif /* (CapSense_ENABLE == CapSense_CSD_SHIELD_EN) */

        CY_SET_REG32(CapSense_SW_RES_PTR, CapSense_CSD_SW_RES_INIT);

        /* Clear all interrupt pending requests */
        CY_SET_REG32(CapSense_INTR_PTR, CapSense_INTR_ALL_MASK);

        CY_SET_REG32(CapSense_INTR_MASK_PTR, CapSense_CLEAR_MASK);

        /* Start SEQUENCER for coarse initialization for Cmod */
        CY_SET_REG32(CapSense_SEQ_START_PTR, CapSense_SEQ_START_SEQ_MODE_MASK |
                                                         CapSense_SEQ_START_START_MASK);

        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = CapSense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM;

        /* Wait for INTR.INIT goes high */
        while((0u == (CY_GET_REG32(CapSense_INTR_PTR) & CapSense_INTR_INIT_MASK)) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }

        if (0u == watchdogCounter)
        {
            /* Set sequencer to idle state if coarse initialization fails */
            CY_SET_REG32(CapSense_SEQ_START_PTR, CapSense_SEQ_START_ABORT_MASK);
        }

    #else

        uint32 tmpRegValue;
        uint32 newRegValue;
        uint32 watchdogCounter;

        /* Save the current IDAC configuration */
        tmpRegValue = CY_GET_REG32(CapSense_IDAC_PTR);

        /* Wait until Cmod discharges below Vref */
        CyDelayCycles(CapSense_CMOD_DISCHARGE_CYCLES);

        newRegValue = CapSense_CSD_IDAC_PRECHARGE_CONFIG | (tmpRegValue & ~CapSense_IDAC_MOD_CFG_MASK);

        /* Set the IDAC configuration for fast Cmod precharge to Vref */
        CY_SET_REG32(CapSense_IDAC_PTR, newRegValue);

        #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
            CY_SET_REG32(CapSense_CONFIG_PTR, CY_GET_REG32(CapSense_CONFIG_PTR) & ~CapSense_CONFIG_POLARITY_MASK);
        #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */

        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = CapSense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM;

        /* Wait until Cmod reaches to Vref */
        while((0u == (CY_GET_REG32(CapSense_STATUS_PTR) & CapSense_STATUS_SAMPLE)) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }

        #if (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG)
            CY_SET_REG32(CapSense_CONFIG_PTR, CY_GET_REG32(CapSense_CONFIG_PTR) | CapSense_CONFIG_POLARITY_MASK);
        #endif /* (CapSense_IDAC_SINKING == CapSense_CSD_IDAC_CONFIG) */

        /* Restore the current IDAC configuration */
        CY_SET_REG32(CapSense_IDAC_PTR, tmpRegValue);

        /* Enable the sense modulator output */
        CY_SET_REG32(CapSense_CONFIG_PTR, CapSense_configCsd | CapSense_CTANK_PRECHARGE_CONFIG_CSD_EN | CapSense_CONFIG_SENSE_EN_MASK);

        CyIntEnable(CapSense_ISR_NUMBER);

    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}


/*******************************************************************************
* Function Name: CapSense_SsCSDTriggerScan
****************************************************************************//**
*
* \brief
*  This function triggers the scanning.
*
* \details
*  For Third-generation HW block:
*  Writes resolution to start the scanning.
*
*  For Fourth-generation HW block:
*  Trigger the fine initialization (scan some dummy cycles) and start sampling.
*  Fine initialization for CMOD and Start scan.
*  For the fine initialization and sampling, Cmod is static connected to AMUXBUS-A
*  and in every conversion (one cycle of SnsClk), the sensor capacitance is charged
*  from Cmod and discharged to ground using the switches in GPIO cell.
*  The CSDCOMP monitors voltage on Cmod using the sense path and charges Cmod back
*  to Vref using IDACs by connecting IDAC to CSDBUS-A and then the AMUXBUS-A.
*
*******************************************************************************/
CY_INLINE static void CapSense_SsCSDTriggerScan(void)
{
    #if (CapSense_ENABLE == CapSense_CSDV2)

        /* Fourth-generation HW block section */

        uint32 watchdogCounter;

        /* Clear previous interrupts */
        CY_SET_REG32(CapSense_INTR_PTR, CapSense_INTR_ALL_MASK);

        /* Clear pending interrupts  */
        CyIntClearPending(CapSense_ISR_NUMBER);

        /* Enable CSD interrupt */
        CyIntEnable(CapSense_ISR_NUMBER);


        CY_SET_REG32(CapSense_SW_HS_P_SEL_PTR, CapSense_CSD_SW_HS_P_SEL_SCAN);

        /* Set scanning configuration for switches */
        CY_SET_REG32(CapSense_SW_FW_MOD_SEL_PTR, CapSense_CSD_SW_FW_MOD_SEL_SCAN);
        CY_SET_REG32(CapSense_SW_FW_TANK_SEL_PTR,CapSense_CSD_SW_FW_TANK_SEL_SCAN);

        CY_SET_REG32(CapSense_SW_SHIELD_SEL_PTR,  CapSense_CSD_SW_SHIELD_SEL_SCAN);

        #if((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN))
            /* Connect CTANK to AMUXBUS-B */
            CapSense_SsCSDEnableShieldTank();
        #endif /* ((CapSense_ENABLE == CapSense_CSD_SHIELD_EN) && (CapSense_ENABLE == CapSense_CSD_SHIELD_TANK_EN)) */

        CY_SET_REG32(CapSense_SW_RES_PTR, CapSense_CSD_SW_RES_SCAN);
        CY_SET_REG32(CapSense_CSDCMP_PTR, CapSense_CSD_CSDCMP_SCAN);

        #if (CapSense_DISABLE == CapSense_CSD_SHIELD_EN)
            /* Disable HSCOMP during the sampling phase when shield is disabled */
            CY_SET_REG32(CapSense_HSCMP_PTR, 0u);
        #else
            CY_SET_REG32(CapSense_HSCMP_PTR, CapSense_HSCMP_SCAN_MASK);
        #endif /* (CapSense_DISABLE == CapSense_CSD_SHIELD_EN) */

        #if (CapSense_CLK_SOURCE_DIRECT != CapSense_CSD_SNS_CLK_SOURCE)
            /* Force the LFSR to it's initial state (all ones) */
            CY_SET_REG32(CapSense_SENSE_PERIOD_PTR, CY_GET_REG32(CapSense_SENSE_PERIOD_PTR) |
                                                           CapSense_SENSE_PERIOD_LFSR_CLEAR_MASK);
        #endif /* (CapSense_CLK_SOURCE_DIRECT != CapSense_CSD_SNS_CLK_SOURCE) */

        /* Enable SAMPLE interrupt */
        CY_SET_REG32(CapSense_INTR_MASK_PTR, CapSense_INTR_MASK_SAMPLE_MASK);

        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = CapSense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM;

        /* Wait for IDLE state of the HW sequencer */
        while((0u != (CapSense_STAT_SEQ_REG & CapSense_STAT_SEQ_SEQ_STATE_MASK)) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }

        /* Start SEQUENCER for fine initialization scan for Cmod and then for normal scan */
        CY_SET_REG32(CapSense_SEQ_START_PTR, CapSense_SEQ_START_AZ0_SKIP_MASK |
                                                     CapSense_SEQ_START_AZ1_SKIP_MASK |
                                                     CapSense_SEQ_START_START_MASK);

    #else

        /* Third-generation HW block section */

        /* Set resolution to Counter register to start scanning */
        CY_SET_REG32(CapSense_COUNTER_PTR, CapSense_counterResolution);

    #endif /* (CapSense_ENABLE == CapSense_CSDV2) */
}

#endif  /* (CapSense_ENABLE == CapSense_CSD_EN) */


/* [] END OF FILE */
