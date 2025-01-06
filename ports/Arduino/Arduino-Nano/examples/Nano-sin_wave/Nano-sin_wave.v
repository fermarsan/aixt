// Project name: sin wave signal
// Author: Fernando M. Santa
// Date: 29/11/2024
// Arduino-Nano board
// sin wave signal through the PORTD 
// (parallel 8 bits for using an external DAC) 

import time
import port

const y = [
	u8(127), 135, 143, 151, 159, 166, 174, 181, 188, 195, 
	202, 208, 214, 220, 225, 230, 235, 239, 242, 246, 
	248, 250, 252, 253, 254, 255, 254, 253, 252, 250, 
	248, 246, 242, 239, 235, 230, 225, 220, 214, 208, 
	202, 195, 188, 181, 174, 166, 159, 151, 143, 135, 
	127, 119, 111, 103, 95, 88, 80, 73, 66, 59, 
	52, 46, 40, 34, 29, 24, 19, 15, 12, 8, 
	6, 4, 2, 1, 0, 0, 0, 1, 2, 4, 
	6, 8, 12, 15, 19, 24, 29, 34, 40, 46, 
	52, 59, 66, 73, 80, 88, 95, 103, 111, 119, 
]

port.setup(port.d, port.all_outputs)	// port d all pins as outputs

for {
	for y_n in y {
		port.write(port.d, y_n)
		time.sleep_us(166)	// (1 / f) / 100  =   166 us
	}
}


