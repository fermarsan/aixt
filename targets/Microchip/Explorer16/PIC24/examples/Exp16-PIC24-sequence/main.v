import time
import port

const leds = port.a

const sequence = [
	u8(0b00000000),
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

port.setup(leds, 0xFF00)	// 8 LSB as outputs (LEDs)

for {
	for i in 0..12 {
		port.write(leds, sequence[i])
		time.sleep_ms(500)
	}
}