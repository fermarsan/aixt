// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: read.c.v
// Author: Andrés Felipe Fajardo Duarte and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PIN management functions  (PIC18F2550 port)

module pin

#define pin__read(PIN_NAME)            PIN_NAME ## _i             // PORTBbits.RB0 