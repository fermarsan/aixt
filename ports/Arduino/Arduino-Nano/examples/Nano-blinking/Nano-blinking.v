// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin

pin.setup(pin.d13, pin.output)

for {
	pin.high(pin.d13)
	time.sleep_ms(500)
	pin.low(pin.d13)
	time.sleep_ms(500)
}

