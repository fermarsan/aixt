// Project Name: UARt-ADC		
// Author: Fernando M. Santa
// Date: 19/09/2024
// Raspberry Pi Pico board

import time
import usb_uart
import adc

uart.setup(9600)
adc.setup(12)

for {
	analog := adc.read(ch0)
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(500)
}