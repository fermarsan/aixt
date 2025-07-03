// Project name: Analog echo
// Author: Fernando M. Santa
// Date: 01/07/2025
// PIC16F6xx-14p fosc = 20Mhz
// import time
import port 
import adc { setup, read }


adc.setup(adc.in0, adc.bits_10)
port.setup(port.c, 0b11000000)
port.setup(port.a, 0b11000011)

for {
	value := adc.read(adc.ch0)
	port.write(
		port.c, 
		u8(value & 0x003f)
	)
	port.write(
		port.a, 
		u8((value & 0x03C0) >> 4)
	)
	// time.sleep_us(100)
}
