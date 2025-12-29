// Project name: W801
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 08/09/2024
// Arduino-W801 board

import time
import pin
import adc
import pwm

pin.setup(pin.a3, pin.output)

for {
	value := adc.read(a1)
	pwm.write(a3, u8(value/4))
	time.sleep_ms(100)
}