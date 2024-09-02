#define _XTAL_FREQ 8000000
#include <xc.h>
#include "USART_452.h"

void USART_Init(long BAUD){
    //Configuraci�n de los pines
    TRISCbits.RC6 = 0;      //RC6 = Tx -> Salida
    TRISCbits.RC7 = 1;      //RC7 = Rx -> Entrada
    
    //Baudios
    SPBRG = (unsigned char)(((_XTAL_FREQ/BAUD)/64)-1);
    
    //Configuraci�n 
    TXSTAbits.BRGH = 0;     //Low Speed
    TXSTAbits.SYNC = 0;     //Asincrono
    RCSTAbits.SPEN = 1;     //Habilitar Tx y Rx
    
    //Transmisi�n
    TXSTAbits.TX9 = 0;      //8 bits
    TXSTAbits.TXEN = 1;     //Activamos transmisi�n
    
    //Recepci�n
    RCSTAbits.RX9 = 0;      //8 bits
    RCSTAbits.CREN = 1;     //Activamos recepci�n
}

void USART_Tx(char data){
    TXREG = data;
}

char USART_Rx(){
    return RCREG; 
}