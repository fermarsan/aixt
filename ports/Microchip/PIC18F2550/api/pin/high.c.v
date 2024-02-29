// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: high.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PIN management functions  (PIC18F2550 port)

module pin

#define pin__high(PIN_NAME)            PIN_NAME = 1          // LATBbits.LB0 = 1