// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin-port functions (PIC16F88x port)
module port

@[inline]
pub fn write(PORT_NAME, VALUE) {
	C.PORT ## PORT_NAME = (uint8_t)VALUE
}