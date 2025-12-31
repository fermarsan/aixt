// Project Name: UART ADC
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Mega board

import time
import uart
import adc { ADC }

uart.setup(9600)
mut an_input := ADC.new(adc.ch5)

for {
	analog := an_input.read()
	uart.println('ADC channel 0: ${analog}')
	time.sleep_ms(1000)
}
