// Project name: PWM signal
// Author: Fernando M. Santa
// Date: 17/09/2024
// Raspberry Pi Pico board

import time
import pin
import pwm

const duty_table = [u8(25), 60, 120, 180, 205]

pin.setup(pin.gp7, pin.output)

for {
	for duty in duty_table {
		pwm.write(pin.gp7, duty)
		time.sleep_ms(250)
	}
}