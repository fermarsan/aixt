// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Microseconds delay function
//              (Explorer16-PIC24 port)
#include <libpic30.h>

#define sleep_us(TIME)    __delay_us(TIME)