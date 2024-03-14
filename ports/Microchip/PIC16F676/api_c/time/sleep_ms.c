// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_ms.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Milliseconds delay function
//              (PIC16F676 port)

#define sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory