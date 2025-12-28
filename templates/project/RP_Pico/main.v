// Project name:
//
// _Author:_ 
//
// _Date:_ 
// Raspberry Pi Pico board

import time
import pin

pin.setup(gp25, pin.output)

pin.high(gp25)
time.sleep_ms(500)

