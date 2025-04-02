// Project name:
// Author: 
// Date: 
// PIC16F886 fosc = 10Mhz

import time
import pin
import port
import adc

pin.setup(pin.a0, pin.input)
adc.setup(
	adc.in0,
	adc.f_21ksps_10mhz,
	adc.bits_8
)

port.setup(port.b, port.all_outputs)

muestra := u8(0)

for {
	muestra = adc.read_byte(adc.ch0)	// lee el ADC a 8 bits
	port.write(port.b, muestra)//u8(muestra/2))		// lo pasa al puerto B
}
