module oled

@[as_macro]
pub fn pixel(x any , y any , color any)  {
	C.DISPLAY_DRAWPIXEL(x,y,color)
	C.DISPLAY_DISPLAY()
}


@[as_macro]
pub fn rect(x any , y any , width any , height any , color any) {
	C.DISPLAY_DRAWRECT(x,y,width,height,color)
	C.DISPLAY_DISPLAY()
}


@[as_macro]
pub fn circle(x any , y any , radio any , color any) {
	C.DISPLAY_DRAWCIRCLE(x,y,radio,color)
	C.DISPLAY_DISPLAY()
}
