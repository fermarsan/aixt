import time { sleep }
import pin

for _ in 0..5 {
	pin.high(a)
	sleep(1)
	pin.low(a)
	sleep(1)
}