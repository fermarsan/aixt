// Project name: blinking
// Author: 
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026
// ch55x boards

import time
import pin_fn as pin

pin.setup(pin.p30, pin.output)

for {
	pin.high(pin.p30)
	time.sleep_ms(500)
	
	pin.low(pin.p30)
	time.sleep_ms(500)
}

