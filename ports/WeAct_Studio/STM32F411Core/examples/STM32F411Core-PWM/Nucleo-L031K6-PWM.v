// Project name: PWM signal
// Author: Fernando M. Santa
// Date: 06/01/2025
// STM32F411Core

import time
import pin
import pwm

const duty_table = [u8(25), 60, 120, 180, 205]

pin.setup(pin.d3, pin.output)	// for PWM

for {
	for duty in duty_table {
		pwm.write(pin.d3, duty*256)
		time.sleep_ms(250)
	}
}