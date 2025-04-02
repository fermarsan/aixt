import pin

pin.setup (pin.c0, pin.output)
pin.setup (pin.c1, pin.output)
pin.setup (pin.a2, pin.input)
pin.setup (pin.a3, pin.input)

pin.write(pin.c0, 0)
pin.write(pin.c1, 0)

pin.digital()

x := u8(0)
x1 := u8(0)

for{
	
	x = pin.read(pin.a2)
	x1 = pin.read(pin.a3)

	if x == 1 {

		pin.high(pin.c0)
		pin.high(pin.c1)
		
	}

	else if x1 == 1 {

		pin.low(pin.c0)
		pin.low(pin.c1)
		
	}

}