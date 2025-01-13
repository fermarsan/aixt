// Project name: On-board LED blinking
// Author:	Fernando M. Santa
// Date:	17/09/2024
// Raspberry Pi Pico board

import time
import pin

pin.setup(led_0, pin.output)

for {
	pin.high(led_0)
	time.sleep_ms(250)
	pin.low(led_0)
	time.sleep_ms(250)
}