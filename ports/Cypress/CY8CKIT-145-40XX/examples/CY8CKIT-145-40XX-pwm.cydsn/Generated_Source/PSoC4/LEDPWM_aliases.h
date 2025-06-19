/*******************************************************************************
* File Name: LEDPWM.h  
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

#if !defined(CY_PINS_LEDPWM_ALIASES_H) /* Pins LEDPWM_ALIASES_H */
#define CY_PINS_LEDPWM_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LEDPWM_0			(LEDPWM__0__PC)
#define LEDPWM_0_PS		(LEDPWM__0__PS)
#define LEDPWM_0_PC		(LEDPWM__0__PC)
#define LEDPWM_0_DR		(LEDPWM__0__DR)
#define LEDPWM_0_SHIFT	(LEDPWM__0__SHIFT)
#define LEDPWM_0_INTR	((uint16)((uint16)0x0003u << (LEDPWM__0__SHIFT*2u)))

#define LEDPWM_INTR_ALL	 ((uint16)(LEDPWM_0_INTR))


#endif /* End Pins LEDPWM_ALIASES_H */


/* [] END OF FILE */
