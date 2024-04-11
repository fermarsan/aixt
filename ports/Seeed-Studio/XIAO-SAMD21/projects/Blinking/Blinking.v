import time
import pin

pin.setup(2, pin.output)
pin.setup(3, pin.output)

for i in 0 .. 10 { // 10 times
	pin.high(2)
	time.sleep_ms(250)
	pin.low(2)
	time.sleep_ms(250)
}

for {
	pin.high(3)
	time.sleep(1)
	pin.low(3)
	time.sleep(2)
}
