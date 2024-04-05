// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

/// write macro sets an output pin. This is expanded in this way:
//   pin.write(b2, val)
//     |
//	   +-->	pin.write(B, 2, val)
//	          |
//	          +-->	PORTBbits.PORTB2 = val	// PIC16	
// 	          		LATBbits.LATB2 = val	// (PIC18, PIC24, dsPIC33)
#define pin__write_(PORT_NAME, PIN, VALUE)   LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = VALUE

#define pin__write(PIN_NAME, VALUE)  pin__write_(PIN_NAME, VALUE)