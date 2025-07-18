// Project name: UART ADC
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import uart
import adc

uart.setup()

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}