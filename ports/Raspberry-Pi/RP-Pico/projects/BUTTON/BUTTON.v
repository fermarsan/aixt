import time { sleep_ms }
import pin

pin.setup(led, pin.output)
pin.setup(gp11, pin.input)

for {
	b0n := false
	if pin.read(gp11) {
		time.sleep_ms(50)
		for pin.read(gp11){}
		time.sleep_ms(50)
		b0n = !b0n

		if b0n {
			pin.high(led)
		} else {
			pin.low(led)
		}
	}
}
