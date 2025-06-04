// Project name: Blinking
// Author: Fernando M. Santa
// Date: 05/09/2024
// PIC16F83 fosc = 4Mhz
import time
import pin
import pin.fast

@[as_macro]
const cpu_freq = 20_000_000 // 20 Mhz
// const cpu_freq = 10_000_000	// 4 Mhz

fast.setup(pin.port_b, 4, pin.output)
// pin.low_fast(pin.port_b, 4)

for {
	fast.high(pin.port_b, 4)
	time.sleep_ms(250)
	// pin.low_fast(pin.port_b, 4)
	fast.toggle(pin.port_b, 4)
	time.sleep_ms(250)
	// pin.toggle_fast(pin.port_b, 4)
	// time.sleep_ms(250)
}
