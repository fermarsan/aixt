import port
import time

port.setup(port.a, 0xFF00)	// the 8 LSBs as outputs

for {
	port.write(port.a, 0x00FF)
	time.sleep_ms(200)
	port.write(port.a, 0x0000)
	time.sleep_ms(200)
}