/*******************************************************************************
* File Name: do3.h  
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

#if !defined(CY_PINS_do3_ALIASES_H) /* Pins do3_ALIASES_H */
#define CY_PINS_do3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define do3_0			(do3__0__PC)
#define do3_0_PS		(do3__0__PS)
#define do3_0_PC		(do3__0__PC)
#define do3_0_DR		(do3__0__DR)
#define do3_0_SHIFT	(do3__0__SHIFT)
#define do3_0_INTR	((uint16)((uint16)0x0003u << (do3__0__SHIFT*2u)))

#define do3_INTR_ALL	 ((uint16)(do3_0_INTR))


#endif /* End Pins do3_ALIASES_H */


/* [] END OF FILE */
