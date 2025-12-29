// Project name: Blinking
// Author: Fernando M. Santa
// Date: 03/03/2025
// ESP32-C3FH4 board

import time
import pin

//builtin LED
pin.setup(8, pin.output)

for {
	pin.high(8)
	time.sleep_ms(200)
	pin.low(8)
	time.sleep_ms(200)
}
