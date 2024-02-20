// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

#define pin_setup(PIN_NAME, MODE)   PIN_NAME = MODE     // pin_setup(b0_s, out);  -->  b0_s = out; --> TRISBbits.TRISB0 = 0;

