// Project name: Blinking
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
// PIC12F629 fosc = 20Mhz
import time
import pin_fn as pin

pin.setup(pin.io2, pin.output)

for {
  pin.toggle(pin.io2)
	time.sleep_ms(250)
}
