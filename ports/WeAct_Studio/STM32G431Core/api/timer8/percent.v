// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer8

@[as_macro]
pub fn write_percent(val int) {
    C.TIMER8_WRITE_PERCENT(val)
}
