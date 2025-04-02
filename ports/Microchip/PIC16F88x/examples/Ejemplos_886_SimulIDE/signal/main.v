// Project name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time
import port

signal := [1, 2, 4, 8, 16, 32, 64, 128,	//rising
		   64, 32, 16, 8, 4, 2, 1]	//falling

port.setup(port.b, port.all_outputs)

for {
	for x in signal {
		port.write(port.b, x)
		time.sleep_ms(10)
	}
}
