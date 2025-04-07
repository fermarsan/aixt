// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn create_char(p1 u8,p2 u8) {  
C.LCD_CREATECHAR(p1,p2) 
}