// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
module pin

/// low macro sets an output pin. This is expanded in this way:
//   pin.low(b2)
//     |
//	   +-->	pin.low(B, 2)
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
