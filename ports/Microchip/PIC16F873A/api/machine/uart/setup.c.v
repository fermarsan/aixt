// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F873A port)

#define uart_setup() \
    SPBRG = 51 /* 51 para 9600 baudios */ \  
    TXSTAbits.SYNC = 0 /* Modo asíncrono*/ \
    TXSTAbits.BRGH = 1 /* Baja velocidad de baudios*/ \
    RCSTAbits.SPEN = 1 /* Habilitar la UART*/ \
    TXSTAbits.TXEN = 1 /* Habilitar transmisor*/ \
    RCSTAbits.CREN = 1 /* Habilitar receptor*/ 

