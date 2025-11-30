/*
 * File:   USART.c
 * Author: Andrés Fajardo
 *
 * Created on 10 de enero de 2024, 10:32 PM
 */


#define _XTAL_FREQ 8000000
#include <xc.h>
#include "USART.h"


void USART_Init(long BAUD){
    //CONFIG DE LOS PINES
    TRISCbits.RC6=0;    //RC6 = TX
    TRISCbits.RC7=1;    //RC7 = RX
    //BAUDIOS
    SPBRG=(unsigned char)((_XTAL_FREQ/BAUD)/64)-1;
    //configuracion
    TXSTAbits.BRGH=0;   //LOW SPEED
    TXSTAbits.SYNC=0;   //ASINCRONO
    RCSTAbits.SPEN =1;   //HABILITAR TX Y RX
    //transmision
    TXSTAbits.TX9=0;    //8 BITS
    TXSTAbits.TXEN=1;   //ACTIVAMOS TRANSMISION
    //RECEPCION
    RCSTAbits.RC9=0;    //8 bits
    RCSTAbits.CREN=1;   //ACTIVAMOS RECEPCION
   
}
void USART_Tx(char data){
    TXREG=data;
}
char USART_Rx(){
  return RCREG;  
}