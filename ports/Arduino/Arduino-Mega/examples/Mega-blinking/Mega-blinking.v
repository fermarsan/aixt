// Project name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Mega board

import time
import pin

//builtin LED
pin.setup(led_0, pin.output)

for {
	pin.high(led_0)
	time.sleep_ms(500)
	pin.low(led_0)
	time.sleep_ms(500)
}