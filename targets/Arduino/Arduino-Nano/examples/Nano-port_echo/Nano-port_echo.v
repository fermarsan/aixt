// Project name: 4-bit echo
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board
// 4-bit echo, from PORTB LSBs to PORTC LSBs

import time
import port

port.setup(port.b, port.all_inputs)	// all inputs
port.setup(port.c, 0b11110000)	// 4 LSBs outputs

for {
	port.write(port.c, port.read(port.b))
	time.sleep_ms(100)
}


