import time
import pin

pin.setup(d6, input)
pin.setup(a0, output)

for {
	if pin.read(d6) == 0 {
		pin.high(a0)
		time.sleep(2)
		pin.low(a0)
	}
}