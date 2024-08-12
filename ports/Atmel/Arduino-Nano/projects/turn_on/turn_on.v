import time
import pin

pin.setup(d13, pin.output)

for {
	pin.high(d13)
	time.sleep(1)
	pin.low(d13)
	time.sleep(1)
}