/*******************************************************************************
* File Name: pwm1_PM.c
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

#include "pwm1.h"

static pwm1_BACKUP_STRUCT pwm1_backup;


/*******************************************************************************
* Function Name: pwm1_SaveConfig
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
void pwm1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm1_Sleep
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
void pwm1_Sleep(void)
{
    if(0u != (pwm1_BLOCK_CONTROL_REG & pwm1_MASK))
    {
        pwm1_backup.enableState = 1u;
    }
    else
    {
        pwm1_backup.enableState = 0u;
    }

    pwm1_Stop();
    pwm1_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm1_RestoreConfig
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
void pwm1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm1_Wakeup
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
void pwm1_Wakeup(void)
{
    pwm1_RestoreConfig();

    if(0u != pwm1_backup.enableState)
    {
        pwm1_Enable();
    }
}


/* [] END OF FILE */
