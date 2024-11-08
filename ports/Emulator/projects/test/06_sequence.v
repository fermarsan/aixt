import time {sleep_ms}
import pin

sleep_ms(1500)

for _ in 0..5 {
	pin.high(pin.a)		// turn on
	sleep_ms(500)
	pin.high(pin.c)
	sleep_ms(500)
	pin.high(pin.x)
	sleep_ms(500)
	pin.high(pin.z)
	sleep_ms(500)

	pin.low(pin.a)		// turn off
	sleep_ms(500)
	pin.low(pin.c)
	sleep_ms(500)
	pin.low(pin.x)
	sleep_ms(500)
	pin.low(pin.z)
	sleep_ms(500)
}