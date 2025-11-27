// Project name: UART-ADC		
// Author: Fernando M. Santa
// Date: 19/09/2024
// Raspberry Pi Pico board

import time
import uart
import adc

uart.setup(9600)
adc.setup(12)	// 12-bit resolution

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(500)
}