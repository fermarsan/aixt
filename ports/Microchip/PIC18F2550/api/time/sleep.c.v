// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Seconds delay function
//              (PIC18F2550)

module time

#define time__sleep(TIME)    __delay_s(TIME*1000)