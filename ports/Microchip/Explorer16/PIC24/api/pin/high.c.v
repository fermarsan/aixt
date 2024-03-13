// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module pin

// high macro sets an output pin. This is expanded in this way:
//   pin.high(b2)
//     |
//	   +-->	b2 = 1
//	          |
//	          +-->	PORTBbits.PORTB2 = 1	// PIC16	
// 	          		LATBbits.LATB2 = 1		// (PIC18, PIC24, dsPIC33)
#define pin__high(PIN_NAME)  PIN_NAME = 1




