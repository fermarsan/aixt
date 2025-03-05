// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn  set_cursor(p1 int,p2 int) {  
C.LCD_SETCURSOR(p1,p2)
}