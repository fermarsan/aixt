import machine {pin}
import time {sleep_ms}

pin_mode(led4, out)

for {
	pin_high(led4)
	sleep_ms(500)
	pin_low(led4)
	sleep_ms(500)
}
