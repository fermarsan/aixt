import port
import time { sleep_ms }

for {
	port.write(p_a, 0xAA)
	sleep_ms(200)
	port.write(p_a, 0x55)
	sleep_ms(200)
}