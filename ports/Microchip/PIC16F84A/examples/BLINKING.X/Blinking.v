import time {sleep_ms}
import pin

pin.setup (b0, pin.output)
pin.setup (b1, pin.output)
pin.setup (b2, pin.output)

pin.write (b0,0)
pin.write (b1,0)
pin.write (b2,0)

for{

	pin.high (b0)
	sleep_ms(500)

	pin.high (b1)
	sleep_ms(500)

	pin.high (b2)
	sleep_ms(500)

	pin.low(b0)
	pin.low(b1)
	pin.low(b2)
	sleep_ms(500)

}