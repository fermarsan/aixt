// Project name: Inverter
// Author: Fernando M. Santa
// Date: 2025
// Echo from GPIO3 to GPIO2
// PIC12F675 fosc = 4Mhz
import time
import pin_fn as pin

pin.setup(pin.io3, pin.input)
pin.setup(pin.io2, pin.output)

for {
	if pin.read(pin.io3) == 1 {
	  pin.high(pin.io2)
	} else {
		pin.low(pin.io2)
	}
}
