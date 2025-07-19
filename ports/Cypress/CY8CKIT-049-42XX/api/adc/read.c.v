// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module adc


//read function reads the value from the specified analog pin
@[inline]
pub fn read(channel int) u16 {

	C.amux_FastSelect(channel)	// Select the channel
	C.CyDelay(5)
	C.adc_StartConvert()	
	for !C.adc_IsEndConversion(C.adc_RETURN_STATUS) {}	// wait for the conversion
	C.adc_StopConvert()
	
	return C.adc_GetResult16(0)	// read the ADC
}