// Project name: Inverter
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
// Echo from PORTB3 to PORTB4
// PIC16F84 fosc = 10Mhz

import time
import pin_fn as pin

pin.setup(pin.b3, pin.input)
pin.setup(pin.b4, pin.output)

for {
	if pin.read(pin.b3) == 1 {
	  pin.high(pin.b4)
	} else {
	  pin.low(pin.b4)
	}
}
