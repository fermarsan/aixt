import time { sleep_ms }
import pin

const t1 = 500
pin.setup(pin.a0, pin.output)

for {
	pin.high(pin.a0)
	time.sleep_ms(t1)
	pin.low(pin.a0)
	time.sleep_ms(t1)
}