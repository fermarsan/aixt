// Project name: Logic inverter
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin

pin.setup(pin.d13, pin.output)
pin.setup(pin.d12, pin.input)

for {
	if pin.read(pin.d12) == 1 {
		pin.low(pin.d13)
	} else {
		pin.high(pin.d13)
	}
}

