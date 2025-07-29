// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer16

@[as_macro]
pub fn write_percent_channel(channel int, val int) {
    C.TIMER16_WRITE_PERCENT_CHANNEL(channel, val)
}