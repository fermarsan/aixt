// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa
//
// Optimization level 0 (as functions)

#ifndef _MACHINE__PIN_0_H_
#define _MACHINE__PIN_0_H_

#include "../ports_0.h"

#define PIN_IN      1
#define PIN_OUT     0

pins port;  
int *addr;      //PORT address pointer
int port_bit;   //specific bit of PORT

//The PORT address are computed as  "(int)(PIN / n)*s + init" 
//and the individual bit is computed as  "PIN % n"
//where "n" is the number of bit of each port (16 for this case) 
//"s" is the address separation between each PORT (6 for this case)
//and "init" is the PORTA address
//the same applies to TRIS and LAT registers 

void pin(pins PIN, int TYPE);
void pin_high(pins PIN);
void pin_low(pins PIN);
void pin_write(pins PIN, int VAL);
void pin_read(pins PIN);

#endif  //_MACHINE__PIN_0_H_ 