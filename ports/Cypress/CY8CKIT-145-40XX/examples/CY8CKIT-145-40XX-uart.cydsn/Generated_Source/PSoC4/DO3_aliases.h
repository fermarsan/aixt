/*******************************************************************************
* File Name: DO3.h  
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

#if !defined(CY_PINS_DO3_ALIASES_H) /* Pins DO3_ALIASES_H */
#define CY_PINS_DO3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DO3_0			(DO3__0__PC)
#define DO3_0_PS		(DO3__0__PS)
#define DO3_0_PC		(DO3__0__PC)
#define DO3_0_DR		(DO3__0__DR)
#define DO3_0_SHIFT	(DO3__0__SHIFT)
#define DO3_0_INTR	((uint16)((uint16)0x0003u << (DO3__0__SHIFT*2u)))

#define DO3_INTR_ALL	 ((uint16)(DO3_0_INTR))


#endif /* End Pins DO3_ALIASES_H */


/* [] END OF FILE */
