// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F87x port)

module uart

@[inline]
pub fn setup() { 
    //Configuración del registro SPBRG (9600 Baudios)
    C.SPBRG=((_XTAL_FREQ/9600)/64)-1  
    //CONFIGURACION
    C.TXSTAbits.BRGH=0   //LOW SPEED  
    C.TXSTAbits.SYNC=0   //ASINCRONO  
    C.RCSTAbits.SPEN =1  //HABILITAR TX Y RX
    //TRANSMISION
    C.TXSTAbits.TX9=0    //8 BITS
    C.TXSTAbits.TXEN=1   //ACTIVAMOS TRANSMISION 
    //RECEPCION
    C.RCSTAbits.RC9=0    //8 bits
    C.RCSTAbits.CREN=1   //ACTIVAMOS RECEPCION
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