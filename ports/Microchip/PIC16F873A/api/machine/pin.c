// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)
#include <xc.h>

#define out 0   // pin direction
#define in  1

unsigned char *__addr;          //PORT address pointer
unsigned char __port_bit;     //specific bit of PORT

#define pin_mode(PIN_NAME,MODE)   \
    __addr = (unsigned char)(PIN_NAME/8) + &TRISA; \
    __port_bit = PIN_NAME%8; \
    if(MODE==in) *__addr |=   0x01<<__port_bit; \
    else         *__addr &= ~(0x01<<__port_bit)

#define pin_high(PIN_NAME)    \
    *((unsigned char)(PIN_NAME/8) + &PORTC)  |=   0x01<<(PIN_NAME%8)

#define pin_low(PIN_NAME)     \
    *((unsigned char)(PIN_NAME/8) + &PORTC)  &= ~(0x01<<(PIN_NAME%8))

#define pin_write(PIN_NAME,VAL)   \
    __addr = (unsigned char)(PIN_NAME/8) + &LATA; \
    __port_bit = PIN_NAME%8; \
    *__addr &= (~((0x01)<<__port_bit)); \
    *__addr |= (VAL<<__port_bit)  

#define pin_read(PIN_NAME)    \
    ((*((unsigned char)(PIN_NAME/8) + &PORTA) >> (PIN_NAME%8)) & 0x01)