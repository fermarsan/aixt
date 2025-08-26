// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer4

@[as_macro]
pub fn write_percent(val int) {
    C.TIMER4_WRITE_PERCENT(val)
}
