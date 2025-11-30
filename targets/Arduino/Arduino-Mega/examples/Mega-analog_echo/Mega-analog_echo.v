// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 09/09/2024
// Arduino-Mega board

import time
import pin
import adc
import pwm

pin.setup(pin.d5, pin.output)

for {
	value := adc.read(adc.ch5)
	pwm.write(pin.d5, u8(value/4))
	time.sleep_ms(100)
}

