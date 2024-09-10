// Project Name:
// Author:
// Date:
// Arduino-Nano board
import time
import port
import adc

port.setup(d, 0b00000000) // all outputs

for {
	analog := adc.read(a0)
	port.write(d, analog >> 2)
	time.sleep_ms(100)
}
