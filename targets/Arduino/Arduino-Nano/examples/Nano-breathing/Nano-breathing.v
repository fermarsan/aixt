// Project name: Breathing
// Author: Fernando M. Santa
// Date: 2025
// Arduino-Nano board breathing LED by PWM

import time
import pin
import pwm

pin.setup(pwm.ch0, pin.output)

for {
	for level in 0 .. 256 {
		pwm.write(pwm.ch0, level)
		time.sleep_ms(5) 
	}
	for level in 0 .. 256 {
		pwm.write(pwm.ch0, 255-level)
		time.sleep_ms(5) 
	}
    time.sleep_ms(100)   
}

