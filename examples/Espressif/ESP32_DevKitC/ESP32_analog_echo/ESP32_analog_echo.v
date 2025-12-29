// Project name: Analog echo
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 21/09/2024
// ESP32-DevKitC board


import time
import pin
import adc2
import pwm

pin.setup(pin.gpio32, pin.output)

for {
	value := adc2.read(adc2.ch4)
	pwm.write(pin.gpio32, u8(value>>4))
	time.sleep_ms(100)
}
