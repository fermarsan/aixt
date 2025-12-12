// Project Name: Logic inverter
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin { Pin }

mut sw := Pin.new(pin.d8);		sw.setup(pin.input)
mut led := Pin.new(pin.d13);	led.setup(pin.output)	// builtin LED

for {
	if sw.read() == 1 {
		led.low()	
	} else {
		led.high()
	}
}