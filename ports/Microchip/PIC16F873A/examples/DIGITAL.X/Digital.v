import pin

pin.setup (c0, pin.output)
pin.setup (c1, pin.output)
pin.setup (a2, pin.input)
pin.setup (a3, pin.input)

pin.write(c0, 0)
pin.write(c1, 0)

pin.digital()

x := u8(0)
x1 := u8(0)

for{
	
	x = pin.read(a2)
	x1 = pin.read(a3)

	if x == 1 {

		pin.high(c0)
		pin.high(c1)
		
	}

	else if x1 == 1 {

		pin.low(c0)
		pin.low(c1)
		
	}

}