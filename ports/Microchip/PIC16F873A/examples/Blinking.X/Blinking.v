import pin
import time{sleep_ms}

pin.setup (b4, pin.output)
pin.setup (b5, pin.output)
pin.setup (b6, pin.output)

for{

	pin.high (b4)
	sleep_ms(500)

	pin.high (b5)
	sleep_ms(500)

	pin.high (b6)
	sleep_ms(500)

	pin.low(b4)
	pin.low(b5)
	pin.low(b6)
	sleep_ms(500)

}