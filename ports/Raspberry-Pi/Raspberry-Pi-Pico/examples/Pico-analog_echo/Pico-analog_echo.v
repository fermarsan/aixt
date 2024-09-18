// Project Name: Analog echo
// Author: Fernando M. Santa
// Date: 17/09/2024
// Raspberry Pi Pico board

import time
import pin
import pwm
import adc

pin.setup(gp7, output)
adc.setup(12)

for {
	value := adc.read(adc0)
	pwm.write(gp7, value/4)
	time.sleep_ms(10)
}

// import time
// import pin
// import pwm

// pin.setup(gp7, output)
// pwm.setup(5000, 65535, 16)

// for {
// 	for level in 0 .. 256 {
// 		pwm.write(gp7, level*256)
// 		time.sleep_ms(10)
// 	}
// 	for level in 0 .. 256 {
// 		pwm.write(gp7, (255-level)*256)
// 		time.sleep_ms(10)
// 	}
// }

