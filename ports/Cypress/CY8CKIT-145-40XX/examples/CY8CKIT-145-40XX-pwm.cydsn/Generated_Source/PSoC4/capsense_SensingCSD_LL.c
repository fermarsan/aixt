/***************************************************************************//**
* \file capsense_SensingCSD_LL.c
* \version 7.10
*
* \brief
*   This file defines the data structure global variables and provides
*   implementation for the low-level APIs of the CSD part of
*   the Sensing module. The file contains the APIs used for the CSD block
*   initialization, calibration, and scanning.
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
#include "capsense_Structure.h"
#include "capsense_Configuration.h"
#include "capsense_SensingCSD_LL.h"
#if (capsense_ENABLE == capsense_SELF_TEST_EN)
    #include "capsense_SelfTest.h"
#endif

#include "cyapicallbacks.h"

#if (capsense_ENABLE == capsense_CSD_EN)

/***************************************
* API Constants
***************************************/

#if (capsense_ENABLE == capsense_CSDV2)

    #if (capsense_ENABLE == capsense_CSD_AUTO_ZERO_EN)
        #define capsense_CSD_AZ_ENABLE_CFG                  (capsense_CSD_AZ_EN_MASK)
    #else
        #define capsense_CSD_AZ_ENABLE_CFG                  (0uL)
    #endif /* (capsense_ENABLE == capsense_CSD_AUTO_ZERO_EN) */

    #if (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG)
        #define capsense_HSCMP_SCAN_MASK                    (capsense_HSCMP_EN_MASK | capsense_CSD_AZ_ENABLE_CFG |\
                                                                     capsense_HSCMP_INVERT_MASK)
    #else
        #define capsense_HSCMP_SCAN_MASK                    (capsense_HSCMP_EN_MASK | capsense_CSD_AZ_ENABLE_CFG)
    #endif /* (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG) */

    #define capsense_HSCMP_INIT_MASK                        (capsense_HSCMP_EN_MASK | capsense_CSD_AZ_ENABLE_CFG)

    #define capsense_DEFAULT_SW_SHIELD_SEL                  (0x00000000uL)
    #define capsense_DEFAULT_CSD_SW_DSI_SEL                 (capsense_SW_DSI_SEL_CMODPAD | capsense_SW_DSI_SEL_TANKPAD)
    #define capsense_DEFAULT_CSD_INTR_SET                   (0x00000000uL)
    #define capsense_DEFAULT_SW_HS_P_SEL                    (0x00000000uL)
    #define capsense_DEFAULT_SW_HS_N_SEL                    (0x00000000uL)
    #define capsense_DEFAULT_CSD_SW_FW_TANK_SEL             (0x00000000uL)
    #define capsense_DEFAULT_CSD_ADC_CTL                    (0x00000000uL)
    #define capsense_DEFAULT_HSCMP_CFG                      (0x00000000uL)

    /* CY_ID285392 */
    #define capsense_FILTER_DELAY_MAX                   (capsense_CONFIG_FILTER_DELAY_4_CYCLES)
    #define capsense_EXTRA_COUNTS_MAX                   (capsense_FILTER_DELAY_MAX + 5u + 20u)

#else

    /* Set IDAC ranges */
    #if (capsense_IDAC_GAIN_8X == capsense_CSD_IDAC_GAIN)
        #define capsense_DEFAULT_IDAC_MOD_RANGE         (capsense_IDAC_MOD_RANGE_MASK)
        #define capsense_DEFAULT_IDAC_COMP_RANGE        (capsense_IDAC_COMP_RANGE_MASK)
    #else
        #define capsense_DEFAULT_IDAC_MOD_RANGE         (0u)
        #define capsense_DEFAULT_IDAC_COMP_RANGE        (0u)
    #endif /* (capsense_IDAC_GAIN_8X == capsense_CSD_IDAC_GAIN) */

    /* Defining default IDACs configuration according to settings in customizer. */
    #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
        #define capsense_DEFAULT_CSD_IDAC_CONFIG        (capsense_IDAC_MOD_MODE_VARIABLE |\
                                                                 capsense_IDAC_COMP_MODE_FIXED |\
                                                                 capsense_DEFAULT_IDAC_MOD_RANGE |\
                                                                 capsense_DEFAULT_IDAC_COMP_RANGE)
    #else
        #define capsense_DEFAULT_CSD_IDAC_CONFIG        (capsense_IDAC_MOD_MODE_VARIABLE |\
                                                                 capsense_DEFAULT_IDAC_MOD_RANGE)
    #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */

#endif /* (capsense_ENABLE == capsense_CSDV2) */


/***************************************
* Variables
***************************************/

#if (capsense_ENABLE == capsense_CSDV2)
    uint32 capsense_configCsd = capsense_DEFAULT_CSD_CONFIG;
#else
    uint32 capsense_configCsd = capsense_DEFAULT_CSD_CONFIG | capsense_DEFAULT_MODULATION_MODE;
    static uint32 capsense_counterResolution = capsense_CNT_RESOLUTION_12_BITS;
#endif /* (capsense_ENABLE == capsense_CSDV2) */

/* Flag to indicate electrodes that were connected previously */
static uint8 capsense_eleCsdDisconnectFlag = 0u;
#if ((capsense_ENABLE == capsense_CSDV2) && (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN))
    /* Number of re-samplings when the bad conversion occurs */
    uint8 capsense_badConversionsNum = capsense_BAD_CONVERSIONS_NUM;
#endif /* ((capsense_ENABLE == capsense_CSDV2) && (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)) */


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/

/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

#if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
    static void capsense_SsSetShieldDelay(uint32 delay);
    #if (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN)
        static void capsense_SsCSDEnableShieldTank(void);
    #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN) */
#endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

#if ((capsense_CSD_SS_DIS != capsense_CSD_AUTOTUNE) || \
     (capsense_ENABLE == capsense_CSD_IDAC_AUTOCAL_EN))
    static cystatus capsense_SsCSDCalibrateCheck(uint32 widgetId, uint32 target);
    static void capsense_SsCSDCalibrate(uint32 widgetId, uint32 target);
    #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
        static void capsense_SsCSDNormalizeIdac(capsense_FLASH_WD_STRUCT const *ptrFlashWidget, uint32 target);
    #endif
    #if (capsense_ENABLE == capsense_CSD_IDAC_AUTO_GAIN_EN)
        static uint32 capsense_SsCSDSwitchIdacGain(capsense_FLASH_WD_STRUCT const *ptrFlashWidget);
    #endif
#endif /* ((capsense_CSD_SS_DIS != capsense_CSD_AUTOTUNE) || \
           (capsense_ENABLE == capsense_CSD_IDAC_AUTOCAL_EN))  */

#if (capsense_ENABLE == capsense_CSDV2)
    static void capsense_SsCSDSetFilterDelay(void);
#else
    CY_INLINE static void capsense_SsCSDClockRestart(void);
#endif /* (capsense_ENABLE == capsense_CSDV2) */
CY_INLINE static void capsense_SsCSDCmodPrecharge(void);
CY_INLINE static void capsense_SsCSDTriggerScan(void);
static void capsense_SsCSDConfigIDACs(void);
static void capsense_SsCSDSetModeSnsClockDivider(uint32 snsClkSource, uint32 snsClkDivider);

/** \}
* \endcond */


