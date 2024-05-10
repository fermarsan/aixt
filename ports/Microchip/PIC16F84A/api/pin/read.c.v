// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F84A port)
module pin

#define pin__read_(PORT_NAME, PIN)	PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN

#define pin__read(PIN_NAME)  pin__read_(PIN_NAME)