// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)
#include <xc.h>

#define output 0   // pin mode (direction)
#define input  1

#define pin_setup(PIN_NAME, MODE)   PIN_NAME = MODE

#define pin_high(PIN_NAME)  PIN_NAME = 1
#define pin_low(PIN_NAME)   PIN_NAME = 0
#define pin_write(PIN_NAME,VAL) PIN_NAME = VAL
#define pin_read(PIN_NAME)  PIN_NAME