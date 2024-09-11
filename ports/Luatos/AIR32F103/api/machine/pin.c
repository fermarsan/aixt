// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: PIN functions (Blue Pill_AIR32F103C)
//              (PC port) 

@[inline]
pub fn pwm.setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}

@[inline]
pub fn pin.high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}

@[inline]
pub fn pin.low(PIN_NAME) {
	C.digitalWrite(PIN_NAME, LOW)
}

#define output OUTPUT

#define input INPUT_PULLUP

@[inline]
pub fn pin.read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}