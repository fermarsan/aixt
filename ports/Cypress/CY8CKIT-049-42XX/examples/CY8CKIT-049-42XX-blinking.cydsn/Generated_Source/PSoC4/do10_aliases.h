/*******************************************************************************
* File Name: do10.h  
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

#if !defined(CY_PINS_do10_ALIASES_H) /* Pins do10_ALIASES_H */
#define CY_PINS_do10_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define do10_0			(do10__0__PC)
#define do10_0_PS		(do10__0__PS)
#define do10_0_PC		(do10__0__PC)
#define do10_0_DR		(do10__0__DR)
#define do10_0_SHIFT	(do10__0__SHIFT)
#define do10_0_INTR	((uint16)((uint16)0x0003u << (do10__0__SHIFT*2u)))

#define do10_INTR_ALL	 ((uint16)(do10_0_INTR))


#endif /* End Pins do10_ALIASES_H */


/* [] END OF FILE */
