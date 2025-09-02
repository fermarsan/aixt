import time { sleep_ms }
import pin

pin.setup(1, pin.output)

for {
	pin.high(1)
	time.sleep_ms(500)
	pin.low(1)
	time.sleep_ms(500)
}
