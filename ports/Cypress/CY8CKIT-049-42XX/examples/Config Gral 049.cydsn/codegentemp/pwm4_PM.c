/*******************************************************************************
* File Name: pwm4_PM.c
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

#include "pwm4.h"

static pwm4_BACKUP_STRUCT pwm4_backup;


/*******************************************************************************
* Function Name: pwm4_SaveConfig
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
void pwm4_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm4_Sleep
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
void pwm4_Sleep(void)
{
    if(0u != (pwm4_BLOCK_CONTROL_REG & pwm4_MASK))
    {
        pwm4_backup.enableState = 1u;
    }
    else
    {
        pwm4_backup.enableState = 0u;
    }

    pwm4_Stop();
    pwm4_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm4_RestoreConfig
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
void pwm4_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm4_Wakeup
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
void pwm4_Wakeup(void)
{
    pwm4_RestoreConfig();

    if(0u != pwm4_backup.enableState)
    {
        pwm4_Enable();
    }
}


/* [] END OF FILE */
