// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin

for {
	pin.high(led0)
	time.sleep_ms(500)
	pin.low(led0)
	time.sleep_ms(500)
}