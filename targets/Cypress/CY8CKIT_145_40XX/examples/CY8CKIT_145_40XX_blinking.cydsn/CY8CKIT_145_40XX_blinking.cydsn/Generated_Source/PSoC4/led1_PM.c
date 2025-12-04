/*******************************************************************************
* File Name: led1.c  
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
#include "led1.h"

static led1_BACKUP_STRUCT  led1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: led1_Sleep
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
*  \snippet led1_SUT.c usage_led1_Sleep_Wakeup
*******************************************************************************/
void led1_Sleep(void)
{
    #if defined(led1__PC)
        led1_backup.pcState = led1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            led1_backup.usbState = led1_CR1_REG;
            led1_USB_POWER_REG |= led1_USBIO_ENTER_SLEEP;
            led1_CR1_REG &= led1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(led1__SIO)
        led1_backup.sioState = led1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        led1_SIO_REG &= (uint32)(~led1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: led1_Wakeup
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
*  Refer to led1_Sleep() for an example usage.
*******************************************************************************/
void led1_Wakeup(void)
{
    #if defined(led1__PC)
        led1_PC = led1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            led1_USB_POWER_REG &= led1_USBIO_EXIT_SLEEP_PH1;
            led1_CR1_REG = led1_backup.usbState;
            led1_USB_POWER_REG &= led1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(led1__SIO)
        led1_SIO_REG = led1_backup.sioState;
    #endif
}


/* [] END OF FILE */
