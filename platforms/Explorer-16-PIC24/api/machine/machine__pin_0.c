// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Fernando Martínez Santa

void pin(PIN,TYPE) { 
    addr = (int)(PIN/16)*3 + &TRISA;
    port_bit = PIN%16;
    if(TYPE==IN) *addr |=   0x0001<<port_bit;
    else         *addr &= ~(0x0001<<port_bit);
}

void pin_high(PIN) {   
    *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16);
}

void pin_low(PIN) {    
    *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16));
}

void pin_write(PIN,VAL) {  
    addr = (int)(PIN/16)*3 + &LATA;
    port_bit = PIN%16;
    *addr &= (~((0x0001)<<port_bit));
    *addr |= (VAL<<port_bit);  
}

void pin_read(PIN) {   
    ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001);
}