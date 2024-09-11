// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F886 port)
module port

#define port.setup(PORT_NAME, VALUE)   TRIS ## PORT_NAME = VALUE