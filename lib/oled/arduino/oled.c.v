module oled

#include "oled.c" 

@[as_macro] pub const black     = 0
@[as_macro] pub const white     = 1
@[as_macro] pub const inverse   = 2
@[as_macro] pub const ssd1306_switchspvcc = C.SSD1306_SWITCHSPVCC


fn C.DISPLAY_BEGIN(type_ any , address any) bool
fn C.DISPLAY_CLEARDISPLAY() 
fn C.DISPLAY_SETTEXTSIZE(number any)
fn C.DISPLAY_TEXTCOLOR(character any)
fn C.DISPLAY_SETCURSOR(x any , y any)
fn C.DISPLAY_PRINTLN(message any)
fn C.DISPLAY_DISPLAY() 
fn C.DISPLAY_DRAWPIXEL(x any , y any , color any)
fn C.DISPLAY_DRAWRECT(x any , y any , width any , height any , color any)
fn C.DISPLAY_FILLRECT(x any , y any , width any , height any , color any)
fn C.DISPLAY_DRAWCIRCLE(x any , y any , radio any , color any)
fn C.DISPLAY_FILLCIRCLE(x any , y any , radio any , color any) 
fn C.DISPLAY_DRAWBITMAP(x any , y any , array_image any , width any , height any , color any) 


@[as_macro]
pub fn setup(type_ any, address any) bool {
	return C.DISPLAY_BEGIN(type_, address)
}

@[as_macro]
pub fn clear() {
	C.DISPLAY_CLEARDISPLAY()
	C.DISPLAY_DISPLAY()
}

@[as_macro] 
pub fn println(message string)  {
	C.DISPLAY_PRINTLN(message)
	C.DISPLAY_DISPLAY()
}

@[as_macro]
pub fn set_cursor(x any , y any) {
	C.DISPLAY_SETCURSOR(x,y)
	C.DISPLAY_DISPLAY()
}