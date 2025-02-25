// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn begin(P1 int,P2 int) {  
C.LCD_BEGIN(P1,P2,P3,P4,P5,P6)
}