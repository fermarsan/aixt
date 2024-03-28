// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin setup.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)

module pin

#define pin__setup(PIN_NAME, PIN_MODE)   PIN_NAME ## _s = PIN_MODE

