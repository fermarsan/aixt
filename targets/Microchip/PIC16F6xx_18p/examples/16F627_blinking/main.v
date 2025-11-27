// Project name: Blinking
// Author: Fernando M. Santa
// Date: 27/04/2025
// PIC16F627 fosc = 20Mhz
import time
import pin

pin.setup(pin.b4, pin.output)

for {
	pin.toggle(pin.b4)
	time.sleep_ms(200)
}
