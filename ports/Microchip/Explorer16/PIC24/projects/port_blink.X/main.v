import port
import time { sleep_ms }

port.setup(port.a, 0b00000000)

for {
	port.write(port.a, 0b11111111)
	sleep_ms(200)
	port.write(port.a, 0b00000000)
	sleep_ms(200)
}