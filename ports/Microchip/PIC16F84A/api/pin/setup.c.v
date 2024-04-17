// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin setup.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)

module pin

#define pin__setup_(PORT_NAME, PIN, MODE)   TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE

#define pin__setup(PIN_NAME, PIN_MODE)  pin__setup_(PIN_NAME, PIN_MODE)