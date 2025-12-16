// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// PIC16F83 fosc = 20Mhz by default
import pin
import timer0

__global int_flag = false

// interrupt service routine for timer0 overload
@[timer0_isr]
fn blinking() {
	timer0.restart()
	int_flag = true
}

// @[as_macro] pub const cpu_freq = 8_000_000	// sets fosc to 8 Mhz
// @[as_macro] pub const cpu_freq = 12_000_000	// sets fosc to 12 Mhz
// @[as_macro] pub const cpu_freq = 20_000_000	// sets fosc to 20 Mhz

mut count := u8(0)

pin.setup(pin.c7, pin.output)
timer0.setup(10_000) // configure the timer0 with a period of 10ms (10000us)

pin.low(pin.c7) // reset LED pin
timer0.irq_enable() // enables timer0 interrupt

for {
	if int_flag {
		count++
		if count >= 20 {
			pin.toggle(pin.c7)
			count = 0
		}
		// pin.toggle(pin.c7)
		int_flag = false
	}
}
