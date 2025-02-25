// Project name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time { sleep_ms }
import port 

port.setup(port.b, port.all_outputs)		// port.setup(a, 0b00000000)

contador := 0

for {
	port.write(port.b, contador)
	time.sleep_ms(1)
	contador++
	if contador >= 256 {
		contador = 0
	}
}
