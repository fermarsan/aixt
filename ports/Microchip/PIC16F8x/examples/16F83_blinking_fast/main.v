// Project name: Blinking
// Author: Fernando M. Santa
// Date: 05/09/2024
// PIC16F83 fosc = 4Mhz
import time
import pin

@[as_macro]
const cpu_freq = 20_000_000 // 20 Mhz
// const cpu_freq = 10_000_000	// 4 Mhz

pin.setup(pin.b4, pin.output)

for {
	pin.high_fast(pin.port_b, 4)
	time.sleep_ms(250)
	pin.low_fast(pin.port_b, 4)
	time.sleep_ms(250)
}
