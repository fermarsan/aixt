// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// READ (PIC18F452)
module pin_fn
@[inline]
pub fn read(PIN_NAME) {
	C.PIN_NAME ##_i             // PORTBbits.RB0 
}