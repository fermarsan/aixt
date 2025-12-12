// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import pin_fn as pin
import adc
import pwm

pin.setup(adc.ch5, pin.input)
pin.setup(pwm.ch3, pin.output)

for {
	value := adc.read(adc.ch5)
	pwm.write(pwm.ch3, u8(value/4))
	time.sleep_ms(100)
}

