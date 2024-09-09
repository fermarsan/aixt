// Project Name:
// Author: 
// Date: 
// Arduino-Nano board

import time
import pin
import adc
import pwm

pin.setup(pin.d13, pin.output)

for {
	value := adc.read(adc.a0)
	pwm.write(pin.d3 50)
}


pin.high(pin.d13)
time.sleep_ms(500)

