/*******************************************************************************
* File Name: pwm3_PM.c
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

#include "pwm3.h"

static pwm3_BACKUP_STRUCT pwm3_backup;


/*******************************************************************************
* Function Name: pwm3_SaveConfig
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
void pwm3_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm3_Sleep
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
void pwm3_Sleep(void)
{
    if(0u != (pwm3_BLOCK_CONTROL_REG & pwm3_MASK))
    {
        pwm3_backup.enableState = 1u;
    }
    else
    {
        pwm3_backup.enableState = 0u;
    }

    pwm3_Stop();
    pwm3_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm3_RestoreConfig
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
void pwm3_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm3_Wakeup
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
void pwm3_Wakeup(void)
{
    pwm3_RestoreConfig();

    if(0u != pwm3_backup.enableState)
    {
        pwm3_Enable();
    }
}


/* [] END OF FILE */
