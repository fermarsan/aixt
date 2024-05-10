// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F84A port)
module port

#define port__setup(PORT_NAME, VALUE)   TRIS ## PORT_NAME = VALUE