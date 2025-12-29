// Project name: Blinking timer0
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// PIC12F675 fosc = 4Mhz by default
import pin_fn as pin
import timer0

// interrupt service routine for timer0 overload
@[timer0_isr]
fn blinking() {
	timer0.restart()
	pin.toggle(pin.io2)
}

pin.setup(pin.io2, pin.output)
timer0.setup(10_000) // configure the timer0 with a period of 10ms (10000us)

pin.low(pin.io2) // reset LED pin
timer0.irq_enable() // enables timer0 interrupt

for {
	// empty infinite loop
}
