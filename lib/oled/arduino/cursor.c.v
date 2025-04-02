module oled 

@[as_macro]
pub fn setcursor(x any , y any) {
	C.DISPLAY_SETCURSOR(x,y)
	C.DISPLAY_DISPLAY()
}
