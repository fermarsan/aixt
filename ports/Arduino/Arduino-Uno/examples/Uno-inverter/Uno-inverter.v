// Project Name: Logic inverter
// Author: Fernando M. Santa
// Date: 09/09/2024
// Arduino-Uno board

import time
import pin

pin.setup(d8, input)

for {
	if pin.read(d8) == 1 {
		pin.low(led0)	// builtin LED
	} else {
		pin.high(led0)
	}
}