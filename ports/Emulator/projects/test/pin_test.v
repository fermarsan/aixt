import pin
import time { sleep }

for i in 1..10 {
	pin.write(y, high)
	sleep(1)
	pin.write(y, low)
	sleep(1)
}