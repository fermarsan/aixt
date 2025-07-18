/*******************************************************************************
* File Name: di0.c  
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
#include "di0.h"

static di0_BACKUP_STRUCT  di0_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: di0_Sleep
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
*  \snippet di0_SUT.c usage_di0_Sleep_Wakeup
*******************************************************************************/
void di0_Sleep(void)
{
    #if defined(di0__PC)
        di0_backup.pcState = di0_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            di0_backup.usbState = di0_CR1_REG;
            di0_USB_POWER_REG |= di0_USBIO_ENTER_SLEEP;
            di0_CR1_REG &= di0_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(di0__SIO)
        di0_backup.sioState = di0_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        di0_SIO_REG &= (uint32)(~di0_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: di0_Wakeup
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
*  Refer to di0_Sleep() for an example usage.
*******************************************************************************/
void di0_Wakeup(void)
{
    #if defined(di0__PC)
        di0_PC = di0_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            di0_USB_POWER_REG &= di0_USBIO_EXIT_SLEEP_PH1;
            di0_CR1_REG = di0_backup.usbState;
            di0_USB_POWER_REG &= di0_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(di0__SIO)
        di0_SIO_REG = di0_backup.sioState;
    #endif
}


/* [] END OF FILE */
