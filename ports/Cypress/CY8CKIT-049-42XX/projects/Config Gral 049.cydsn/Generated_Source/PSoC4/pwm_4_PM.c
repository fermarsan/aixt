/*******************************************************************************
* File Name: pwm_4.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "pwm_4.h"

static pwm_4_BACKUP_STRUCT  pwm_4_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: pwm_4_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet pwm_4_SUT.c usage_pwm_4_Sleep_Wakeup
*******************************************************************************/
void pwm_4_Sleep(void)
{
    #if defined(pwm_4__PC)
        pwm_4_backup.pcState = pwm_4_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            pwm_4_backup.usbState = pwm_4_CR1_REG;
            pwm_4_USB_POWER_REG |= pwm_4_USBIO_ENTER_SLEEP;
            pwm_4_CR1_REG &= pwm_4_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pwm_4__SIO)
        pwm_4_backup.sioState = pwm_4_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        pwm_4_SIO_REG &= (uint32)(~pwm_4_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: pwm_4_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to pwm_4_Sleep() for an example usage.
*******************************************************************************/
void pwm_4_Wakeup(void)
{
    #if defined(pwm_4__PC)
        pwm_4_PC = pwm_4_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            pwm_4_USB_POWER_REG &= pwm_4_USBIO_EXIT_SLEEP_PH1;
            pwm_4_CR1_REG = pwm_4_backup.usbState;
            pwm_4_USB_POWER_REG &= pwm_4_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pwm_4__SIO)
        pwm_4_SIO_REG = pwm_4_backup.sioState;
    #endif
}


/* [] END OF FILE */
