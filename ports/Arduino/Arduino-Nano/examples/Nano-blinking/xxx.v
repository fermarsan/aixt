// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/20
// Arduino-Nano board

import time
import pin

pin.setup(pin.b13, pin.output)

for {
	pin.high(pin.b13)
	time.sleep_ms(500)
	pin.low(pin.b13)
	time.sleep_ms(500)
}

