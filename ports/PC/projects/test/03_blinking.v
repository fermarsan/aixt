import time { sleep_us }
import machine { pin }

pin_update()
sleep_us(500000)

for i in 0..5 {
	pin_high(a)
	sleep_us(500000)
	pin_low(a)
	sleep_us(500000)
}