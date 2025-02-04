module oled

@[as_macro]
pub fn fillrect(x,y,width,height u8, color int)  {
	C.DISPLAY_FILLRECT(x,y,width,height,color)
}

@[as_macro]
pub fn fillcircle(x,y,radio u8, color int)  {
	C.DISPLAY_FILLCIRCLE(x,y,radio,color)
}
