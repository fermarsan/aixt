// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Port management functions
//              (PIC16F676 port)
module port

#define port.setup(PORT_NAME, VALUE)   TRIS ## PORT_NAME = VALUE