// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (LQFP32 MiniEVB Nano - LGT8F328P port)
module pin

// in macro defines the pin input mode
#define input  INPUT
#define input_pullup  INPUT_PULLUP

// out macro defines the pin output mode
#define output  OUTPUT

// setup configures a pin's input/output mode
@[inline]
pub fn setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}

// high function puts a high value (logic 1) to a specific pin
@[inline]
pub fn high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}

// low function puts a low value (logic 0) to a specific pin
@[inline]
pub fn low(PIN_NAME) {
	C.digitalWrite(PIN_NAME, LOW)
}

//Reads the value from a specified digital pin, either HIGH or LOW
@[inline]
pub fn read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}

//Write a HIGH or a LOW value to a digital pin
@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.digitalWrite(PIN_NAME, VALUE)
}