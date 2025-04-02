/*******************************************************************************
* File Name: di6.h  
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

#if !defined(CY_PINS_di6_ALIASES_H) /* Pins di6_ALIASES_H */
#define CY_PINS_di6_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define di6_0			(di6__0__PC)
#define di6_0_PS		(di6__0__PS)
#define di6_0_PC		(di6__0__PC)
#define di6_0_DR		(di6__0__DR)
#define di6_0_SHIFT	(di6__0__SHIFT)
#define di6_0_INTR	((uint16)((uint16)0x0003u << (di6__0__SHIFT*2u)))

#define di6_INTR_ALL	 ((uint16)(di6_0_INTR))


#endif /* End Pins di6_ALIASES_H */


/* [] END OF FILE */
