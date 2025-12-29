// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Jan Carlo Peñuela Jurado and Fernando M. Santa
//
// _Date:_ 2024
//
// ## Description
// SETUP (PIC18F452)
module pin_fn

@[inline]
pub fn setup(id u8, mode u8) {
	C.PIN_NAME ## _s = PIN_MODE  // pin.setup(pin.b0_s, out);  -->  b0_s = out; --> TRISBbits.RB0 = 0;
}

//#fn port.setup(PORT_NAME, MODE)   PORT_NAME = MODE
//#fn pin.write(PORT_NAME,VAL)      PORT_NAME = VAL
