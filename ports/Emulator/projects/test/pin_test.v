import pin
import time { sleep }

for _ in 1..10 {
	pin.write(pin.y, 1)
	sleep(1)
	pin.write(pin.y, 0)
	sleep(1)
}