// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin

//builtin LED
pin.setup(led0, pin.output)

for {
	pin.high(led0)
	time.sleep_ms(500)
	pin.low(led0)
	time.sleep_ms(500)
}