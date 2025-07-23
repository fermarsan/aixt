/*******************************************************************************
* File Name: pwm_3.h  
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

#if !defined(CY_PINS_pwm_3_ALIASES_H) /* Pins pwm_3_ALIASES_H */
#define CY_PINS_pwm_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define pwm_3_0			(pwm_3__0__PC)
#define pwm_3_0_PS		(pwm_3__0__PS)
#define pwm_3_0_PC		(pwm_3__0__PC)
#define pwm_3_0_DR		(pwm_3__0__DR)
#define pwm_3_0_SHIFT	(pwm_3__0__SHIFT)
#define pwm_3_0_INTR	((uint16)((uint16)0x0003u << (pwm_3__0__SHIFT*2u)))

#define pwm_3_INTR_ALL	 ((uint16)(pwm_3_0_INTR))


#endif /* End Pins pwm_3_ALIASES_H */


/* [] END OF FILE */
