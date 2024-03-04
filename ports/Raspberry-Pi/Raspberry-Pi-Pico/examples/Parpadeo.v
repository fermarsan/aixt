import time {sleep_ms}
import pin

pin.setup(1, pin.out)

for {
	pin.high(1)
	sleep_ms(250)
	pin.low(1)
	sleep_ms(250)
}