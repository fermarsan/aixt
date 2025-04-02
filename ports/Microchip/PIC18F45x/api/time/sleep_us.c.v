// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC18F452)

module time

#define time.sleep_us(TIME)    __delay_us(TIME)