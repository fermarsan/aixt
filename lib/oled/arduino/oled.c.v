module oled

#include "oled.c" 

@[as_macro] pub const black     = 0
@[as_macro] pub const white     = 1
@[as_macro] pub const inverse   = 2


fn C.DISPLAY_BEGIN (type_ u8, address int) bool
fn C.DISPLAY_CLEARDISPLAY() u8
fn C.DISPLAY_SETTEXTSIZE(number int)
fn C.DISPLAY_TEXTCOLOR(character u8)
fn C.DISPLAY_SETCURSOR(x,y u8)
fn C.DISPLAY_PRINTLN(message string)
fn C.DISPLAY_DISPLAY() u8
fn C.DISPLAY_DRAWPIXEL(x,y,color u8, int)
fn C.DISPLAY_DRAWRECT(x any, y any , width any, height,color u8, int)
fn C.DISPLAY_FILLRECT(x,y,width,height,color u8, int)
fn C.DISPLAY_DRAWCIRCLE(x,y,radio,color u8, int)
fn C.DISPLAY_FILLCIRCLE(x,y,radio,color u8, int) 
fn C.DISPLAY_DRAWBITMAP(x any,y any,array_image any,width any,height any,color any) 

// cada variable lleva el tipo
// colocar any a todos, si no revisar tipo de datos 
// definir constantes propias 
//#define SSD1306_BLACK 0   ///< Draw 'off' pixels
//#define SSD1306_WHITE 1   ///< Draw 'on' pixels
//#define SSD1306_INVERSE 2 ///< Invert pixels
