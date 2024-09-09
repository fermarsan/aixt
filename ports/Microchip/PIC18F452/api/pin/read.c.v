// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: READ (PIC18F452)
module pin
#define pin__read(PIN_NAME)  PIN_NAME ##_i             // PORTBbits.RB0 