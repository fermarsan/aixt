// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Arduino-Nano board

import time
import adc_fn as adc
import pwm_fn as pwm

pin.setup(pwm.ch0, pin.output)

for {
	value := adc.read(adc.ch0)
	pwm.write(pwm.ch0, u8(value/4))	// pwm.write(pwm.ch0, u8(value>>2))
	time.sleep_ms(100)
}

