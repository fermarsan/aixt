// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 05/09/2024
// PIC16F83 fosc = 4Mhz

import pin 
import timer0

@[timer0_isr]
fn blinking() {
	pin.toggle(pin.b4)
	timer0.restart()
}

pin.setup(pin.b4, pin.output)
timer0.setup(20_000)	// configure the timer0 with a period of 50ms (50000us)

pin.low(pin.b4)			// reset LED pin
timer0.irq_enable()		// enables timer0 interrupt

for {
	// empty infinite loop
}
