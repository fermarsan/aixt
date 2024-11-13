// Project Name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time
import pin

pin.setup(pin.a0, pin.output)

for {
	pin.high(pin.a0)
	time.sleep_ms(500)
	pin.low(pin.a0)
}
