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
pub fn set_text_color(color any, bkg_color any) {
	C.TFT_SETTEXTCOLOR(color, bkg_color)
}
