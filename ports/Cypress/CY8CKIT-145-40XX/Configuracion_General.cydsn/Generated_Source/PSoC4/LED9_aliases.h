/*******************************************************************************
* File Name: LED9.h  
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

#if !defined(CY_PINS_LED9_ALIASES_H) /* Pins LED9_ALIASES_H */
#define CY_PINS_LED9_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LED9_0			(LED9__0__PC)
#define LED9_0_PS		(LED9__0__PS)
#define LED9_0_PC		(LED9__0__PC)
#define LED9_0_DR		(LED9__0__DR)
#define LED9_0_SHIFT	(LED9__0__SHIFT)
#define LED9_0_INTR	((uint16)((uint16)0x0003u << (LED9__0__SHIFT*2u)))

#define LED9_INTR_ALL	 ((uint16)(LED9_0_INTR))


#endif /* End Pins LED9_ALIASES_H */


/* [] END OF FILE */