#if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
    /*******************************************************************************
    * Function Name: capsense_SsSetShieldDelay
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
    static void capsense_SsSetShieldDelay(uint32 delay)
    {
        /* Update CSD config register shield delay bits with shield delay value */
        capsense_configCsd &= (uint32)(~capsense_CONFIG_SHIELD_DELAY_MASK);
        capsense_configCsd |= (delay << capsense_SHIELD_DELAY_SHIFT);
    }

    #if (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN)
        /*******************************************************************************
        * Function Name: capsense_SsCSDEnableShieldTank
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
        static void capsense_SsCSDEnableShieldTank(void)
        {
            /* Update the CSH_HSIOM register to connect Csh to AMUXBUS-B */
            capsense_WriteBitsSafe(capsense_CSH_HSIOM_PTR, capsense_CSH_HSIOM_MASK,
                        (uint32)(capsense_HSIOM_SEL_AMUXB << capsense_CSH_HSIOM_SHIFT));

            #if ((capsense_CSH_PRECHARGE_IO_BUF == capsense_CSD_CSH_PRECHARGE_SRC) &&\
                 (capsense_DISABLE == capsense_CSDV2))
                /* Set Strong drive mode for Csh */
                capsense_WriteBitsSafe(capsense_CSH_PC_PTR,
                            (uint32)(capsense_CSH_PC_MASK << capsense_CSH_PC_SHIFT),
                            (uint32)(capsense_CSH_PC_STRONG_MODE << capsense_CSH_PC_SHIFT));
                /* Appliy High level to Csh pin for Csh */
                capsense_WriteBitsSafe(capsense_CSH_DR_PTR, (uint32)(capsense_DR_MASK << capsense_CSH_SHIFT), capsense_CSH_DR_CONFIG);
            #else
                /* Set output port register to 0 to connect to GND */
                capsense_WriteBitsSafe(capsense_CSH_DR_PTR, (uint32)(capsense_DR_MASK << capsense_CSH_SHIFT), 0u);
            #endif
        }
    #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN) */

    #if (0u != capsense_CSD_TOTAL_SHIELD_COUNT)
        /*******************************************************************************
        * Function Name: capsense_SsCSDEnableShieldElectrodes
        ****************************************************************************//**
        *
        * \brief
        *   This internal function initializes Shield Electrodes.
        *
        * \details
        *   The function sets the bit in the HSIOM register which enables the shield electrode
        *   functionality on the pin. The port and pin configurations are stored in
        *   the capsense_shieldIoList structure.
        *
        *******************************************************************************/
        void capsense_SsCSDEnableShieldElectrodes(void)
        {
            capsense_SsCSDSetShieldElectrodesState(capsense_SNS_CONNECTION_SHIELD);
        }


        /*******************************************************************************
        * Function Name: capsense_SsCSDDisableShieldElectrodes
        ****************************************************************************//**
        *
        * \brief
        *   This internal function disables Shield Electrodes.
        *
        * \details
        *   The function resets the bit in the HSIOM register which disables the shield
        *   electrode functionality on the pin. The port and pin configurations are
        *   stored in  the capsense_shieldIoList structure.
        *
        *******************************************************************************/
        void capsense_SsCSDDisableShieldElectrodes(void)
        {
            capsense_SsCSDSetShieldElectrodesState(capsense_SNS_CONNECTION_GROUND);
        }


        /*******************************************************************************
        * Function Name: capsense_SsCSDSetShieldElectrodesState
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
        *   stored in the capsense_shieldIoList structure.
        *
        * \param state
        *   A new state of the shield electrodes. Available values:
        *   - capsense_SNS_CONNECTION_GROUND - disconnects electrode from
        *       CSD hardware block and sets it to GPIO mode with Strong Drive
        *   - capsense_SNS_CONNECTION_HIGHZ - disconnects electrode from
        *       CSD hardware block and sets it to GPIO mode with Analog Hi-Z
        *   - capsense_SNS_CONNECTION_SHIELD - connects electrode to
        *       CSD hardware block
        *   - capsense_SNS_CONNECTION_UNDEFINED - sets the same electrode
        *       connection as for capsense_SNS_CONNECTION_GROUND
        *
        *******************************************************************************/
        void capsense_SsCSDSetShieldElectrodesState(uint32 state)
        {
            uint8  interruptState;

            uint32 loopIndex;

            uint32 newPinPcVal;
            uint32 newPinHsiomVal;

            uint32 tmpPcDrRegValue;
            uint32 tmpHsiomRegValue;

            capsense_SHIELD_IO_STRUCT const *shieldIoPtr;

            switch(state)
            {
                case capsense_SNS_CONNECTION_GROUND:
                    newPinPcVal = CY_SYS_PINS_DM_STRONG;
                    newPinHsiomVal = capsense_HSIOM_SEL_GPIO;
                    break;
                case capsense_SNS_CONNECTION_HIGHZ:
                    newPinPcVal = CY_SYS_PINS_DM_ALG_HIZ;
                    newPinHsiomVal = capsense_HSIOM_SEL_GPIO;
                    break;
                case capsense_SNS_CONNECTION_SHIELD:
                    newPinPcVal = CY_SYS_PINS_DM_ALG_HIZ;
                    newPinHsiomVal = capsense_HSIOM_SEL_CSD_SHIELD;
                    break;
                default:
                    newPinPcVal = CY_SYS_PINS_DM_STRONG;
                    newPinHsiomVal = capsense_HSIOM_SEL_GPIO;
                    break;
            }

            shieldIoPtr = &capsense_shieldIoList[0u];
            for (loopIndex = 0u; loopIndex < capsense_CSD_TOTAL_SHIELD_COUNT; loopIndex++)
            {
                interruptState = CyEnterCriticalSection();

                tmpHsiomRegValue = CY_GET_REG32 (shieldIoPtr->hsiomPtr);
                tmpHsiomRegValue &= ~(shieldIoPtr->hsiomMask);
                CY_SET_REG32 (shieldIoPtr->hsiomPtr, tmpHsiomRegValue);

                tmpPcDrRegValue = CY_GET_REG32 (shieldIoPtr->pcPtr);
                tmpPcDrRegValue &= ~(capsense_GPIO_PC_MASK << shieldIoPtr->shift);
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
    #endif /* (0u != capsense_CSD_TOTAL_SHIELD_COUNT) */
#endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */


/*******************************************************************************
* Function Name: capsense_SsCSDSetModeSnsClockDivider
****************************************************************************//**
*
* \brief
*   Sets sense source and Sense Clock Divider
*
* \details
*   For Fourth-generation HW block: Updates capsense_SENSE_PERIOD register with
*   sense source and Sense Clock Divider.
*   For Third-generation HW block: Updates capsense_configCsd variable with
*   sense source and sets sense clock divider.
*
* \param
*   snsClkSource The sense source for the sense clock.
* \param
*   snsClkDivider The divider value for the sense clock.
*
*******************************************************************************/
static void capsense_SsCSDSetModeSnsClockDivider(uint32 snsClkSource, uint32 snsClkDivider)
{
    #if (capsense_ENABLE == capsense_CSDV2)
        /* Update reg value with divider and configuration */
        CY_SET_REG32(capsense_SENSE_PERIOD_PTR, snsClkSource | (snsClkDivider - 1u));
    #else
        /* Set configuration */
        capsense_configCsd &= ~(capsense_CONFIG_PRS_SELECT_MASK | capsense_CSD_PRS_12_BIT);
        capsense_configCsd |= snsClkSource;

        /* Set sense clock divider */
        capsense_SsSetSnsClockDivider(snsClkDivider);
    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


#if (capsense_ENABLE == capsense_CSDV2)
    /*******************************************************************************
    * Function Name: capsense_SsCSDSetFilterDelay
    ****************************************************************************//**
    *
    * \brief
    *   Sets the filter delay for Fourth-generation HW block.
    *
    * \details
    *   This function updates Fourth-generation HW block configuration
    *   variable capsense_configCsd
    *   with the filter delay which depends on the sample clock frequency.
    *   This variable is written into register during enabling
    *   Fourth-generation HW block .
    *
    *******************************************************************************/
    static void capsense_SsCSDSetFilterDelay(void)
    {
        #if (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
            uint32 sampleClkFreqHz;
        #endif /* (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */

        capsense_configCsd &= ~capsense_CONFIG_FILTER_DELAY_MASK;

        #if (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
            sampleClkFreqHz = CYDEV_BCLK__HFCLK__HZ / (uint32)capsense_dsRam.modCsdClk;
            if(sampleClkFreqHz <= capsense_MOD_CSD_CLK_12MHZ)
            {
                capsense_configCsd |= capsense_CONFIG_FILTER_DELAY_12MHZ;
            }
            else if(sampleClkFreqHz <= capsense_MOD_CSD_CLK_24MHZ)
            {
                capsense_configCsd |= capsense_CONFIG_FILTER_DELAY_24MHZ;
            }
            else
            {
                capsense_configCsd |= capsense_CONFIG_FILTER_DELAY_48MHZ;
            }
        #else
            capsense_configCsd |= capsense_CONFIG_FILTER_DELAY_12MHZ;
        #endif /* (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */
    }
#endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)  */


/*******************************************************************************
* Function Name: capsense_SsCSDConfigIDACs
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
static void capsense_SsCSDConfigIDACs(void)
{
    #if (capsense_ENABLE == capsense_CSDV2)
        CY_SET_REG32(capsense_CSD_IDACA_PTR, capsense_IDAC_MOD_DEFAULT_CFG);
        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            CY_SET_REG32(capsense_CSD_IDACB_PTR, capsense_IDAC_COMP_DEFAULT_CFG);
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */
    #else
        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            CY_SET_REG32(capsense_IDAC_PTR, capsense_DEFAULT_CSD_IDAC_CONFIG);
        #else
            CY_SET_REG32(capsense_IDAC_PTR, CY_GET_REG32(capsense_IDAC_PTR) &
                                                                ~(capsense_IDAC_MOD_MODE_MASK |
                                                                  capsense_IDAC_MOD_MASK));
            CY_SET_REG32(capsense_IDAC_PTR, CY_GET_REG32(capsense_IDAC_PTR) |
                                                                 capsense_DEFAULT_CSD_IDAC_CONFIG);
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */
    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


/*******************************************************************************
* Function Name: capsense_SsCSDInitialize
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
void capsense_SsCSDInitialize(void)
{
    #if (capsense_ENABLE == capsense_CSDV2)
        uint32 newRegValue;
    #endif

    /* Set all the sensors to inactive state */
    if(capsense_dsRam.scanCurrentISC != capsense_dsRam.scanCsdISC)
    {
        capsense_SsSetAllIOsState((uint32)capsense_dsRam.scanCsdISC);
        capsense_dsRam.scanCurrentISC = capsense_dsRam.scanCsdISC;
    }

    #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
        /* Connect shields to AMUX-B bus (config HSIOM regs) */
        #if (0u != capsense_CSD_TOTAL_SHIELD_COUNT)
            capsense_SsCSDEnableShieldElectrodes();
        #endif /* (0u != capsense_CSD_TOTAL_SHIELD_COUNT) */

        #if (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN)
            /* Configure Csh */
            capsense_SsCSDEnableShieldTank();
        #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN) */
    #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

    #if (capsense_ENABLE == capsense_CSDV2)

        capsense_DischargeExtCapacitors(capsense_EXT_CAP_DISCHARGE_TIME);

        /* Initialize the unused CSD registers to defaut state */
        CY_SET_REG32(capsense_SENSE_DUTY_PTR, capsense_DEFAULT_SENSE_DUTY_SEL);

        /* Configure VREF */
        newRegValue = CY_GET_REG32(capsense_SW_REFGEN_SEL_PTR);
        newRegValue |= capsense_DEFAULT_SW_REFGEN_SEL;

        CY_SET_REG32(capsense_SW_REFGEN_SEL_PTR, newRegValue);
        CY_SET_REG32(capsense_INTR_SET_PTR,         capsense_DEFAULT_CSD_INTR_SET);
        CY_SET_REG32(capsense_SW_FW_TANK_SEL_PTR,   capsense_DEFAULT_CSD_SW_FW_TANK_SEL);
        CY_SET_REG32(capsense_SW_DSI_SEL_PTR,       capsense_DEFAULT_CSD_SW_DSI_SEL);
        CY_SET_REG32(capsense_ADC_CTL_PTR,          capsense_DEFAULT_CSD_ADC_CTL);
        CY_SET_REG32(capsense_AMBUF_PTR,            capsense_AMBUF_PWR_MODE_OFF);
        CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR,    capsense_DEFAULT_SW_SHIELD_SEL);
        CY_SET_REG32(capsense_SW_HS_P_SEL_PTR,      capsense_DEFAULT_SW_HS_P_SEL);
        CY_SET_REG32(capsense_SW_HS_N_SEL_PTR,      capsense_DEFAULT_SW_HS_N_SEL);
        CY_SET_REG32(capsense_HSCMP_PTR,            capsense_DEFAULT_HSCMP_CFG);

        /* Connect CMOD to AMUXBUS-A */
        capsense_WriteBitsSafe(capsense_CMOD_HSIOM_PTR, capsense_CMOD_HSIOM_MASK,
                    (uint32)(capsense_HSIOM_SEL_AMUXA << capsense_CMOD_HSIOM_SHIFT));

        /* Set output port register to 0 to connect to GND */
        capsense_WriteBitsSafe(capsense_CMOD_DR_PTR, capsense_Cmod__0__MASK, 0u);

        /* Connect AMUXBUS-A to CSDBUS-A */
        newRegValue = CY_GET_REG32(capsense_SW_BYP_SEL_PTR);
        newRegValue |= capsense_SW_BYP_SEL_SW_BYA_MASK;
        CY_SET_REG32(capsense_SW_BYP_SEL_PTR, newRegValue);

        /* Connect CMOD to (sense path) to CSDCOMP */
        #if (capsense_CSD__CMOD_PAD == capsense_CMOD_CONNECTION)
            CY_SET_REG32(capsense_SW_CMP_P_SEL_PTR, capsense_SW_CMP_P_SEL_SW_SFPM_STATIC_CLOSE);
        #elif (capsense_CSD__CSHIELD_PAD == capsense_CMOD_CONNECTION)
            CY_SET_REG32(capsense_SW_CMP_P_SEL_PTR, capsense_SW_CMP_P_SEL_SW_SFPS_STATIC_CLOSE);
        #else
            CY_SET_REG32(capsense_SW_CMP_P_SEL_PTR, capsense_SW_CMP_P_SEL_SW_SFPT_STATIC_CLOSE);
        #endif /* (capsense_CSD__CMOD_PAD == capsense_CMOD_CONNECTION) */

        /* Configure shield driving path */
        #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
            /* Connect AMUXBUS-B to CSDBUS-B (and AMUXBUS-A to CSDBUS-A ) */
            CY_SET_REG32(capsense_SW_BYP_SEL_PTR, capsense_SW_BYP_SEL_SW_BYA_MASK | capsense_SW_BYP_SEL_SW_BYB_MASK);

            /* Connect AMUXBUS-B to HSCMP positive input */
            CY_SET_REG32(capsense_SW_HS_P_SEL_PTR, 0x00000000uL);
        #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

        /* Configure VREF */
        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            /* Connect VREF to REFGEN. Connect IDACB to CSDBUSA */
            newRegValue = CY_GET_REG32(capsense_SW_REFGEN_SEL_PTR);
            newRegValue |= capsense_SW_REFGEN_SEL_SW_SGR_MASK | capsense_SW_REFGEN_SEL_SW_IAIB_MASK;
            CY_SET_REG32(capsense_SW_REFGEN_SEL_PTR, newRegValue);
        #else
            /* Connect VREF to REFGEN (IAIB switch is open) */
            newRegValue = CY_GET_REG32(capsense_SW_REFGEN_SEL_PTR);
            newRegValue |= capsense_SW_REFGEN_SEL_SW_SGR_MASK;
            CY_SET_REG32(capsense_SW_REFGEN_SEL_PTR, newRegValue);
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */

        /* Connect VREFHI (from RefGen) to CSDCOMP when Vdda >= 2 V */
        CY_SET_REG32(capsense_SW_CMP_N_SEL_PTR, capsense_SW_CMP_N_SEL_SW_SCRH_STATIC_CLOSE);

        #if (capsense_2000_MV > capsense_CYDEV_VDDA_MV)

            /* Configure REFGEN. Set reference voltage when Vdda < 2 V */
            CY_SET_REG32(capsense_REFGEN_PTR, capsense_REFGEN_LV);

            /* Connect Vrefhi to AMUBUF positive input when Vdaa < 2V
             *  Connect AMUBUF to SCDCMP negative input when Vdaa < 2V
             */
            #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
                #if (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG)
                    CY_SET_REG32(capsense_SW_AMUXBUF_SEL_PTR, capsense_SW_AMUXBUF_SEL_SW_IRH_STATIC_CLOSE |
                                                                          capsense_SW_AMUXBUF_SEL_SW_ICB_PHI2);
                #else
                    CY_SET_REG32(capsense_SW_AMUXBUF_SEL_PTR, capsense_SW_AMUXBUF_SEL_SW_DEFAULT);
                #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */
                CY_SET_REG32(capsense_AMBUF_PTR, capsense_AMBUF_PWR_MODE_NORM);
            #else
                CY_SET_REG32(capsense_AMBUF_PTR, capsense_AMBUF_PWR_MODE_OFF);
            #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

            /* Connect VREFHI to HSCOMP */
            CY_SET_REG32(capsense_SW_HS_N_SEL_PTR, capsense_SW_HS_N_SEL_SW_HCRH_STATIC_CLOSE);
        #else

            /* Configure REFGEN. Set reference voltage when Vdda >= 2 V */
            CY_SET_REG32(capsense_REFGEN_PTR, capsense_REFGEN_HV);

            #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
                /* Turn on CSD_AMBUF high power level when Vdaa >= 2V */
                CY_SET_REG32(capsense_AMBUF_PTR, capsense_AMBUF_PWR_MODE_HI);

                #if (capsense_IDAC_SINKING != capsense_CSD_IDAC_CONFIG)
                    CY_SET_REG32(capsense_SW_AMUXBUF_SEL_PTR, capsense_SW_AMUXBUF_SEL_SW_IRH_STATIC_CLOSE |
                                                                          capsense_SW_AMUXBUF_SEL_SW_ICB_PHI2);
                #else
                    CY_SET_REG32(capsense_SW_AMUXBUF_SEL_PTR, capsense_SW_AMUXBUF_SEL_SW_DEFAULT);
                #endif /* (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG) */
            #else
                CY_SET_REG32(capsense_SW_AMUXBUF_SEL_PTR, capsense_SW_AMUXBUF_SEL_SW_DEFAULT);
            #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

            /* Connect VREFHI to HSCOMP */
            CY_SET_REG32(capsense_SW_HS_N_SEL_PTR, capsense_SW_HS_N_SEL_SW_HCRH_STATIC_CLOSE);
        #endif /* (capsense_2000_MV > capsense_CYDEV_VDDA_MV) */

        /* Configure IDACs mode */
        capsense_SsCSDConfigIDACs();

        /* Configure ModClk */
        capsense_SsSetModClkClockDivider((uint32)capsense_dsRam.modCsdClk);

        /* Set other CSD configurations */
        #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
            capsense_SsSetShieldDelay(capsense_CSD_SHIELD_DELAY);
        #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

        /* Configure HW block filter delay */
        capsense_SsCSDSetFilterDelay();

        #if (capsense_DISABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
            /* Enable power to sub-blocks */
            CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd |
                                                      capsense_CONFIG_SENSE_EN_MASK |
                                                      capsense_CONFIG_ENABLE_MASK);
        #endif /* (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN) */

        /* Set Csd Auto Zero time (set AZ_TIME bitmask) */
        CY_SET_REG32(capsense_SEQ_TIME_PTR, capsense_CSD_AUTO_ZERO_TIME);

        /* Select CMOD and Csh_tank/shield initialization switch resistance */
        CY_SET_REG32(capsense_SW_RES_PTR, 0x00000000);

        /* Set the number of dummy fine initialization cycles */
        CY_SET_REG32(capsense_SEQ_INIT_CNT_PTR, capsense_CSD_FINE_INIT_TIME);

    #else

        /* Configure IDACs mode */
        capsense_SsCSDConfigIDACs();

        /* Connect Cmod to AMUXBUS-A using HSIOM registers */
        capsense_WriteBitsSafe(capsense_CMOD_HSIOM_PTR, capsense_CMOD_HSIOM_MASK,
                    (uint32)(capsense_HSIOM_SEL_AMUXA << capsense_CMOD_HSIOM_SHIFT));

        #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
            capsense_SsSetShieldDelay(capsense_CSD_SHIELD_DELAY);
        #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

        /* Enable CSD block. Connect Vref Buffer to AMUX bus to make sure that Cmod is charged before scanning in active mode */
        #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
            CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd);
        #else
            CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);
        #endif
    #endif /* (capsense_ENABLE == capsense_CSDV2) */

    #if ((capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN) &&\
         (capsense_CLK_SOURCE_DIRECT == capsense_CSD_SNS_CLK_SOURCE))
         /* Set clock dividers and clock source mode */
        capsense_SsCSDConfigClock();
    #endif
}


