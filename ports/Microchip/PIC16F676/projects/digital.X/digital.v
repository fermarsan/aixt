import pin

pin.setup (c2, pin.input)
pin.setup (c4, pin.input)
pin.setup (c0, pin.output)
pin.setup (c1, pin.output)

pin.write(c0, 0)

x := u8(0)
x1 := u8(0)

pin.digital ()

for{
	
	x = pin.read(c2)
	x1 = pin.read(c4)

	if x == 1 {

		pin.high(c0)
		pin.high(c1)
		
	}

	else if x1 == 1 {

		pin.low(c0)
		pin.low(c1)
		
	}

}