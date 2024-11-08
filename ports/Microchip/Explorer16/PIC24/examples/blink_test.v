import time {sleep_ms}
import pin

pin.setup(pin.b3, pin.output)
pin.setup(pin.a6, pin.input)

x := 0

for {
	pin.high(pin.b3)
	sleep_ms(500)
	pin.low(pin.b3)
	sleep_ms(500)

	x = pin.read(pin.a6)	// PIC16
	x = pin.read(pin.a6)	// PIC18
}

