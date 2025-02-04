module oled

@[as_macro] {
pub fn size(number u8)
	C.DISPLAY_SETTEXTSIZE(number)
}
 

@[as_macro] {
pub fn color(character int)
	C.DISPLAY_TEXTCOLOR(character)
}

