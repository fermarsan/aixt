// Project name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time
import port

salidas := [ 
	0b11111100,
	0b01100000,
	0b11011010,
	0b11110010,
	0b01100110,
	0b10110110,
	0b10111110,
	0b11100000,
	0b11111110,
	0b11110110,
]

indice := 0

port.setup(port.b, port.all_outputs)
port.setup(port.a, 0b00001111)	// del A0 a A3 como entradas

for {
	indice = port.read(port.a)
	port.write(port.b, salidas[indice])
	time.sleep_ms(100)
}
