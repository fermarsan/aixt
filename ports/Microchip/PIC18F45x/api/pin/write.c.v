// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: WRITE (PIC18F452)
module pin
@[inline]
pub fn write(PIN_NAME,VAL) {
	C.PIN_NAME = VAL    // LATBbits.LB0 = 0
}