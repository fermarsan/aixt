// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: low functions (CY8CKIT-145-40XX)



module pin

@[as_macro]
pub fn low(name any) {
	C.PIN_LOW(name)
}