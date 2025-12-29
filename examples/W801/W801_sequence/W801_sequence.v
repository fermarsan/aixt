// Project name: Blinking
// Author: Fernando M. Santa
// Date: 05/03/2025
// W801 board

import time
import leds

const sequence := [
	u8(0b0000000),
	   0b0000001,
	   0b0000011,
	   0b0000111,
	   0b0001111,
	   0b0001110,
	   0b0011100,
	   0b0111000,
	   0b1110000,
	   0b1100000,
	   0b1000000,
]

leds.setup()	// Initialize the LED pins as outputs

for {
	for step in sequence {
		leds.write(step)
		time.sleep_ms(250)
	}
}

