// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin

pin.setup(pin.led0, pin.output)	// set the on-board LED as output
pin.low(pin.led0)				// turn it off 

for {
	pin.toggle(pin.led0)
	time.sleep_ms(500)
}