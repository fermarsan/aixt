// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 19/02/2025
// Arduino Nano board

import pin
import ext

__global (
	state = true
)

@[ext_isr:'pin.d2']
fn blink() {
	state = !state
}

pin.setup(pin.d2, pin.input)
pin.setup(pin.d13, pin.output)
pin.low(pin.d13)

ext.irq_enable(pin.d2, ext.change)

for {
	pin.write(pin.d13, u8(state))
}