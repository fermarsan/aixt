import time { sleep_ms }
import pin

pin.setup(1, pin.out)

for {
	pin.high(1)
	sleep_ms(500)
	pin.low(1)
	sleep_ms(500)
}
