/*******************************************************************************
* File Name: led1.h  
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

#if !defined(CY_PINS_led1_ALIASES_H) /* Pins led1_ALIASES_H */
#define CY_PINS_led1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define led1_0			(led1__0__PC)
#define led1_0_PS		(led1__0__PS)
#define led1_0_PC		(led1__0__PC)
#define led1_0_DR		(led1__0__DR)
#define led1_0_SHIFT	(led1__0__SHIFT)
#define led1_0_INTR	((uint16)((uint16)0x0003u << (led1__0__SHIFT*2u)))

#define led1_INTR_ALL	 ((uint16)(led1_0_INTR))


#endif /* End Pins led1_ALIASES_H */


/* [] END OF FILE */
