// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 21/09/2024
// ESP32-DevKitC board

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

