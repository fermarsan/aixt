// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// Description: Pin management functions (Exp16-PIC24 port)
module pin

#include <p24FJ128GA010.h>

@[as_macro] pub const input		= u8(C.INPUT)
@[as_macro] pub const output	= u8(C.OUTPUT)
@[as_macro] pub const in_pullup = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)

@[as_macro] pub const a0 =      A, 0      // pin names
@[as_macro] pub const a1 =      A, 1 
@[as_macro] pub const a2 =      A, 2 
@[as_macro] pub const a3 =      A, 3 
@[as_macro] pub const a4 =      A, 4 
@[as_macro] pub const a5 =      A, 5 
@[as_macro] pub const a6 =      A, 6 
@[as_macro] pub const a7 =      A, 7 
// @[as_macro] pub const a8 =      A, 8 
@[as_macro] pub const a9 =      A, 9 
@[as_macro] pub const a10 =     A, 10
// @[as_macro] pub const a11 =     A, 11
// @[as_macro] pub const a12 =     A, 12
// @[as_macro] pub const a13 =     A, 13
@[as_macro] pub const a14 =     A, 14
@[as_macro] pub const a15 =     A, 15

@[as_macro] pub const b0 =      B, 0 
@[as_macro] pub const b1 =      B, 1 
@[as_macro] pub const b2 =      B, 2 
@[as_macro] pub const b3 =      B, 3 
@[as_macro] pub const b4 =      B, 4 
@[as_macro] pub const b5 =      B, 5 
@[as_macro] pub const b6 =      B, 6 
@[as_macro] pub const b7 =      B, 7 
@[as_macro] pub const b8 =      B, 8 
@[as_macro] pub const b9 =      B, 9 
@[as_macro] pub const b10 =     B, 10
@[as_macro] pub const b11 =     B, 11
@[as_macro] pub const b12 =     B, 12
@[as_macro] pub const b13 =     B, 13
@[as_macro] pub const b14 =     B, 14
@[as_macro] pub const b15 =     B, 15

// @[as_macro] pub const c0 =      C, 0 
@[as_macro] pub const c1 =      C, 1 
@[as_macro] pub const c2 =      C, 2 
@[as_macro] pub const c3 =      C, 3 
@[as_macro] pub const c4 =      C, 4 
// @[as_macro] pub const c5 =      C, 5 
// @[as_macro] pub const c6 =      C, 6 
// @[as_macro] pub const c7 =      C, 7 
// @[as_macro] pub const c8 =      C, 8 
// @[as_macro] pub const c9 =      C, 9 
// @[as_macro] pub const c10 =     C, 10
// @[as_macro] pub const c11 =     C, 11
@[as_macro] pub const c12 =     C, 12
@[as_macro] pub const c13 =     C, 13
@[as_macro] pub const c14 =     C, 14
@[as_macro] pub const c15 =     C, 15

@[as_macro] pub const d0 =      D, 0 
@[as_macro] pub const d1 =      D, 1 
@[as_macro] pub const d2 =      D, 2 
@[as_macro] pub const d3 =      D, 3 
@[as_macro] pub const d4 =      D, 4 
@[as_macro] pub const d5 =      D, 5 
@[as_macro] pub const d6 =      D, 6 
@[as_macro] pub const d7 =      D, 7 
@[as_macro] pub const d8 =      D, 8 
@[as_macro] pub const d9 =      D, 9 
@[as_macro] pub const d10 =     D, 10
@[as_macro] pub const d11 =     D, 11
@[as_macro] pub const d12 =     D, 12
@[as_macro] pub const d13 =     D, 13
@[as_macro] pub const d14 =     D, 14
@[as_macro] pub const d15 =     D, 15

@[as_macro] pub const e0 =      E, 0 
@[as_macro] pub const e1 =      E, 1 
@[as_macro] pub const e2 =      E, 2 
@[as_macro] pub const e3 =      E, 3 
@[as_macro] pub const e4 =      E, 4 
@[as_macro] pub const e5 =      E, 5 
@[as_macro] pub const e6 =      E, 6 
@[as_macro] pub const e7 =      E, 7 
@[as_macro] pub const e8 =      E, 8 
@[as_macro] pub const e9 =      E, 9 
// @[as_macro] pub const e10 =     E, 10
// @[as_macro] pub const e11 =     E, 11
// @[as_macro] pub const e12 =     E, 12
// @[as_macro] pub const e13 =     E, 13
// @[as_macro] pub const e14 =     E, 14
// @[as_macro] pub const e15 =     E, 15

@[as_macro] pub const f0 =      F, 0 
@[as_macro] pub const f1 =      F, 1 
@[as_macro] pub const f2 =      F, 2 
@[as_macro] pub const f3 =      F, 3 
@[as_macro] pub const f4 =      F, 4 
@[as_macro] pub const f5 =      F, 5 
@[as_macro] pub const f6 =      F, 6 
@[as_macro] pub const f7 =      F, 7 
@[as_macro] pub const f8 =      F, 8 
// @[as_macro] pub const f9 =      F, 9 
// @[as_macro] pub const f10 =     F, 10
// @[as_macro] pub const f11 =     F, 11
@[as_macro] pub const f12 =     F, 12
@[as_macro] pub const f13 =     F, 13
// @[as_macro] pub const f14 =     F, 14
// @[as_macro] pub const f15 =     F, 15

#define g0      G, 0 
#define g1      G, 1 
#define g2      G, 2 
#define g3      G, 3 
// #define g4      G, 4 
// #define g5      G, 5 
#define g6      G, 6 
#define g7      G, 7 
#define g8      G, 8 
#define g9      G, 9 
// #define g10     G, 10
// #define g11     G, 11
#define g12     G, 12
#define g13     G, 13
#define g14     G, 14
#define g15     G, 15

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

// toggle macro sets an output pin. This is expanded in this way:
//   pin.toggle(pin.b2)
//     |
//	   +-->	pin.toggle(pin.B, 2)
//	          |
//	          +-->	PORTBbits.PORTB2 ^= 1	// PIC16	
// 	          		LATBbits.LATB2 ^= 1		// (PIC18, PIC24, dsPIC33)
@[inline]
pub fn toggle_(PORT_NAME, PIN) {
	C.LAT ## PORT_NAME ## bits.LAT ## PORT_NAME ## PIN ^= 1
}

@[inline]
pub fn toggle(PIN_NAME) {
	C.pin.toggle_(PIN_NAME)
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