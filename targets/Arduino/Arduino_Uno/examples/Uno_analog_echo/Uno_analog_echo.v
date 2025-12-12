// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Uno board

import time
import pin_fn as pin
import adc
import pwm

pin.setup(pwm.ch0, pin.output)

for {
	value := adc.read(adc.ch0)
	pwm.write(pwm.ch0, u8(value/4))
	time.sleep_ms(100)
}

