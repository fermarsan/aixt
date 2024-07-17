import pin
import time

time.sleep(2)

for _ in 0..5 {
	pin.high(pin.a)
	time.sleep_ms(500)
	pin.low(pin.a)
	time.sleep_ms(500)
}