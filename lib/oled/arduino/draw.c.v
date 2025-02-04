module oled

@[as_macro]
pub fn pixel(x,y u8, color int)  {
	C.DISPLAY_DRAWPIXEL(x,y,color)
}


@[as_macro]
pub fn rect(x,y,width,height u8, color int) {
	C.DISPLAY_DRAWRECT(x,y,width,height,color)
}


@[as_macro]
pub fn circle(x,y,radio u8, color int) {
	C.DISPLAY_DRAWCIRCLE(x,y,radio,color)
}
