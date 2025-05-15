// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2025
// License: MIT
//
// // Description: pwm functions (CY8CKIT-145-40XX)

module pwm

@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.WriteCompare(VALUE)
}