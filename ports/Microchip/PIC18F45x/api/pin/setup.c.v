// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela Jurado and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: SETUP (PIC18F452)
module pin

@[inline]
pub fn setup(PIN_NAME, PIN_MODE) {
	C.PIN_NAME ## _s = PIN_MODE  // pin.setup(pin.b0_s, out);  -->  b0_s = out; --> TRISBbits.RB0 = 0;
}

//#fn port.setup(PORT_NAME, MODE)   PORT_NAME = MODE
//#fn pin.write(PORT_NAME,VAL)      PORT_NAME = VAL  