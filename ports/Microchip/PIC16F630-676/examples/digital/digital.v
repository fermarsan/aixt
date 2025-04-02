import pin

pin.setup (pin.c2, pin.input)
pin.setup (pin.c4, pin.input)
pin.setup (pin.c0, pin.output)
pin.setup (pin.c1, pin.output)

pin.write(pin.c0, 0)

x := u8(0)
x1 := u8(0)

pin.digital ()

for{
	
	x = pin.read(pin.c2)
	x1 = pin.read(pin.c4)

	if x == 1 {

		pin.high(pin.c0)
		pin.high(pin.c1)
		
	}

	else if x1 == 1 {

		pin.low(pin.c0)
		pin.low(pin.c1)
		
	}

}