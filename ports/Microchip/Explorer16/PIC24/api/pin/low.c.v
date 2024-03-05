// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// low macro clears an output pin. This is expanded in this way:
//   pin.low(b2)
//     |
//	   +-->	b2 = 0
//	          |
//	          +-->	PORTBbits.PORTB2 = 0	// PIC16	
// 	          		LATBbits.LATB2 = 0		// (PIC18, PIC24, dsPIC33)
#define pin__low(PIN_NAME)   PIN_NAME = 0
