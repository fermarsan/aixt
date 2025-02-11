// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
module pin

/// low macro sets an output pin. This is expanded in this way:
//   pin.low(pin.b2)
//     |
//	   +-->	pin.low(pin.B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 = 0	// PIC16	
// 	          		LATBbits.LATB2 = 0		// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn low_(PORT_NAME, PIN) {
	C.LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 0
}

@[inline]
pub fn low(PIN_NAME) {
	C.pin.low_(PIN_NAME)
}
