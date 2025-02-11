// Project name: 10-bit ADC
// Author: Fernando M. Santa
// Date: 13/11/2024
// PIC16F886 fosc = 10Mhz

import time
import pin
import port
import adc

adc.setup(
	adc.in0,
	adc.f_21ksps_10mhz,
	adc.bits_10
)
pin.setup(pin.a0, pin.input)	// adc input

port.setup(port.b, port.all_outputs)
port.setup(port.c, 0b11111100)		// C0 and C1 as outputs

// mut value := u16(0)

for {
	value := adc.read(adc.ch0)
	port.write(port.b, u8(value))		// 8 LSBs
	port.write(port.c, u8(value>>8))	// 2 MSBs
	time.sleep_ms(100)
}
