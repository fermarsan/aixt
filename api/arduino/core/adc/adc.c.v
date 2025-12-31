// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// ADC functions
module adc

fn C.analogRead(id u8) u16

// ADC is a struct that represents an analog pin
pub struct ADC {
pub mut:
    id      u8
}

// new returns a new ADC instance
pub fn ADC.new(id u8) ADC {
    return ADC {
        id:     id
    }
}

//read function reads the value from the specified analog pin
// @[as_macro]
@[inline]
pub fn (mut a ADC) read() u16 {
	return C.analogRead(a.id)
}
