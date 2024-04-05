// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

/// low macro sets an output pin. This is expanded in this way:
//   pin.low(b2)
//     |
//	   +-->	pin.low(B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 = 0	// PIC16	
// 	          		LATBbits.LATB2 = 0		// (PIC18, PIC24, dsPIC33)
#define pin__low_(PORT_NAME, PIN)   LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 1

#define pin__low(PIN_NAME)  pin__low_(PIN_NAME)
