// Project Name: Inverter
// Author: Fernando M. Santa
// Date: 05/09/2024
// Inverted echo from PORTB3 to PORTB4
// PIC16F83 fosc = 4Mhz

import pin

pin.setup(pin.b3, pin.input)
pin.setup(pin.b4, pin.output)

for {
	pin.write(pin.b4, ~pin.read(pin.b3))
}
