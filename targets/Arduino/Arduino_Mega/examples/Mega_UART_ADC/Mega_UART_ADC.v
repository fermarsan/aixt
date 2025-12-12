// Project Name: UART ADC
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import uart
import adc
import pin_fn as pin

uart.setup(9600)
pin.setup(adc.ch5, pin.input)

for {
	analog := adc.read(adc.ch5)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}