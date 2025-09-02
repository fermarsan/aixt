/*******************************************************************************
* File Name: BTN2.h  
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

#if !defined(CY_PINS_BTN2_ALIASES_H) /* Pins BTN2_ALIASES_H */
#define CY_PINS_BTN2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BTN2_0			(BTN2__0__PC)
#define BTN2_0_PS		(BTN2__0__PS)
#define BTN2_0_PC		(BTN2__0__PC)
#define BTN2_0_DR		(BTN2__0__DR)
#define BTN2_0_SHIFT	(BTN2__0__SHIFT)
#define BTN2_0_INTR	((uint16)((uint16)0x0003u << (BTN2__0__SHIFT*2u)))

#define BTN2_INTR_ALL	 ((uint16)(BTN2_0_INTR))


#endif /* End Pins BTN2_ALIASES_H */


/* [] END OF FILE */
