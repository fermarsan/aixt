// Author: Fernando M. Santa
// Date: 2024

module lcd

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn display() {
C.LCD_DISPLAY()
}
