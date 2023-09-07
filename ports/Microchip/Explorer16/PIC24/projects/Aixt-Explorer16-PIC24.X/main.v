import machine {pin}
import time {sleep_ms}

pin_mode(a7, out)

for {
	pin_high(a7)
	sleep_ms(500)
	pin_low(a7)
	sleep_ms(500)
}
