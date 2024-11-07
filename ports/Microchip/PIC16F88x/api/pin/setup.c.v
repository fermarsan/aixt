// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F88x port)
module pin

@[inline]
pub fn setup_(PORT_NAME, PIN, MODE) {
	C.TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE
}

@[inline]
pub fn setup(PIN_NAME, PIN_MODE) {
	C.pin.setup_(PIN_NAME, PIN_MODE)
}