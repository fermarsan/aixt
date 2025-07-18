// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pin high functions (CY8CKIT-049-42XX)


module pin

@[as_macro]
pub fn high(name any) {
	C.PIN_HIGH(name)
}