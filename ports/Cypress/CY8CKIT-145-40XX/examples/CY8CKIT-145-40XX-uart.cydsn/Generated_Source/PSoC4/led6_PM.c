/*******************************************************************************
* File Name: led6.c  
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
#include "led6.h"

static led6_BACKUP_STRUCT  led6_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: led6_Sleep
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
*  \snippet led6_SUT.c usage_led6_Sleep_Wakeup
*******************************************************************************/
void led6_Sleep(void)
{
    #if defined(led6__PC)
        led6_backup.pcState = led6_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            led6_backup.usbState = led6_CR1_REG;
            led6_USB_POWER_REG |= led6_USBIO_ENTER_SLEEP;
            led6_CR1_REG &= led6_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(led6__SIO)
        led6_backup.sioState = led6_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        led6_SIO_REG &= (uint32)(~led6_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: led6_Wakeup
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
*  Refer to led6_Sleep() for an example usage.
*******************************************************************************/
void led6_Wakeup(void)
{
    #if defined(led6__PC)
        led6_PC = led6_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            led6_USB_POWER_REG &= led6_USBIO_EXIT_SLEEP_PH1;
            led6_CR1_REG = led6_backup.usbState;
            led6_USB_POWER_REG &= led6_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(led6__SIO)
        led6_SIO_REG = led6_backup.sioState;
    #endif
}


/* [] END OF FILE */
