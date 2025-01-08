import pin
import time{sleep_ms}

pin.setup (pin.b4, pin.output)
pin.setup (pin.b5, pin.output)
pin.setup (pin.b6, pin.output)

for{

	pin.high (pin.b4)
	time.sleep_ms(500)

	pin.high (pin.b5)
	time.sleep_ms(500)

	pin.high (pin.b6)
	time.sleep_ms(500)

	pin.low(pin.b4)
	pin.low(pin.b5)
	pin.low(pin.b6)
	time.sleep_ms(500)

}