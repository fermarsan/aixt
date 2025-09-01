// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
//
// Description: 
module port

#define TRISa	TRISA	// port setup name equivalents
#define TRISb	TRISB
...

#define PORTa	PORTA	// port in name equivalents
#define PORTb	PORTB
...

#define LATa	LATA	// port out name equivalents (PIC18, PIC24, dsPIC33)
#define LATb	LATB	
...

// setup macro configures a complete pin port input/output mode. This is expanded in this way:
//   pin.setup(pin.a, value)
//     |
//	   +-->	TRISa = value
//            |
//	          +-->	TRISA = value
@[inline]
pub fn setup(PORT_NAME, VALUE) {
	C.TRIS ## PORT_NAME = VALUE
}

// read macro reads the value of a complete pin port. This is expanded in this way:
//   x = port.read(port.a)
//     |
//	   +-->	x = PORTa
//            |
//	          +-->	x = PORTA
@[inline]
pub fn read(PORT_NAME) {
C.PORT ## PORT_NAME
}

// write macro writes a value on a complete pin port. This is expanded in this way:
//   port.write(port.b, 0x45)
//     |
//	   +-->	PORTb = 0x45			// PIC16
//           LATb = 0x45			// (PIC18, PIC24, dsPIC33)
//	          +-->	PORTB = 0x45	// PIC16
//                  LATB = 0x45		// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn write(PORT_NAME, VALUE) {
	C.LAT ## PORT_NAME = VALUE
}