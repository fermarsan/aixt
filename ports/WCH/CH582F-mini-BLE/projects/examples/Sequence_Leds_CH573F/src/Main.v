
import time {sleep_ms}
import pin

pin.setup(pin.a13, pin.output) 
pin.setup(pin.a14, pin.output)
pin.setup(pin.a15, pin.output)

for {
	pin.high(pin.a13)	// turn on and turn off the LEDs one by one
	time.sleep_ms(500)
	pin.low(pin.a13)

	pin.high(pin.a14)
	time.sleep_ms(500)
	pin.low(pin.a14)

	pin.high(pin.a15)
	time.sleep_ms(500)
	pin.low(pin.a15)	
}