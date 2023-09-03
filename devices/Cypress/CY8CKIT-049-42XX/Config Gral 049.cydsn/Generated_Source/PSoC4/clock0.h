/*******************************************************************************
* File Name: clock0.h
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

#if !defined(CY_CLOCK_clock0_H)
#define CY_CLOCK_clock0_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void clock0_StartEx(uint32 alignClkDiv);
#define clock0_Start() \
    clock0_StartEx(clock0__PA_DIV_ID)

#else

void clock0_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void clock0_Stop(void);

void clock0_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 clock0_GetDividerRegister(void);
uint8  clock0_GetFractionalDividerRegister(void);

#define clock0_Enable()                         clock0_Start()
#define clock0_Disable()                        clock0_Stop()
#define clock0_SetDividerRegister(clkDivider, reset)  \
    clock0_SetFractionalDividerRegister((clkDivider), 0u)
#define clock0_SetDivider(clkDivider)           clock0_SetDividerRegister((clkDivider), 1u)
#define clock0_SetDividerValue(clkDivider)      clock0_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define clock0_DIV_ID     clock0__DIV_ID

#define clock0_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define clock0_CTRL_REG   (*(reg32 *)clock0__CTRL_REGISTER)
#define clock0_DIV_REG    (*(reg32 *)clock0__DIV_REGISTER)

#define clock0_CMD_DIV_SHIFT          (0u)
#define clock0_CMD_PA_DIV_SHIFT       (8u)
#define clock0_CMD_DISABLE_SHIFT      (30u)
#define clock0_CMD_ENABLE_SHIFT       (31u)

#define clock0_CMD_DISABLE_MASK       ((uint32)((uint32)1u << clock0_CMD_DISABLE_SHIFT))
#define clock0_CMD_ENABLE_MASK        ((uint32)((uint32)1u << clock0_CMD_ENABLE_SHIFT))

#define clock0_DIV_FRAC_MASK  (0x000000F8u)
#define clock0_DIV_FRAC_SHIFT (3u)
#define clock0_DIV_INT_MASK   (0xFFFFFF00u)
#define clock0_DIV_INT_SHIFT  (8u)

#else 

#define clock0_DIV_REG        (*(reg32 *)clock0__REGISTER)
#define clock0_ENABLE_REG     clock0_DIV_REG
#define clock0_DIV_FRAC_MASK  clock0__FRAC_MASK
#define clock0_DIV_FRAC_SHIFT (16u)
#define clock0_DIV_INT_MASK   clock0__DIVIDER_MASK
#define clock0_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_clock0_H) */

/* [] END OF FILE */
