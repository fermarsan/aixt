// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer16


@[as_macro]
pub fn irq_enable() {
	C.TIMER16_ATTACHINTERRUPT(C.ptr_timer16_isr)
}