// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)
module pin

@[inline]
pub fn write_(PORT_NAME, PIN, VALUE) {
	C.PORT ##  PORT_NAME ##  bits.R ##  PORT_NAME ##  PIN = VALUE
}

@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.pin.write_(PIN_NAME, VALUE)
}