// Project name: Aixt, https://github.com/fermarsan/aixt.git
//
// _Author:_ Fernando M. Santa
//
// _Date:_ 2024
// License: MIT
module disp7seg

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn value_double(p1 f64) {
	C.DIGITSHIELD_SETVALUEFLOAT(p1)
}