/*******************************************************************************
* Function Name: capsense_SsCSDElectrodeCheck
****************************************************************************//**
*
* \brief
*   Checks if electrodes were previously connected using
 * capsense_CSDSetupWidgetExt() API and if yes disconnects them.
*
* \details
*   This function checks if capsense_eleCsdDisconnectFlag is set.
*   If it set, the function disconnects the previously connected electrode.
*   The previous IO is contained in capsense_curSnsIOPtr and
*   capsense_curFlashSnsPtr contains the previous data for Ganged
*   sensors.
*
*******************************************************************************/
void capsense_SsCSDElectrodeCheck(void)
{
    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        uint32 tempVal;
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */

    if (capsense_ENABLE == capsense_eleCsdDisconnectFlag)
    {
        /* Disconnect if electrodes were previous connected by CSDSetupWidgetExt() API */
        #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
            /* Check ganged sns flag  */
            if (capsense_GANGED_SNS_MASK == (capsense_curFlashWdgtPtr->staticConfig & capsense_GANGED_SNS_MASK))
            {
                /* Get number of ganged pins */
                tempVal = capsense_curFlashSnsPtr->numPins;

                /* Get IO pointer  */
                capsense_curSnsIOPtr = &capsense_ioList[capsense_curFlashSnsPtr->firstPinId];

                /* Disconnect all ganged sensors */
                do
                {
                    capsense_CSDDisconnectSns(capsense_curSnsIOPtr);
                    capsense_curSnsIOPtr++;
                    tempVal--;
                } while (0u != tempVal);
            }
            else
            {
                /* Disconnect ganged sensor */
                capsense_CSDDisconnectSns(capsense_curSnsIOPtr);
            }
        #else
            /* Disable sensor */
            capsense_CSDDisconnectSns(capsense_curSnsIOPtr);
        #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)  */

        capsense_eleCsdDisconnectFlag = 0u;
    }
}


/*******************************************************************************
* Function Name: capsense_SsCSDSetUpIdacs
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
void capsense_SsCSDSetUpIdacs(capsense_RAM_WD_BASE_STRUCT const *ptrWdgt)
{
    uint8 interruptState;
    uint32 idacGain;

    /* Getting IDAC gain */
    idacGain = capsense_idacGainTable[ptrWdgt->idacGainIndex].gainReg;

    #if (capsense_ENABLE == capsense_CSDV2)
        uint32 idacARegValue;
        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            uint32 idacBRegValue;
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */

        interruptState = CyEnterCriticalSection();

        /* Get IDACA Value */
        idacARegValue = CY_GET_REG32(capsense_CSD_IDACA_PTR);

        /* Clear IDACA value and gain */
        idacARegValue &= ~(capsense_IDAC_MOD_VAL_MASK | capsense_IDAC_GAIN_MASK);

        /* Set IDACA value gain */
        #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
            if (capsense_dsFlash.wdgtArray[(capsense_widgetIndex)].numCols <= capsense_sensorIndex)
            {
                idacARegValue |= (uint32)ptrWdgt->rowIdacMod[capsense_scanFreqIndex];
            }
            else
            {
                idacARegValue |= (uint32)ptrWdgt->idacMod[capsense_scanFreqIndex];
            }
        #else
            idacARegValue |= (uint32)ptrWdgt->idacMod[capsense_scanFreqIndex];
        #endif /* (capsense_CSD_MATRIX_WIDGET_EN | capsense_CSD_TOUCHPAD_WIDGET_EN) */
        idacARegValue |= idacGain;

        /* Update IDACA register with new value */
        CY_SET_REG32(capsense_CSD_IDACA_PTR, idacARegValue);
        CyExitCriticalSection(interruptState);

        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            interruptState = CyEnterCriticalSection();
            /* Get IDACB Value */
            idacBRegValue = CY_GET_REG32(capsense_CSD_IDACB_PTR);

            /* Clear IDACB value and gain */
            idacBRegValue &= ~(capsense_IDAC_COMP_VAL_MASK | capsense_IDAC_GAIN_MASK);

            /* Set IDACB value and gain */
            idacBRegValue |= (uint32)capsense_curRamSnsPtr->idacComp[capsense_scanFreqIndex];
            idacBRegValue |= idacGain;

            /* Update IDACA register with new value */
            CY_SET_REG32(capsense_CSD_IDACB_PTR, idacBRegValue);
            CyExitCriticalSection(interruptState);
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */

    #else

        uint32 newRegValue;
        uint8 const *ptrIdacMod = ptrWdgt->idacMod;

        #if (capsense_CSD_MATRIX_WIDGET_EN  | capsense_CSD_TOUCHPAD_WIDGET_EN)
            if (capsense_dsFlash.wdgtArray[(capsense_widgetIndex)].numCols <= capsense_sensorIndex)
            {
                ptrIdacMod = &ptrWdgt->rowIdacMod[0u];
            }
        #endif /* (capsense_CSD_MATRIX_WIDGET_EN  | capsense_CSD_TOUCHPAD_WIDGET_EN) */

        interruptState = CyEnterCriticalSection();

        /* Get Idac Value */
        newRegValue = CY_GET_REG32(capsense_IDAC_PTR);

        /* Clear Idac value and gain */
        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            newRegValue &= ~(capsense_IDAC_MOD_MASK | capsense_IDAC_COMP_MASK |
                capsense_IDAC_GAIN_MASK | (capsense_IDAC_GAIN_MASK << capsense_IDAC_COMP_DATA_OFFSET));
        #else
            newRegValue &= ~(capsense_IDAC_MOD_MASK | capsense_IDAC_GAIN_MASK);
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */

        /* Set Idac value and gain */
        #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
            newRegValue |= (ptrIdacMod[capsense_scanFreqIndex] |
                           (uint32)((uint32)capsense_curRamSnsPtr->idacComp[capsense_scanFreqIndex] <<
                           capsense_IDAC_COMP_DATA_OFFSET));
            newRegValue |= idacGain;
            newRegValue |= (idacGain << capsense_IDAC_COMP_DATA_OFFSET);
        #else
            newRegValue |= ptrIdacMod[capsense_scanFreqIndex];
            newRegValue |= idacGain;
        #endif /* (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) */
        CY_SET_REG32(capsense_IDAC_PTR, newRegValue);

        CyExitCriticalSection(interruptState);

    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


