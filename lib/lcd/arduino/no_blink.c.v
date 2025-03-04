// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn no_blink() {  
C.LCD_NOBLINK()
}