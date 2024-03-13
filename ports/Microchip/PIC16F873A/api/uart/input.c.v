// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: input.c.v
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Uart management functions
//              (PIC16F873A port)

module uart

#define uart__input() (PIR1bits.RCIF ? 1 : 0)  // Valida si hay datos recibidos retorna un 1 si no hay datos recibidos un 0


