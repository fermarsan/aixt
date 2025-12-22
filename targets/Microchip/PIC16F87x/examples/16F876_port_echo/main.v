// Project name: Port echo
// Author: Fernando M. Santa
// Date: 2024-2025
// Echo from the 4 LSBs of PORTC to the 4 LSBs of PORTB
// PIC16F876 fosc = 20Mhz

import time
import port

port.setup(port.c, port.all_inputs)	// all inputs 0b11111111
port.setup(port.b, 0b11110000)	// 4 LSBs outputs

for {
	port.write(port.b, port.read(port.c))
	time.sleep_ms(100)
}
