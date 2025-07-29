// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer15


@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER15_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER15_COMPARE_CHANNEL_ISR(ch, C.ptr_timer15_isr)
	)
}