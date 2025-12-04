// Project Name: Logic inverter
// Author: Fernando M. Santa
// Date: 09/09/2024
// Arduino-Uno board

import time
import pin
import adc
import pwm

pin.setup(pin.d8, pin.input)

for {
	if pin.read(pin.d8) == 1 {
		pin.low(pin.led0)	// builtin LED
	} else {
		pin.high(pin.led0)
	}
}