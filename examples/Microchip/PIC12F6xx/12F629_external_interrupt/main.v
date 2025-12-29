// Project name: External interrupt
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Changing a LED state by using the external interrupt
// PIC12F629 fosc = 4Mhz

import pin_fn as pin
import ext

@[ext_isr]
fn toggle_led() {
	pin.toggle(pin.io1)	// changes the pin state
}

pin.setup(pin.io1, pin.output)	// as output
pin.low(pin.io1)					// reset the pin

pin.setup(pin.irq, pin.input)	// as input
ext.setup(ext.falling)			// rising edge for external interrupt
ext.irq_enable()				// enable the interrupt

for {
	// empty infinite loop
}
