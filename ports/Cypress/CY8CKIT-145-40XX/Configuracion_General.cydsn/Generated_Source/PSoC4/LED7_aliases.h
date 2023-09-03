/*******************************************************************************
* File Name: LED7.h  
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

#if !defined(CY_PINS_LED7_ALIASES_H) /* Pins LED7_ALIASES_H */
#define CY_PINS_LED7_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LED7_0			(LED7__0__PC)
#define LED7_0_PS		(LED7__0__PS)
#define LED7_0_PC		(LED7__0__PC)
#define LED7_0_DR		(LED7__0__DR)
#define LED7_0_SHIFT	(LED7__0__SHIFT)
#define LED7_0_INTR	((uint16)((uint16)0x0003u << (LED7__0__SHIFT*2u)))

#define LED7_INTR_ALL	 ((uint16)(LED7_0_INTR))


#endif /* End Pins LED7_ALIASES_H */


/* [] END OF FILE */
