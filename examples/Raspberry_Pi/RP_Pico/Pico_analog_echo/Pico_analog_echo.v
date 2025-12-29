// Project name: Analog echo
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 17/09/2024
// Raspberry Pi Pico board

import time
import pin
import pwm
import adc

pin.setup(pin.gp7, pin.output)
adc.setup(12)	// 12-bit resolution

for {
	value := adc.read(adc.ch0)
	pwm.write(pin.gp7, u8(value>>4))
	time.sleep_ms(10)
}