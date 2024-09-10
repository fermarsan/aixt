// Project Name: Logic inverter
// Author: Fernando M. Santa
// Date: 08/09/2024
// Arduino-Nano board

import time
import pin

pin.setup(d13, output)
pin.setup(d12, input)

for {
	if pin.read(d12) == 1 {
		pin.low(d13)
	} else {
		pin.high(d13)
	}
}

