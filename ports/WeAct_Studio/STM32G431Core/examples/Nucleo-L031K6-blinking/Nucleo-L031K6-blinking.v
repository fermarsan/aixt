// Project name: On-board LED blinking
// Author:	Fernando M. Santa
// Date:	06/01/2025
// Nucleo-L031K6 board

import time
import pin

pin.setup(led_0, pin.output)

for {
	pin.high(led_0)
	time.sleep_ms(250)
	pin.low(led_0)
	time.sleep_ms(250)
}