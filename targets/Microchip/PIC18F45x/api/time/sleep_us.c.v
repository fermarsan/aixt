// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// Microseconds delay function
//              (PIC18F452)

module time

#define time.sleep_us(TIME)    __delay_us(TIME)