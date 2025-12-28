// Project name:
//
// _Author:_ 
//
// _Date:_ 
// Exp16-PIC24FJ128GA010 fosc = 32Mhz (8Mhz + PLL)

import time { sleep_ms }
import pin_fn as pin

for {
	pin.high(led10)
	time.sleep_ms(500)
}
