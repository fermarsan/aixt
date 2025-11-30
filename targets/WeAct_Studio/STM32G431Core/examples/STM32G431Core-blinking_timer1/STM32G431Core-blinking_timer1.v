// Project name: On-board LED blinking
// Author:	Fernando M. Santa & Santiago Farfán
// Date:	09/05/2025
// STM32G431Core board

import timer1
import pin

__global (
	state = true
)

// interrupt service routine for timer1 overload
@[timer1_isr]
fn blinking() {
	state = !state
}

timer1.setup(1, timer1.hz)
timer1.irq_enable()	// enables timer1 interrupt
timer1.restart()

for {
	// empty infinite loop
	pin.write(pin.led0, u8(state))
}