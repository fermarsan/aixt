// Project name: UART ADC
// Author: Fernando M. Santa
// Date: 08/09/2024
// W801 board

import time
import uart
import adc

uart.setup(9600)

for {
	analog := adc.read(a1)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}
