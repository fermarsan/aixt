// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: high.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F873A port)

module pin

#define pin__digital()   ADCON1bits.PCFG = 0b00000110