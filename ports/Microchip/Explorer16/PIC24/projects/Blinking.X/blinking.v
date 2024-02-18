import time { sleep_ms }
import pin {
	high
	low
}

pin_setup(led3, out)

for {
	high(led3)
	sleep_ms(500)
	low(led3)
	sleep_ms(500)
}

