// Project Name: External interrupt
// Author: Fernando M. Santa
// Date: 04/12/2024
// Changing a LED state by using the external interrupt
// PIC16F84 fosc = 4Mhz

import pin
import ext

@[ext_isr]
fn toggle_led() {
	pin.toggle(pin.b4)	// changes the pin state
}

pin.setup(pin.b4, pin.output)	// as output
pin.low(pin.b4)			// reset the pin

pin.setup(pin.irq, pin.input)	// as input
ext.edge(ext.falling)	// rising edge for external interrupt
ext.irq_enable()		// enable the interrupt

for {
	// empty infinite loop
}