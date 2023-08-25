// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: machine__pin_emu.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate digital pines in console.
#include <stdio.h>
#include <stdlib.h>

enum pin_names {    // enumerated type for the pin names
    A = 0,    
    B,
    C,
    D,
    w,
    x,
    y,
    z
};

int pins[8] = {0, 0, 0, 0, 0, 0, 0, 0};    // virtual pin array

void pin_update(void) {
    system("clear");
    printf(" Virtual pines    [ ] = OFF, [#] = ON\n");
    printf(" _____ _____ _____ _____ _____ _____ _____ _____\n");
    printf("|  A  |  B  |  C  |  D  |  w  |  x  |  y  |  z  |\n");
    for(int i=0;i<=7;i++) {
        if(pins[i] == 0) {
            printf("| [ ] ");
        } else {
            printf("| [#] ");
        }
    }
    printf("|\n'-----'-----'-----'-----'-----'-----'-----'-----'\n");
}

void pin_high(int pin) {   
    pins[pin] = 1;
    pin_update();
}

void pin_low(int pin) {   
    pins[pin] = 0;
    pin_update();
}

void pin_write(int pin, int val) {  
    pins[pin] = val;
    pin_update();
}
