// Project Name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Arduino-Mega board

import time
import adc_fn as adc
import pwm_fn as pwm

pwm.setup_pin(pwm.ch3)

for {
	value := adc.read(adc.ch5)
	pwm.write(pwm.ch3, u8(value/4))
	time.sleep_ms(100)
}

