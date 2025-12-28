// Project name: Analog echo
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 14/01/2025
// Raspberry XIAO-ESP32-xx board

import time
import pin
import pwm
import adc

pin.setup(pin.d7, pin.output)
adc.setup(12)	// 12-bit resolution

for {
	value := adc.read(adc.ch0)
	pwm.write(pin.d7, u8(value>>4))
	time.sleep_ms(10)
}