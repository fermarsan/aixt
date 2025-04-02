import time {sleep_ms}
import pin

time.sleep_ms(1500)

for _ in 0..5 {
	pin.high(pin.a)		// turn on
	time.sleep_ms(500)
	pin.high(pin.c)
	time.sleep_ms(500)
	pin.high(pin.x)
	time.sleep_ms(500)
	pin.high(pin.z)
	time.sleep_ms(500)

	pin.low(pin.a)		// turn off
	time.sleep_ms(500)
	pin.low(pin.c)
	time.sleep_ms(500)
	pin.low(pin.x)
	time.sleep_ms(500)
	pin.low(pin.z)
	time.sleep_ms(500)
}