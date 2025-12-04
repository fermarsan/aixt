// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: adc functions (CY8CKIT-049-42XX)
module adc

@[as_macro]
pub fn setup() {
	C.adc_Start()       
    C.amux_Start()          
}