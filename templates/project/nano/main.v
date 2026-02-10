// Project name:
// Author: 
// Date: 
// Arduino Nano board

import time
import pin_fn as pin

pin.setup(pin.d13, pin.output)

pin.high(pin.d13)
time.sleep_ms(500)

