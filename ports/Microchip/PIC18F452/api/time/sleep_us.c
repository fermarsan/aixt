// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC18F452)

#include <xc.h>
#define sleep_us(TIME)    __delay_us(TIME)