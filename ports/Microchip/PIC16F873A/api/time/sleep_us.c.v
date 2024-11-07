// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC16F87x port)

module time

#define time.sleep_us(TIME)    __delay_us(TIME)