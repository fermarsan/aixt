// Project Name : Aixt: http://github.com/fermansan/aixt.git
// Authors:
//  - Arley Junco
//  - Luis Quevedo
//  - Fernando M. Santa
// Date: 2024
// License : MIT

module pin

@[as_macro] pub const input		= u8(C.INPUT)
@[as_macro] pub const output	= u8(C.OUTPUT)
@[as_macro] pub const in_pullup = u8(C.INPUT_PULLUP)
@[as_macro] pub const in_pulldown = u8(C.INPUT_PULLDOWN)

@[inline]
pub fn setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}

@[inline]
pub fn high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}

@[inline]
pub fn low(PIN_NAME) {
	C.digitalWrite(PIN_NAME, LOW)
}

@[inline]
pub fn read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}

@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.digitalWrite(PIN_NAME, VALUE)
}