#if (capsense_ENABLE == capsense_CSDV2)
    /*******************************************************************************
    * Function Name: capsense_SsCSDGetNumberOfConversions
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
    uint32 capsense_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc)
    {
        uint32 conversionsNum;
        #if ((capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) && (capsense_ENABLE != capsense_CSDV2_REF9P6UA_EN))
            uint32 sampleClkFreqHz;
        #endif /* ((capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) && (capsense_ENABLE != capsense_CSDV2_REF9P6UA_EN)) */

        /* Calculate scanning resolution value in register */
        conversionsNum = (uint32)(1uL << resolution);

        #if(capsense_ENABLE != capsense_CSDV2_REF9P6UA_EN)
            /* Apply correction to oveflow for 16 bit resolution */
            if (capsense_RES16BIT == resolution)
            {
                conversionsNum -= ((snsClkDivider + 1u) >> 1u);

                #if (capsense_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ)
                    sampleClkFreqHz = CYDEV_BCLK__HFCLK__HZ / (uint32)capsense_dsRam.modCsdClk;

                    if (sampleClkFreqHz <= capsense_MOD_CSD_CLK_12MHZ)
                    {
                        conversionsNum -= capsense_CONFIG_FILTER_DELAY_2_CYCLES;
                    }
                    else if (sampleClkFreqHz <= capsense_MOD_CSD_CLK_24MHZ)
                    {
                        conversionsNum -= capsense_CONFIG_FILTER_DELAY_3_CYCLES;
                    }
                    else
                    {
                        conversionsNum -= capsense_CONFIG_FILTER_DELAY_4_CYCLES;
                    }
                #else
                    conversionsNum -= capsense_CONFIG_FILTER_DELAY_2_CYCLES;
                #endif /* (INSTANCE_NAME`_MOD_CSD_CLK_12MHZ < CYDEV_BCLK__HFCLK__HZ) */
            }
        #else
            /* CY_ID285392: Apply correction to oveflow for 16 bit resolution */
            if (capsense_RES16BIT == resolution)
            {
                conversionsNum -= capsense_EXTRA_COUNTS_MAX;
            }
        #endif

        if (0u < snsClkDivider)
        {
            conversionsNum /= snsClkDivider;
        }

    #if((capsense_CLK_SOURCE_PRS8  == capsense_CSD_SNS_CLK_SOURCE) ||\
        (capsense_CLK_SOURCE_PRS12 == capsense_CSD_SNS_CLK_SOURCE) ||\
        (capsense_CLK_SOURCE_PRSAUTO == capsense_CSD_SNS_CLK_SOURCE))
        switch (snsClkSrc)
        {
            case capsense_CLK_SOURCE_PRS8:
            case capsense_CLK_SOURCE_PRS12:
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
#endif /* (capsense_ENABLE == capsense_CSDV2) */


/*******************************************************************************
* Function Name: capsense_SsCSDConfigClock
****************************************************************************//**
*
* \brief
*  This function configure sense clock for different modes.
*
* \details
*  Function sets the clock divider and configures the mode based on configuration.
*
*******************************************************************************/
void capsense_SsCSDConfigClock(void)
{
    uint32 snsClkDivider;
    uint32 snsClkSrc;
    uint32 newRegValue;

    capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
             capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2WdgtRam;

    /* Get sense divider based on configuration */
    #if (capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN)
        snsClkDivider = (uint32)capsense_dsRam.snsCsdClk;
    #else
        #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
            /* Get SnsClck divider for rows or columns */
            if (capsense_dsFlash.wdgtArray[capsense_widgetIndex].numCols <= capsense_sensorIndex)
            {
                snsClkDivider = (uint32)(ptrWdgt->rowSnsClk);
            }
            else
            {
                snsClkDivider = (uint32)(ptrWdgt->snsClk);
            }
        #else
            snsClkDivider = (uint32)(ptrWdgt->snsClk);
        #endif /* (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN) */
    #endif /* (capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN) */

    /* Get sense clk source calculated in capsense_SsCSDInitialize() before */
    #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
        /* Get SnsClc Source for rows or columns */
        if (capsense_dsFlash.wdgtArray[capsense_widgetIndex].numCols <= capsense_sensorIndex)
        {
            snsClkSrc = (uint32)ptrWdgt->rowSnsClkSource;
        }
        else
        {
            snsClkSrc = (uint32)ptrWdgt->snsClkSource;
        }
    #else
        snsClkSrc = (uint32)ptrWdgt->snsClkSource;
    #endif /* (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN) */

    #if (capsense_ENABLE == capsense_CSDV2)
        newRegValue = (snsClkSrc << CYFLD_CSD_LFSR_SIZE__OFFSET);

        /* Configuring PRS SEL_BIT */
        if ((capsense_CLK_SOURCE_PRS8 == snsClkSrc) ||
            (capsense_CLK_SOURCE_PRS12 == snsClkSrc))
        {
            newRegValue |= capsense_SENSE_PERIOD_SEL_LFSR_MSB_MASK;
        }
    #else
        newRegValue = snsClkSrc;
    #endif /* (capsense_ENABLE == capsense_CSDV2) */

    #if (capsense_ENABLE == capsense_CSDV2)
        #if((capsense_CLK_SOURCE_PRS8  == capsense_CSD_SNS_CLK_SOURCE) ||\
            (capsense_CLK_SOURCE_PRS12 == capsense_CSD_SNS_CLK_SOURCE) ||\
            (capsense_CLK_SOURCE_PRSAUTO == capsense_CSD_SNS_CLK_SOURCE))
            switch (snsClkSrc)
            {
            case capsense_CLK_SOURCE_PRS8:
            case capsense_CLK_SOURCE_PRS12:
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
        #endif /* ((capsense_CLK_SOURCE_PRS8  == capsense_CSD_SNS_CLK_SOURCE) ||\
                   (capsense_CLK_SOURCE_PRS12 == capsense_CSD_SNS_CLK_SOURCE) ||\
                   (capsense_CLK_SOURCE_PRSAUTO == capsense_CSD_SNS_CLK_SOURCE)) */
    #endif
    capsense_SsCSDSetModeSnsClockDivider(newRegValue, snsClkDivider);
}


/*******************************************************************************
* Function Name: capsense_SsCSDCalculateScanDuration
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
*   capsense_counterResolution global variable and used in
*   capsense_SsCSDStartSample() function to trigger the scan process.
*
* \param wdgtIndex
*  ptrWdgt The pointer to the RAM_WD_BASE_STRUCT structure.
*
*******************************************************************************/
void capsense_SsCSDCalculateScanDuration(capsense_RAM_WD_BASE_STRUCT const *ptrWdgt)
{
    #if (capsense_ENABLE == capsense_CSDV2)
        uint32 conversionsNum;
        uint32 snsClkDivider;

        /* Get Number Of Conversions */
        #if (capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN)
            snsClkDivider = capsense_dsRam.snsCsdClk;
        #else
            #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
                /* Get SnsClck divider for rows or columns */
                if (capsense_dsFlash.wdgtArray[capsense_widgetIndex].numCols <= capsense_sensorIndex)
                {
                    snsClkDivider = (uint32)(ptrWdgt->rowSnsClk);
                }
                else
                {
                    snsClkDivider = (uint32)(ptrWdgt->snsClk);
                }
            #else
                snsClkDivider = (uint32)(ptrWdgt->snsClk);
            #endif /* (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN) */
        #endif /* (capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN) */

        conversionsNum = capsense_SsCSDGetNumberOfConversions(snsClkDivider, (uint32)ptrWdgt->resolution, (uint32)ptrWdgt->snsClkSource);

        /* Set Number Of Conversions based on scanning resolution */
        CY_SET_REG32(capsense_SEQ_NORM_CNT_PTR, (conversionsNum & capsense_SEQ_NORM_CNT_CONV_CNT_MASK));
    #else
        /* Set up scanning resolution  */
        capsense_counterResolution = (uint32)((0x00000001Lu << ptrWdgt->resolution) - 1u) << capsense_RESOLUTION_OFFSET;
    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


/*******************************************************************************
* Function Name: capsense_CSDSetupWidget
****************************************************************************//**
*
* \brief
*  Performs hardware and firmware initialization required for scanning sensors
*  in a specific widget using the CSD sensing method. This function requires using
*  the capsense_CSDScan() function to start scanning.
*
* \details
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_SetupWidget() function should be used instead.
*
*  This function initializes the specific widget common parameters to perform
*  the CSD scanning. The initialization includes setting up a Modulator and
*  Sense clock frequency and scanning resolution.
*
*  This function does not connect any specific sensors to the scanning hardware,
*  neither does it start a scanning process. The capsense_CSDScan()
*  API must be called after initializing the widget to start scanning.
*
*  This function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status.
*
*  This function is called by the capsense_SetupWidget() API if the
*  given widget uses the CSD sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
* \param  widgetId
*  Specifies the ID number of the widget to perform hardware and firmware
*  initialization required for scanning sensors in the specific widget.
*  A macro for the widget ID can be found in the capsense Configuration header
*  file defined as capsense_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void capsense_CSDSetupWidget(uint32 widgetId)
{
    capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                                capsense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;

    /* Save widget Id to have assess to it after scanning  */
    capsense_widgetIndex = (uint8)widgetId;

    capsense_SsSwitchSensingMode(capsense_SENSE_METHOD_CSD_E);

    #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
        /* Reset the frequency scan channel if enabled */
        capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;
    #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

    /* Disconnect previous electrode if it has been connected */
    capsense_SsCSDElectrodeCheck();

    /* Initialize IO Sns electrode structure pointer to current widget */
    capsense_curSnsIOPtr = (capsense_FLASH_IO_STRUCT const *)
                                    capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsFlash;

    /* Update status register in Data structure */
    capsense_dsRam.status &= ~capsense_STATUS_WDGT0_MASK;
    capsense_dsRam.status |= capsense_widgetIndex;

    capsense_SsCSDCalculateScanDuration(ptrWdgt);
    #if (((capsense_DISABLE == capsense_CSD_COMMON_SNS_CLK_EN) || \
          (capsense_CLK_SOURCE_DIRECT != capsense_CSD_SNS_CLK_SOURCE)) && \
         ((!(capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)) || \
          (capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN)))
        capsense_SsCSDConfigClock();
    #endif
}


