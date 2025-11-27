// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module adc

//read function reads the value from the specified analog pin
@[inline]
pub fn read(channel int) u16 {

	C.capsense_ADC_AdcReadResult_mVolts(channel int) //Select the channel
	C.CyDelay(5)
	C.capsense_ADC_AdcStartConvert()
	for !C.capsense_ADC_AdcReadResult_mVolts(0) {}
	C.capsense_ADC_AdcStop()


	return C.capsense_ADC_AdcGetResult_mVolts(channel int) // read the ADC
}