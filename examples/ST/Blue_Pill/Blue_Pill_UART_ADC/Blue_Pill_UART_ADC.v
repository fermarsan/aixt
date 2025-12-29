// Project name: UARt-ADC		
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 14/01/2025
// Blue-Pill board

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