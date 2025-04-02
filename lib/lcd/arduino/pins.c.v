// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn pins(rs int,en int, d4 int, d5 int, d6 int, d7 int) {  
	C.LCD_PINS(rs,en,d4,d5,d6,d7)
}