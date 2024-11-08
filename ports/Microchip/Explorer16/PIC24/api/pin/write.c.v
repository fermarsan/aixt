// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
module pin

/// write macro sets an output pin. This is expanded in this way:
//   pin.write(pin.b2, val)
//     |
//	   +-->	pin.write(pin.B, 2, val)
//	          |
//	          +-->	PORTBbits.PORTB2 = val	// PIC16	
// 	          		LATBbits.LATB2 = val	// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn write_(PORT_NAME, PIN, VALUE) {
	C.LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = VALUE
}

@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.pin.write_(PIN_NAME, VALUE)
}