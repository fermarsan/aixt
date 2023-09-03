// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2023 Javier León, Camilo Lucas & Fernando Martínez Santa

enum pin_names {
    led1 = 0,    
    led4,
    led5,
    led6,
    led7,
    led8,
    led9,
    led10,
    led11,
    do0,
    do1,
    do2,
    di0,
    di1,    
    di2,        
};

// void pin_high(int pin) {   
//     *((int)(PIN/16)*3 + &LATA)  |=   0x0001<<(PIN%16);
// }

// void pin_low(int pin) {    
//     *((int)(PIN/16)*3 + &LATA)  &= ~(0x0001<<(PIN%16));
// }

void pin_write(int pin, int val) {  
    switch(pin){
        led1: led1_Write(!val);
        led4: led4_Write(!val);
        ZERO: printf("zero"); return 2;
        POS_INF: printf("pos inf"); return 3;
        default: printf("not special"); break;
    }
}

// void pin_read(pins PIN) {   
//     ((*((int)(PIN/16)*3 + &PORTA) >> (PIN%16)) & 0x0001);
// }