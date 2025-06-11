// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 19/02/2025
// Blue Pill board

import pin
import ext

__global (
	state = true
)

@[ext_isr:'pin.a2']
fn blink() {
	state = !state
}

pin.setup(pin.a2, pin.input)
pin.setup(led_0, pin.output)
pin.low(led_0)

ext.irq_enable(pin.a2, ext.change)

for {
	pin.write(led_0, u8(state))
}