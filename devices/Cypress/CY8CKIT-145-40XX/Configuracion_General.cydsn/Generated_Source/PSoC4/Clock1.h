/*******************************************************************************
* File Name: clock1.h
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

#if !defined(CY_CLOCK_clock1_H)
#define CY_CLOCK_clock1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void clock1_StartEx(uint32 alignClkDiv);
#define clock1_Start() \
    clock1_StartEx(clock1__PA_DIV_ID)

#else

void clock1_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void clock1_Stop(void);

void clock1_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 clock1_GetDividerRegister(void);
uint8  clock1_GetFractionalDividerRegister(void);

#define clock1_Enable()                         clock1_Start()
#define clock1_Disable()                        clock1_Stop()
#define clock1_SetDividerRegister(clkDivider, reset)  \
    clock1_SetFractionalDividerRegister((clkDivider), 0u)
#define clock1_SetDivider(clkDivider)           clock1_SetDividerRegister((clkDivider), 1u)
#define clock1_SetDividerValue(clkDivider)      clock1_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define clock1_DIV_ID     clock1__DIV_ID

#define clock1_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define clock1_CTRL_REG   (*(reg32 *)clock1__CTRL_REGISTER)
#define clock1_DIV_REG    (*(reg32 *)clock1__DIV_REGISTER)

#define clock1_CMD_DIV_SHIFT          (0u)
#define clock1_CMD_PA_DIV_SHIFT       (8u)
#define clock1_CMD_DISABLE_SHIFT      (30u)
#define clock1_CMD_ENABLE_SHIFT       (31u)

#define clock1_CMD_DISABLE_MASK       ((uint32)((uint32)1u << clock1_CMD_DISABLE_SHIFT))
#define clock1_CMD_ENABLE_MASK        ((uint32)((uint32)1u << clock1_CMD_ENABLE_SHIFT))

#define clock1_DIV_FRAC_MASK  (0x000000F8u)
#define clock1_DIV_FRAC_SHIFT (3u)
#define clock1_DIV_INT_MASK   (0xFFFFFF00u)
#define clock1_DIV_INT_SHIFT  (8u)

#else 

#define clock1_DIV_REG        (*(reg32 *)clock1__REGISTER)
#define clock1_ENABLE_REG     clock1_DIV_REG
#define clock1_DIV_FRAC_MASK  clock1__FRAC_MASK
#define clock1_DIV_FRAC_SHIFT (16u)
#define clock1_DIV_INT_MASK   clock1__DIVIDER_MASK
#define clock1_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_clock1_H) */

/* [] END OF FILE */
