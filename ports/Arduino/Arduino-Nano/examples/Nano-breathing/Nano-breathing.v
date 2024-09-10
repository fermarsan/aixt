// Project Name:
// Author: 
// Date: 
// Arduino-Nano board

import time
import pin
import pwm

pin.setup(d3, output)

for {
	for level in 0 .. 256 {
		pwm.write(d3, level)
		time.sleep_ms(10)
	}
	for level in 0 .. 256 {
		pwm.write(d3, 255-level)
		time.sleep_ms(10)
	}
}

