// Project name: UART ADC
// Author: Fernando M. Santa
// Date: 21/09/2024
// ESP32-DevKitC board


import time
import uart
import adc2

uart.setup(9600)

for {
	analog := adc2.read(adc2.ch4)
	uart.println('ADC 2 channel 4: ${analog}')
	time.sleep_ms(1000)
}
