// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2024
// License: MIT
//
// // Description: write functions (CY8CKIT-145-40XX)

module pin

@[as_macro]
pub fn write(name any, value any) {
	C.PIN_WRITE(name, value)
}