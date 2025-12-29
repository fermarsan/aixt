/*******************************************************************************
* File Name: DI3.c  
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
#include "DI3.h"

static DI3_BACKUP_STRUCT  DI3_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DI3_Sleep
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
*  \snippet DI3_SUT.c usage_DI3_Sleep_Wakeup
*******************************************************************************/
void DI3_Sleep(void)
{
    #if defined(DI3__PC)
        DI3_backup.pcState = DI3_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DI3_backup.usbState = DI3_CR1_REG;
            DI3_USB_POWER_REG |= DI3_USBIO_ENTER_SLEEP;
            DI3_CR1_REG &= DI3_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DI3__SIO)
        DI3_backup.sioState = DI3_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DI3_SIO_REG &= (uint32)(~DI3_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DI3_Wakeup
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
*  Refer to DI3_Sleep() for an example usage.
*******************************************************************************/
void DI3_Wakeup(void)
{
    #if defined(DI3__PC)
        DI3_PC = DI3_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DI3_USB_POWER_REG &= DI3_USBIO_EXIT_SLEEP_PH1;
            DI3_CR1_REG = DI3_backup.usbState;
            DI3_USB_POWER_REG &= DI3_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DI3__SIO)
        DI3_SIO_REG = DI3_backup.sioState;
    #endif
}


/* [] END OF FILE */
