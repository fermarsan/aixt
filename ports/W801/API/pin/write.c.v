// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: WRITE functions (W801)
//              (PC port) 

module pin

@[inline]
pub fn pwm.write(PIN_NAME, VALUE) {
	C.digitalWrite(PIN_NAME, VALUE)
}