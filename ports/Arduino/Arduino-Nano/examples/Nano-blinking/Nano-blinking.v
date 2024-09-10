// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin

pin.setup(d13, pin.output)

for {
	pin.high(d13)
	time.sleep_ms(500)
	pin.low(d13)
	time.sleep_ms(500)
}

