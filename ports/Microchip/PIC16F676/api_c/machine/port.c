// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: port.c
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Port management functions
//              (PIC16F676 port)

#define port_setup(PORT_NAME, VALUE)  TRIS ## PORT_NAME = VALUE
#define port_read(PORT_NAME)          PORT ## PORT_NAME
#define port_write(PORT_NAME, VALUE)  PORT ## PORT_NAME = VALUE