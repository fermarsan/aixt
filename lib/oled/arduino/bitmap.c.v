module oled 

@[as_macro]
pub fn drawbitmap(x any , y any , array_image any , width any , height any , color any) {
	C.DISPLAY_DRAWBITMAP(x,y,array_image,width,height,color)
	C.DISPLAY_DISPLAY()
}