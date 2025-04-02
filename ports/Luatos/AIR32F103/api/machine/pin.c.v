// Project name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	 - Julian Camilo Guzmán Zambrano
//	 - Juan Pablo Gonzalez Penagos
//	 - Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// // Description: PIN functions (Blue Pill_AIR32F103C)
//              (PC port) 

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

#define output OUTPUT

#define input INPUT_PULLUP

@[inline]
pub fn read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}