// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

module pin

#define pin__write(PIN_NAME,VAL) PIN_NAME = VAL
