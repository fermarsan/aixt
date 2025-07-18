/*******************************************************************************
* File Name: do5.h  
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

#if !defined(CY_PINS_do5_ALIASES_H) /* Pins do5_ALIASES_H */
#define CY_PINS_do5_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define do5_0			(do5__0__PC)
#define do5_0_PS		(do5__0__PS)
#define do5_0_PC		(do5__0__PC)
#define do5_0_DR		(do5__0__DR)
#define do5_0_SHIFT	(do5__0__SHIFT)
#define do5_0_INTR	((uint16)((uint16)0x0003u << (do5__0__SHIFT*2u)))

#define do5_INTR_ALL	 ((uint16)(do5_0_INTR))


#endif /* End Pins do5_ALIASES_H */


/* [] END OF FILE */
