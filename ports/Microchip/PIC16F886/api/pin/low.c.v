// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)
module pin

#define pin.low_(PORT_NAME, PIN)   PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN = 0

#define pin.low(PIN_NAME)  pin.low_(PIN_NAME)