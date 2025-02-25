import time {sleep_ms}
import pin

pin.setup (pin.c0, pin.output)
pin.setup (pin.c1, pin.output)
pin.setup (pin.c2, pin.output)

for{

	pin.high (pin.c0)
	time.sleep_ms(500)

	pin.high (pin.c1)
	time.sleep_ms(500)

	pin.high (pin.c2)
	time.sleep_ms(500)

	pin.low(pin.c0)
	pin.low(pin.c1)
	pin.low(pin.c2)
	time.sleep_ms(500)

}