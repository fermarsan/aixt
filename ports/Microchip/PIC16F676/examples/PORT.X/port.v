import port
import time {sleep_ms}

port.setup(c, 0b00000)

for{

	port.write(c,0b010101)
	sleep_ms(500)
	port.write(c,0b101010)
	sleep_ms(500)
}