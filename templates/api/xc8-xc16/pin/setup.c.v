// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
module pin

// setup macro configures a pin's input/output mode. This is expanded in this way:
//   pin.setup(a7, input)
//     |
//	   +-->	pin.setup(A, 7, 1)
//	          |
//            +-->	TRISAbits.TRISA7 = 1
@[inline]
pub fn setup_(PORT_NAME, PIN, MODE) {
	C.TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE
}

@[inline]
pub fn setup(PIN_NAME, PIN_MODE) {
	C.pin.setup_(PIN_NAME, PIN_MODE)
}