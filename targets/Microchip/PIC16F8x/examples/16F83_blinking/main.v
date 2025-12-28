// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024-2025
// PIC16F83 fosc = 10Mhz
import time
import pin_fn as pin

pin.setup(pin.b4, pin.output)

for {
	pin.toggle(pin.b4)
	time.sleep_ms(250)
}
