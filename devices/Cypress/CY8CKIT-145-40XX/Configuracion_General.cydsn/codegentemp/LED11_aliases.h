/*******************************************************************************
* File Name: LED11.h  
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

#if !defined(CY_PINS_LED11_ALIASES_H) /* Pins LED11_ALIASES_H */
#define CY_PINS_LED11_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LED11_0			(LED11__0__PC)
#define LED11_0_PS		(LED11__0__PS)
#define LED11_0_PC		(LED11__0__PC)
#define LED11_0_DR		(LED11__0__DR)
#define LED11_0_SHIFT	(LED11__0__SHIFT)
#define LED11_0_INTR	((uint16)((uint16)0x0003u << (LED11__0__SHIFT*2u)))

#define LED11_INTR_ALL	 ((uint16)(LED11_0_INTR))


#endif /* End Pins LED11_ALIASES_H */


/* [] END OF FILE */
