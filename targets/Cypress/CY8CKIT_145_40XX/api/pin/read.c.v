// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pin read functions (CY8CKIT-145-40XX)

module pin

@[as_macro]
pub fn read(name any) u8 {
	return C.PIN_READ(name) 
}