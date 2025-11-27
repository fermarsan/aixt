// Project name: ADC_External_DAC
// Author: Fernando M. Santa
// Date: 05/12/2024
// Arduino-Nano board

import time
import port
import adc

port.setup(port.d, port.all_outputs)	// all the port d as output

for {
	muestra := adc.read(adc.ch0)		// single sample of A0 pin
	port.write(port.d, u8(muestra>>2))	// shifts right 2 bits and gets out to port d
	time.sleep_ms(100)
}