/*******************************************************************************
* File Name: clock2.h
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

#if !defined(CY_CLOCK_clock2_H)
#define CY_CLOCK_clock2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void clock2_StartEx(uint32 alignClkDiv);
#define clock2_Start() \
    clock2_StartEx(clock2__PA_DIV_ID)

#else

void clock2_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void clock2_Stop(void);

void clock2_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 clock2_GetDividerRegister(void);
uint8  clock2_GetFractionalDividerRegister(void);

#define clock2_Enable()                         clock2_Start()
#define clock2_Disable()                        clock2_Stop()
#define clock2_SetDividerRegister(clkDivider, reset)  \
    clock2_SetFractionalDividerRegister((clkDivider), 0u)
#define clock2_SetDivider(clkDivider)           clock2_SetDividerRegister((clkDivider), 1u)
#define clock2_SetDividerValue(clkDivider)      clock2_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define clock2_DIV_ID     clock2__DIV_ID

#define clock2_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define clock2_CTRL_REG   (*(reg32 *)clock2__CTRL_REGISTER)
#define clock2_DIV_REG    (*(reg32 *)clock2__DIV_REGISTER)

#define clock2_CMD_DIV_SHIFT          (0u)
#define clock2_CMD_PA_DIV_SHIFT       (8u)
#define clock2_CMD_DISABLE_SHIFT      (30u)
#define clock2_CMD_ENABLE_SHIFT       (31u)

#define clock2_CMD_DISABLE_MASK       ((uint32)((uint32)1u << clock2_CMD_DISABLE_SHIFT))
#define clock2_CMD_ENABLE_MASK        ((uint32)((uint32)1u << clock2_CMD_ENABLE_SHIFT))

#define clock2_DIV_FRAC_MASK  (0x000000F8u)
#define clock2_DIV_FRAC_SHIFT (3u)
#define clock2_DIV_INT_MASK   (0xFFFFFF00u)
#define clock2_DIV_INT_SHIFT  (8u)

#else 

#define clock2_DIV_REG        (*(reg32 *)clock2__REGISTER)
#define clock2_ENABLE_REG     clock2_DIV_REG
#define clock2_DIV_FRAC_MASK  clock2__FRAC_MASK
#define clock2_DIV_FRAC_SHIFT (16u)
#define clock2_DIV_INT_MASK   clock2__DIVIDER_MASK
#define clock2_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_clock2_H) */

/* [] END OF FILE */
