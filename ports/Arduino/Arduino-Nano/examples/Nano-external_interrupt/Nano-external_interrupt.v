// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 19/02/2025
// Arduino Nano board

import pin
import ext

__global (
	state = false
)

@[ext_isr]
fn blink() {
	state = !state
}

pin.setup(pin.d11, pin.input)
pin.setup(pin.d13, pin.output)
pin.low(pin.d13)

ext.setup(ext.change)

for {
	pin.write(pin.d11, u8(state))
}