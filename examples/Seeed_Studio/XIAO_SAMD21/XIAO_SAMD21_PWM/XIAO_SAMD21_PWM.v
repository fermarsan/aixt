// Project name: PWM signal
// Author: Fernando M. Santa
// Date: 14/01/2025
// XIAO-SAMD21

import time
import pin
import pwm

const duty_table = [u8(25), 60, 120, 180, 205]

pin.setup(pin.d8, pin.output)	// for PWM

for {
	for duty in duty_table {
		pwm.write(pin.d8, duty*256)
		time.sleep_ms(250)
	}
}