// Project name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time
import uart

uart.setup(9600)

for {
	uart.write(`f`)
	time.sleep_ms(500)
}
