/*******************************************************************************
* File Name: amux.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "amux.h"

static uint8 amux_lastChannel = amux_NULL_CHANNEL;


/*******************************************************************************
* Function Name: amux_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void amux_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < amux_CHANNELS ; chan++)
    {
#if (amux_MUXTYPE == amux_MUX_SINGLE)
        amux_Unset(chan);
#else
        amux_CYAMUXSIDE_A_Unset(chan);
        amux_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    amux_lastChannel = amux_NULL_CHANNEL;
}


#if (!amux_ATMOSTONE)
/*******************************************************************************
* Function Name: amux_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void amux_Select(uint8 channel) 
{
    amux_DisconnectAll();        /* Disconnect all previous connections */
    amux_Connect(channel);       /* Make the given selection */
    amux_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: amux_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void amux_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( amux_lastChannel != amux_NULL_CHANNEL)
    {
        amux_Disconnect(amux_lastChannel);
    }

    /* Make the new channel connection */
#if (amux_MUXTYPE == amux_MUX_SINGLE)
    amux_Set(channel);
#else
    amux_CYAMUXSIDE_A_Set(channel);
    amux_CYAMUXSIDE_B_Set(channel);
#endif


    amux_lastChannel = channel;   /* Update last channel */
}


#if (amux_MUXTYPE == amux_MUX_DIFF)
#if (!amux_ATMOSTONE)
/*******************************************************************************
* Function Name: amux_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void amux_Connect(uint8 channel) 
{
    amux_CYAMUXSIDE_A_Set(channel);
    amux_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: amux_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void amux_Disconnect(uint8 channel) 
{
    amux_CYAMUXSIDE_A_Unset(channel);
    amux_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (amux_ATMOSTONE)
/*******************************************************************************
* Function Name: amux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void amux_DisconnectAll(void) 
{
    if(amux_lastChannel != amux_NULL_CHANNEL) 
    {
        amux_Disconnect(amux_lastChannel);
        amux_lastChannel = amux_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
