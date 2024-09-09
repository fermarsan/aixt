// Project Name:
// Author: 
// Date: 
// Arduino-Nano board

import time
import port
import adc

port.setup(port.d, 0b00000000)	// all outputs

for {
	val := adc.read(adc.a0)
	port.write(port.d, val >> 2)
	time.sleep_ms(100)
}
