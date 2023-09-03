/***************************************************************************//**
* \file uart_BOOT.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_uart_H)
#define CY_SCB_BOOT_uart_H

#include "uart_PVT.h"

#if (uart_SCB_MODE_I2C_INC)
    #include "uart_I2C.h"
#endif /* (uart_SCB_MODE_I2C_INC) */

#if (uart_SCB_MODE_EZI2C_INC)
    #include "uart_EZI2C.h"
#endif /* (uart_SCB_MODE_EZI2C_INC) */

#if (uart_SCB_MODE_SPI_INC || uart_SCB_MODE_UART_INC)
    #include "uart_SPI_UART.h"
#endif /* (uart_SCB_MODE_SPI_INC || uart_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define uart_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (uart_SCB_MODE_I2C_INC)
    #define uart_I2C_BTLDR_COMM_ENABLED     (uart_BTLDR_COMM_ENABLED && \
                                                            (uart_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             uart_I2C_SLAVE_CONST))
#else
     #define uart_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (uart_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (uart_SCB_MODE_EZI2C_INC)
    #define uart_EZI2C_BTLDR_COMM_ENABLED   (uart_BTLDR_COMM_ENABLED && \
                                                         uart_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define uart_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (uart_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (uart_SCB_MODE_SPI_INC)
    #define uart_SPI_BTLDR_COMM_ENABLED     (uart_BTLDR_COMM_ENABLED && \
                                                            (uart_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             uart_SPI_SLAVE_CONST))
#else
        #define uart_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (uart_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (uart_SCB_MODE_UART_INC)
       #define uart_UART_BTLDR_COMM_ENABLED    (uart_BTLDR_COMM_ENABLED && \
                                                            (uart_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (uart_UART_RX_DIRECTION && \
                                                              uart_UART_TX_DIRECTION)))
#else
     #define uart_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (uart_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define uart_BTLDR_COMM_MODE_ENABLED    (uart_I2C_BTLDR_COMM_ENABLED   || \
                                                     uart_SPI_BTLDR_COMM_ENABLED   || \
                                                     uart_EZI2C_BTLDR_COMM_ENABLED || \
                                                     uart_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void uart_I2CCyBtldrCommStart(void);
    void uart_I2CCyBtldrCommStop (void);
    void uart_I2CCyBtldrCommReset(void);
    cystatus uart_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uart_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (uart_SCB_MODE_I2C_CONST_CFG)
        #define uart_CyBtldrCommStart   uart_I2CCyBtldrCommStart
        #define uart_CyBtldrCommStop    uart_I2CCyBtldrCommStop
        #define uart_CyBtldrCommReset   uart_I2CCyBtldrCommReset
        #define uart_CyBtldrCommRead    uart_I2CCyBtldrCommRead
        #define uart_CyBtldrCommWrite   uart_I2CCyBtldrCommWrite
    #endif /* (uart_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void uart_EzI2CCyBtldrCommStart(void);
    void uart_EzI2CCyBtldrCommStop (void);
    void uart_EzI2CCyBtldrCommReset(void);
    cystatus uart_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uart_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (uart_SCB_MODE_EZI2C_CONST_CFG)
        #define uart_CyBtldrCommStart   uart_EzI2CCyBtldrCommStart
        #define uart_CyBtldrCommStop    uart_EzI2CCyBtldrCommStop
        #define uart_CyBtldrCommReset   uart_EzI2CCyBtldrCommReset
        #define uart_CyBtldrCommRead    uart_EzI2CCyBtldrCommRead
        #define uart_CyBtldrCommWrite   uart_EzI2CCyBtldrCommWrite
    #endif /* (uart_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void uart_SpiCyBtldrCommStart(void);
    void uart_SpiCyBtldrCommStop (void);
    void uart_SpiCyBtldrCommReset(void);
    cystatus uart_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uart_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (uart_SCB_MODE_SPI_CONST_CFG)
        #define uart_CyBtldrCommStart   uart_SpiCyBtldrCommStart
        #define uart_CyBtldrCommStop    uart_SpiCyBtldrCommStop
        #define uart_CyBtldrCommReset   uart_SpiCyBtldrCommReset
        #define uart_CyBtldrCommRead    uart_SpiCyBtldrCommRead
        #define uart_CyBtldrCommWrite   uart_SpiCyBtldrCommWrite
    #endif /* (uart_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void uart_UartCyBtldrCommStart(void);
    void uart_UartCyBtldrCommStop (void);
    void uart_UartCyBtldrCommReset(void);
    cystatus uart_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uart_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (uart_SCB_MODE_UART_CONST_CFG)
        #define uart_CyBtldrCommStart   uart_UartCyBtldrCommStart
        #define uart_CyBtldrCommStop    uart_UartCyBtldrCommStop
        #define uart_CyBtldrCommReset   uart_UartCyBtldrCommReset
        #define uart_CyBtldrCommRead    uart_UartCyBtldrCommRead
        #define uart_CyBtldrCommWrite   uart_UartCyBtldrCommWrite
    #endif /* (uart_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_BTLDR_COMM_ENABLED)
    #if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void uart_CyBtldrCommStart(void);
        void uart_CyBtldrCommStop (void);
        void uart_CyBtldrCommReset(void);
        cystatus uart_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus uart_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart)
        #define CyBtldrCommStart    uart_CyBtldrCommStart
        #define CyBtldrCommStop     uart_CyBtldrCommStop
        #define CyBtldrCommReset    uart_CyBtldrCommReset
        #define CyBtldrCommWrite    uart_CyBtldrCommWrite
        #define CyBtldrCommRead     uart_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uart) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uart_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define uart_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define uart_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define uart_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define uart_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef uart_SPI_BYTE_TO_BYTE
    #define uart_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef uart_UART_BYTE_TO_BYTE
    #define uart_UART_BYTE_TO_BYTE  (171u)
#endif /* uart_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_uart_H) */


/* [] END OF FILE */
