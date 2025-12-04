// Project name: Blinking
// Author: Fernando M. Santa
// Date: 03/03/2025
// Arduino-Nano board

import time
import pin

//builtin LED
pin.setup(pin.led0, pin.output)

for {
	pin.high(pin.led0)
	time.sleep_ms(500)
	pin.low(pin.led0)
	time.sleep_ms(500)
}