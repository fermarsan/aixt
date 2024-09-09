import machine
import time

machine.pin(b0, pin_out)

for {
	machine.pin.high(b0)
	time.sleep_ms(1000) 
	machine.pin.low(b0) 
	time.sleep_ms(1000)

	time.sleep_ms(500)
}
