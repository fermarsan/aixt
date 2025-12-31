// Author: Fernando M. Santa
// Date: 2024

module disp7seg

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn precision(p1 int) {
	C.DIGITSHIELD_SETPRECISION(p1)
}
