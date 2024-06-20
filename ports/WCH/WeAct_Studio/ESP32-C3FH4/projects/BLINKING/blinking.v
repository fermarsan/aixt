import time { sleep_ms }
import pin 

pin.setup(1, pin.output)

for { 
	pin.high(1)
	sleep_ms(1000)
	pin.low(1)
	sleep_ms(1000)
}