/*******************************************************************************
* Function Name: capsense_CSDSetupWidgetExt
****************************************************************************//**
*
* \brief
*  Performs extended initialization for the CSD widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the capsense_CSDScanExt() function to initiate a scan.
*
* \details
*  Performs extended initialization for the CSD widget and also performs
*  initialization required for a specific sensor in the widget. This function
*  requires using the capsense_CSDScanExt() function to initiate a scan.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_SetupWidgetExt() function should be used instead.
*
*  This function does the same as capsense_CSDSetupWidget() and also
*  does the following tasks:
*    1. Connects the first sensor of the widget.
*    2. Configures the IDAC value.
*    3. Initializes an interrupt callback function to initialize a scan of the
*  next sensors in a widget.
*
*  Once this function is called to initialize a widget and a sensor, the
*  capsense_CSDScanExt() function is called to scan the sensor.
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
*  initialization required for scanning the specific sensor in the specific
*  widget.
*  A macro for the widget ID can be found in the capsense Configuration header
*  file defined as capsense_<WidgetName>_WDGT_ID.
*
* \param sensorId
*  Specifies the ID number of the sensor within the widget to perform hardware
*  and firmware initialization required for scanning a specific sensor in a
*  specific widget.
*  A macro for the sensor ID within a specified widget can be found in the
*  capsense Configuration header file defined as
*  capsense_<WidgetName>_SNS<SensorNumber>_ID
*
*******************************************************************************/
void capsense_CSDSetupWidgetExt(uint32 widgetId, uint32 sensorId)
{
    capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                                    capsense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;

    /* Save widget and sensor Ids to have access to it after scanning  */
    capsense_sensorIndex = (uint8)sensorId;

    /* Update global pointer to capsense_RAM_SNS_STRUCT to current sensor  */
    capsense_curRamSnsPtr = (capsense_RAM_SNS_STRUCT *)
                                              capsense_dsFlash.wdgtArray[widgetId].ptr2SnsRam
                                              + capsense_sensorIndex;

    capsense_CSDSetupWidget(widgetId);

     /* Setup Idac Value */
    capsense_SsCSDSetUpIdacs(ptrWdgt);

    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        /* initialize access pointers for current pointer to widget configuration in Flash */
        capsense_curFlashWdgtPtr = &capsense_dsFlash.wdgtArray[widgetId];
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)  */

    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        capsense_SsCSDConnectSensorExt(widgetId, sensorId);
    #else
        /* Enable sensor */
        capsense_curSnsIOPtr += capsense_sensorIndex;
        capsense_CSDConnectSns(capsense_curSnsIOPtr);
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)  */

    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        /* Save sns pointer */
        capsense_curFlashSnsPtr = (capsense_FLASH_SNS_STRUCT const *)
                                           capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsFlash +
                                           capsense_sensorIndex;
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */

    capsense_eleCsdDisconnectFlag = capsense_DISCONNECT_IO_FLAG;

    /* Setup ISR handler to single-sensor scan function */
    capsense_ISR_StartEx(&capsense_CSDPostSingleScan);
}

/*******************************************************************************
* Function Name: capsense_SsCSDStartSample
****************************************************************************//**
*
* \brief
*   Starts the CSD conversion.
*
* \details
*   This function assumes that the CSD block is already set up using
*   the capsense_CSDSetupWidget API and the sensor port-pin is connected to the CSD
*   block using capsense_CSDConnectSns.
*   For Third-generation HW block the function performs the following tasks:
*   1. Disconnects the Vref buffer from AMUX;
*   2. Precharges Cmod;
*   3. Makes the PreSettling delay to have a stable Vref voltage;
*   4. Sets the resolution to the Counter register to start scanning.
*
*******************************************************************************/
void capsense_SsCSDStartSample(void)
{
    #if (capsense_ENABLE != capsense_CSDV2)
        uint8 interruptState;
    #endif

    #ifdef capsense_START_SAMPLE_CALLBACK
        capsense_StartSampleCallback(capsense_widgetIndex, capsense_sensorIndex);
    #endif /* capsense_START_SAMPLE_CALLBACK */

    #if (capsense_ENABLE == capsense_CSDV2)
        /* Fourth-generation HW block section */

        /* Disable CSD interrupt to prevent it during coarse initialization */
        CyIntDisable(capsense_ISR_NUMBER);

        /* Enable power to sub-blocks */
        CY_SET_REG32(capsense_HSCMP_PTR, capsense_HSCMP_INIT_MASK);

        #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
            CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd |
                                                      capsense_CONFIG_SENSE_EN_MASK |
                                                      capsense_CONFIG_ENABLE_MASK);
            #if(capsense_CSD_ANALOG_STARTUP_DELAY_US > 0uL)
                CyDelayUs(capsense_CSD_ANALOG_STARTUP_DELAY_US);
            #endif /* (capsense_CSD_ANALOG_STARTUP_DELAY_US > 0uL) */
        #endif /* (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN) */

        /* Precharging Cmod and Csh */
        capsense_SsCSDCmodPrecharge();

        /* Trigger Scan */
        capsense_SsCSDTriggerScan();

    #else
        /* Third-generation HW block section */
        interruptState = CyEnterCriticalSection();

        /* Enable CSD block. Disconnect Vref Buffer from AMUX */
        #if ((capsense_CSH_PRECHARGE_IO_BUF == capsense_CSD_CSH_PRECHARGE_SRC) &&\
             (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN))
            CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CMOD_PRECHARGE_CONFIG_CSD_EN);
        #else
            CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);
        #endif

        /* Restart the clocks. Scan one cycle to reset the flip-flop for Direct clock mode */
        capsense_SsCSDClockRestart();

        /* Precharging Cmod to Vref */
        capsense_SsCSDCmodPrecharge();

        #if (capsense_CLK_SOURCE_DIRECT != capsense_CSD_SNS_CLK_SOURCE)
            /* Set PreSettling delay to skip IDAC glitch before scanning */
            CyDelayCycles(capsense_GLITCH_ELIMINATION_CYCLES);
        #endif /* (capsense_CSD_SNS_CLK_SOURCE != capsense_CLK_SOURCE_DIRECT) */

        /* Trigger Scan */
        capsense_SsCSDTriggerScan();

        CyExitCriticalSection(interruptState);
    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


/*******************************************************************************
* Function Name: capsense_CSDScanExt
****************************************************************************//**
*
* \brief
*  Starts the CSD conversion on the preconfigured sensor. This function requires
*  using the capsense_CSDSetupWidgetExt() function to set up the a
*  widget.
*
* \details
*  Starts the CSD conversion on the preconfigured sensor. This function requires
*  using the capsense_CSDSetupWidgetExt() function to set up the a
*  widget.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_ScanExt() function should be used instead.
*
*  This function performs single scanning of one sensor in the widget configured
*  by the capsense_CSDSetupWidgetExt() function. It does the following
*  tasks:
*    1. Sets the busy flag in the capsense_dsRam structure.
*    2. Performs the clock-phase alignment of the sense and modulator clocks.
*    3. Performs the Cmod pre-charging.
*    4. Starts single scanning.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*  This function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status.
*
*  The sensor must be preconfigured by using the
*  capsense_CSDSetupWidgetExt() API prior to calling this function.
*  The sensor remains ready for a next scan if a previous scan was triggered
*  by using the capsense_CSDScanExt() function. In this case, calling
*  capsense_CSDSetupWidgetExt() is not required every time before the
*  capsense_CSDScanExt() function. If a previous scan was triggered in
*  any other way - capsense_Scan(), capsense_ScanAllWidgets() or
*  capsense_RunTuner() - (see the capsense_RunTuner() function
*  description for more details), the sensor must be preconfigured again by
*  using the capsense_CSDSetupWidgetExt() API prior to calling the
*  capsense_CSDScanExt() function.
*
*  If disconnection of the sensors is required after calling
*  capsense_CSDScanExt(), the capsense_CSDDisconnectSns()
*  function can be used.
*
*******************************************************************************/
void capsense_CSDScanExt(void)
{
    #if ((capsense_DISABLE == capsense_CSD_COMMON_SNS_CLK_EN) && \
         (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN))
        capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                                        capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2WdgtRam;

        capsense_SsCSDCalculateScanDuration(ptrWdgt);
        capsense_SsCSDConfigClock();
    #endif

    /* Set Start of sensor scan flag */
    capsense_dsRam.status |= (capsense_SW_STS_BUSY | capsense_WDGT_SW_STS_BUSY);

    #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
        /* Reset the frequency scan channel if enabled */
        capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;
    #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

    #if (capsense_ENABLE != capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
        (capsense_ENABLE == capsense_CSDV2)
        #if(capsense_CSD_ANALOG_STARTUP_DELAY_US > 0uL)
            CyDelayUs(capsense_CSD_ANALOG_STARTUP_DELAY_US);
        #endif /* (capsense_CSD_ANALOG_STARTUP_DELAY_US > 0uL) */
    #endif /* (capsense_ENABLE != capsense_BLOCK_OFF_AFTER_SCAN_EN) &&\
              (capsense_ENABLE == capsense_CSDV2)*/

    capsense_SsCSDStartSample();
}


/*******************************************************************************
* Function Name: capsense_CSDScan
****************************************************************************//**
*
* \brief
*  This function initiates a scan for the sensors of the widget initialized by the
*  capsense_CSDSetupWidget() function.
*
* \details
*  This function initiates a scan for the sensors of the widget initialized by the
*  capsense_CSDSetupWidget() function.
*
*  \note This function is obsolete and kept for backward compatibility only.
*  The capsense_Scan() function should be used instead.
*
*  This function performs scanning of all the sensors in the widget configured by
*  the capsense_CSDSetupWidget() function. It does the following tasks:
*    1. Connects the first sensor of the widget.
*    2. Configures the IDAC value.
*    3. Initializes the interrupt callback function to initialize a scan of
*       the next sensors in a widget.
*    4. Starts scanning for the first sensor in the widget.
*
*  This function is called by the capsense_Scan() API if the given
*  widget uses the CSD sensing method.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases (for faster execution time or pipeline scanning for example).
*
*  This function is called when no scanning is in progress. I.e.
*  capsense_IsBusy() returns a non-busy status. The widget must be
*  preconfigured by the capsense_CSDSetupWidget() function if any other
*  widget was previously scanned or any other type of the scan functions was used.
*
*******************************************************************************/
void capsense_CSDScan(void)
{
    capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                                    capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2WdgtRam;

    /* Set all the sensors to inactive state */
    if(capsense_dsRam.scanCurrentISC != capsense_dsRam.scanCsdISC)
    {
        capsense_SsSetAllIOsState((uint32)capsense_dsRam.scanCsdISC);
        capsense_dsRam.scanCurrentISC = capsense_dsRam.scanCsdISC;
    }

     /*
      * Update capsense_sensorIndex with the first sensor in
      * widget to use it in ISR handler to configure the next sensor
      */
    capsense_sensorIndex = 0u;

    /* Update global pointer to capsense_RAM_SNS_STRUCT to current sensor  */
    capsense_curRamSnsPtr = (capsense_RAM_SNS_STRUCT *)
                                              capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsRam
                                              + capsense_sensorIndex;

    #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
        /* Reset the frequency scan channel if enabled */
        capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;
    #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

    /* Setup Idac Value */
   capsense_SsCSDSetUpIdacs(ptrWdgt);

    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if (capsense_GANGED_SNS_MASK == (capsense_dsFlash.wdgtArray[capsense_widgetIndex].staticConfig &
            capsense_GANGED_SNS_MASK))
        {
            /* Setup ISR handler to multiple-sensor scan function with ganged sensors */
            capsense_ISR_StartEx(&capsense_CSDPostMultiScanGanged);
        }
        else
        {
            /* Set up ISR handler to multiple-sensor scan function without ganged sensors */
            capsense_ISR_StartEx(&capsense_CSDPostMultiScan);
        }

        capsense_SsCSDConnectSensorExt((uint32)capsense_widgetIndex, (uint32)capsense_sensorIndex);
    #else
        /* initialize ptr to sensor IO structure to appropriate address */
        capsense_curSnsIOPtr = (capsense_FLASH_IO_STRUCT const *)
                                        capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsFlash
                                        + capsense_sensorIndex;

        /* Enable sensor */
        capsense_CSDConnectSns(capsense_curSnsIOPtr);

        /* Set-up ISR handler to multiple-sensor scan function without ganged sensors */
        capsense_ISR_StartEx(&capsense_CSDPostMultiScan);
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)  */

    /* Start scanning */
    capsense_CSDScanExt();
}


