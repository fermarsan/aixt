// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer11


@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER11_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER11_COMPARE_CHANNEL_ISR(ch, C.ptr_timer11_isr)
	)
}