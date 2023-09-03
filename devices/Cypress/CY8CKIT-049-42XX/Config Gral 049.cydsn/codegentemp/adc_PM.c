/*******************************************************************************
* File Name: adc_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "adc.h"


/***************************************
* Local data allocation
***************************************/

static adc_BACKUP_STRUCT  adc_backup =
{
    adc_DISABLED,
    0u    
};


/*******************************************************************************
* Function Name: adc_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void adc_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: adc_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void adc_RestoreConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: adc_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  adc_backup - modified.
*
*******************************************************************************/
void adc_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    adc_backup.dftRegVal = adc_SAR_DFT_CTRL_REG & (uint32)~adc_ADFT_OVERRIDE;
    adc_SAR_DFT_CTRL_REG |= adc_ADFT_OVERRIDE;
    if((adc_SAR_CTRL_REG  & adc_ENABLE) != 0u)
    {
        if((adc_SAR_SAMPLE_CTRL_REG & adc_CONTINUOUS_EN) != 0u)
        {
            adc_backup.enableState = adc_ENABLED | adc_STARTED;
        }
        else
        {
            adc_backup.enableState = adc_ENABLED;
        }
        adc_StopConvert();
        adc_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((adc_SAR_CTRL_REG & adc_BOOSTPUMP_EN) != 0u)
        {
            adc_SAR_CTRL_REG &= (uint32)~adc_BOOSTPUMP_EN;
            adc_backup.enableState |= adc_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        adc_backup.enableState = adc_DISABLED;
    }
}


/*******************************************************************************
* Function Name: adc_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  adc_backup - used.
*
*******************************************************************************/
void adc_Wakeup(void)
{
    adc_SAR_DFT_CTRL_REG = adc_backup.dftRegVal;
    if(adc_backup.enableState != adc_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((adc_backup.enableState & adc_BOOSTPUMP_ENABLED) != 0u)
        {
            adc_SAR_CTRL_REG |= adc_BOOSTPUMP_EN;
        }
        adc_Enable();
        if((adc_backup.enableState & adc_STARTED) != 0u)
        {
            adc_StartConvert();
        }
    }
}
/* [] END OF FILE */
