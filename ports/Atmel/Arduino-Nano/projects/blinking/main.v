import time
import pin

for {
	pin.high(13)
	time.sleep(1)
	pin.low(13)
	time.sleep(1)
}