// Project name:
// Author: 
// Date: 
// Arduino Nano board

import time
import port
import random


port.setup(port.b, port.all_outputs)
port.write(port.b, u8(random.in_range(0, 255)))
time.sleep_ms(500)

