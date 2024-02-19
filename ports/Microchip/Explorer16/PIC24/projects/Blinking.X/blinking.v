import time { sleep_ms }
import pin

pin.setup(a0, pin.out)

for {
	pin.high(led3)
	sleep_ms(500)
	pin.low(led3)
	sleep_ms(500)
}