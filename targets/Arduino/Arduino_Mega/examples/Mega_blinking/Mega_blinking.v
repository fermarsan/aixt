// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin { Pin }

// mut led := Pin { pin.led0 }	// set the on-board LED as output
mut led := Pin.new(pin.led0)	// set the on-board LED as output

led.setup(pin.output)
led.low()	// turn it off 

for {
	led.toggle()
	time.sleep_ms(500)
}