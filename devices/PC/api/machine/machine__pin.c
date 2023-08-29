// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: machine__pin.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate digital pines in console.
#include <stdio.h>
#include <stdlib.h>

enum __pin_names {    // enumerated type for the pin names
    A = 0,    
    B,
    C,
    D,
    w,
    x,
    y,
    z
};

int __pins[8] = {0, 0, 0, 0, 0, 0, 0, 0};    // virtual pin array
int __input;

void pin_update(void) {
    system("clear");
    printf(" Aixt virtual pins     [#] = ON   [ ] = OFF\n");
    printf(" _____ _____ _____ _____ _____ _____ _____ _____\n");
    printf("|  A  |  B  |  C  |  D  |  w  |  x  |  y  |  z  |\n");
    for(int __i=0; __i<=7; __i++) {
        if(__pins[__i] == 0) {
            printf("| [ ] ");
        } else {
            printf("| [#] ");
        }
    }
    printf("|\n'-----'-----'-----'-----'-----'-----'-----'-----'\n");
}

char *pin_name(int pin) {
    switch (pin) {
    case A:  return "A";
    case B:  return "B";
    case C:  return "C";
    case D:  return "D";
    case w:  return "w";
    case x:  return "x";
    case y:  return "y";
    case z:  return "z";    
    default: return "ERROR";
    }
} 

void pin_high(int pin) {   
    __pins[pin] = 1;
    pin_update();
}

void pin_low(int pin) {   
    __pins[pin] = 0;
    pin_update();
}

void pin_write(int pin, int val) {  
    __pins[pin] = val;
    pin_update();
}

int pin_read(int pin) {
    system("clear");
    printf(" Aixt virtual pins     Input %s : ", pin_name(pin));
    scanf("%d", &__input);
    pin_write(pin, __input);
    return __input;
}