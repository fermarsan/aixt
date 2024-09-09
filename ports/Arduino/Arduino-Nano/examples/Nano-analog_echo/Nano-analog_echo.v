// Project Name:
// Author: 
// Date: 
// Arduino-Nano board

import time
import pin
import adc
import pwm

pin.setup(pin.d3, pin.output)

for {
	value := adc.read(adc.a0)
	pwm.write(pin.d3, u8(value/4))
	time.sleep_ms(100)
}