/*******************************************************************************
* Function Name: capsense_SsCSDConnectSensorExt
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
void capsense_SsCSDConnectSensorExt(uint32 widgetId, uint32 sensorId)
{
    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        uint32 tempVal;
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */

    /* initialize ptr to sensor IO structure to appropriate address */
    capsense_curSnsIOPtr = (capsense_FLASH_IO_STRUCT const *)
                                                      capsense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash
                                                      + sensorId;

    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if (capsense_GANGED_SNS_MASK ==
           (capsense_dsFlash.wdgtArray[widgetId].staticConfig &
            capsense_GANGED_SNS_MASK))
        {
            /* Get sns pointer */
            capsense_curFlashSnsPtr = (capsense_FLASH_SNS_STRUCT const *)
                                               capsense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash +
                                               sensorId;

            /* Get number of ganged pins */
            tempVal = capsense_curFlashSnsPtr->numPins;

            /* Get IO pointer  */
            capsense_curSnsIOPtr = &capsense_ioList[capsense_curFlashSnsPtr->firstPinId];

            /* Connect all ganged sensors  */
            do
            {
                capsense_CSDConnectSns(capsense_curSnsIOPtr);
                capsense_curSnsIOPtr++;
                tempVal--;
            } while (0u != tempVal);
        }
        else
        {
            /* Connect sensor */
            capsense_CSDConnectSns(capsense_curSnsIOPtr);
        }
    #else
        /* Connect sensor */
        capsense_CSDConnectSns(capsense_curSnsIOPtr);
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */
}


/*******************************************************************************
* Function Name: capsense_SsCSDDisconnectSnsExt
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
void capsense_SsCSDDisconnectSnsExt(uint32 widgetId, uint32 sensorId)
{
    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        uint32 tempVal;
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */

    /* initialize ptr to sensor IO structure to appropriate address        */
    capsense_curSnsIOPtr = (capsense_FLASH_IO_STRUCT const *)
                                                      capsense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash
                                                      + sensorId;

    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if ((capsense_dsFlash.wdgtArray[widgetId].staticConfig &
            capsense_GANGED_SNS_MASK) == capsense_GANGED_SNS_MASK)
        {
            /* Get sns pointer */
            capsense_curFlashSnsPtr = (capsense_FLASH_SNS_STRUCT const *)
                                               capsense_dsFlash.wdgtArray[widgetId].ptr2SnsFlash +
                                               sensorId;

            /* Get number of ganged pins */
            tempVal = capsense_curFlashSnsPtr->numPins;

            /* Get IO pointer  */
            capsense_curSnsIOPtr = &capsense_ioList[capsense_curFlashSnsPtr->firstPinId];

            /* Disconnect all ganged sensors */
            do
            {
                capsense_CSDDisconnectSns(capsense_curSnsIOPtr);
                capsense_curSnsIOPtr++;
                tempVal--;
            } while (0u != tempVal);
        }
        else
        {
            /* Disconnect ganged sensor */
            capsense_CSDDisconnectSns(capsense_curSnsIOPtr);
        }
    #else
        /* Disconnect ganged sensor */
        capsense_CSDDisconnectSns(capsense_curSnsIOPtr);
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */
}


/*******************************************************************************
* Function Name: capsense_CSDConnectSns
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
*  capsense_CSDConnectSns() function.
*
* \param  snsAddrPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a sensor
*  which to be connected to the sensing HW block.
*
*******************************************************************************/
void capsense_CSDConnectSns(capsense_FLASH_IO_STRUCT const *snsAddrPtr)
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
    newRegisterValue &= ~(capsense_HSIOM_SEL_MASK << pinHSIOMShift);
    newRegisterValue |= (uint32)((uint32)capsense_HSIOM_SEL_CSD_SENSE << pinHSIOMShift);

    /* Update port configuration register (drive mode) for sensor */
    CY_SET_REG32(snsAddrPtr->pcPtr, CY_GET_REG32(snsAddrPtr->pcPtr) & (uint32)~((uint32)capsense_GPIO_PC_MASK << pinModeShift));

    /* Update HSIOM register for sensor */
    CY_SET_REG32(snsAddrPtr->hsiomPtr, newRegisterValue);

    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: capsense_CSDDisconnectSns
****************************************************************************//**
*
* \brief
*  Disconnects a sensor port pin from the sensing HW block and the AMUX bus. Sets
*  the default state of the un-scanned sensor.
*
* \details
*  This function works identically to capsense_CSDConnectSns() except
*  it disconnects the specified port-pin used by the sensor.
*
*  Calling this function directly from the application layer is not
*  recommended. This function is used to implement only the user's specific
*  use cases. Functions that perform a setup and scan of sensor/widget
*  automatically set the required pin states and perform the sensor connection.
*  They ignore changes in the design made by the
*  capsense_CSDDisconnectSns() function.
*
* \param  snsAddrPtr
*  Specifies the pointer to the FLASH_IO_STRUCT object belonging to a sensor
*  which should be disconnected from the sensing HW block.
*
*******************************************************************************/
void capsense_CSDDisconnectSns(capsense_FLASH_IO_STRUCT const *snsAddrPtr)
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
    newPcRegValue &= ~(capsense_GPIO_PC_MASK << pinModeShift);

    newHsiomRegValue  = CY_GET_REG32(snsAddrPtr->hsiomPtr);
    newHsiomRegValue &= ~(capsense_HSIOM_SEL_MASK << pinHSIOMShift);
    CY_SET_REG32(snsAddrPtr->hsiomPtr, newHsiomRegValue);

    if(capsense_SNS_CONNECTION_GROUND == capsense_dsRam.scanCurrentISC)
    {
        newPcRegValue |= (CY_SYS_PINS_DM_STRONG << pinModeShift);
        CY_SET_REG32(snsAddrPtr->pcPtr, newPcRegValue);
    }
    else
    {
        newPcRegValue |= (CY_SYS_PINS_DM_ALG_HIZ << pinModeShift);
        if(capsense_SNS_CONNECTION_SHIELD == capsense_dsRam.scanCurrentISC)
        {
            /* Connect to Shield */
            newHsiomRegValue |= (capsense_HSIOM_SEL_CSD_SHIELD << pinHSIOMShift);
            CY_SET_REG32(snsAddrPtr->pcPtr, newPcRegValue);
            CY_SET_REG32(snsAddrPtr->hsiomPtr, newHsiomRegValue);
        }
    }
    /* Set logic 0 to port data register */
    CY_SET_REG32(snsAddrPtr->drPtr, CY_GET_REG32(snsAddrPtr->drPtr) & (uint32)~(uint32)((uint32)1u << snsAddrPtr->drShift));

    CyExitCriticalSection(interruptState);
}

