// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 17/06/2025
// Arduino Nano board

import pin
import ext

@[ext_isr:'pin.d2']	// interrupt service routine
fn blink() {
	pin.toggle(pin.led0)
}

pin.setup(pin.d2, pin.input)
pin.low(pin.led0)

ext.irq_enable(pin.d2, ext.change)	// interrupt request enabled

for {
	// Empty infinite loop
}