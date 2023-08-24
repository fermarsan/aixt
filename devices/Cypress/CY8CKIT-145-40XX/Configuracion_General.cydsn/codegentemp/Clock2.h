/*******************************************************************************
* File Name: Clock2.h
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

#if !defined(CY_CLOCK_Clock2_H)
#define CY_CLOCK_Clock2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock2_StartEx(uint32 alignClkDiv);
#define Clock2_Start() \
    Clock2_StartEx(Clock2__PA_DIV_ID)

#else

void Clock2_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock2_Stop(void);

void Clock2_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock2_GetDividerRegister(void);
uint8  Clock2_GetFractionalDividerRegister(void);

#define Clock2_Enable()                         Clock2_Start()
#define Clock2_Disable()                        Clock2_Stop()
#define Clock2_SetDividerRegister(clkDivider, reset)  \
    Clock2_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock2_SetDivider(clkDivider)           Clock2_SetDividerRegister((clkDivider), 1u)
#define Clock2_SetDividerValue(clkDivider)      Clock2_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock2_DIV_ID     Clock2__DIV_ID

#define Clock2_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock2_CTRL_REG   (*(reg32 *)Clock2__CTRL_REGISTER)
#define Clock2_DIV_REG    (*(reg32 *)Clock2__DIV_REGISTER)

#define Clock2_CMD_DIV_SHIFT          (0u)
#define Clock2_CMD_PA_DIV_SHIFT       (8u)
#define Clock2_CMD_DISABLE_SHIFT      (30u)
#define Clock2_CMD_ENABLE_SHIFT       (31u)

#define Clock2_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock2_CMD_DISABLE_SHIFT))
#define Clock2_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock2_CMD_ENABLE_SHIFT))

#define Clock2_DIV_FRAC_MASK  (0x000000F8u)
#define Clock2_DIV_FRAC_SHIFT (3u)
#define Clock2_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock2_DIV_INT_SHIFT  (8u)

#else 

#define Clock2_DIV_REG        (*(reg32 *)Clock2__REGISTER)
#define Clock2_ENABLE_REG     Clock2_DIV_REG
#define Clock2_DIV_FRAC_MASK  Clock2__FRAC_MASK
#define Clock2_DIV_FRAC_SHIFT (16u)
#define Clock2_DIV_INT_MASK   Clock2__DIVIDER_MASK
#define Clock2_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock2_H) */

/* [] END OF FILE */
