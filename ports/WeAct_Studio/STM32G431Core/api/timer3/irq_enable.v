// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer3


@[as_macro]
pub fn irq_enable() {
	C.TIMER3_ATTACHINTERRUPT(C.ptr_timer8_isr)
}