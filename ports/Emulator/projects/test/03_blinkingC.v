import time { sleep }
import pin {
	high
	low
}

for _ in 0..5 {
	high(pin.a)
	sleep(1)
	low(pin.a)
	sleep(1)
}