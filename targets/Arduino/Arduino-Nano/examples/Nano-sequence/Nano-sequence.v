// Project name: 4-bit sequence (LSBs PORTC)
// Author: Fernando M. Santa
// Date: 08/09/20
// Arduino-Nano board

import time
import port

const sequence := [
	u8(0b0000),
	   0b0001,
	   0b0011,
	   0b0111,
	   0b1111,
	   0b1110,
	   0b1100,
	   0b1000,
]

port.setup(port.c, 0b11110000)

for {
	for step in sequence {
		port.write(port.c, step)
		time.sleep_ms(250)
	}
}

