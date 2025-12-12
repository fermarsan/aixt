// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin { Pin }

mut led := Pin { pin.led0, pin.output }	// set the on-board LED as output
led.low()	// turn it off 

for {
	led.toggle()
	time.sleep_ms(500)
}