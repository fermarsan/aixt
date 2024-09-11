// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)
module pin

#define pin.setup_(PORT_NAME, PIN, MODE)   TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE

#define pin.setup(PIN_NAME, PIN_MODE)  pin.setup_(PIN_NAME, PIN_MODE)