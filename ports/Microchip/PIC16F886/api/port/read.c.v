// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: port read.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F886 port)

module port

#define port__read(PORT_NAME)  PORT ## PORT_NAME