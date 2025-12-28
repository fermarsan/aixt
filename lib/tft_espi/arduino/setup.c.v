// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
//
// _Date:_ 02/04/2025
//
// ## Description
// Example of a Library module.
//
module tft_espi

@[as_macro]
pub fn setup() {
	C.TFT_INIT()
}
