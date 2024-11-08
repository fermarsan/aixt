import port
import time {sleep_ms}

port.setup(port.c, 0b00000)

for{

	port.write(port.c,0b010101)
	sleep_ms(500)
	port.write(port.c,0b101010)
	sleep_ms(500)
}