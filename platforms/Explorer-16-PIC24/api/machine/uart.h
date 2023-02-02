// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
//
//
// Copyright (c) 2022 Santiago Orjuela R

#ifndef _UART_H_
#define _UART_H_

#define CTS1 	_RF12		        // Clear To Send
#define RTS1    _RF13               // Request To Send
#define TRTS1   TRISFbits.TRISF13   // tris control for RTS
#define CTS2 	_RF12		        // Clear To Send
#define RTS2    _RF13               // Request To Send
#define TRTS2   TRISFbits.TRISF13   // tris control for RTS

#define BRATE    412      	// 9600 baud (BREGH=1)
#define U_ENABLE 0x8008		// enable the UART peripheral (BREGH=1)
#define U_TX	 0x0400		// enable transmission

#define uart1(BAUD)                 \
    U1BRG 	= FCY / (4*(uint32_t)BAUD) - 1;   \
    U1MODE 	= U_ENABLE;             \
    U1STA 	= U_TX;                 \
    TRTS1   = 0;                    \
    RTS1    = 1;

#define uart2(BAUD)                 \
    U2BRG 	= FCY / (4*(uint32_t)BAUD) - 1;   \
    U2MODE 	= U_ENABLE;             \
    U2STA 	= U_TX;                 \
    TRTS2   = 0;                    \
    RTS2    = 1;  

#define uart1_put(C)             \
        while(CTS1);            \
        while(U1STAbits.UTXBF); \
	    U2TXREG = C;            \

#define uart2_put(C)             \
        while(CTS2);            \
        while(U2STAbits.UTXBF); \
	    U2TXREG = C;            \

char uart1_get(void) {           // wait for a new character to arrive to the UART2 
    RTS1 = 0;            	    // assert Request To Send !RTS
    while(!U1STAbits.URXDA);    // wait for a new character to arrive
    RTS1 = 1;
    return U1RXREG;		        // read the character from receive buffer 
}

char uart2_get(void) {     
    RTS2 = 0;            	    // assert Request To Send !RTS
    while(!U2STAbits.URXDA);    // wait for a new character to arrive
    RTS2 = 1;
    return U2RXREG;		        // read the character from receive buffer 
}

void uart1_write(char *str) {
    while(*str != '\0'){
        uart1_put(*str);
        str++;
    }
}

void uart2_write(char *str) {
    while(*str != '\0'){
        uart2_put(*str);
        str++;
    }
}

void uart1_read(int n, char *str){
    for(int i=0;i<n;i++)
        str[i] = uart1_get();
    str[n] = '\0';  //NULL    
}

void uart2_read(int n, char *str){
    for(int i=0;i<n;i++)
        str[i] = uart2_get();
    str[n] = '\0';  //NULL    
}

#endif  //_UART_H_ 

