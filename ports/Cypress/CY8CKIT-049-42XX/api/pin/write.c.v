// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2024
// License: MIT
//
// // Description: write functions (CY8CKIT-049-42XX)

module pin

@[inline]
pub fn write(PIN_NAME, VALUE) {
	C.PIN_NAME_Write(VALUE)
}