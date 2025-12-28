// Project name: UART ADC
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Arduino-Nano board

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

