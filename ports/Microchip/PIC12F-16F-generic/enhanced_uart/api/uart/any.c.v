// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: UART functions
//              (PIC16F family)
module uart

@[inline]
pub fn any() {
	C.RCIF
}
