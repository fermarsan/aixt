// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2022-2023 Fernando Martínez Santa
//
// Optimization level 1 (functions as macros)

#ifndef _MACHINE__PIN_1_H_
#define _MACHINE__PIN_1_H_

#include "../ports_1.h"

#define PIN_IN      1
#define PIN_OUT     0

int *addr; //PORT address pointer
int port_bit;       //specific bit of PORT

//The PORT address are computed as  "(int)(PIN / n)*s + init" 
//and the individual bit is computed as  "PIN % n"
//where "n" is the number of bit of each port (16 for this case) 
//"s" is the address separation between each PORT (6 for this case)
//and "init" is the PORTA address
//the same applies to TRIS and LAT registers 

#define pin(PIN,TYPE)   \
    addr = (int)(PIN/16)*3 + &TRISA; \
    port_bit = PIN%16; \
    if(TYPE==PIN_IN) *addr |=   0x0001<<port_bit; \
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

#endif  //_MACHINE__PIN_1_H_ 