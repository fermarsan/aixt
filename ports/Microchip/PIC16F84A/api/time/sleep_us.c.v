// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: time_sleep_us.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: seconds delay function
//              (PIC16F886 port)

module time

#define time__sleep_us(TIME)    __delay_s(TIME)  // implementing by a macro for saving memory