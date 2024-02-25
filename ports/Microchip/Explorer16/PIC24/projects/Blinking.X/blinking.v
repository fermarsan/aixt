import time { sleep_ms }
import pin

pin.setup(a0, pin.out)

for {
	pin.high(a0)
	sleep_ms(500)
	pin.low(a0)
	sleep_ms(500)
}