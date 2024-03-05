import pin
import time

time.sleep(2)

for i in 0..5 {
	pin.high(a)
	time.sleep_us(500000)
	pin.low(a)
	time.sleep_us(500000)
}