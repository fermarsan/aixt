/*******************************************************************************
* File Name: led8.h  
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

#if !defined(CY_PINS_led8_ALIASES_H) /* Pins led8_ALIASES_H */
#define CY_PINS_led8_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define led8_0			(led8__0__PC)
#define led8_0_PS		(led8__0__PS)
#define led8_0_PC		(led8__0__PC)
#define led8_0_DR		(led8__0__DR)
#define led8_0_SHIFT	(led8__0__SHIFT)
#define led8_0_INTR	((uint16)((uint16)0x0003u << (led8__0__SHIFT*2u)))

#define led8_INTR_ALL	 ((uint16)(led8_0_INTR))


#endif /* End Pins led8_ALIASES_H */


/* [] END OF FILE */
