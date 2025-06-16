// Project name: On-board LED blinking
// Author:	Fernando M. Santa & Santiago Farfán
// Date:	09/05/2025
// STM32G431Coreboard

import time
import pin

pin.setup(led_0, pin.output)

for {
	pin.high(led_0)
	time.sleep_ms(250)
	pin.low(led_0)
	time.sleep_ms(250)
} 