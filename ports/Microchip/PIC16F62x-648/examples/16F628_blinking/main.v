// Project name: Blinking
// Author: Fernando M. Santa
// Date: 27/04/2025
// PIC16F628 fosc = 20Mhz
import time
import pin

@[as_macro]
const cpu_freq = 20_000_000 // 20 Mhz

pin.setup(pin.b4, pin.output)

for {
	pin.toggle(pin.b4)
	time.sleep_ms(200)
}
