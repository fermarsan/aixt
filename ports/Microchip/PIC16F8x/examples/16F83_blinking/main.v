// Project Name: Blinking
// Author: Fernando M. Santa
// Date: 05/09/2024
// PIC16F83 fosc = 4Mhz

import time
import pin

pin.setup(b4, pin.output)

for {
	pin.toggle(b4)
	time.sleep_ms(500)
}
