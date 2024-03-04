import time {sleep_ms}
import pin

sleep_ms(2000)

for i in 0..5 {
	pin.high(a)		// turn on
	sleep_ms(500)
	pin.high(c)
	sleep_ms(500)
	pin.high(x)
	sleep_ms(500)
	pin.high(z)
	sleep_ms(500)

	pin.low(a)		// turn off
	sleep_ms(500)
	pin.low(c)
	sleep_ms(500)
	pin.low(x)
	sleep_ms(500)
	pin.low(z)
	sleep_ms(500)
}