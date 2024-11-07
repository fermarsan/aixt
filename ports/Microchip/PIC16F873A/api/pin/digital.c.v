// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions
//              (PIC16F87x port)

module pin

@[inline]
pub fn digital() {
	C.ADCON1bits.PCFG = 0b00000110
}