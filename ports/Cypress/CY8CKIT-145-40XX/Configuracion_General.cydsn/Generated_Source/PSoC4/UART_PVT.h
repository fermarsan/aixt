/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_uart_H)
#define CY_SCB_PVT_uart_H

#include "uart.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define uart_SetI2CExtClkInterruptMode(interruptMask) uart_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define uart_ClearI2CExtClkInterruptSource(interruptMask) uart_CLEAR_INTR_I2C_EC(interruptMask)
#define uart_GetI2CExtClkInterruptSource()                (uart_INTR_I2C_EC_REG)
#define uart_GetI2CExtClkInterruptMode()                  (uart_INTR_I2C_EC_MASK_REG)
#define uart_GetI2CExtClkInterruptSourceMasked()          (uart_INTR_I2C_EC_MASKED_REG)

#if (!uart_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define uart_SetSpiExtClkInterruptMode(interruptMask) \
                                                                uart_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define uart_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                uart_CLEAR_INTR_SPI_EC(interruptMask)
    #define uart_GetExtSpiClkInterruptSource()                 (uart_INTR_SPI_EC_REG)
    #define uart_GetExtSpiClkInterruptMode()                   (uart_INTR_SPI_EC_MASK_REG)
    #define uart_GetExtSpiClkInterruptSourceMasked()           (uart_INTR_SPI_EC_MASKED_REG)
#endif /* (!uart_CY_SCBIP_V1) */

#if(uart_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void uart_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (uart_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_uart_CUSTOM_INTR_HANDLER)
    extern cyisraddress uart_customIntrHandler;
#endif /* !defined (CY_REMOVE_uart_CUSTOM_INTR_HANDLER) */
#endif /* (uart_SCB_IRQ_INTERNAL) */

extern uart_BACKUP_STRUCT uart_backup;

#if(uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 uart_scbMode;
    extern uint8 uart_scbEnableWake;
    extern uint8 uart_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 uart_mode;
    extern uint8 uart_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * uart_rxBuffer;
    extern uint8   uart_rxDataBits;
    extern uint32  uart_rxBufferSize;

    extern volatile uint8 * uart_txBuffer;
    extern uint8   uart_txDataBits;
    extern uint32  uart_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 uart_numberOfAddr;
    extern uint8 uart_subAddrSize;
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (uart_SCB_MODE_I2C_CONST_CFG || \
        uart_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 uart_IntrTxMask;
#endif /* (! (uart_SCB_MODE_I2C_CONST_CFG || \
              uart_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define uart_SCB_MODE_I2C_RUNTM_CFG     (uart_SCB_MODE_I2C      == uart_scbMode)
    #define uart_SCB_MODE_SPI_RUNTM_CFG     (uart_SCB_MODE_SPI      == uart_scbMode)
    #define uart_SCB_MODE_UART_RUNTM_CFG    (uart_SCB_MODE_UART     == uart_scbMode)
    #define uart_SCB_MODE_EZI2C_RUNTM_CFG   (uart_SCB_MODE_EZI2C    == uart_scbMode)
    #define uart_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (uart_SCB_MODE_UNCONFIG == uart_scbMode)

    /* Defines wakeup enable */
    #define uart_SCB_WAKE_ENABLE_CHECK       (0u != uart_scbEnableWake)
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!uart_CY_SCBIP_V1)
    #define uart_SCB_PINS_NUMBER    (7u)
#else
    #define uart_SCB_PINS_NUMBER    (2u)
#endif /* (!uart_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_uart_H) */


/* [] END OF FILE */
