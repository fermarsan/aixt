/***************************************************************************//**
* \file uart.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "uart_PVT.h"

#if (uart_SCB_MODE_I2C_INC)
    #include "uart_I2C_PVT.h"
#endif /* (uart_SCB_MODE_I2C_INC) */

#if (uart_SCB_MODE_EZI2C_INC)
    #include "uart_EZI2C_PVT.h"
#endif /* (uart_SCB_MODE_EZI2C_INC) */

#if (uart_SCB_MODE_SPI_INC || uart_SCB_MODE_UART_INC)
    #include "uart_SPI_UART_PVT.h"
#endif /* (uart_SCB_MODE_SPI_INC || uart_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 uart_scbMode = uart_SCB_MODE_UNCONFIG;
    uint8 uart_scbEnableWake;
    uint8 uart_scbEnableIntr;

    /* I2C configuration variables */
    uint8 uart_mode;
    uint8 uart_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * uart_rxBuffer;
    uint8  uart_rxDataBits;
    uint32 uart_rxBufferSize;

    volatile uint8 * uart_txBuffer;
    uint8  uart_txDataBits;
    uint32 uart_txBufferSize;

    /* EZI2C configuration variables */
    uint8 uart_numberOfAddr;
    uint8 uart_subAddrSize;
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** uart_initVar indicates whether the uart 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the uart_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  uart_Init() function can be called before the 
*  uart_Start() or uart_Enable() function.
*/
uint8 uart_initVar = 0u;


#if (! (uart_SCB_MODE_I2C_CONST_CFG || \
        uart_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * uart_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent uart_Enable() call.
    */
    uint16 uart_IntrTxMask = 0u;
#endif /* (! (uart_SCB_MODE_I2C_CONST_CFG || \
              uart_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (uart_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_uart_CUSTOM_INTR_HANDLER)
    void (*uart_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_uart_CUSTOM_INTR_HANDLER) */
