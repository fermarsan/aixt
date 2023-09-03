import time { sleep_ms }
import machine { pin }

for i in 0..5 {
	pin_high(A)
	sleep_ms(1)
	pin_low(A)
	sleep_ms(1)
}