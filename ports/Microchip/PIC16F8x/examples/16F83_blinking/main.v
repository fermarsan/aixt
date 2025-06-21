// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2024-2025
// PIC16F83 fosc = 10Mhz
import time
import pin

pin.setup(pin.b4, pin.output)

for {
	pin.toggle(pin.b4)
	time.sleep_ms(250)
}
