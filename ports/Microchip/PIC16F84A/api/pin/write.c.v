// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin write.c
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)

module pin

#define pin__write(PIN_NAME,VAL) PIN_NAME = VAL