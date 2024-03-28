// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F873A port)

module uart

fn setup() { 
    //Configuración del registro SPBRG (9600 Baudios)
    SPBRG=((_XTAL_FREQ/9600)/64)-1  
    //CONFIGURACION
    TXSTAbits.BRGH=0   //LOW SPEED  
    TXSTAbits.SYNC=0   //ASINCRONO  
    RCSTAbits.SPEN =1  //HABILITAR TX Y RX
    //TRANSMISION
    TXSTAbits.TX9=0    //8 BITS
    TXSTAbits.TXEN=1   //ACTIVAMOS TRANSMISION 
    //RECEPCION
    RCSTAbits.RC9=0    //8 bits
    RCSTAbits.CREN=1   //ACTIVAMOS RECEPCION
    }




/*
fn setup() {
    SPBRG = 51 /* 51 para 9600 baudios */  
    TXSTAbits.SYNC = 0 /* Modo asíncrono*/ 
    TXSTAbits.BRGH = 1 /* Baja velocidad de baudios*/ 
    RCSTAbits.SPEN = 1 /* Habilitar la UART*/ 
    TXSTAbits.TXEN = 1 /* Habilitar transmisor*/ 
    RCSTAbits.CREN = 1 /* Habilitar receptor*/ 
}
*/