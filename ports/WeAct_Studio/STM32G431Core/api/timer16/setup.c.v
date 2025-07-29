// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer16


@[as_macro]
pub fn setup(value f32, format int) {
	C.TIMER16_SETOVERFLOW(value, format)
}