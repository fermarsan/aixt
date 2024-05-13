import pin

pin.setup (b2, pin.input)
pin.setup (b4, pin.input)
pin.setup (b0, pin.output)
pin.setup (b1, pin.output)

pin.write(b0, 0)
pin.write(b1, 0)

x := u8(0)
x1 := u8(0)



for{
	
	x = pin.read(b2)
	x1 = pin.read(b4)

	if x == 1 {

		pin.high(b0)
		pin.high(b1)
		
	}

	else if x1 == 1 {

		pin.low(b0)
		pin.low(b1)
		
	}

}