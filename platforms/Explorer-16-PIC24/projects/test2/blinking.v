import machine
import time

machine.pin(b0, pin_out)

for {
	machine.pin_high(b0)
	time.sleep_ms(1000) 
	machine.pin_low(b0)
	time.sleep_ms(1000)
}
