// Project name:
// Author: 
// Date: 
// Exp16-PIC24FJ128GA010 fosc = 32Mhz (8Mhz + PLL)

import time { sleep_ms }
import pin

for {
	pin.high(led10)
	time.sleep_ms(500)
}
