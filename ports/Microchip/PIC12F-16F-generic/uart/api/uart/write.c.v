// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Pin management functions
//              (PIC16F family)

module uart

@[as_macro]
pub fn write(ch u8) {
	for C.TXIF == 0 {} // for C.TRMT == 0 {} // wait until tx buffer is empty
	C.TXREG = ch
}
