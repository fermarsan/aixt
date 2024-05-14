// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: milliseconds delay function (PIC16F84A port)
module time

#define time__sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory