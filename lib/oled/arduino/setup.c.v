module oled 

@[as_macro]
pub fn setup(type_ u8, address int) {
	C.DISPLAY_BEGIN(type_, address)
}
