// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// LOW (PIC18F452)
module pin_fn
@[inline]
pub fn low(PIN_NAME) {
	C.PIN_NAME = 0          // LATBbits.LB0 = 0
}