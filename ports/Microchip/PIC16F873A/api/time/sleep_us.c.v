// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: sleep_us.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC16F873A port)

module time

#define time__sleep_us(TIME)    __delay_us(TIME)