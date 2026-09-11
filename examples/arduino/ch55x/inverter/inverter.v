// Project name: Logic inverter
// Author: 
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026
// ch55x inverter example

import time
import pin_fn as pin

pin.setup(pin.p14, pin.input)

for {
	if pin.read(pin.p14) == 1 {
		pin.low(pin.led0)	
	} else {
		pin.high(pin.led0)
	}
}

