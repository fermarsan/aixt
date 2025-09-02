// Project name: Analog echo
// Author: Fernando M. Santa
// Date: 01/07/2025
// PIC16F676 fosc = 20Mhz
import time
import port 
import adc


adc.setup(adc.in2, adc.bits_8)
port.setup(port.c, port.all_outputs)
port.setup(port.a, 0b11_111100)

for {
	value := adc.read_byte(adc.ch2)
	port.write(
		port.c, 
		u8(value & 0b00111111)
	)
	port.write(
		port.a, 
		u8((value & 0b11000000) >> 6)
	)
	time.sleep_ms(1)
}
