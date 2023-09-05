/*******************************************************************************
* File Name: pwm0_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "pwm0.h"

static pwm0_BACKUP_STRUCT pwm0_backup;


/*******************************************************************************
* Function Name: pwm0_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm0_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm0_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm0_Sleep(void)
{
    if(0u != (pwm0_BLOCK_CONTROL_REG & pwm0_MASK))
    {
        pwm0_backup.enableState = 1u;
    }
    else
    {
        pwm0_backup.enableState = 0u;
    }

    pwm0_Stop();
    pwm0_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm0_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm0_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm0_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm0_Wakeup(void)
{
    pwm0_RestoreConfig();

    if(0u != pwm0_backup.enableState)
    {
        pwm0_Enable();
    }
}


/* [] END OF FILE */
