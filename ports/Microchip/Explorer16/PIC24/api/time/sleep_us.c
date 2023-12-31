// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Microseconds delay function
//              (Explorer16-PIC24 port)
#include <libpic30.h>

#define sleep_us(TIME)    __delay_us(TIME)