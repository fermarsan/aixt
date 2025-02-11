// Project name: On-board LED blinking
// Author:	Fernando M. Santa
// Date:	14/01/2025
// XIAO-ESP32-xx board

import time
import pin

pin.setup(pin.d0, pin.output)

for {
	pin.high(pin.d0)
	time.sleep_ms(250)
	pin.low(pin.d0)
	time.sleep_ms(250)
}