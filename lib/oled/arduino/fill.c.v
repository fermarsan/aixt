module oled

@[as_macro]
pub fn fill_rect(x any , y any , width any , height any , color any)  {
	C.DISPLAY_FILLRECT(x,y,width,height,color)
	C.DISPLAY_DISPLAY()
}

@[as_macro]
pub fn fill_circle(x any , y any , radio any , color any)  {
	C.DISPLAY_FILLCIRCLE(x,y,radio,color)
	C.DISPLAY_DISPLAY()
}
