// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: READ (PIC18F452)
module pin
@[inline]
pub fn read(PIN_NAME) {
	C.PIN_NAME ##_i             // PORTBbits.RB0 
}