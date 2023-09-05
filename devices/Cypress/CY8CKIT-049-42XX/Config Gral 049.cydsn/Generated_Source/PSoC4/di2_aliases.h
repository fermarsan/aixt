/*******************************************************************************
* File Name: di2.h  
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

#if !defined(CY_PINS_di2_ALIASES_H) /* Pins di2_ALIASES_H */
#define CY_PINS_di2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define di2_0			(di2__0__PC)
#define di2_0_PS		(di2__0__PS)
#define di2_0_PC		(di2__0__PC)
#define di2_0_DR		(di2__0__DR)
#define di2_0_SHIFT	(di2__0__SHIFT)
#define di2_0_INTR	((uint16)((uint16)0x0003u << (di2__0__SHIFT*2u)))

#define di2_INTR_ALL	 ((uint16)(di2_0_INTR))


#endif /* End Pins di2_ALIASES_H */


/* [] END OF FILE */
