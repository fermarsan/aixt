// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 02/04/2025
// License: MIT
//
// Description: Example of a Library module.
//
module tft_espi

@[as_macro]
pub fn fill_screen(color any) {
	C.TFT_FILLSCREEN(color)
}
