import pin
import time { sleep }

pin.setup(pin.a0, pin.output)	// LED3
pin.setup(pin.d6, pin.input)	// SW3

for {
	if pin.read(pin.d6) == 0 {
		pin.high(pin.a0)
		time.sleep(3)
		pin.low(pin.a0)
	}
}