// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SETUP functions (W801)
//              (PC port) 

module pin

@[inline]
pub fn pwm.setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}