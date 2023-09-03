import time { sleep_us }
import machine { pin }

for i in 0..5 {
	pin_high(A)
	sleep_us(500000)
	pin_low(A)
	sleep_us(500000)
}