// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// PIC16F83 fosc = 4Mhz
import time
import pin_fast as  pin

@[as_macro] const cpu_freq = 4_000_000 // 4 Mhz

pin.setup(pin.port_b, 4, pin.output)
pin.low(pin.port_b, 4)

for {
	pin.toggle(pin.port_b, 4)
	time.sleep_ms(250)
}
