// Project Name: Blinking LED on PORTB3
// Author: Fernando M. Santa
// Date: 05/09/2024
// PIC16F83 fosc = 4Mhz

import time
import pin

pin.setup(pin.b4, pin.output)

for {
	pin.toggle(pin.b4)
	time.sleep_ms(500)
}
