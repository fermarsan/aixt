// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32F411Core
module timer2


@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER2_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER2_COMPARE_CHANNEL_ISR(ch, C.ptr_timer2_isr)
	)
}