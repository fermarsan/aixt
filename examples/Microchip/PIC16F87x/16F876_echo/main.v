// Project name: Inverter
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// Echo from PORTC0 to PORTC7
// PIC16F876 fosc = 20Mhz

import time
import pin_fn as pin

pin.setup(pin.c0, pin.input)
pin.setup(pin.c7, pin.output)

for {
	if pin.read(pin.c0) == 1 {
	  pin.high(pin.c7)
	} else {
		pin.low(pin.c7)
	}
}
