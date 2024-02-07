import time { sleep }
import pin

pin.update()
sleep(1)

for i in 0..5 {
	pin.high(a)
	sleep(1)
	pin.low(a)
	sleep(1)
}