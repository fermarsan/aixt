// Project name: Port echo
// Author: Fernando M. Santa
// Date: 05/09/2024
// Echo from the 4 LSBs of PORTA to the 4 LSBs of PORTB
// PIC16F84 fosc = 10Mhz

import time
import port

port.setup(port.a, port.all_inputs)	// all inputs 0b11111111
port.setup(port.b, 0b11110000)	// 4 LSBs outputs

for {
	port.write(port.b, port.read(port.a))
	time.sleep_ms(100)
}