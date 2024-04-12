import pin
import time { sleep }

pin.setup(a0, pin.output)	// LED3
pin.setup(d6, pin.input)	// SW3

for {
	if pin.read(d6) == 0 {
		pin.high(a0)
		sleep(3)
		pin.low(a0)
	}
}