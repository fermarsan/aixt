// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Pin management functions (Explorer16-PIC24 port)
#include <p24FJ128GA010.h>

#define out 0   // pin direction
#define in  1

unsigned int *__addr;       // PORT address pointer
unsigned int __port_bit;    // specific bit of PORT

#define pin_mode(PIN_NAME, MODE)    \
    __addr = (unsigned int)(PIN_NAME/16)*3 + &TRISA; \
    __port_bit = PIN_NAME%16; \
    if(MODE==in) *__addr |=   0x0001<<__port_bit; \
    else         *__addr &= ~(0x0001<<__port_bit)

#define pin_high(PIN_NAME)  \
    *((unsigned int)(PIN_NAME/16)*3 + &LATA)  |=   0x0001<<(PIN_NAME%16)

#define pin_low(PIN_NAME)   \
    *((unsigned int)(PIN_NAME/16)*3 + &LATA)  &= ~(0x0001<<(PIN_NAME%16))

#define pin_write(PIN_NAME,VAL) \
    __addr = (unsigned int)(PIN_NAME/16)*3 + &LATA; \
    __port_bit = PIN_NAME%16; \
    *__addr &= (~((0x0001)<<__port_bit)); \
    *__addr |= (VAL<<__port_bit)  

#define pin_read(PIN_NAME)  \
    ((*((unsigned int)(PIN_NAME/16)*3 + &PORTA) >> (PIN_NAME%16)) & 0x0001)


// void pin_mode(unsigned int PIN_NAME, unsigned int MODE) { 
//     __addr = (unsigned int)(PIN_NAME/16)*3 + &TRISA;
//     __port_bit = PIN_NAME%16;
//     if(MODE==in) *__addr |=   0x0001<<__port_bit;
//     else         *__addr &= ~(0x0001<<__port_bit);
// }

// void pin_high(unsigned int PIN_NAME) {   
//     *((unsigned int)(PIN_NAME/16)*3 + &LATA)  |=   0x0001<<(PIN_NAME%16);
// }

// void pin_low(unsigned int PIN_NAME) {    
//     *((unsigned int)(PIN_NAME/16)*3 + &LATA)  &= ~(0x0001<<(PIN_NAME%16));
// }

// void pin_write(unsigned int PIN_NAME, unsigned int VAL) {  
//     __addr = (unsigned int)(PIN_NAME/16)*3 + &LATA;
//     __port_bit = PIN_NAME % 16;
//     *__addr &= (~((0x0001)<<__port_bit));
//     *__addr |= (VAL<<__port_bit);  
// }

// void pin_read(unsigned int PIN_NAME) {   
//     ((*((unsigned int)(PIN_NAME/16)*3 + &PORTA) >> (PIN_NAME%16)) & 0x0001);
// }