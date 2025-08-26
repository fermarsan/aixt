// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer7


@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER7_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER7_COMPARE_CHANNEL_ISR(ch, C.ptr_timer7_isr)
	)
}