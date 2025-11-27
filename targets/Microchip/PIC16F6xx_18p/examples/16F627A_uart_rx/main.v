// Project name: Hello world by UART
// Author: Fernando M. Santa
// Date: 2025
// PIC16F627A fosc = 20Mhz

import pin
import uart
import time

const led = pin.b7

pin.setup(led, pin.output)
pin.setup(pin.b2, pin.output) // RB2 = TX
pin.setup(pin.b1, pin.input) // RB1 = RX

uart.setup(115200) // Initialize serial communication to 115200 bps
uart.println('Press 1 or 0 to change the LED state')

for {
	input := uart.read()
	match input {
		u8(`0`) {
			pin.low(led)
			uart.println('LED Off')
		}
		u8(`1`) {
			pin.low(led)
			uart.println('LED On')
		}
		else {
			uart.println('Invalid option')
		}
	}
}
