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
pub fn draw_centre_string(temp_text any, center_x any, text_y any, font_size any) {
	C.TFT_DRAWCENTRESTRING(temp_text, center_x, text_y, font_size)
}
