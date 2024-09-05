// Project Name:
// Author: 
// Date: 
// PIC16F8x fosc = 4Mhz

import time
import pin

// pin.setup(3, 1)

for {
	pin.write(pin.b3, 1)
	time.sleep_ms(500)
}
