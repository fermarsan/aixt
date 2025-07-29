// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer15


@[as_macro]
pub fn irq_enable() {
	C.TIMER15_ATTACHINTERRUPT(C.ptr_timer15_isr)
}