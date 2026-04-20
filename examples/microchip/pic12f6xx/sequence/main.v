// Project name: Sequence
// Author: Fernando M. Santa
// Date: 2024-2025
// 6-bit LED sequence on LSBs of GPIO
// PIC12F675 fosc = 4Mhz

import time
import port

const sequence = [
 u8(0b000000),
	  0b000001,
	  0b000011,
	  0b000111,
	  0b010111,
	  0b110111,
	  0b110110,
	  0b110100,
	  0b110000,
	  0b100000,
]

port.setup(0b11000000)	// least 6 bit as outputs (all)

for {
	for step in sequence {
		port.write(step)
		time.sleep_ms(200)
	}
}
