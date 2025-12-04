/*******************************************************************************
* File Name: clock3.h
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

#if !defined(CY_CLOCK_clock3_H)
#define CY_CLOCK_clock3_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void clock3_StartEx(uint32 alignClkDiv);
#define clock3_Start() \
    clock3_StartEx(clock3__PA_DIV_ID)

#else

void clock3_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void clock3_Stop(void);

void clock3_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 clock3_GetDividerRegister(void);
uint8  clock3_GetFractionalDividerRegister(void);

#define clock3_Enable()                         clock3_Start()
#define clock3_Disable()                        clock3_Stop()
#define clock3_SetDividerRegister(clkDivider, reset)  \
    clock3_SetFractionalDividerRegister((clkDivider), 0u)
#define clock3_SetDivider(clkDivider)           clock3_SetDividerRegister((clkDivider), 1u)
#define clock3_SetDividerValue(clkDivider)      clock3_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define clock3_DIV_ID     clock3__DIV_ID

#define clock3_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define clock3_CTRL_REG   (*(reg32 *)clock3__CTRL_REGISTER)
#define clock3_DIV_REG    (*(reg32 *)clock3__DIV_REGISTER)

#define clock3_CMD_DIV_SHIFT          (0u)
#define clock3_CMD_PA_DIV_SHIFT       (8u)
#define clock3_CMD_DISABLE_SHIFT      (30u)
#define clock3_CMD_ENABLE_SHIFT       (31u)

#define clock3_CMD_DISABLE_MASK       ((uint32)((uint32)1u << clock3_CMD_DISABLE_SHIFT))
#define clock3_CMD_ENABLE_MASK        ((uint32)((uint32)1u << clock3_CMD_ENABLE_SHIFT))

#define clock3_DIV_FRAC_MASK  (0x000000F8u)
#define clock3_DIV_FRAC_SHIFT (3u)
#define clock3_DIV_INT_MASK   (0xFFFFFF00u)
#define clock3_DIV_INT_SHIFT  (8u)

#else 

#define clock3_DIV_REG        (*(reg32 *)clock3__REGISTER)
#define clock3_ENABLE_REG     clock3_DIV_REG
#define clock3_DIV_FRAC_MASK  clock3__FRAC_MASK
#define clock3_DIV_FRAC_SHIFT (16u)
#define clock3_DIV_INT_MASK   clock3__DIVIDER_MASK
#define clock3_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_clock3_H) */

/* [] END OF FILE */
