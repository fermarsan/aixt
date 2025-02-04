module oled

@[as_macro]
pub fn display() u8 {
	C.DISPLAY_DISPLAY()
}
