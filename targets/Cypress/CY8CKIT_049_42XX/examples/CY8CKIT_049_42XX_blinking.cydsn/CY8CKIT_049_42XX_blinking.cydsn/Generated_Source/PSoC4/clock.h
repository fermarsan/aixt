/*******************************************************************************
* File Name: clock.h
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

#if !defined(CY_CLOCK_clock_H)
#define CY_CLOCK_clock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void clock_StartEx(uint32 alignClkDiv);
#define clock_Start() \
    clock_StartEx(clock__PA_DIV_ID)

#else

void clock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void clock_Stop(void);

void clock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 clock_GetDividerRegister(void);
uint8  clock_GetFractionalDividerRegister(void);

#define clock_Enable()                         clock_Start()
#define clock_Disable()                        clock_Stop()
#define clock_SetDividerRegister(clkDivider, reset)  \
    clock_SetFractionalDividerRegister((clkDivider), 0u)
#define clock_SetDivider(clkDivider)           clock_SetDividerRegister((clkDivider), 1u)
#define clock_SetDividerValue(clkDivider)      clock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define clock_DIV_ID     clock__DIV_ID

#define clock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define clock_CTRL_REG   (*(reg32 *)clock__CTRL_REGISTER)
#define clock_DIV_REG    (*(reg32 *)clock__DIV_REGISTER)

#define clock_CMD_DIV_SHIFT          (0u)
#define clock_CMD_PA_DIV_SHIFT       (8u)
#define clock_CMD_DISABLE_SHIFT      (30u)
#define clock_CMD_ENABLE_SHIFT       (31u)

#define clock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << clock_CMD_DISABLE_SHIFT))
#define clock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << clock_CMD_ENABLE_SHIFT))

#define clock_DIV_FRAC_MASK  (0x000000F8u)
#define clock_DIV_FRAC_SHIFT (3u)
#define clock_DIV_INT_MASK   (0xFFFFFF00u)
#define clock_DIV_INT_SHIFT  (8u)

#else 

#define clock_DIV_REG        (*(reg32 *)clock__REGISTER)
#define clock_ENABLE_REG     clock_DIV_REG
#define clock_DIV_FRAC_MASK  clock__FRAC_MASK
#define clock_DIV_FRAC_SHIFT (16u)
#define clock_DIV_INT_MASK   clock__DIVIDER_MASK
#define clock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_clock_H) */

/* [] END OF FILE */
