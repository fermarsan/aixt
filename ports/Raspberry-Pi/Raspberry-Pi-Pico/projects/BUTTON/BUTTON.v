import time { sleep_ms }
import pin

pin.setup(led, output)
pin.setup(gp11, input)

for {
	b0n := false
	if pin.read(gp11) {
		sleep_ms(50)
		for pin.read(gp11){}
		sleep_ms(50)
		b0n = !b0n

		if b0n {
			pin.high(led)
		} else {
			pin.low(led)
		}
	}
}
