// Project Name:
// Author: 
// Date: 
// Arduino-Nano board

import time
import uart
import adc

uart.setup(9600)

for {
	analog := adc.read(adc.a0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}

