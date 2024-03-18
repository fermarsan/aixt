// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart setup.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F886 port)

module uart

#define uart__setup() \
    SPBRG = 51; /* 51 para 9600 baudios */ \  
    TXSTAbits.SYNC = 0; /* Modo asíncrono*/ \
    TXSTAbits.BRGH = 1; /* Baja velocidad de baudios*/ \
    RCSTAbits.SPEN = 1; /* Habilitar la UART*/ \
    TXSTAbits.TXEN = 1; /* Habilitar transmisor*/ \
    RCSTAbits.CREN = 1; /* Habilitar receptor*/ \
    TXSTAbits.TX9 = 0;    // 8 BITS