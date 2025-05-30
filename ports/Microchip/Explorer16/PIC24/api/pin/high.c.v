// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
module pin

// high macro sets an output pin. This is expanded in this way:
//   pin.high(pin.b2)
//     |
//	   +-->	pin.high(pin.B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 = 1	// PIC16	
// 	          		LATBbits.LATB2 = 1		// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn high_(PORT_NAME, PIN) {
	C.LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 1
}

@[inline]
pub fn high(PIN_NAME) {
	C.pin.high_(PIN_NAME)
}

