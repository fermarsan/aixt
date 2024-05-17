// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// toggle macro sets an output pin. This is expanded in this way:
//   pin.toggle(b2)
//     |
//	   +-->	pin.toggle(B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 ^= 1	// PIC16	
// 	          		LATBbits.LATB2 ^= 1		// (PIC18, PIC24, dsPIC33)
#define pin__toggle_(PORT_NAME, PIN)   LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN ^= 1

#define pin__toggle(PIN_NAME)  pin__toggle_(PIN_NAME)



