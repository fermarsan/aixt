// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Seconds delay function
//              (PIC16F873A port)

module time

#define time.sleep(TIME)    __delay_s(TIME)

