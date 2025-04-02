// Project name:
// Author:
// Date:
// Arduino-Nano board
import time
import port
import adc

port.setup(port.d, 0b00000000) // all outputs

for {
	analog := adc.read(adc.ch0)
	port.write(port.d, analog >> 2)
	time.sleep_ms(100)
}
