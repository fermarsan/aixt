/*******************************************************************************
* File Name: Clock3.h
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

#if !defined(CY_CLOCK_Clock3_H)
#define CY_CLOCK_Clock3_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock3_StartEx(uint32 alignClkDiv);
#define Clock3_Start() \
    Clock3_StartEx(Clock3__PA_DIV_ID)

#else

void Clock3_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock3_Stop(void);

void Clock3_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock3_GetDividerRegister(void);
uint8  Clock3_GetFractionalDividerRegister(void);

#define Clock3_Enable()                         Clock3_Start()
#define Clock3_Disable()                        Clock3_Stop()
#define Clock3_SetDividerRegister(clkDivider, reset)  \
    Clock3_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock3_SetDivider(clkDivider)           Clock3_SetDividerRegister((clkDivider), 1u)
#define Clock3_SetDividerValue(clkDivider)      Clock3_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock3_DIV_ID     Clock3__DIV_ID

#define Clock3_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock3_CTRL_REG   (*(reg32 *)Clock3__CTRL_REGISTER)
#define Clock3_DIV_REG    (*(reg32 *)Clock3__DIV_REGISTER)

#define Clock3_CMD_DIV_SHIFT          (0u)
#define Clock3_CMD_PA_DIV_SHIFT       (8u)
#define Clock3_CMD_DISABLE_SHIFT      (30u)
#define Clock3_CMD_ENABLE_SHIFT       (31u)

#define Clock3_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock3_CMD_DISABLE_SHIFT))
#define Clock3_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock3_CMD_ENABLE_SHIFT))

#define Clock3_DIV_FRAC_MASK  (0x000000F8u)
#define Clock3_DIV_FRAC_SHIFT (3u)
#define Clock3_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock3_DIV_INT_SHIFT  (8u)

#else 

#define Clock3_DIV_REG        (*(reg32 *)Clock3__REGISTER)
#define Clock3_ENABLE_REG     Clock3_DIV_REG
#define Clock3_DIV_FRAC_MASK  Clock3__FRAC_MASK
#define Clock3_DIV_FRAC_SHIFT (16u)
#define Clock3_DIV_INT_MASK   Clock3__DIVIDER_MASK
#define Clock3_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock3_H) */

/* [] END OF FILE */
