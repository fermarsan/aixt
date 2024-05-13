import time {sleep_ms}
import pin

pin.setup(a0, pin.output)
pin.setup(a1, pin.output)
pin.setup(a2, pin.output)

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