// Implements de sequence:
// a2 a1 a0
//  0  0  0
//  0  0  1
//  0  1  1
//  1  1  1

import time {sleep_ms}
import pin

pin.setup(a0, pin.out) 
pin.setup(a1, pin.out)
pin.setup(a2, pin.out)

for {
	pin.high(a0)	// turn on the LEDs one by one
	sleep_ms(200)

	pin.high(a1)
	sleep_ms(200)

	pin.high(a2)
	sleep_ms(200)

	pin.low(a0)		// turn off all the LEDs
	pin.low(a1)
	pin.low(a2)
	sleep_ms(200)	
}