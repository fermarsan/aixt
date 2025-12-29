// Project name: ADC_External_DAC
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Arduino-Nano board

import time
import port
import adc { ADC }

mut an_input := ADC.new(adc.ch0)
port.setup(port.d, port.all_outputs)	// all the port d as output

for {
	muestra := an_input.read()		// single sample of A0 pin
	port.write(port.d, u8(muestra>>2))	// shifts right 2 bits and gets out to port d
	time.sleep_ms(100)
}