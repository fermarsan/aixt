// Project name:
// Author:
// Date:
// Arduino-Nano board
import time
import port
import adc_fn as adc

port.setup(port.d, 0b00000000) // all outputs

for {
	analog := adc.read(adc.ch0)
	port.write(port.d, u8(analog >> 2))
	time.sleep_ms(100)
}
