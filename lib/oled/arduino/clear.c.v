module oled 

@[as_macro]
pub fn clear() u8 {
	C.DISPLAY_CLEARDISPLAY()
}