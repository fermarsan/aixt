// Project name: UART ADC
// _Author:_
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2025-2026
// ch55x board

import time
import uart
import adc_fn as adc

uart.setup(9600)

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}