import port
import time {sleep_ms}

port.setup(b, 0b00000000)

for{

	port.write(b,0b01010101)
	sleep_ms(500)
	port.write(b,0b10101010)
	sleep_ms(500)
}