/*******************************************************************************
* File Name: in0_adc.c  
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
#include "in0_adc.h"

static in0_adc_BACKUP_STRUCT  in0_adc_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: in0_adc_Sleep
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
*  \snippet in0_adc_SUT.c usage_in0_adc_Sleep_Wakeup
*******************************************************************************/
void in0_adc_Sleep(void)
{
    #if defined(in0_adc__PC)
        in0_adc_backup.pcState = in0_adc_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            in0_adc_backup.usbState = in0_adc_CR1_REG;
            in0_adc_USB_POWER_REG |= in0_adc_USBIO_ENTER_SLEEP;
            in0_adc_CR1_REG &= in0_adc_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(in0_adc__SIO)
        in0_adc_backup.sioState = in0_adc_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        in0_adc_SIO_REG &= (uint32)(~in0_adc_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: in0_adc_Wakeup
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
*  Refer to in0_adc_Sleep() for an example usage.
*******************************************************************************/
void in0_adc_Wakeup(void)
{
    #if defined(in0_adc__PC)
        in0_adc_PC = in0_adc_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            in0_adc_USB_POWER_REG &= in0_adc_USBIO_EXIT_SLEEP_PH1;
            in0_adc_CR1_REG = in0_adc_backup.usbState;
            in0_adc_USB_POWER_REG &= in0_adc_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(in0_adc__SIO)
        in0_adc_SIO_REG = in0_adc_backup.sioState;
    #endif
}


/* [] END OF FILE */