#if ((capsense_CSD_SS_DIS != capsense_CSD_AUTOTUNE) || \
     (capsense_ENABLE == capsense_CSD_IDAC_AUTOCAL_EN))
    /*******************************************************************************
    * Function Name: capsense_SsCSDCalibrateCheck
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
    static cystatus capsense_SsCSDCalibrateCheck(uint32 widgetId, uint32 target)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;
        uint32 rawcount;
        uint32 snsIndex;
        uint32 freqChannel;
        uint32 upperLimit;
        uint32 lowerLimit;

        capsense_FLASH_WD_STRUCT const *ptrFlashWidget = &capsense_dsFlash.wdgtArray[widgetId];
        capsense_RAM_WD_BASE_STRUCT *ptrRamWidget = (capsense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;
        capsense_RAM_SNS_STRUCT *ptrRamSensor = ptrFlashWidget->ptr2SnsRam;

        /* Calculate acceptable raw count range based on the resolution, target and error */
        rawcount = (0x00000001Lu << ptrRamWidget->resolution) - 1u;
        lowerLimit = 0u;
        if (target > capsense_CSD_CALIBRATION_ERROR)
        {
            lowerLimit = target - capsense_CSD_CALIBRATION_ERROR;
        }
        upperLimit = target + capsense_CSD_CALIBRATION_ERROR;
        if (upperLimit > capsense_PERCENTAGE_100)
        {
            upperLimit = capsense_PERCENTAGE_100;
        }
        lowerLimit = (rawcount * lowerLimit) / capsense_PERCENTAGE_100;
        upperLimit = (rawcount * upperLimit) / capsense_PERCENTAGE_100;

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


    #if (capsense_ENABLE == capsense_CSD_IDAC_AUTO_GAIN_EN)
        /*******************************************************************************
        * Function Name: capsense_SsCSDSwitchIdacGain
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
        static uint32 capsense_SsCSDSwitchIdacGain(capsense_FLASH_WD_STRUCT const *ptrFlashWidget)
        {
            uint32 ratio;
            uint32 maxIdac;
            uint32 minIdac;
            uint32 status = 0u;
            uint32 freqChannel;
            uint32 gainIndex;

            capsense_RAM_WD_BASE_STRUCT *ptrRamWidget = (capsense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;
            #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
                uint32 snsIndex;
                capsense_RAM_SNS_STRUCT *ptrRamSensor = ptrFlashWidget->ptr2SnsRam;
            #endif

            gainIndex = ptrRamWidget->idacGainIndex;

            /* Find maximum and minimum IDACs */
            maxIdac = 0u;
            minIdac = capsense_CSD_CAL_IDAC_MAX_VALUE;
            for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                if (maxIdac < ptrRamWidget->idacMod[freqChannel])
                {
                    maxIdac = ptrRamWidget->idacMod[freqChannel];
                }
                if (minIdac > ptrRamWidget->idacMod[freqChannel])
                {
                    minIdac = ptrRamWidget->idacMod[freqChannel];
                }
                #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
                    if ((capsense_WD_TOUCHPAD_E == capsense_GET_WIDGET_TYPE(ptrFlashWidget)) ||
                        (capsense_WD_MATRIX_BUTTON_E == capsense_GET_WIDGET_TYPE(ptrFlashWidget)))
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
            #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
                for(snsIndex = 0u; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
                {
                    for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
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
                if (minIdac < capsense_CSD_IDAC_MIN)
                {
                    ratio = capsense_idacGainTable[gainIndex].gainValue /
                            capsense_idacGainTable[gainIndex - 1u].gainValue;
                    if ((maxIdac * ratio) < capsense_CSD_CAL_IDAC_MAX_VALUE)
                    {
                        /* Switch to lower idac gain */
                        ptrRamWidget->idacGainIndex--;
                        status = 1u;
                    }
                }
            }

            return (status);
        }
    #endif /* (capsense_ENABLE == capsense_CSD_IDAC_AUTO_GAIN_EN) */


    #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
        /*******************************************************************************
        * Function Name: capsense_SsCSDNormalizeIdac
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
        static void capsense_SsCSDNormalizeIdac(capsense_FLASH_WD_STRUCT const *ptrFlashWidget, uint32 target)
        {
            uint32 snsIndex;
            uint32 freqChannel;
            uint32 maxIdac;
            uint32 minIdac;
            uint32 minRaw;
            uint32 maxRawLevel;
            uint32 rawLevel;
            uint32 iMod;

            capsense_RAM_WD_BASE_STRUCT *ptrRamWidget = (capsense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;
            capsense_RAM_SNS_STRUCT *ptrRamSensor;

            /* Calculate raw count level based on resolution and target */
            maxRawLevel = (0x00000001Lu << ptrRamWidget->resolution) - 1u;

            /*
            * IDAC Normalization is performed separately for each multi-frequency channel
            * and separately for row and column
            */
            for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
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
                rawLevel = ((minRaw * capsense_PERCENTAGE_100) / maxRawLevel) + capsense_PERCENTAGE_100;
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
                    rawLevel = (((ptrRamSensor->raw[freqChannel] * capsense_PERCENTAGE_100) / maxRawLevel) +
                        capsense_PERCENTAGE_100) * ptrRamSensor->idacComp[freqChannel];
                    if (rawLevel < (iMod * target))
                    {
                        ptrRamSensor->idacComp[freqChannel] = 0u;
                    }
                    else
                    {
                        ptrRamSensor->idacComp[freqChannel] = (uint8)(((rawLevel - (iMod * target)) +
                            (capsense_PERCENTAGE_100 >> 1u)) / capsense_PERCENTAGE_100);
                    }
                    ptrRamSensor++;
                }

                #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
                    if ((capsense_WD_TOUCHPAD_E == capsense_GET_WIDGET_TYPE(ptrFlashWidget)) ||
                        (capsense_WD_MATRIX_BUTTON_E == capsense_GET_WIDGET_TYPE(ptrFlashWidget)))
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
                        rawLevel = ((minRaw * capsense_PERCENTAGE_100) / maxRawLevel) + capsense_PERCENTAGE_100;
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
                            rawLevel = (((ptrRamSensor->raw[freqChannel] * capsense_PERCENTAGE_100) / maxRawLevel) +
                                capsense_PERCENTAGE_100) * ptrRamSensor->idacComp[freqChannel];
                            if (rawLevel < (iMod * target))
                            {
                                ptrRamSensor->idacComp[freqChannel] = 0u;
                            }
                            else
                            {
                                ptrRamSensor->idacComp[freqChannel] = (uint8)(((rawLevel - (iMod * target)) +
                                    (capsense_PERCENTAGE_100 >> 1u)) / capsense_PERCENTAGE_100);
                            }
                            ptrRamSensor++;
                        }
                    }
                #endif
            }
        }
    #endif


    /*******************************************************************************
    * Function Name: capsense_SsCSDCalibrate
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
    *  capsense Configuration header file defined as
    *  capsense_<WidgetName>_WDGT_ID.
    *
    * \param target
    *  Specifies the calibration target in percentages of the maximum raw count.
    *
    *******************************************************************************/
    static void capsense_SsCSDCalibrate(uint32 widgetId, uint32 target)
    {
        uint32 snsIndex;
        uint32 freqChannel;
        uint32 calMask;
        uint32 temp;
        uint32 watchdogCounter;

        uint8 *ptrIdacMod;
        uint8 *ptrMaxIdac;

        uint8 maxIdac[capsense_NUM_SCAN_FREQS];

        #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
            uint8 maxRowIdac[capsense_NUM_SCAN_FREQS];
            uint32 dualWidgetType = 0u;
        #endif

        capsense_RAM_SNS_STRUCT *ptrRamSensor;
        capsense_FLASH_WD_STRUCT const *ptrFlashWidget = &capsense_dsFlash.wdgtArray[widgetId];
        capsense_RAM_WD_BASE_STRUCT *ptrRamWidget = (capsense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam;

        ptrIdacMod = &ptrRamWidget->idacMod[0u];
        ptrMaxIdac = &maxIdac[0u];

        for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
        {
            maxIdac[freqChannel] = 0u;
            #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
                maxRowIdac[freqChannel] = 0u;
            #endif
        }

        /* Calculate raw count level based on resolution and target */
        temp = (((0x00000001Lu << ptrRamWidget->resolution) - 1u) * target) / capsense_PERCENTAGE_100;

        #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
            if ((capsense_WD_TOUCHPAD_E == capsense_GET_WIDGET_TYPE(ptrFlashWidget)) ||
                (capsense_WD_MATRIX_BUTTON_E == capsense_GET_WIDGET_TYPE(ptrFlashWidget)))
            {
                dualWidgetType = 1u;
            }
        #endif

        /* Loop through the widget sensors */
        for(snsIndex = 0u; snsIndex < ptrFlashWidget->totalNumSns; snsIndex++)
        {
            #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
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
            calMask = capsense_CSD_CAL_MIDDLE_VALUE;
            for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                ptrIdacMod[freqChannel] = capsense_CSD_CAL_MIDDLE_VALUE;
                #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
                    ptrRamSensor->idacComp[freqChannel] = ptrIdacMod[freqChannel];
                #endif
            }

            /* Loop through IDAC code */
            do
            {
                /* Need to configure HW block with each IDAC change */
                capsense_CSDSetupWidgetExt(widgetId, snsIndex);

                #if (capsense_ENABLE == capsense_CSDV2)
                    capsense_DischargeExtCapacitors(capsense_EXT_CAP_DISCHARGE_TIME);
                #endif

                /* Scan sensor */
                capsense_CSDScanExt();

                watchdogCounter = capsense_CSD_CALIBR_WATCHDOG_CYCLES_NUM;
                while (((capsense_dsRam.status & capsense_SW_STS_BUSY) != 0u) && (0uL != watchdogCounter))
                {
                    watchdogCounter--;
                }

                /* Update IDAC based on scan result */
                for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
                {
                    if (ptrRamSensor->raw[freqChannel] < temp)
                    {
                        ptrIdacMod[freqChannel] &= (uint8)(~calMask);
                    }
                }

                /* Switch to the lower IDAC mask */
                calMask >>= 1u;
                for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
                {
                    ptrIdacMod[freqChannel] |= (uint8)calMask;
                    #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
                        ptrRamSensor->idacComp[freqChannel] = ptrIdacMod[freqChannel];
                    #endif
                    if (0u == calMask)
                    {
                        if (0u == ptrIdacMod[freqChannel])
                        {
                            ptrIdacMod[freqChannel] = 1u;
                            #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
                                ptrRamSensor->idacComp[freqChannel] = ptrIdacMod[freqChannel];
                            #endif
                        }
                    }
                }
            }
            while (calMask != 0u);

            for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
            {
                if (ptrMaxIdac[freqChannel] < ptrIdacMod[freqChannel])
                {
                    ptrMaxIdac[freqChannel] = ptrIdacMod[freqChannel];
                }
            }

            /* Perform scan again to get real raw count if IDAC was changed at the last iteration */
            capsense_CSDSetupWidgetExt(widgetId, snsIndex);
            capsense_CSDScanExt();

            watchdogCounter = capsense_CSD_CALIBR_WATCHDOG_CYCLES_NUM;
            while (((capsense_dsRam.status & capsense_SW_STS_BUSY) != 0u) && (0uL != watchdogCounter))
            {
                watchdogCounter--;
            }
        }

        for(freqChannel = capsense_NUM_SCAN_FREQS; freqChannel-- > 0u;)
        {
            ptrRamWidget->idacMod[freqChannel] = maxIdac[freqChannel];
            #if (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)
                if (0u != dualWidgetType)
                {
                    ptrRamWidget->rowIdacMod[freqChannel] = maxRowIdac[freqChannel];

                    #if (capsense_ENABLE == capsense_CSD_COL_ROW_IDAC_ALIGNMENT_EN)
                        #if (capsense_ENABLE == capsense_CSD_COMMON_SNS_CLK_EN)
                            if (ptrRamWidget->idacMod[freqChannel] < ptrRamWidget->rowIdacMod[freqChannel])
                            {
                                temp = ptrRamWidget->rowIdacMod[freqChannel];
                                if (temp > capsense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = capsense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->idacMod[freqChannel] = (uint8)temp;
                            }
                            else
                            {
                                temp = ptrRamWidget->idacMod[freqChannel];
                                if (temp > capsense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = capsense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->rowIdacMod[freqChannel] = (uint8)temp;
                            }
                        #else
                            if (((uint32)ptrRamWidget->idacMod[freqChannel] * ptrRamWidget->snsClk) <
                                ((uint32)ptrRamWidget->rowIdacMod[freqChannel] * ptrRamWidget->rowSnsClk))
                            {
                                temp = ((uint32)ptrRamWidget->rowIdacMod[freqChannel] *
                                                ptrRamWidget->rowSnsClk) / ptrRamWidget->snsClk;
                                if (temp > capsense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = capsense_CSD_CAL_IDAC_MAX_VALUE;
                                }
                                ptrRamWidget->idacMod[freqChannel] = (uint8)temp;
                            }
                            else
                            {
                                temp = ((uint32)ptrRamWidget->idacMod[freqChannel] *
                                                ptrRamWidget->snsClk) / ptrRamWidget->rowSnsClk;
                                if (temp > capsense_CSD_CAL_IDAC_MAX_VALUE)
                                {
                                    temp = capsense_CSD_CAL_IDAC_MAX_VALUE;
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
    * Function Name: capsense_CSDCalibrateWidget
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
    *  The capsense_CalibrateWidget() function should be used instead.
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
    *  capsense Configuration header file defined as
    *  capsense_<WidgetName>_WDGT_ID.
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
    cystatus capsense_CSDCalibrateWidget(uint32 widgetId, uint32 target)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;
        uint32 watchdogCounter;

        #if (capsense_ENABLE == capsense_CSD_IDAC_AUTO_GAIN_EN)
            uint32 gainSwitch;
        #endif

        capsense_FLASH_WD_STRUCT const *ptrFlashWidget = &capsense_dsFlash.wdgtArray[widgetId];

        if (capsense_WDGT_SW_STS_BUSY == (capsense_dsRam.status & capsense_WDGT_SW_STS_BUSY))
        {
            /* Previous widget is being scanned, return error */
            calibrateStatus = CYRET_INVALID_STATE;
        }
        else
        {
            /* Set default IDAC gain */
            ((capsense_RAM_WD_BASE_STRUCT *)ptrFlashWidget->ptr2WdgtRam)->idacGainIndex =
                capsense_CSD_IDAC_GAIN_INDEX_DEFAULT;

            /* Perform calibration */
            #if (capsense_ENABLE != capsense_CSD_IDAC_AUTO_GAIN_EN)
                capsense_SsCSDCalibrate(widgetId, target);
            #else
                do
                {
                    capsense_SsCSDCalibrate(widgetId, target);
                    gainSwitch = capsense_SsCSDSwitchIdacGain(ptrFlashWidget);
                } while(0u != gainSwitch);
            #endif

            #if (capsense_ENABLE == capsense_CSD_IDAC_COMP_EN)
                /* IDAC Normalization in Dual IDAC mode */
                capsense_SsCSDNormalizeIdac(ptrFlashWidget, target);
            #endif

            /* Perform specified widget scan to check calibration result */
            capsense_CSDSetupWidget(widgetId);
            capsense_CSDScan();

            watchdogCounter = capsense_WIDGET_MAX_SCAN_TIME;
            while (((capsense_dsRam.status & capsense_SW_STS_BUSY) != 0u) && (0uL != watchdogCounter))
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
                calibrateStatus = capsense_SsCSDCalibrateCheck(widgetId, target);
            }

             /* Update CRC */
            #if (capsense_ENABLE ==capsense_TST_WDGT_CRC_EN)
                capsense_DsUpdateWidgetCrc(widgetId);
            #endif
        }

        return calibrateStatus;
    }
#endif /* ((capsense_CSD_SS_DIS != capsense_CSD_AUTOTUNE)) || \
            (capsense_ENABLE == capsense_CSD_IDAC_AUTOCAL_EN)) */


#if (capsense_DISABLE == capsense_CSDV2)
    /*******************************************************************************
    * Function Name: capsense_SsCSDClockRestart
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
    CY_INLINE static void capsense_SsCSDClockRestart(void)
    {
        #if (capsense_CLK_SOURCE_DIRECT == capsense_CSD_SNS_CLK_SOURCE)
            uint32 watchdogCounter;
        #endif /* (capsense_CLK_SOURCE_DIRECT == capsense_CSD_SNS_CLK_SOURCE) */

        /* Stop clocks, set dividers, and start clock to align clock phase */
        capsense_SsSetModClkClockDivider((uint32)capsense_dsRam.modCsdClk);

        #if (capsense_ENABLE == capsense_IS_M0S8PERI_BLOCK)
            /* Stop sense clock clock   */
            CY_SET_REG32(capsense_SNSCLK_CMD_PTR,
                         ((uint32)capsense_SnsClk__DIV_ID <<
                         capsense_SNSCLK_CMD_DIV_SHIFT)|
                         ((uint32)capsense_SNSCLK_CMD_DISABLE_MASK));

            /* Check whether previous sense clock start command has finished. */
            while(0u != (CY_GET_REG32(capsense_SNSCLK_CMD_PTR) & capsense_SNSCLK_CMD_ENABLE_MASK))
            {
                /* Wait until previous sense clock start command has finished. */
            }

            /* Start sense clock aligned to previously started modulator clock. */
            CY_SET_REG32(capsense_SNSCLK_CMD_PTR,
                         (uint32)(((uint32)capsense_SnsClk__DIV_ID << capsense_SNSCLK_CMD_DIV_SHIFT) |
                          ((uint32)capsense_ModClk__PA_DIV_ID << capsense_SNSCLK_CMD_PA_DIV_SHIFT) |
                          capsense_SNSCLK_CMD_ENABLE_MASK));
        #else
            /* Clear bit to disable SnsClk clock. */
            CY_SET_REG32(capsense_SNSCLK_CMD_PTR,
                         CY_GET_REG32(capsense_SNSCLK_CMD_PTR) &
                         (uint32)(~(uint32)capsense_SnsClk__ENABLE_MASK));

            /* Set bit to enable SnsClk clock. */
            CY_SET_REG32(capsense_SNSCLK_CMD_PTR,
                         CY_GET_REG32(capsense_SNSCLK_CMD_PTR) |
                        capsense_SnsClk__ENABLE_MASK);
        #endif /* (capsense_ENABLE == capsense_IS_M0S8PERI_BLOCK) */

        #if (capsense_CLK_SOURCE_DIRECT == capsense_CSD_SNS_CLK_SOURCE)
            /* Scan one cycle to reset the flip-flop for Direct clock mode */
            CyIntDisable(capsense_ISR_NUMBER);
            CY_SET_REG32(capsense_COUNTER_PTR, capsense_ONE_CYCLE);

            watchdogCounter = capsense_ONE_CLOCK_WATCHDOG_CYCLES_NUM;
            while((0u != (CY_GET_REG32(capsense_COUNTER_PTR) & capsense_RESOLUTION_16_BITS)) && (0uL != watchdogCounter))
            {
                watchdogCounter--;
            }
            CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);
            CyIntClearPending(capsense_ISR_NUMBER);
        #endif /* (capsense_CLK_SOURCE_DIRECT == capsense_CSD_SNS_CLK_SOURCE) */
    }
#endif /* (capsense_DISABLE == capsense_CSDV2) */


/*******************************************************************************
* Function Name: capsense_SsCSDCmodPrecharge
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
CY_INLINE static void capsense_SsCSDCmodPrecharge(void)
{
    #if (capsense_ENABLE == capsense_CSDV2)
        uint32 watchdogCounter;
        /* Fourth-generation HW block section */

        CY_SET_REG32(capsense_CSDCMP_PTR, capsense_CSD_CSDCMP_INIT);
        CY_SET_REG32(capsense_SW_FW_MOD_SEL_PTR,  capsense_CSD_SW_FW_MOD_SEL_INIT);
        CY_SET_REG32(capsense_SW_FW_TANK_SEL_PTR, capsense_CSD_SW_FW_TANK_SEL_INIT);
        CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR,  capsense_CSD_SW_SHIELD_SEL_INIT);
        #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
            /*
             * Connect CMOD to (sense path) to HSCOMP: HMPM or HMPS or HMPT switches depend on Cmod connects to certain pad
             * Connect AMUXBUS-B to HSCMP positive input
             */
            CY_SET_REG32(capsense_SW_HS_P_SEL_PTR, capsense_SW_HS_P_SEL_COARSE);

            #if(0u != capsense_CSD_SHIELD_TANK_EN)
                /* Connect CTANK to AMUXBUS-A */
                capsense_WriteBitsSafe(capsense_CSH_HSIOM_PTR, capsense_CSH_HSIOM_MASK,
                    (uint32)(capsense_HSIOM_SEL_AMUXA << capsense_CSH_HSIOM_SHIFT));
            #endif /* (0u != capsense_CSD_SHIELD_TANK_EN) */
        #else
            /* Connect CMOD to (sense path) to HSCOMP: HMPM or HMPS or HMPT switches depend on Cmod connects to certain pad */
            CY_SET_REG32(capsense_SW_HS_P_SEL_PTR, capsense_SW_HS_P_SEL_COARSE);
        #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

        CY_SET_REG32(capsense_SW_RES_PTR, capsense_CSD_SW_RES_INIT);

        /* Clear all interrupt pending requests */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_ALL_MASK);

        CY_SET_REG32(capsense_INTR_MASK_PTR, capsense_CLEAR_MASK);

        /* Start SEQUENCER for coarse initialization for Cmod */
        CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SEQ_START_SEQ_MODE_MASK |
                                                         capsense_SEQ_START_START_MASK);

        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = capsense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM;

        /* Wait for INTR.INIT goes high */
        while((0u == (CY_GET_REG32(capsense_INTR_PTR) & capsense_INTR_INIT_MASK)) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }

        if (0u == watchdogCounter)
        {
            /* Set sequencer to idle state if coarse initialization fails */
            CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SEQ_START_ABORT_MASK);
        }

    #else

        uint32 tmpRegValue;
        uint32 newRegValue;
        uint32 watchdogCounter;

        /* Save the current IDAC configuration */
        tmpRegValue = CY_GET_REG32(capsense_IDAC_PTR);

        /* Wait until Cmod discharges below Vref */
        CyDelayCycles(capsense_CMOD_DISCHARGE_CYCLES);

        newRegValue = capsense_CSD_IDAC_PRECHARGE_CONFIG | (tmpRegValue & ~capsense_IDAC_MOD_CFG_MASK);

        /* Set the IDAC configuration for fast Cmod precharge to Vref */
        CY_SET_REG32(capsense_IDAC_PTR, newRegValue);

        #if (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG)
            CY_SET_REG32(capsense_CONFIG_PTR, CY_GET_REG32(capsense_CONFIG_PTR) & ~capsense_CONFIG_POLARITY_MASK);
        #endif /* (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG) */

        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = capsense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM;

        /* Wait until Cmod reaches to Vref */
        while((0u == (CY_GET_REG32(capsense_STATUS_PTR) & capsense_STATUS_SAMPLE)) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }

        #if (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG)
            CY_SET_REG32(capsense_CONFIG_PTR, CY_GET_REG32(capsense_CONFIG_PTR) | capsense_CONFIG_POLARITY_MASK);
        #endif /* (capsense_IDAC_SINKING == capsense_CSD_IDAC_CONFIG) */

        /* Restore the current IDAC configuration */
        CY_SET_REG32(capsense_IDAC_PTR, tmpRegValue);

        /* Enable the sense modulator output */
        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN | capsense_CONFIG_SENSE_EN_MASK);

        CyIntEnable(capsense_ISR_NUMBER);

    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


