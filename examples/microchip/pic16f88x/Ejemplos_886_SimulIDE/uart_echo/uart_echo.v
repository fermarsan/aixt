// Project name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time
import uart

uart.setup(9600)

for {
	uart.write(uart.read())
	time.sleep_ms(500)
}
