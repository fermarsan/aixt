import time {sleep_ms}
import pin

pin.setup(pin.a0, pin.output)
pin.setup(pin.a1, pin.output)
pin.setup(pin.a2, pin.output)

for {
	pin.high(pin.a0)	// turn on the LEDs one by one
	time.sleep_ms(200)

	pin.high(pin.a1)
	time.sleep_ms(200)

	pin.high(pin.a2)
	time.sleep_ms(200)

	pin.low(pin.a0)		// turn off all the LEDs
	pin.low(pin.a1)
	pin.low(pin.a2)
	time.sleep_ms(200)	
}