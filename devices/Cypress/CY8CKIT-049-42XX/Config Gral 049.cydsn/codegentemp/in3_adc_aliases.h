/*******************************************************************************
* File Name: in3_adc.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_in3_adc_ALIASES_H) /* Pins in3_adc_ALIASES_H */
#define CY_PINS_in3_adc_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define in3_adc_0			(in3_adc__0__PC)
#define in3_adc_0_PS		(in3_adc__0__PS)
#define in3_adc_0_PC		(in3_adc__0__PC)
#define in3_adc_0_DR		(in3_adc__0__DR)
#define in3_adc_0_SHIFT	(in3_adc__0__SHIFT)
#define in3_adc_0_INTR	((uint16)((uint16)0x0003u << (in3_adc__0__SHIFT*2u)))

#define in3_adc_INTR_ALL	 ((uint16)(in3_adc_0_INTR))


#endif /* End Pins in3_adc_ALIASES_H */


/* [] END OF FILE */
