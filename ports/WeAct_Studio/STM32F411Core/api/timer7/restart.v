// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer7


@[as_macro]
pub fn restart() {
	C.TIMER7_RESUME() 
}