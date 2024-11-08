// Project:	Name: On-board LED blinking
// Author:	Fernando M. Santa
// Date:	17/09/2024
// Raspberry Pi Pico board

import time
import pin

pin.setup(led0, pin.output)

for {
	pin.high(led0)
	time.sleep_ms(500)
	pin.low(led0)
	time.sleep_ms(500)
}


