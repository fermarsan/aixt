// Project Name: External interrupt
// Author: Fernando M. Santa
// Date: 04/12/2024
// Changing a LED state by using the external interrupt
// PIC16F84 fosc = 4Mhz

import pin
import ext

@[ext_isr]
fn extenal_interrupt_handler() {
	pin.toggle(pin.b3)	// changes the pin state
}

pin.setup(pin.b3, pin.output)	// as output
pin.low(pin.b3)		// reset the pin

pin.setup(pin.irq, pin.input)	// as input
ext.edge(ext.rising)	// rising edge for external interrupt

for {
	// empty infinite loop
}
