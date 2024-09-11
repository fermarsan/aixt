// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: WRITE functions (W801)
//              (PC port) 

module pwm

@[inline]
pub fn write(PIN_NAME, MODE) {
	C.analogWrite(PIN_NAME, MODE)
}