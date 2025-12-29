// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
//
// ## Description
// LOW (PIC18F452)
module pin_fn
@[inline]
pub fn low(id u8) {
	C.PIN_NAME = 0          // LATBbits.LB0 = 0
}
