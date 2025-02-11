module oled 

@[as_macro]
pub fn clear()  {
	C.DISPLAY_CLEARDISPLAY()
	C.DISPLAY_DISPLAY()
}