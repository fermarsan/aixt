// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// PIC16F83 fosc = 10Mhz by default
import pin
import timer0

// @[as_macro] pub const cpu_freq = 8_000_000	// sets fosc to 8 Mhz

// interrupt service routine for timer0 overload
@[timer0_isr]
fn blinking() {
	timer0.restart()
	pin.toggle(pin.b4)
}

pin.setup(pin.b4, pin.output)
timer0.setup(100) // configure the timer0 with a period of 10ms (10000us)

pin.low(pin.b4) // reset LED pin
timer0.irq_enable() // enables timer0 interrupt

for {
	// empty infinite loop
}
