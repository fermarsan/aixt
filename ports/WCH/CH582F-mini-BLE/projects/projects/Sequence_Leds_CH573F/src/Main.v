
import time {sleep_ms}
import pin

pin.setup(a13, output) 
pin.setup(a14, output)
pin.setup(a15, output)

for {
	pin.high(a13)	// turn on and turn off the LEDs one by one
	sleep_ms(500)
	pin.low(a13)

	pin.high(a14)
	sleep_ms(500)
	pin.low(a14)

	pin.high(a15)
	sleep_ms(500)
	pin.low(a15)	
}