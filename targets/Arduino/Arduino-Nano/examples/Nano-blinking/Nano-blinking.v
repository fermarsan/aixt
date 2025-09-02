// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Nano board
import time
import pin

pin.low(led0)	// turn off the on-board LED

for {
	pin.toggle(led0)
	time.sleep_ms(500)
}