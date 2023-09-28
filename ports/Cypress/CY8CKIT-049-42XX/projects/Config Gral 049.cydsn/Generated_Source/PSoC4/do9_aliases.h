/*******************************************************************************
* File Name: do9.h  
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

#if !defined(CY_PINS_do9_ALIASES_H) /* Pins do9_ALIASES_H */
#define CY_PINS_do9_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define do9_0			(do9__0__PC)
#define do9_0_PS		(do9__0__PS)
#define do9_0_PC		(do9__0__PC)
#define do9_0_DR		(do9__0__DR)
#define do9_0_SHIFT	(do9__0__SHIFT)
#define do9_0_INTR	((uint16)((uint16)0x0003u << (do9__0__SHIFT*2u)))

#define do9_INTR_ALL	 ((uint16)(do9_0_INTR))


#endif /* End Pins do9_ALIASES_H */


/* [] END OF FILE */
