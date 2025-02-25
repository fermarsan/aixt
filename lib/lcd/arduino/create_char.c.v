// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn createChar(P1 u8,P2 u8) {  
C.LCD_CREATECHAR(P1,P2) 
}