// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 02/04/2025
//
// ## Description
// Example of a Library module.
//
module tft_espi

@[as_macro]
pub fn setup() {
	C.TFT_INIT()
}
