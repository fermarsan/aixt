// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Jan Carlo Peñuela y Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module port

// write macro writes a value on a complete pin port. This is expanded in this way:
//   port.write(b, 0x45)
//     |
//	   +-->	PORTb = 0x45	// PIC16
//          LATb = 0x45		// (PIC18, PIC24, dsPIC33)
//            |
//	          +-->	PORTB = 0x45	// PIC16
//                  LATB = 0x45		// (PIC18, PIC24, dsPIC33)
#define port__write(PORT_NAME, VALUE)	LAT ## PORT_NAME = VALUE