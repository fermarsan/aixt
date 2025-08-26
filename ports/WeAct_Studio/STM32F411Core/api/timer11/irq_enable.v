// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer11


@[as_macro]
pub fn irq_enable() {
	C.TIMER11_ATTACHINTERRUPT(C.ptr_timer11_isr)
}