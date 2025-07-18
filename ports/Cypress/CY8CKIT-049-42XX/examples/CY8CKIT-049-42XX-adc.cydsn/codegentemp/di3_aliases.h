/*******************************************************************************
* File Name: di3.h  
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

#if !defined(CY_PINS_di3_ALIASES_H) /* Pins di3_ALIASES_H */
#define CY_PINS_di3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define di3_0			(di3__0__PC)
#define di3_0_PS		(di3__0__PS)
#define di3_0_PC		(di3__0__PC)
#define di3_0_DR		(di3__0__DR)
#define di3_0_SHIFT	(di3__0__SHIFT)
#define di3_0_INTR	((uint16)((uint16)0x0003u << (di3__0__SHIFT*2u)))

#define di3_INTR_ALL	 ((uint16)(di3_0_INTR))


#endif /* End Pins di3_ALIASES_H */


/* [] END OF FILE */
