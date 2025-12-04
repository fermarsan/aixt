// Project name: 4-bit echo
// Author: Fernando M. Santa
// Date: 09/09/2024
// Arduino-Uno board
// 4-bit echo, from PORTB LSBs to PORTC LSBs

import time
import port

port.setup(port.b, 0b11111111)	// all inputs
port.setup(port.c, 0b11110000)	// 4 LSBs outputs

for {
	port.write(port.c, port.read(port.b))
	time.sleep_ms(100)
}