/*******************************************************************************
* File Name: LED4.h  
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

#if !defined(CY_PINS_LED4_ALIASES_H) /* Pins LED4_ALIASES_H */
#define CY_PINS_LED4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LED4_0			(LED4__0__PC)
#define LED4_0_PS		(LED4__0__PS)
#define LED4_0_PC		(LED4__0__PC)
#define LED4_0_DR		(LED4__0__DR)
#define LED4_0_SHIFT	(LED4__0__SHIFT)
#define LED4_0_INTR	((uint16)((uint16)0x0003u << (LED4__0__SHIFT*2u)))

#define LED4_INTR_ALL	 ((uint16)(LED4_0_INTR))


#endif /* End Pins LED4_ALIASES_H */


/* [] END OF FILE */
