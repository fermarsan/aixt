// Project name: UART ADC
// Author: Fernando M. Santa
// Date: 18/07/2025
// CYC8CKIT-049-42XX

import time
import uart
import adc

uart.setup()
adc.setup()

for {
	analog := adc.read(adc.ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}