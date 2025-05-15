// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2025
// License: MIT
//
// // Description: low functions (CY8CKIT-145-40XX)

module pin

@[inline]
pub fn low(PIN_NAME) {
	C.PIN_NAME_Write(1)
}