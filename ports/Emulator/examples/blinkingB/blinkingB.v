import time { sleep }
import pin

for _ in 0..5 {
	pin.high(pin.a)
	sleep(1)
	pin.low(pin.a)
	sleep(1)
}