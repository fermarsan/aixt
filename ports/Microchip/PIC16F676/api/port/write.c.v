// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Port management functions
//              (PIC16F676 port)
module port

#define port__write(PORT_NAME, VALUE)  PORT ## PORT_NAME = VALUE