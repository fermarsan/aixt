// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: low.c.v
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: LOW (PIC18F452)
module pin
#define pin__low(PIN_NAME)   PIN_NAME = 0          // LATBbits.LB0 = 0