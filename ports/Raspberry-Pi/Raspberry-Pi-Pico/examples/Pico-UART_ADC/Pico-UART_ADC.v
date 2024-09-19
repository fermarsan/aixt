// Project Name: UARYt-ADC		
// Author: Fernando M. Santa
// Date: 19/09/2024
// Raspberry Pi Pico board

import time
import uart
import adc

uart.setup(9600)
adc.setup(12)

for {
	analog := adc.read(adc0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(500)
}