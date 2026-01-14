// Project name:
// Author:
// Date:
// Arduino-Nano board
import time
import port
import adc

mut an_input := adc.ADC { adc.ch0 }
port.setup(port.d, 0b00000000) // all outputs

for {
	analog := an_input.read()
	port.write(port.d, u8(analog >> 2))
	time.sleep_ms(100)
}
