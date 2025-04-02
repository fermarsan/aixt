module oled

@[as_macro]
pub fn size(number any) {
	C.DISPLAY_SETTEXTSIZE(number)
	C.DISPLAY_DISPLAY()
}
 
@[as_macro]
pub fn color(character any) {
	C.DISPLAY_TEXTCOLOR(character)
	C.DISPLAY_DISPLAY()
}

