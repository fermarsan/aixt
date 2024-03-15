import time {sleep_ms}
import pin

pin.setup(17, pin.output)

for {
	pin.high(17)
	sleep_ms(250)
	pin.low(17)
	sleep_ms(250)
}