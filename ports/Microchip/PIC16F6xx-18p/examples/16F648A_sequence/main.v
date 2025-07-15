// Project name: Sequence
// Author: Fernando M. Santa
// Date: 05/09/2024
// 4-bit LED sequence on LSBs of PORTB
// PIC16F648A fosc = 20Mhz

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

port.setup(port.b, 0b11110000)	// least 4 bit as outputs

for {
	for step in sequence {
		port.write(port.b, step)
		time.sleep_ms(200)
	}
}
