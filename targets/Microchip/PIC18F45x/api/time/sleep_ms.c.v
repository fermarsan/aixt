// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Milliseconds delay function
//              (PIC18F452)

module time

#define time.sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory