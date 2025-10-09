import port
import time { sleep_ms }

port.setup(port.a, 0b1111111100000000)

for {
	port.write(port.a, 0b0000000011111111)
	time.sleep_ms(200)
	port.write(port.a, 0b0000000000000000)
	time.sleep_ms(200)
}