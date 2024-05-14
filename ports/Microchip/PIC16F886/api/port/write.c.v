// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F886 port)
module port

#define port__write(PORT_NAME, VALUE)  PORT ## PORT_NAME = VALUE