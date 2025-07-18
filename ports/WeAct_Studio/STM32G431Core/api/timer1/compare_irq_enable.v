// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management STM32G431Core
module timer1


@[as_macro]
pub fn compare_irq_enable(ch int) {
	C.TIMER1_COMPARE_ATTACHINTERRUPT(
		ch, 
		C.TIMER1_COMPARE_CHANNEL_ISR(ch, C.ptr_timer1_isr)
	)
}