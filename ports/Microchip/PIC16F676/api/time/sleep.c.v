// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Seconds delay function
//              (PIC16F676 port)

module time

#define time__sleep(TIME)    __delay_s(TIME)