// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Uno board

import time
import adc { ADC }
import pwm { PWM }

mut an_input := ADC.new(adc.ch5)
mut pwm_output := PWM.new(pwm.ch3)
pwm_output.setup_pin()

for {
	value := an_input.read()
	pwm_output.write(u8(value/4))
	time.sleep_ms(100)
}
