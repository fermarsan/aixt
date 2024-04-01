/*******************************************************************************
* File Name: di7.h  
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

#if !defined(CY_PINS_di7_ALIASES_H) /* Pins di7_ALIASES_H */
#define CY_PINS_di7_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define di7_0			(di7__0__PC)
#define di7_0_PS		(di7__0__PS)
#define di7_0_PC		(di7__0__PC)
#define di7_0_DR		(di7__0__DR)
#define di7_0_SHIFT	(di7__0__SHIFT)
#define di7_0_INTR	((uint16)((uint16)0x0003u << (di7__0__SHIFT*2u)))

#define di7_INTR_ALL	 ((uint16)(di7_0_INTR))


#endif /* End Pins di7_ALIASES_H */


/* [] END OF FILE */
