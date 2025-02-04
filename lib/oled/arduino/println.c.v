module oled

@[as_macro] 
pub fn println(message string)  {
		C.DISPLAY_PRINTLN(message)
		C.DISPLAY_DISPLAY()
}
