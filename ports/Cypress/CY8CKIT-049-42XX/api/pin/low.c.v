// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pin low functions (CY8CKIT-049-42XX)



module pin

@[as_macro]
pub fn low(name any) {
	C.PIN_LOW(name)
}