// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo Duarte and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// Seconds delay function
//              (PIC18F2550)

module time

#define time.sleep(TIME)    __delay_s(TIME*1000)