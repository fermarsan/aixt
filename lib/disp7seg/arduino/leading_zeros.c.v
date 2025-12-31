// Author: Fernando M. Santa
// Date: 2024

module disp7seg

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn leading_zeros(p1 bool) {
	C.DIGITSHIELD_SETLEADINGZEROS(p1)
}
