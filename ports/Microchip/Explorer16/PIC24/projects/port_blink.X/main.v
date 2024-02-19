import port
import time { sleep_ms }

for {
	port.write(a, 0b11001100)
	sleep_ms(200)
	port.write(a, 0b00110011)
	sleep_ms(200)
}