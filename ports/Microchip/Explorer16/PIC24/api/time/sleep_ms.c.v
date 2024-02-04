// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Milliseconds delay function
//              (Explorer16-PIC24 port)
#include <libpic30.h>

#define sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory

// void sleep_ms(int time)  // equivalent using a function
// {
//     __delay_ms(time);
// }