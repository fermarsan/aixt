/*******************************************************************************
* File Name: amux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_amux_H)
#define CY_AMUX_amux_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*        Function Prototypes
***************************************/

void amux_Start(void) ;
#define amux_Init() amux_Start()
void amux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void amux_Stop(void); */
/* void amux_Select(uint8 channel); */
/* void amux_Connect(uint8 channel); */
/* void amux_Disconnect(uint8 channel); */
/* void amux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define amux_CHANNELS  4u
#define amux_MUXTYPE   1
#define amux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define amux_NULL_CHANNEL 0xFFu
#define amux_MUX_SINGLE   1
#define amux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if amux_MUXTYPE == amux_MUX_SINGLE
# if !amux_ATMOSTONE
#  define amux_Connect(channel) amux_Set(channel)
# endif
# define amux_Disconnect(channel) amux_Unset(channel)
#else
# if !amux_ATMOSTONE
void amux_Connect(uint8 channel) ;
# endif
void amux_Disconnect(uint8 channel) ;
#endif

#if amux_ATMOSTONE
# define amux_Stop() amux_DisconnectAll()
# define amux_Select(channel) amux_FastSelect(channel)
void amux_DisconnectAll(void) ;
#else
# define amux_Stop() amux_Start()
void amux_Select(uint8 channel) ;
# define amux_DisconnectAll() amux_Start()
#endif

#endif /* CY_AMUX_amux_H */


/* [] END OF FILE */
