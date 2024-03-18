// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: WRITE (PIC18F452)
module pin
#define pin__write(PIN_NAME,VAL)   PIN_NAME = VAL    // LATBbits.LB0 = 0