// Project name: Blinking
// Author: Fernando M. Santa
// Date: 04/05/2025
// PIC16F873 fosc = 20Mhz
import time
import pin

@[as_macro]
const cpu_freq = 20_000_000 // 20 Mhz

pin.setup(pin.c7, pin.output)

for {
	pin.toggle(pin.c7)
	time.sleep_ms(20)
}
