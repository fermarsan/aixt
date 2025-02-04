module oled 

@[as_macro]
pub fn setcursor(x,y u8) {
	C.DISPLAY_SETCURSOR(x,y)
}
