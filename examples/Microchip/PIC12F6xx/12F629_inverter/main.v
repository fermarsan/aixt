// Project name: Inverter
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
// Inverted echo from GPIO3 to GPIO2
// PIC12F629 fosc = 4Mhz
import time
import pin_fn as pin

pin.setup(pin.io3, pin.input)
pin.setup(pin.io2, pin.output)

for {
	if pin.read(pin.io3) == 1 {
	pin.low(pin.io2)
	} else {
		pin.high(pin.io2)
	}
}
