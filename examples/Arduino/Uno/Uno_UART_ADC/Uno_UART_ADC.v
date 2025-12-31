// Project name: UART ADC
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Uno board

import time
import uart
import adc

uart.setup(9600)
// mut an_input := adc.ADC { adc.ch5 }

for {
	an_input := adc.read(adc.ch5)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}
