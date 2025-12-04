/*******************************************************************************
* File Name: pwm2_PM.c
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

#include "pwm2.h"

static pwm2_BACKUP_STRUCT pwm2_backup;


/*******************************************************************************
* Function Name: pwm2_SaveConfig
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
void pwm2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm2_Sleep
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
void pwm2_Sleep(void)
{
    if(0u != (pwm2_BLOCK_CONTROL_REG & pwm2_MASK))
    {
        pwm2_backup.enableState = 1u;
    }
    else
    {
        pwm2_backup.enableState = 0u;
    }

    pwm2_Stop();
    pwm2_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm2_RestoreConfig
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
void pwm2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm2_Wakeup
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
void pwm2_Wakeup(void)
{
    pwm2_RestoreConfig();

    if(0u != pwm2_backup.enableState)
    {
        pwm2_Enable();
    }
}


/* [] END OF FILE */
