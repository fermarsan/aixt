import time { sleep_ms }
import pin

for {
	pin.high(led3)
	sleep_ms(500)
	pin.low(led3)
	sleep_ms(500)
}