// Project name: External interrupt
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Changing a LED state by using the external interrupt
// PIC16F84 fosc = 20Mhz

import pin_fn as pin
import ext

@[ext_isr]
fn toggle_led() {
	pin.toggle(pin.d7)	// changes the pin state
}

pin.setup(pin.d7, pin.output)	// as output
pin.low(pin.d7)					// reset the pin

pin.setup(pin.irq, pin.input)	// as input
ext.setup(ext.falling)			// rising edge for external interrupt
ext.irq_enable()				// enable the interrupt

for {
	// empty infinite loop
}
