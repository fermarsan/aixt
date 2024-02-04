// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Pin management functions (Explorer16-PIC24 port)
#include <p24FJ128GA010.h>

#define out 0   // pin mode (direction)
#define in  1

#define pin_setup(PIN_NAME, MODE)   PIN_NAME = MODE

#define pin_high(PIN_NAME)  PIN_NAME = 1
#define pin_low(PIN_NAME)   PIN_NAME = 0
#define pin_write(PIN_NAME,VAL) PIN_NAME = VAL
#define pin_read(PIN_NAME)  PIN_NAME