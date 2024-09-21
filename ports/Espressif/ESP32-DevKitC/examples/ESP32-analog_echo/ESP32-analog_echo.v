// Project Name: Analog echo
// Author: Fernando M. Santa
// Date: 21/09/2024
// ESP32-DevKitC board


import time
import pin
import adc
import pwm

pin.setup(gpio32, output)

for {
	value := adc.read(adc2_4)
	pwm.write(gpio32, u8(value/4))
	time.sleep_ms(100)
}
