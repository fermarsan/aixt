// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// PIC16F83 fosc = 4Mhz by default

import pin 
import timer0



@[timer0_isr]	// interrupt service routine for timer0 overload
fn blinking() {
	timer0.restart()
	pin.toggle(pin.b4)
}

// @[as_macro] const cpu_freq = 8_000_000	// sets fosc to 8 Mhz
// @[as_macro] const cpu_freq = 12_000_000	// sets fosc to 12 Mhz
// @[as_macro] const cpu_freq = 20_000_000	// sets fosc to 20 Mhz

pin.setup(pin.b4, pin.output)
timer0.setup(10_000)	// configure the timer0 with a period of 10ms (10000us)

pin.low(pin.b4)			// reset LED pin
timer0.irq_enable()		// enables timer0 interrupt

for {
	// empty infinite loop
}
