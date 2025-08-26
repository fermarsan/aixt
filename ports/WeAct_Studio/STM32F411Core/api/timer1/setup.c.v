// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer1


@[as_macro]
pub fn setup(value f32, format int) {
	C.TIMER1_SETOVERFLOW(value, format)
}