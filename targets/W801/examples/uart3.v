// Project name: UART ADC
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 08/09/2024
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
