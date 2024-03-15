// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_s.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Seconds delay function
//              (PIC16F676 port)

#define sleep_s(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory