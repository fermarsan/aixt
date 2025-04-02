module oled 

@[as_macro]
pub fn setup(type_ any, address any) bool {
	return C.DISPLAY_BEGIN(type_, address)
}
