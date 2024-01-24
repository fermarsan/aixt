// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC16F886 port)
#include <xc.h>

#define sleep_us(TIME)    __delay_us(TIME)  // implementing by a macro for saving memory