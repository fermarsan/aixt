// Project Name:
// Author: 
// Date: 

import time { sleep_ms }
import pin

pin.setup(b7, pin.output)

for {
	pin.high(b7)
	sleep_ms(500)
}
