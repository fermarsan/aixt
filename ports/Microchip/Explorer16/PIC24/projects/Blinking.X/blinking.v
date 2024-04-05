import time { sleep_ms }
import pin

const t1 = 500
pin.setup(a0, pin.output)

for {
	pin.high(a0)
	sleep_ms(t1)
	pin.low(a0)
	sleep_ms(t1)
}