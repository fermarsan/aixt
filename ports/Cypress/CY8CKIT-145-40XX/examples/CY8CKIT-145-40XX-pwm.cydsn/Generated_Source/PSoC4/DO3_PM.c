/*******************************************************************************
* File Name: DO3.c  
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
#include "DO3.h"

static DO3_BACKUP_STRUCT  DO3_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DO3_Sleep
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
*  \snippet DO3_SUT.c usage_DO3_Sleep_Wakeup
*******************************************************************************/
void DO3_Sleep(void)
{
    #if defined(DO3__PC)
        DO3_backup.pcState = DO3_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DO3_backup.usbState = DO3_CR1_REG;
            DO3_USB_POWER_REG |= DO3_USBIO_ENTER_SLEEP;
            DO3_CR1_REG &= DO3_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DO3__SIO)
        DO3_backup.sioState = DO3_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DO3_SIO_REG &= (uint32)(~DO3_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DO3_Wakeup
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
*  Refer to DO3_Sleep() for an example usage.
*******************************************************************************/
void DO3_Wakeup(void)
{
    #if defined(DO3__PC)
        DO3_PC = DO3_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DO3_USB_POWER_REG &= DO3_USBIO_EXIT_SLEEP_PH1;
            DO3_CR1_REG = DO3_backup.usbState;
            DO3_USB_POWER_REG &= DO3_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DO3__SIO)
        DO3_SIO_REG = DO3_backup.sioState;
    #endif
}


/* [] END OF FILE */
