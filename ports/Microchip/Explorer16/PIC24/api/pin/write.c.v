// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// write macro writes a binary value on an output pin. This is expanded in this way:
//   pin.write(b2, value)
//     |
//	   +-->	b2 = value
//	          |
//	          +-->	PORTBbits.PORTB2 = value	// PIC16	
// 	          		LATBbits.LATB2 = value		// (PIC18, PIC24, dsPIC33)
#define pin__write(PIN_NAME, VALUE) PIN_NAME = VALUE