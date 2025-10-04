// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Uno board
import time
import pin

pin.setup(pin.led0, pin.output)	// set the on-board LED as output

for {
	pin.high(pin.led0)
	time.sleep_ms(100)
	pin.low(pin.led0)
	time.sleep_ms(200)
}