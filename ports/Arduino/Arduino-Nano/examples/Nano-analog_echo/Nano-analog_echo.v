// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin
import adc
import pwm

pin.setup(d3, output)

for {
	value := adc.read(a0)
	pwm.write(d3, u8(value/4))
	time.sleep_ms(100)
}

