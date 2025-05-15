// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2024
// License: MIT
//
// // Description: example PWM (CY8CKIT-145-40XX)

import time
import pin
import pwm

pin.setup(gpio2, output)

for {
	for level in 0 .. 256 {
		pwm.write(gpio2, level)
		time.sleep_ms(5) 
	}
	for level in 0 .. 256 {
		pwm.write(gpio2, 255-level)
		time.sleep_ms(5) 
	}
    time.sleep_ms(100)   
}