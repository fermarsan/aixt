// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 17/06/2025
// Arduino Nano board

import pin
import ext

// __global (
// 	state = false
// )

@[ext_isr:'pin.d2']
fn blink() {
	// state = !state
	pin.toggle(led_0)
}

pin.setup(pin.d2, pin.input)
// pin.setup(pin.d13, pin.output)
pin.low(led_0)

ext.irq_enable(pin.d2, ext.change)

for {
	// pin.write(pin.d13, u8(state))
}