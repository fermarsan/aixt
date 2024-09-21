// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F886 port)

module uart

@[inline]
pub fn write(DATA) {
	C.while (TRMT == 0);    TXREG = DATA
}
