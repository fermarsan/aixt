// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2025
// PIC16LF648A fosc = 20Mhz by default
import pin
import timer0
import uart

__global ( 
	int_flag = false 
)

const led = pin.b7

// interrupt service routine for timer0 overload
@[timer0_isr]
fn blinking() {
	timer0.restart()
	int_flag = true
}

mut count := u8(0)

pin.setup(led, pin.output)	// LED 
pin.setup(pin.b2, pin.output)	// RB2 = TX
timer0.setup(10_000) // configure the timer0 with a period of 10ms (10000us)
uart.setup(115200) // Initialize serial communication to 115200 bps

pin.low(pin.c7) // reset LED pin
timer0.irq_enable() // enables timer0 interrupt

for {
	if int_flag {
		count++
		if count >= 100 {
			uart.println('LED toggle...')
			pin.toggle(led)
			count = 0
		}
		int_flag = false
	}
}
