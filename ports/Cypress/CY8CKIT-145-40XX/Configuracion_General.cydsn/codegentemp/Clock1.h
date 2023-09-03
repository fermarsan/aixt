/*******************************************************************************
* File Name: Clock1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock1_H)
#define CY_CLOCK_Clock1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock1_StartEx(uint32 alignClkDiv);
#define Clock1_Start() \
    Clock1_StartEx(Clock1__PA_DIV_ID)

#else

void Clock1_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock1_Stop(void);

void Clock1_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock1_GetDividerRegister(void);
uint8  Clock1_GetFractionalDividerRegister(void);

#define Clock1_Enable()                         Clock1_Start()
#define Clock1_Disable()                        Clock1_Stop()
#define Clock1_SetDividerRegister(clkDivider, reset)  \
    Clock1_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock1_SetDivider(clkDivider)           Clock1_SetDividerRegister((clkDivider), 1u)
#define Clock1_SetDividerValue(clkDivider)      Clock1_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock1_DIV_ID     Clock1__DIV_ID

#define Clock1_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock1_CTRL_REG   (*(reg32 *)Clock1__CTRL_REGISTER)
#define Clock1_DIV_REG    (*(reg32 *)Clock1__DIV_REGISTER)

#define Clock1_CMD_DIV_SHIFT          (0u)
#define Clock1_CMD_PA_DIV_SHIFT       (8u)
#define Clock1_CMD_DISABLE_SHIFT      (30u)
#define Clock1_CMD_ENABLE_SHIFT       (31u)

#define Clock1_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock1_CMD_DISABLE_SHIFT))
#define Clock1_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock1_CMD_ENABLE_SHIFT))

#define Clock1_DIV_FRAC_MASK  (0x000000F8u)
#define Clock1_DIV_FRAC_SHIFT (3u)
#define Clock1_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock1_DIV_INT_SHIFT  (8u)

#else 

#define Clock1_DIV_REG        (*(reg32 *)Clock1__REGISTER)
#define Clock1_ENABLE_REG     Clock1_DIV_REG
#define Clock1_DIV_FRAC_MASK  Clock1__FRAC_MASK
#define Clock1_DIV_FRAC_SHIFT (16u)
#define Clock1_DIV_INT_MASK   Clock1__DIVIDER_MASK
#define Clock1_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock1_H) */

/* [] END OF FILE */
