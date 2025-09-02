// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Milliseconds delay function
//              (PIC18F2550)

module time

#define time.sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory