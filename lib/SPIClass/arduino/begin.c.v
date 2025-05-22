// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 02/04/2025
// License: MIT
//
// Description: Example of a Library module.
//
module spiclass

@[as_macro]
pub fn begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS) {
	C.SPICLASS_BEGIN(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS)
}