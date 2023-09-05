/*******************************************************************************
* File Name: led11.h  
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

#if !defined(CY_PINS_led11_ALIASES_H) /* Pins led11_ALIASES_H */
#define CY_PINS_led11_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define led11_0			(led11__0__PC)
#define led11_0_PS		(led11__0__PS)
#define led11_0_PC		(led11__0__PC)
#define led11_0_DR		(led11__0__DR)
#define led11_0_SHIFT	(led11__0__SHIFT)
#define led11_0_INTR	((uint16)((uint16)0x0003u << (led11__0__SHIFT*2u)))

#define led11_INTR_ALL	 ((uint16)(led11_0_INTR))


#endif /* End Pins led11_ALIASES_H */


/* [] END OF FILE */
