// Project name: UART ADC
// Author: Fernando M. Santa
// Date: 09/09/2024
// Arduino-Uno board

import time
import uart
import adc

uart.setup(9600)

for {
	analog := adc.read(adc.ch5)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}