// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin port management functions (Exp16-PIC24 port)
module port

#define TRISport_a	TRISA	// port setup name equivalents
#define TRISport_b	TRISB
#define TRISport_c	TRISC
#define TRISport_d	TRISD
#define TRISport_e	TRISE
#define TRISport_f	TRISF
#define TRISport_g	TRISG

#define PORTport_a	PORTA	// port in name equivalents
#define PORTport_b	PORTB
#define PORTport_c	PORTC
#define PORTport_d	PORTD
#define PORTport_e	PORTE
#define PORTport_f	PORTF
#define PORTport_g	PORTG

#define LATport_a	LATA	// port out name equivalents
#define LATport_b	LATB
#define LATport_c	LATC
#define LATport_d	LATD
#define LATport_e	LATE
#define LATport_f	LATF
#define LATport_g	LATG

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