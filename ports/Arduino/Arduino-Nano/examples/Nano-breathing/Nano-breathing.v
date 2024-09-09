// Project Name:
// Author: 
// Date: 
// Arduino-Nano board

import time
import pin
import pwm

pin.setup(pin.d3, pin.output)

for {
	for level in 0 .. 256 {
		pwm.write(pin.d3, level)
		time.sleep_ms(10)
	}
	for level in 0 .. 256 {
		pwm.write(pin.d3, 255-level)
		time.sleep_ms(10)
	}
}

