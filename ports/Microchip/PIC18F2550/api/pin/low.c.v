// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: low.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PIN management functions  (PIC18F2550 port)

module pin

#define pin__low(PIN_NAME)             PIN_NAME = 0          // LATBbits.LB0 = 0