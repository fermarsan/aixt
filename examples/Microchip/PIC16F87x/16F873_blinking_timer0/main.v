// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// PIC16F873 fosc = 20Mhz by default
import pin_fn as pin
import timer0

__global int_flag = false

// interrupt service routine for timer0 overload
@[timer0_isr]
fn blinking() {
	timer0.restart()
	pin.toggle(pin.c4)
	int_flag = true
}

mut count := u8(0)

pin.setup(pin.c4, pin.output)
pin.setup(pin.c7, pin.output)
timer0.setup(10_000) // configure the timer0 with a period of 10ms (10000us)

pin.low(pin.c7) // reset LED pin
pin.low(pin.c4)
timer0.irq_enable() // enables timer0 interrupt

for {
	if int_flag {
		count++
		if count >= 20 {
			pin.toggle(pin.c7)
			count = 0
		}
		int_flag = false
	}
}
