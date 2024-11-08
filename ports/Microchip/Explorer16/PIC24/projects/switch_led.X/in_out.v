import time
import pin

pin.setup(pin.d6, pin.input)
pin.setup(pin.a0, pin.output)

for {
	if pin.read(pin.d6) == 0 {
		pin.high(pin.a0)
		time.sleep(2)
		pin.low(pin.a0)
	}
}