// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: uart
//              (PIC18F452)
module uart

fn setup() {
    //Configuración del registro SPBRG (9600 Baudios)
    SPBRG=((_XTAL_FREQ/9600)/64)-1 
    //configuracion
    TXSTAbits.BRGH=0   /*LOW SPEED*/  
    TXSTAbits.SYNC=0   /*ASINCRONO*/  
    RCSTAbits.SPEN =1  /*HABILITAR TX Y RX*/  
    //transmision
    TXSTAbits.TX9=0    /*8 BITS*/  
    TXSTAbits.TXEN=1   /*ACTIVAMOS TRANSMISION*/  
    //RECEPCION
    RCSTAbits.RC9=0    /*8 bits*/  
    RCSTAbits.CREN=1   //ACTIVAMOS RECEPCION
}