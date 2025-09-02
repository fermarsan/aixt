// Project name: Blinking
// Author: Fernando M. Santa
// Date: 2025
// PIC12F629 fosc = 20Mhz
import time
import pin

pin.setup(pin.io2, pin.output)

for {
	pin.toggle(pin.io2)
	time.sleep_ms(250)
}
