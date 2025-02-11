// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: WRITE functions (Blue Pill_STM32F103C)
//              (PC port) 

module pin

@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.digitalWrite(PIN_NAME, VALUE)
}