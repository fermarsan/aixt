// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 19/02/2025
// Blue Pill board

import pin
import ext

__global (
	state = true
)

@[ext_isr:'pin.b0']
fn blink() {
	state = !state
}

fn main() {
	pin.setup(pin.b0, pin.input)
	ext.irq_enable(pin.b0, ext.change)
	
	for {
		pin.write(pin.led0, u8(state))
	}
}