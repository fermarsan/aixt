import time {sleep_ms}
import pin

for {
	pin.write(led1, 0)
	time.sleep_ms(500)
	pin.write(led1, 1)
	time.sleep_ms(500)
}
