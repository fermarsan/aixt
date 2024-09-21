// Project Name: UART ADC
// Author: Fernando M. Santa
// Date: 21/09/2024
// ESP32-DevKitC board


import time
import uart
import adc

uart.setup(9600)

for {
	analog := adc.read(adc2_4)
	uart.println('ADC 2 channel 4: ${analog}')
	time.sleep_ms(1000)
}
