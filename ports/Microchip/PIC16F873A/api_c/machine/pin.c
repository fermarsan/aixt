// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

#define out 0   // pin mode (direction)
#define in  1

#define pin_setup(PIN_NAME, MODE)   PIN_NAME ## _s = MODE

#define pin_high(PIN_NAME)  PIN_NAME = 1
#define pin_low(PIN_NAME)   PIN_NAME = 0
#define pin_write(PIN_NAME,VAL) PIN_NAME = VAL

#define pin_read(PIN_NAME)  PIN_NAME