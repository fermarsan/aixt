// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)
module pin

@[inline]
pub fn read_(PORT_NAME, PIN) {
	C.PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN
}

@[inline]
pub fn read(PIN_NAME) {
	C.pin.read_(PIN_NAME)
}