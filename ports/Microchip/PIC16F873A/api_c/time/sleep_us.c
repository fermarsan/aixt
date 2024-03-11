// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Microseconds delay function
//              (PIC16F873A port)

#define sleep_us(TIME)    __delay_us(TIME)