#endif /* (uart_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void uart_ScbEnableIntr(void);
static void uart_ScbModeStop(void);
static void uart_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: uart_Init
****************************************************************************//**
*
*  Initializes the uart component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  uart_I2CInit, uart_SpiInit, 
*  uart_UartInit or uart_EzI2CInit.
*
*******************************************************************************/
void uart_Init(void)
{
#if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
    if (uart_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        uart_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (uart_SCB_MODE_I2C_CONST_CFG)
    uart_I2CInit();

#elif (uart_SCB_MODE_SPI_CONST_CFG)
    uart_SpiInit();

#elif (uart_SCB_MODE_UART_CONST_CFG)
    uart_UartInit();

#elif (uart_SCB_MODE_EZI2C_CONST_CFG)
    uart_EzI2CInit();

#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uart_Enable
****************************************************************************//**
*
*  Enables uart component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  uart_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The uart configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured uart”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void uart_Enable(void)
{
#if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!uart_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        uart_CTRL_REG |= uart_CTRL_ENABLED;

        uart_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        uart_ScbModePostEnable();
    }
#else
    uart_CTRL_REG |= uart_CTRL_ENABLED;

    uart_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    uart_ScbModePostEnable();
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uart_Start
****************************************************************************//**
*
*  Invokes uart_Init() and uart_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  uart_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void uart_Start(void)
{
    if (0u == uart_initVar)
    {
        uart_Init();
        uart_initVar = 1u; /* Component was initialized */
    }

    uart_Enable();
}


/*******************************************************************************
* Function Name: uart_Stop
****************************************************************************//**
*
*  Disables the uart component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function uart_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void uart_Stop(void)
{
#if (uart_SCB_IRQ_INTERNAL)
    uart_DisableInt();
#endif /* (uart_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    uart_ScbModeStop();

    /* Disable SCB IP */
    uart_CTRL_REG &= (uint32) ~uart_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    uart_SetTxInterruptMode(uart_NO_INTR_SOURCES);

#if (uart_SCB_IRQ_INTERNAL)
    uart_ClearPendingInt();
#endif /* (uart_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: uart_SetRxFifoLevel
****************************************************************************//**
*
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
*  \param level: Level in the RX FIFO to generate RX level interrupt.
*   The range of valid level values is between 0 and RX FIFO depth - 1.
*
*******************************************************************************/
void uart_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = uart_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~uart_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (uart_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    uart_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: uart_SetTxFifoLevel
****************************************************************************//**
*
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has less entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
*  \param level: Level in the TX FIFO to generate TX level interrupt.
*   The range of valid level values is between 0 and TX FIFO depth - 1.
*
*******************************************************************************/
void uart_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = uart_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~uart_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (uart_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    uart_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (uart_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: uart_SetCustomInterruptHandler
    ****************************************************************************//**
    *
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    *  \param func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    *******************************************************************************/
    void uart_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_uart_CUSTOM_INTR_HANDLER)
        uart_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_uart_CUSTOM_INTR_HANDLER) */
    }
#endif /* (uart_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: uart_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void uart_ScbEnableIntr(void)
{
#if (uart_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != uart_scbEnableIntr)
        {
            uart_EnableInt();
        }

    #else
        uart_EnableInt();

    #endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (uart_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: uart_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void uart_ScbModePostEnable(void)
{
#if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!uart_CY_SCBIP_V1)
    if (uart_SCB_MODE_SPI_RUNTM_CFG)
    {
        uart_SpiPostEnable();
    }
    else if (uart_SCB_MODE_UART_RUNTM_CFG)
    {
        uart_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!uart_CY_SCBIP_V1) */

#elif (uart_SCB_MODE_SPI_CONST_CFG)
    uart_SpiPostEnable();

#elif (uart_SCB_MODE_UART_CONST_CFG)
    uart_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uart_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void uart_ScbModeStop(void)
{
#if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
    if (uart_SCB_MODE_I2C_RUNTM_CFG)
    {
        uart_I2CStop();
    }
    else if (uart_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        uart_EzI2CStop();
    }
#if (!uart_CY_SCBIP_V1)
    else if (uart_SCB_MODE_SPI_RUNTM_CFG)
    {
        uart_SpiStop();
    }
    else if (uart_SCB_MODE_UART_RUNTM_CFG)
    {
        uart_UartStop();
    }
#endif /* (!uart_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (uart_SCB_MODE_I2C_CONST_CFG)
    uart_I2CStop();

#elif (uart_SCB_MODE_EZI2C_CONST_CFG)
    uart_EzI2CStop();

#elif (uart_SCB_MODE_SPI_CONST_CFG)
    uart_SpiStop();

#elif (uart_SCB_MODE_UART_CONST_CFG)
    uart_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: uart_SetPins
    ****************************************************************************//**
    *
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    *  \param mode:      Mode of SCB operation.
    *  \param subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  \param uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    *******************************************************************************/
    void uart_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[uart_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!uart_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!uart_CY_SCBIP_V1) */
        
        uint32 hsiomSel[uart_SCB_PINS_NUMBER] = 
        {
            uart_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            uart_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (uart_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (uart_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < uart_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = uart_PIN_DM_ALG_HIZ;
        }

        if ((uart_SCB_MODE_I2C   == mode) ||
            (uart_SCB_MODE_EZI2C == mode))
        {
        #if (uart_RX_SCL_MOSI_PIN)
            hsiomSel[uart_RX_SCL_MOSI_PIN_INDEX] = uart_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [uart_RX_SCL_MOSI_PIN_INDEX] = uart_PIN_DM_OD_LO;
        #elif (uart_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[uart_RX_WAKE_SCL_MOSI_PIN_INDEX] = uart_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [uart_RX_WAKE_SCL_MOSI_PIN_INDEX] = uart_PIN_DM_OD_LO;
        #else
        #endif /* (uart_RX_SCL_MOSI_PIN) */
        
        #if (uart_TX_SDA_MISO_PIN)
            hsiomSel[uart_TX_SDA_MISO_PIN_INDEX] = uart_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [uart_TX_SDA_MISO_PIN_INDEX] = uart_PIN_DM_OD_LO;
        #endif /* (uart_TX_SDA_MISO_PIN) */
        }
    #if (!uart_CY_SCBIP_V1)
        else if (uart_SCB_MODE_SPI == mode)
        {
        #if (uart_RX_SCL_MOSI_PIN)
            hsiomSel[uart_RX_SCL_MOSI_PIN_INDEX] = uart_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (uart_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[uart_RX_WAKE_SCL_MOSI_PIN_INDEX] = uart_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (uart_RX_SCL_MOSI_PIN) */
        
        #if (uart_TX_SDA_MISO_PIN)
            hsiomSel[uart_TX_SDA_MISO_PIN_INDEX] = uart_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (uart_TX_SDA_MISO_PIN) */
        
        #if (uart_SCLK_PIN)
            hsiomSel[uart_SCLK_PIN_INDEX] = uart_SCLK_HSIOM_SEL_SPI;
        #endif /* (uart_SCLK_PIN) */

            if (uart_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[uart_RX_SCL_MOSI_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;
                pinsDm[uart_TX_SDA_MISO_PIN_INDEX] = uart_PIN_DM_STRONG;
                pinsDm[uart_SCLK_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;

            #if (uart_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[uart_SS0_PIN_INDEX] = uart_SS0_HSIOM_SEL_SPI;
                pinsDm  [uart_SS0_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;
            #endif /* (uart_SS0_PIN) */

            #if (uart_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= uart_TX_SDA_MISO_PIN_MASK;
            #endif /* (uart_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[uart_RX_SCL_MOSI_PIN_INDEX] = uart_PIN_DM_STRONG;
                pinsDm[uart_TX_SDA_MISO_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;
                pinsDm[uart_SCLK_PIN_INDEX] = uart_PIN_DM_STRONG;

            #if (uart_SS0_PIN)
                hsiomSel [uart_SS0_PIN_INDEX] = uart_SS0_HSIOM_SEL_SPI;
                pinsDm   [uart_SS0_PIN_INDEX] = uart_PIN_DM_STRONG;
                pinsInBuf |= uart_SS0_PIN_MASK;
            #endif /* (uart_SS0_PIN) */

            #if (uart_SS1_PIN)
                hsiomSel [uart_SS1_PIN_INDEX] = uart_SS1_HSIOM_SEL_SPI;
                pinsDm   [uart_SS1_PIN_INDEX] = uart_PIN_DM_STRONG;
                pinsInBuf |= uart_SS1_PIN_MASK;
            #endif /* (uart_SS1_PIN) */

            #if (uart_SS2_PIN)
                hsiomSel [uart_SS2_PIN_INDEX] = uart_SS2_HSIOM_SEL_SPI;
                pinsDm   [uart_SS2_PIN_INDEX] = uart_PIN_DM_STRONG;
                pinsInBuf |= uart_SS2_PIN_MASK;
            #endif /* (uart_SS2_PIN) */

            #if (uart_SS3_PIN)
                hsiomSel [uart_SS3_PIN_INDEX] = uart_SS3_HSIOM_SEL_SPI;
                pinsDm   [uart_SS3_PIN_INDEX] = uart_PIN_DM_STRONG;
                pinsInBuf |= uart_SS3_PIN_MASK;
            #endif /* (uart_SS3_PIN) */

                /* Disable input buffers */
            #if (uart_RX_SCL_MOSI_PIN)
                pinsInBuf |= uart_RX_SCL_MOSI_PIN_MASK;
            #elif (uart_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= uart_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (uart_RX_SCL_MOSI_PIN) */

            #if (uart_SCLK_PIN)
                pinsInBuf |= uart_SCLK_PIN_MASK;
            #endif /* (uart_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (uart_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (uart_TX_SDA_MISO_PIN)
                hsiomSel[uart_TX_SDA_MISO_PIN_INDEX] = uart_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [uart_TX_SDA_MISO_PIN_INDEX] = uart_PIN_DM_OD_LO;
            #endif /* (uart_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (uart_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (uart_RX_SCL_MOSI_PIN)
                    hsiomSel[uart_RX_SCL_MOSI_PIN_INDEX] = uart_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [uart_RX_SCL_MOSI_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;
                #elif (uart_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[uart_RX_WAKE_SCL_MOSI_PIN_INDEX] = uart_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [uart_RX_WAKE_SCL_MOSI_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;
                #else
                #endif /* (uart_RX_SCL_MOSI_PIN) */
                }

                if (0u != (uart_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (uart_TX_SDA_MISO_PIN)
                    hsiomSel[uart_TX_SDA_MISO_PIN_INDEX] = uart_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [uart_TX_SDA_MISO_PIN_INDEX] = uart_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= uart_TX_SDA_MISO_PIN_MASK;
                #endif /* (uart_TX_SDA_MISO_PIN) */
                }

            #if !(uart_CY_SCBIP_V0 || uart_CY_SCBIP_V1)
                if (uart_UART_MODE_STD == subMode)
                {
                    if (0u != (uart_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (uart_SCLK_PIN)
                        hsiomSel[uart_SCLK_PIN_INDEX] = uart_SCLK_HSIOM_SEL_UART;
                        pinsDm  [uart_SCLK_PIN_INDEX] = uart_PIN_DM_DIG_HIZ;
                    #endif /* (uart_SCLK_PIN) */
                    }

                    if (0u != (uart_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (uart_SS0_PIN)
                        hsiomSel[uart_SS0_PIN_INDEX] = uart_SS0_HSIOM_SEL_UART;
                        pinsDm  [uart_SS0_PIN_INDEX] = uart_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= uart_SS0_PIN_MASK;
                    #endif /* (uart_SS0_PIN) */
                    }
                }
            #endif /* !(uart_CY_SCBIP_V0 || uart_CY_SCBIP_V1) */
            }
        }
    #endif /* (!uart_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (uart_RX_SCL_MOSI_PIN)
        uart_SET_HSIOM_SEL(uart_RX_SCL_MOSI_HSIOM_REG,
                                       uart_RX_SCL_MOSI_HSIOM_MASK,
                                       uart_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[uart_RX_SCL_MOSI_PIN_INDEX]);

        uart_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[uart_RX_SCL_MOSI_PIN_INDEX]);

        #if (!uart_CY_SCBIP_V1)
            uart_SET_INP_DIS(uart_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         uart_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & uart_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!uart_CY_SCBIP_V1) */
    
    #elif (uart_RX_WAKE_SCL_MOSI_PIN)
        uart_SET_HSIOM_SEL(uart_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       uart_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       uart_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[uart_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        uart_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[uart_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        uart_SET_INP_DIS(uart_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     uart_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & uart_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        uart_SET_INCFG_TYPE(uart_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        uart_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        uart_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        uart_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (uart_RX_WAKE_SCL_MOSI_PIN) */

    #if (uart_TX_SDA_MISO_PIN)
        uart_SET_HSIOM_SEL(uart_TX_SDA_MISO_HSIOM_REG,
                                       uart_TX_SDA_MISO_HSIOM_MASK,
                                       uart_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[uart_TX_SDA_MISO_PIN_INDEX]);

        uart_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[uart_TX_SDA_MISO_PIN_INDEX]);

    #if (!uart_CY_SCBIP_V1)
        uart_SET_INP_DIS(uart_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     uart_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & uart_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!uart_CY_SCBIP_V1) */
    #endif /* (uart_RX_SCL_MOSI_PIN) */

    #if (uart_SCLK_PIN)
        uart_SET_HSIOM_SEL(uart_SCLK_HSIOM_REG,
                                       uart_SCLK_HSIOM_MASK,
                                       uart_SCLK_HSIOM_POS,
                                       hsiomSel[uart_SCLK_PIN_INDEX]);

        uart_spi_sclk_SetDriveMode((uint8) pinsDm[uart_SCLK_PIN_INDEX]);

        uart_SET_INP_DIS(uart_spi_sclk_INP_DIS,
                                     uart_spi_sclk_MASK,
                                     (0u != (pinsInBuf & uart_SCLK_PIN_MASK)));
    #endif /* (uart_SCLK_PIN) */

    #if (uart_SS0_PIN)
        uart_SET_HSIOM_SEL(uart_SS0_HSIOM_REG,
                                       uart_SS0_HSIOM_MASK,
                                       uart_SS0_HSIOM_POS,
                                       hsiomSel[uart_SS0_PIN_INDEX]);

        uart_spi_ss0_SetDriveMode((uint8) pinsDm[uart_SS0_PIN_INDEX]);

        uart_SET_INP_DIS(uart_spi_ss0_INP_DIS,
                                     uart_spi_ss0_MASK,
                                     (0u != (pinsInBuf & uart_SS0_PIN_MASK)));
    #endif /* (uart_SS0_PIN) */

    #if (uart_SS1_PIN)
        uart_SET_HSIOM_SEL(uart_SS1_HSIOM_REG,
                                       uart_SS1_HSIOM_MASK,
                                       uart_SS1_HSIOM_POS,
                                       hsiomSel[uart_SS1_PIN_INDEX]);

        uart_spi_ss1_SetDriveMode((uint8) pinsDm[uart_SS1_PIN_INDEX]);

        uart_SET_INP_DIS(uart_spi_ss1_INP_DIS,
                                     uart_spi_ss1_MASK,
                                     (0u != (pinsInBuf & uart_SS1_PIN_MASK)));
    #endif /* (uart_SS1_PIN) */

    #if (uart_SS2_PIN)
        uart_SET_HSIOM_SEL(uart_SS2_HSIOM_REG,
                                       uart_SS2_HSIOM_MASK,
                                       uart_SS2_HSIOM_POS,
                                       hsiomSel[uart_SS2_PIN_INDEX]);

        uart_spi_ss2_SetDriveMode((uint8) pinsDm[uart_SS2_PIN_INDEX]);

        uart_SET_INP_DIS(uart_spi_ss2_INP_DIS,
                                     uart_spi_ss2_MASK,
                                     (0u != (pinsInBuf & uart_SS2_PIN_MASK)));
    #endif /* (uart_SS2_PIN) */

    #if (uart_SS3_PIN)
        uart_SET_HSIOM_SEL(uart_SS3_HSIOM_REG,
                                       uart_SS3_HSIOM_MASK,
                                       uart_SS3_HSIOM_POS,
                                       hsiomSel[uart_SS3_PIN_INDEX]);

        uart_spi_ss3_SetDriveMode((uint8) pinsDm[uart_SS3_PIN_INDEX]);

        uart_SET_INP_DIS(uart_spi_ss3_INP_DIS,
                                     uart_spi_ss3_MASK,
                                     (0u != (pinsInBuf & uart_SS3_PIN_MASK)));
    #endif /* (uart_SS3_PIN) */
    }

#endif /* (uart_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (uart_CY_SCBIP_V0 || uart_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: uart_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void uart_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (uart_CTRL_REG & uart_CTRL_EC_AM_MODE)) &&
            (0u == (uart_I2C_CTRL_REG & uart_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            uart_CTRL_REG &= ~uart_CTRL_EC_AM_MODE;
            uart_CTRL_REG |=  uart_CTRL_EC_AM_MODE;
        }

        uart_I2C_SLAVE_CMD_REG = uart_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (uart_CY_SCBIP_V0 || uart_CY_SCBIP_V1) */


/* [] END OF FILE */
