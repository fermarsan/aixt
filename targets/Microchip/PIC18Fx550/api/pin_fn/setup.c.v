// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Andrés Felipe Fajardo Duarte and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// PIN management functions  (PIC18F2550 port)

module pin_fn

@[inline]
pub fn setup(PIN_NAME, PIN_MODE) {
	C.PIN_NAME ## _s = PIN_MODE    // pin.setup(pin.b0_s, out);  -->  b0_s = out; --> TRISBbits.RB0 = 0;
}