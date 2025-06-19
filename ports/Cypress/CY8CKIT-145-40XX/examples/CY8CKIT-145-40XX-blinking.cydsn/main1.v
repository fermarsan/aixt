import time {sleep_ms}
import pin



for {
	pin.high(led_1)
	time.sleep_ms(5000)
	pin.low(led_1)
	time.sleep_ms(5000)
}