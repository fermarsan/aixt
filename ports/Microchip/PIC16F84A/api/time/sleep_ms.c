// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_ms.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Milliseconds delay function
//              (PIC16F84A port)
#include <xc.h>

#define sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory
