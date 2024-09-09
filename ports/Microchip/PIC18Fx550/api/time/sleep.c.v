// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: sleep.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Seconds delay function
//              (PIC18F2550)

module time

#define time__sleep(TIME)    __delay_s(TIME*1000)