/*******************************************************************************
* File Name: di10.c  
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
#include "di10.h"

static di10_BACKUP_STRUCT  di10_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: di10_Sleep
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
*  \snippet di10_SUT.c usage_di10_Sleep_Wakeup
*******************************************************************************/
void di10_Sleep(void)
{
    #if defined(di10__PC)
        di10_backup.pcState = di10_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            di10_backup.usbState = di10_CR1_REG;
            di10_USB_POWER_REG |= di10_USBIO_ENTER_SLEEP;
            di10_CR1_REG &= di10_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(di10__SIO)
        di10_backup.sioState = di10_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        di10_SIO_REG &= (uint32)(~di10_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: di10_Wakeup
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
*  Refer to di10_Sleep() for an example usage.
*******************************************************************************/
void di10_Wakeup(void)
{
    #if defined(di10__PC)
        di10_PC = di10_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            di10_USB_POWER_REG &= di10_USBIO_EXIT_SLEEP_PH1;
            di10_CR1_REG = di10_backup.usbState;
            di10_USB_POWER_REG &= di10_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(di10__SIO)
        di10_SIO_REG = di10_backup.sioState;
    #endif
}


/* [] END OF FILE */
