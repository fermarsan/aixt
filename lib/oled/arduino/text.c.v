module oled

@[as_macro]
pub fn set_text_size(number any) {
	C.DISPLAY_SETTEXTSIZE(number)
	C.DISPLAY_DISPLAY()
}
 
@[as_macro]
pub fn set_text_color(character any) {
	C.DISPLAY_TEXTCOLOR(character)
	C.DISPLAY_DISPLAY()
}

