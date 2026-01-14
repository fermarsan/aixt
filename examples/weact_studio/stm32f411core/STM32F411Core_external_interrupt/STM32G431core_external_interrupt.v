// Project name: On-board LED blinking
// Author:	Fernando M. Santa & Santiago Farfán
// Date:	09/05/2025
// STM32F411Coreboard
import pin
import ext

__global (
	state = true
)

@[ext_isr: 'pin.pc13']
fn blink() {
	state = !state
}

fn main() {
	pin.setup(pin.pc13, pin.in_pulldown)
	pin.setup(pin.pa8, pin.output)
	pin.high(pin.pa8)

	ext.irq_enable(pin.pc13, ext.rising)

	for {
		pin.write(pin.pa8, u8(state))
	}
}