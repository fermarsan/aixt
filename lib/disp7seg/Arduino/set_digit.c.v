// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module disp7seg

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn setDigit(p1 int, p2 int) {  
C.DISP7SEG_SETDIGIT(p1, p2) 
}