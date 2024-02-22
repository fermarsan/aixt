import time {sleep_ms}
import pin

pin.setup(b3_s, pin.out)

pin.setup(a6_s, pin.in)

x := 0

for {
	pin.high(b3)
	sleep_ms(500)
	pin.low(b3)
	sleep_ms(500)

	x = pin.read(a6)	// PIC16
	x = pin.read(a6_i)	// PIC18
}

