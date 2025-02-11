module oled 

@[as_macro]
pub fn clear(any)  {
	C.DISPLAY_CLEARDISPLAY()
	C.DISPLAY_DISPLAY()
}