/*******************************************************************************
* Function Name: capsense_SsCSDTriggerScan
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
CY_INLINE static void capsense_SsCSDTriggerScan(void)
{
    #if (capsense_ENABLE == capsense_CSDV2)

        /* Fourth-generation HW block section */

        uint32 watchdogCounter;

        /* Clear previous interrupts */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_ALL_MASK);

        /* Clear pending interrupts  */
        CyIntClearPending(capsense_ISR_NUMBER);

        /* Enable CSD interrupt */
        CyIntEnable(capsense_ISR_NUMBER);


        CY_SET_REG32(capsense_SW_HS_P_SEL_PTR, capsense_CSD_SW_HS_P_SEL_SCAN);

        /* Set scanning configuration for switches */
        CY_SET_REG32(capsense_SW_FW_MOD_SEL_PTR, capsense_CSD_SW_FW_MOD_SEL_SCAN);
        CY_SET_REG32(capsense_SW_FW_TANK_SEL_PTR,capsense_CSD_SW_FW_TANK_SEL_SCAN);

        CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR,  capsense_CSD_SW_SHIELD_SEL_SCAN);

        #if((capsense_ENABLE == capsense_CSD_SHIELD_EN) && (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN))
            /* Connect CTANK to AMUXBUS-B */
            capsense_SsCSDEnableShieldTank();
        #endif /* ((capsense_ENABLE == capsense_CSD_SHIELD_EN) && (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN)) */

        CY_SET_REG32(capsense_SW_RES_PTR, capsense_CSD_SW_RES_SCAN);
        CY_SET_REG32(capsense_CSDCMP_PTR, capsense_CSD_CSDCMP_SCAN);

        #if (capsense_DISABLE == capsense_CSD_SHIELD_EN)
            /* Disable HSCOMP during the sampling phase when shield is disabled */
            CY_SET_REG32(capsense_HSCMP_PTR, 0u);
        #else
            CY_SET_REG32(capsense_HSCMP_PTR, capsense_HSCMP_SCAN_MASK);
        #endif /* (capsense_DISABLE == capsense_CSD_SHIELD_EN) */

        #if (capsense_CLK_SOURCE_DIRECT != capsense_CSD_SNS_CLK_SOURCE)
            /* Force the LFSR to it's initial state (all ones) */
            CY_SET_REG32(capsense_SENSE_PERIOD_PTR, CY_GET_REG32(capsense_SENSE_PERIOD_PTR) |
                                                           capsense_SENSE_PERIOD_LFSR_CLEAR_MASK);
        #endif /* (capsense_CLK_SOURCE_DIRECT != capsense_CSD_SNS_CLK_SOURCE) */

        /* Enable SAMPLE interrupt */
        CY_SET_REG32(capsense_INTR_MASK_PTR, capsense_INTR_MASK_SAMPLE_MASK);

        /* Init Watchdog Counter to prevent a hang */
        watchdogCounter = capsense_CSD_PRECHARGE_WATCHDOG_CYCLES_NUM;

        /* Wait for IDLE state of the HW sequencer */
        while((0u != (capsense_STAT_SEQ_REG & capsense_STAT_SEQ_SEQ_STATE_MASK)) && (0u != watchdogCounter))
        {
            watchdogCounter--;
        }

        /* Start SEQUENCER for fine initialization scan for Cmod and then for normal scan */
        CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SEQ_START_AZ0_SKIP_MASK |
                                                     capsense_SEQ_START_AZ1_SKIP_MASK |
                                                     capsense_SEQ_START_START_MASK);

    #else

        /* Third-generation HW block section */

        /* Set resolution to Counter register to start scanning */
        CY_SET_REG32(capsense_COUNTER_PTR, capsense_counterResolution);

    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}

#endif  /* (capsense_ENABLE == capsense_CSD_EN) */


/* [] END OF FILE */
