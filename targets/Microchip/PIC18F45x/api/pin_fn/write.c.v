// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// WRITE (PIC18F452)
module pin_fn
@[inline]
pub fn write(PIN_NAME,VAL) {
	C.PIN_NAME = VAL    // LATBbits.LB0 = 0
}