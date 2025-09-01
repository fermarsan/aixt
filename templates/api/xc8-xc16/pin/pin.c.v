// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
//
// Description: Pin management functions (Exp16-PIC24 port)
module pin

#include <pxxx.h>	// device header file

// out macro defines the pin output mode
#define output		0

// in macro defines the pin input mode
#define input		1

#define a0      A, 0      // pin names
#define a1      A, 1 
...

#define b0      B, 0 
#define b1      B, 1 
...

#define c0      C, 0 
#define c1      C, 1 
...

...

// setup macro configures a pin's input/output mode. This is expanded in this way:
//   pin.setup(pin.a7, pin.input)
//     |
//	   +-->	pin.setup(pin.A, 7, 1)
//	          |
//            +-->	TRISAbits.TRISA7 = 1
@[inline]
pub fn setup_(PORT_NAME, PIN, MODE) {
	C.TRIS ## PORT_NAME ## bits.TRIS ## PORT_NAME ## PIN = MODE
}

@[inline]
pub fn setup(PIN_NAME, PIN_MODE) {
	C.pin.setup_(PIN_NAME, PIN_MODE)
}

// high macro sets an output pin. This is expanded in this way:
//   pin.high(pin.b2)
//     |
//	   +-->	pin.high(pin.B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 = 1	// PIC16	
// 	          		LATBbits.LATB2 = 1		// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn high_(PORT_NAME, PIN) {
	C.LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 1
}

@[inline]
pub fn high(PIN_NAME) {
	C.pin.high_(PIN_NAME)
}

/// low macro sets an output pin. This is expanded in this way:
//   pin.low(pin.b2)
//     |
//	   +-->	pin.low(pin.B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 = 0	// PIC16	
// 	          		LATBbits.LATB2 = 0		// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn low_(PORT_NAME, PIN) {
	C.LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN = 0
}

@[inline]
pub fn low(PIN_NAME) {
	C.pin.low_(PIN_NAME)
}

// read macro reads the value of an input pin. This is expanded in this way:
//   x = pin.read(pin.a7)
//     |
//	   +-->	x = pin.read(pin.A, 7)		
//	          |
//	          +-->	x = PORTAbits.PORTA7	// (PIC16, PIC18, PIC24, dsPIC33)
@[inline]
pub fn read_(PORT_NAME, PIN) {
	C.PORT ## PORT_NAME ## bits.R ## PORT_NAME ## PIN
}

@[inline]
pub fn read(PIN_NAME) {
	C.pin.read_(PIN_NAME)
}

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