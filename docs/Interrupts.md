# Interrupts
Aixt gives support to interrupts by means of using the function attribute `@[<block_name>_isr]` as the following example:

```v
import pin
import ext

@[ext_isr]
fn toggle_led() {
	pin.toggle(pin.b4)	// changes the pin state
}

fn main() {
    pin.setup(pin.b4, pin.output)	// as output
    pin.low(pin.b4)					// reset the pin

    pin.setup(pin.irq, pin.input)	// as input
    ext.setup(ext.falling)			// rising edge for external interrupt
    ext.irq_enable()				// enable the interrupt

    for {
        // empty infinite loop
    }
}
```
