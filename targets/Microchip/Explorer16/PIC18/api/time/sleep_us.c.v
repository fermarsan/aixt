// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC18F2550)

module time

#define time.sleep_us(TIME)    __delay_us(TIME)  // implementing by a macro for saving memory