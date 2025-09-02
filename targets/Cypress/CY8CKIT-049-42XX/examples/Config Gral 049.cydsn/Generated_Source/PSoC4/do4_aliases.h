/*******************************************************************************
* File Name: do4.h  
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

#if !defined(CY_PINS_do4_ALIASES_H) /* Pins do4_ALIASES_H */
#define CY_PINS_do4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define do4_0			(do4__0__PC)
#define do4_0_PS		(do4__0__PS)
#define do4_0_PC		(do4__0__PC)
#define do4_0_DR		(do4__0__DR)
#define do4_0_SHIFT	(do4__0__SHIFT)
#define do4_0_INTR	((uint16)((uint16)0x0003u << (do4__0__SHIFT*2u)))

#define do4_INTR_ALL	 ((uint16)(do4_0_INTR))


#endif /* End Pins do4_ALIASES_H */


/* [] END OF FILE */
