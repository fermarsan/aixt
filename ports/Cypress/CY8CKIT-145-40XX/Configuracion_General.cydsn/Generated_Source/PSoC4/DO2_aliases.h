/*******************************************************************************
* File Name: DO2.h  
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

#if !defined(CY_PINS_DO2_ALIASES_H) /* Pins DO2_ALIASES_H */
#define CY_PINS_DO2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DO2_0			(DO2__0__PC)
#define DO2_0_PS		(DO2__0__PS)
#define DO2_0_PC		(DO2__0__PC)
#define DO2_0_DR		(DO2__0__DR)
#define DO2_0_SHIFT	(DO2__0__SHIFT)
#define DO2_0_INTR	((uint16)((uint16)0x0003u << (DO2__0__SHIFT*2u)))

#define DO2_INTR_ALL	 ((uint16)(DO2_0_INTR))


#endif /* End Pins DO2_ALIASES_H */


/* [] END OF FILE */
