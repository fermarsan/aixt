// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: UART management functions  (PIC18F2550 port)

#include <xc.h>
#define _XTAL_FREQ 8000000

#define uart_setup() \
    //Configuración del registro SPBRG (9600 Baudios)
    SPBRG=(unsigned char)((_XTAL_FREQ/9600)/64)-1;  \
    //configuracion
    TXSTAbits.BRGH=0;   /*LOW SPEED*/  \
    TXSTAbits.SYNC=0;   /*ASINCRONO*/  \
    RCSTAbits.SPEN =1;  /*HABILITAR TX Y RX*/  \
    //transmision
    TXSTAbits.TX9=0;    /*8 BITS*/  \
    TXSTAbits.TXEN=1;   /*ACTIVAMOS TRANSMISION*/  \
    //RECEPCION
    RCSTAbits.RC9=0;    /*8 bits*/  \
    RCSTAbits.CREN=1   //ACTIVAMOS RECEPCION


void tx_write(char data){
    TXREG=data;
}

char rx_read(){
  return RCREG;  
}