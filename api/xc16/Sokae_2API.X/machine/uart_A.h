#ifndef _UART_H_
#define _UART_H_

#include "../settings.h"

#define CTS1 	_RF12		        // Clear To Send
#define RTS1    _RF13               // Request To Send
#define TRTS1   TRISFbits.TRISF13   // tris control for RTS
#define CTS2 	_RF12		        // Clear To Send
#define RTS2    _RF13               // Request To Send
#define TRTS2   TRISFbits.TRISF13   // tris control for RTS

#define BRATE    412      	// 9600 baud (BREGH=1)
#define U_ENABLE 0x8008		// enable the UART peripheral (BREGH=1)
#define U_TX	 0x0400		// enable transmission

#define uart(N,BAUD)                    \
    if(N==1){                           \
        U1BRG 	= ((FCY/2) / BAUD) - 1; \
        U1MODE 	= U_ENABLE;             \
        U1STA 	= U_TX;                 \
        TRTS1   = 0;                    \
        RTS1    = 1; }                  \
    else if(N==2){                      \
        U2BRG 	= ((FCY/2) / BAUD) - 1; \
        U2MODE 	= U_ENABLE;             \
        U2STA 	= U_TX;                 \
        TRTS2   = 0;                    \
        RTS2    = 1; }        

#define uartPut(N,C)            \
    if(N==1){                   \
        while(CTS1);            \
        while(U1STAbits.UTXBF); \
	    U2TXREG = C; }          \
    else if(N==2){              \
        while(CTS2);            \
        while(U2STAbits.UTXBF); \
	    U2TXREG = C; }          \

int uartGet(int n) {                // wait for a new character to arrive to the UART2 
    if(n==1){
        RTS1 = 0;            	    // assert Request To Send !RTS
        while(!U1STAbits.URXDA);    // wait for a new character to arrive
        RTS1 = 1;
        return U1RXREG;		        // read the character from receive buffer 
    }
    else if(n==2){     
        RTS2 = 0;            	    // assert Request To Send !RTS
        while(!U2STAbits.URXDA);    // wait for a new character to arrive
        RTS2 = 1;
        return U2RXREG;		        // read the character from receive buffer 
    } 
    else return 0;
}

void uartWrite(int n, char *str) {
    while(*str != '\0'){
        uartPut(n, *str);
        str++;
    }
}

// void uartRead(int n, int m, char *str){
//     while(m > 0){
        
//     }
// }
#endif  //_UART_H_

