// Project name: Inverter
// Author: Fernando M. Santa
// Date: 05/09/2024
// Inverted echo from PORTC0 to PORTC7
// PIC16F876 fosc = 20Mhz

import time
import pin_fn as pin

pin.setup(pin.c0, pin.input)
pin.setup(pin.c7, pin.output)

for {
	if pin.read(pin.c0) == 1 {
		pin.low(pin.c7)
	} else {
		pin.high(pin.c7)
	}
}
