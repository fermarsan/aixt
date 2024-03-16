// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: low.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F676 port)

module pin

#define pin__low(PIN_NAME)   PIN_NAME = 0
