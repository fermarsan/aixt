// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 04/05/2025
// PIC16F873 fosc = 20Mhz
import time
import pin_fn as pin

pin.setup(pin.c7, pin.output)

for {
	pin.toggle(pin.c7)
	time.sleep_ms(200)
}
