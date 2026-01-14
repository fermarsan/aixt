// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin

led0.low()	// turn the builtin LED off 

for {
	led0.toggle()
	time.sleep_ms(500)
}