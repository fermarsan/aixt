// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Arduino-Mega board

import time
import pin_fn as pin

pin.low(pin.led0)	// turn the on-board LED off 

for {
	pin.toggle(pin.led0)
	time.sleep_ms(500)
}