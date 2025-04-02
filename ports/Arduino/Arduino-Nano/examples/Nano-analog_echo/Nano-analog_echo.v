// Project name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin
import adc
import pwm

pin.setup(pin.d3, pin.output)

for {
	value := adc.read(adc.ch0)
	pwm.write(pwm.ch0, u8(value/4))	// pwm.write(pwm.ch0, u8(value>>2))
	time.sleep_ms(100)
}

