// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F88x port)
module pin

@[inline]
pub fn low_(PORT_NAME, PIN) {
	C.PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN = 0
}

@[inline]
pub fn low(PIN_NAME) {
	C.pin.low_(PIN_NAME)
}