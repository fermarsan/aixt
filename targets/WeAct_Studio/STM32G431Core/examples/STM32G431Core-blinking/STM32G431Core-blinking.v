// Project name: On-board LED blinking
// Author:	Fernando M. Santa & Santiago Farfán
// Date:	09/05/2025
// STM32G431Coreboard

import time
import pin

pin.setup(pin.led0, pin.output)

for {
	pin.high(pin.led0)
	time.sleep_ms(250)
	pin.low(pin.led0)
	time.sleep_ms(250)
} 