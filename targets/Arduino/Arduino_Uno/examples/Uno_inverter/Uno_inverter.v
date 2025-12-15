// Project name: Logic inverter
// Author: Fernando M. Santa
// Date: 2024-2025
// Arduino-Uno board

import time
import pin

mut sw := pin.Pin { pin.d8 }	// define an input switch
sw.setup(pin.input)

for {
	if sw.read() == 1 {
		led0.low()	
	} else {
		led0.high()
	}
}
