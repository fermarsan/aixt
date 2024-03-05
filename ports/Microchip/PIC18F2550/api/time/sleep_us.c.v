// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Microseconds delay function
//              (PIC18F2550)

module time

#define time__sleep_us(TIME)    __delay_us(TIME)  // implementing by a macro for saving memory