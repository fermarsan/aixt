// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2025
//
// ## Description
// adc functions (CY8CKIT-049-42XX)
module adc

@[as_macro]
pub fn setup() {
	C.capsense_ADC_Start()                    
}