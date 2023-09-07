// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Pin management functions
//              (Explorer16-PIC24 port)
#include <p24FJ128GA010.h>

#define in  1
#define out 0

int *addr;      //PORT address pointer
int port_bit;   //specific bit of PORT

#define pin_mode(PIN,TYPE)   \
    addr = (int)(PIN/16)*3 + &TRISA; \
    port_bit = PIN%16; \
    if(TYPE==in) *addr |=   0x0001<<port_bit; \
    else         *addr &= ~(0x0001<<port_bit)

#define pin_high(PIN)    \
    *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16)

#define pin_low(PIN)     \
    *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16))

#define pin_write(PIN,VAL)   \
    addr = (int)(PIN/16)*3 + &LATA; \
    port_bit = PIN%16; \
    *addr &= (~((0x0001)<<port_bit)); \
    *addr |= (VAL<<port_bit)  

#define pin_read(PIN)    \
    ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001)


// void pin_mode(int PIN, int TYPE) { 
//     addr = (int)(PIN/16)*3 + &TRISA;
//     port_bit = PIN%16;
//     if(TYPE==in) *addr |=   0x0001<<port_bit;
//     else         *addr &= ~(0x0001<<port_bit);
// }

// void pin_high(int PIN) {   
//     *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16);
// }

// void pin_low(int PIN) {    
//     *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16));
// }

// void pin_write(int PIN, int VAL) {  
//     addr = (int)(PIN/16)*3 + &LATA;
//     port_bit = PIN % 16;
//     *addr &= (~((0x0001)<<port_bit));
//     *addr |= (VAL<<port_bit);  
// }

// void pin_read(int PIN) {   
//     ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001);
// }