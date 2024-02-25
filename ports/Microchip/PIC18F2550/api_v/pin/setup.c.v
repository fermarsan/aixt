// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pic.c
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PIN management functions  (PIC18F2550 port)

module pin

#define pin_setup(PIN_NAME, MODE)     PIN_NAME = MODE  // pin_setup(b0_s, out);  -->  b0_s = out; --> TRISBbits.RB0 = 0;