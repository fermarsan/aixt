/*******************************************************************************
* File Name: uart_SCBCLK.h
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

#if !defined(CY_CLOCK_uart_SCBCLK_H)
#define CY_CLOCK_uart_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void uart_SCBCLK_StartEx(uint32 alignClkDiv);
#define uart_SCBCLK_Start() \
    uart_SCBCLK_StartEx(uart_SCBCLK__PA_DIV_ID)

#else

void uart_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void uart_SCBCLK_Stop(void);

void uart_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 uart_SCBCLK_GetDividerRegister(void);
uint8  uart_SCBCLK_GetFractionalDividerRegister(void);

#define uart_SCBCLK_Enable()                         uart_SCBCLK_Start()
#define uart_SCBCLK_Disable()                        uart_SCBCLK_Stop()
#define uart_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    uart_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define uart_SCBCLK_SetDivider(clkDivider)           uart_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define uart_SCBCLK_SetDividerValue(clkDivider)      uart_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define uart_SCBCLK_DIV_ID     uart_SCBCLK__DIV_ID

#define uart_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define uart_SCBCLK_CTRL_REG   (*(reg32 *)uart_SCBCLK__CTRL_REGISTER)
#define uart_SCBCLK_DIV_REG    (*(reg32 *)uart_SCBCLK__DIV_REGISTER)

#define uart_SCBCLK_CMD_DIV_SHIFT          (0u)
#define uart_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define uart_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define uart_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define uart_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << uart_SCBCLK_CMD_DISABLE_SHIFT))
#define uart_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << uart_SCBCLK_CMD_ENABLE_SHIFT))

#define uart_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define uart_SCBCLK_DIV_FRAC_SHIFT (3u)
#define uart_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define uart_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define uart_SCBCLK_DIV_REG        (*(reg32 *)uart_SCBCLK__REGISTER)
#define uart_SCBCLK_ENABLE_REG     uart_SCBCLK_DIV_REG
#define uart_SCBCLK_DIV_FRAC_MASK  uart_SCBCLK__FRAC_MASK
#define uart_SCBCLK_DIV_FRAC_SHIFT (16u)
#define uart_SCBCLK_DIV_INT_MASK   uart_SCBCLK__DIVIDER_MASK
#define uart_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_uart_SCBCLK_H) */

/* [] END OF FILE */
