// Project name: On-board LED blinking
// Author:	Fernando M. Santa
// Date:	17/09/2024
// Raspberry Pi Pico board

import time
import pin

pin.setup(pin.led0, pin.output)

for {
	pin.high(pin.led0)
	time.sleep_ms(250)
	pin.low(pin.led0)
	time.sleep_ms(250)
}