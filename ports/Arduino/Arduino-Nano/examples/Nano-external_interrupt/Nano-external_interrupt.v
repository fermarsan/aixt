// Project name: External Interrupt example
// Author: Fernando M. Santa
// Date: 17/06/2025
// Arduino Nano board

import pin
import ext

@[ext_isr:'pin.d2']
fn blink() {
	pin.toggle(led0)
}

pin.setup(pin.d2, pin.input)
pin.low(led0)

ext.irq_enable(pin.d2, ext.change)

for {
	
}