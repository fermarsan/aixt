module oled 

@[as_macro]
pub fn setup(type_ any, address any) {
	C.DISPLAY_BEGIN(type_, address)
	C.DISPLAY_DISPLAY()
}
