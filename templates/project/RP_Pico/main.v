// Project name:
// Author: 
// Date: 
// Raspberry Pi Pico board

import time
import pin

pin.setup(gp25, pin.output)

pin.high(gp25)
time.sleep_ms(500)

