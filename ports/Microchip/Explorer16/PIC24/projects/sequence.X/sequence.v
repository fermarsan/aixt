import time {sleep_ms}
import port

const sequence = [
	0b00000000,
	0b00000001,
	0b00000011,
	0b00000111,
	0b00001110,
	0b00011100,
	0b00111000,
	0b01110000,
	0b11100000,
	0b11000000,
	0b10000000,
]

for {
	// for step in sequence {
	// 	port.write(a, step)
	for i in 0..12 {
		port.write(a, sequence[i])
	}
}