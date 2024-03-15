// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart input.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F886 port)

module uart

#define uart__input() (PIR1bits.RCIF ? 1 : 0)  // Valida si hay datos recibidos retorna un 1 si no hay datos recibidos un 0
    