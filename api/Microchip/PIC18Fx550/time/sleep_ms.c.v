// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo Duarte and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// Milliseconds delay function
//              (PIC18F2550)

module time

#define time.sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory