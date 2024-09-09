// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: setup.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

module pin

#define pin__setup(PIN_NAME, PIN_MODE)   PIN_NAME ## _s = PIN_MODE

