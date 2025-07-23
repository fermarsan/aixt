// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: ADC analog pin setup for PIC16F88x family
module adc


@[as_macro]
fn set_as_analog(pins any) {
	C.ANSEL = u8(~pins)
    C.ANSELH = u8(~pins>>8)
}