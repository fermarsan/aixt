import machine { pin }
import time { sleep_ms }

pin(b0, pin_out)

for {
	pin.high(pin.b0)
	time.sleep_ms(1000)
	pin.low(pin.b0)
	time.sleep_ms(1000) 
	time.sleep_ms(500) 
}
 