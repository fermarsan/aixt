// Project Name: sin wave signal
// Author: Fernando M. Santa
// Date: 29/11/2024
// Arduino-Nano board
// sin wave signal through the PORTD (parallel 8 bits with external DAC) 

import time
import port


// sin wave table
const y = [
	u8(127), 143, 159, 174, 188, 202, 214, 225, 235, 242, 
	248, 252, 254, 254, 252, 248, 242, 235, 225, 214, 
	202, 188, 174, 159, 143, 127, 111, 95, 80, 66, 
	52, 40, 29, 19, 12, 6, 2, 0, 0, 2, 
	6, 12, 19, 29, 40, 52, 66, 80, 95, 111, 
]

port.setup(port.d, port.all_outputs)	// port d all pins as outputs

for {
	for n in 0 .. 50 {
		port.write(port.d, y[n])
		time.sleep_us(333)	// (1 / f) / 50 samples  =   333 us
	}
}


