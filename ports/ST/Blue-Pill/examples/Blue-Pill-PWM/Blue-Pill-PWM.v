// Project name: PWM signal
// Author: Fernando M. Santa
// Date: 13/01/2025
// Blue-Pill

import time
import pin
import pwm

const duty_table = [u8(25), 60, 120, 180, 205]

pin.setup(pin.a8, pin.output)	// for PWM

for {
	for duty in duty_table {
		pwm.write(pin.a8, duty*256)
		time.sleep_ms(250)
	}
}