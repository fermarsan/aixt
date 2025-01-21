// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: LCD module for M5Stack (arduino backend)

module lcd	// M5Stack LCD module

#include "lcd.c"


@[as_macro] pub const red 		= u16(C.RED)
@[as_macro] pub const green 	= u16(C.GREEN)
@[as_macro] pub const blue 		= u16(C.BLUE)
@[as_macro] pub const yellow 	= u16(C.YELLOW)
@[as_macro] pub const cyan 		= u16(C.CYAN)
@[as_macro] pub const magenta	= u16(C.MAGENTA)
@[as_macro] pub const white 	= u16(C.WHITE)
@[as_macro] pub const black 	= u16(C.BLACK)
@[as_macro] pub const gray		= u16(C.GRAY)


fn C.M5_LCD_SETBRIGHTNESS(brightness u8)
fn C.M5_LCD_DRAWPIXEL(x i16, y i16, color u16)
fn C.M5_LCD_DRAWLINE(x0 i16, y0 i16, x1 i16, y1 i16, color u16)
fn C.M5_LCD_FILLRECT(x i16, y i16, w i16, h i16, color u16)
fn C.M5_LCD_FILLSCREEN(color u16)
fn C.M5_LCD_DRAWCIRCLE(x0 i16, y0 i16, r i16, color u16)
fn C.M5_LCD_DRAWCIRCLEHELPER(x0 i16, y0 i16, r i16, cornername u8, color u16)
fn C.M5_LCD_FILLCIRCLE(x0 i16, y0 i16, r i16, color u16)
fn C.M5_LCD_FILLCIRCLEHELPER(x0 i16, y0 i16, r i16, cornername u8, delta i16, color u16)
fn C.M5_LCD_DRAWTRIANGLE(x0 i16, y0 i16, x1 i16, y1 i16, x2 i16, y2 i16, color u16)
fn C.M5_LCD_FILLTRIANGLE(x0 i16, y0 i16, x1 i16, y1 i16, x2 i16, y2 i16, color u16)
fn C.M5_LCD_DRAWROUNDRECT(x0 i16, y0 i16, w i16, h i16, radius i16, color u16)
fn C.M5_LCD_FILLROUNDRECT(x0 i16, y0 i16, w i16, h i16, radius i16, color u16)
fn C.M5_LCD_DRAWBITMAP(x i16, y i16, bitmap []u8, w i16, h i16, color u16)
fn C.M5_LCD_DRAWRGBBITMAP(x i16, y i16, bitmap []u16, w i16, h i16)
fn C.M5_LCD_DRAWCHAR(x u16, y u16, c u8, color u16, bg u16, size u8)
fn C.M5_LCD_SETCURSOR(x0 u16, y0 u16)
fn C.M5_LCD_SETTEXTCOLOR(color u16)
fn C.M5_LCD_SETTEXTCOLORBG(color u16, bgcolor u16)
fn C.M5_LCD_SETTEXTSIZE(size u8)
fn C.M5_LCD_SETTEXTWRAP(w bool)
fn C.M5_LCD_PRINT(str string)
fn C.M5_LCD_PRINTLN(str string)
fn C.M5_LCD_DRAWCENTRESTRING(str string, dx int, poy int, font int)
fn C.M5_LCD_DRAWRIGHTSTRING(str string, dx int, poy int, font int)
fn C.M5_LCD_DRAWJPG(jpg_data string, jpg_len any, x u16, y u16)
fn C.M5_LCD_DRAWJPGFILE(fs any, path string, x u16, y u16)
fn C.M5_LCD_DRAWBMPFILE(fs any, path string, x u16, y u16)
fn C.M5_LCD_CLEAR(color u16) 


@[as_macro]
pub fn brightness(brightness u8) {
	C.M5_LCD_SETBRIGHTNESS(brightness)
}

@[as_macro]
pub fn draw_pixel(x i16, y i16, color u16) {
	C.M5_LCD_DRAWPIXEL(x, y, color)
}

@[as_macro]
pub fn draw_line(x0 i16, y0 i16, x1 i16, y1 i16, color u16) {
	C.M5_LCD_DRAWLINE(x0, y0, x1, y1, color)
}

@[as_macro]
pub fn fill_rect(x i16, y i16, w i16, h i16, color u16) {
	C.M5_LCD_FILLRECT(x, y, w, h, color)
}

@[as_macro]
pub fn fill_screen(color u16) {
	C.M5_LCD_FILLSCREEN(color)
}

@[as_macro]
pub fn circle(x0 i16, y0 i16, r i16, color u16) {
	C.M5_LCD_DRAWCIRCLE(x0, y0, r, color)
}

@[as_macro]
pub fn circle_helper(x0 i16, y0 i16, r i16, cornername u8, color u16) {
	C.M5_LCD_DRAWCIRCLEHELPER(x0, y0, r, cornername, color)
}

@[as_macro]
pub fn fill_circle(x0 i16, y0 i16, r i16, color u16) {
	C.M5_LCD_FILLCIRCLE(x0, y0, r, color)
}

@[as_macro]
pub fn fill_circle_helper(x0 i16, y0 i16, r i16, cornername u8, delta i16, color u16) {
	C.M5_LCD_FILLCIRCLEHELPER(x0, y0, r, cornername, delta, color)
}

@[as_macro]
pub fn triangle(x0 i16, y0 i16, x1 i16, y1 i16, x2 i16, y2 i16, color u16) {
	C.M5_LCD_DRAWTRIANGLE(x0, y0, x1, y1, x2, y2, color)
}

@[as_macro]
pub fn fill_triangle(x0 i16, y0 i16, x1 i16, y1 i16, x2 i16, y2 i16, color u16) {
	C.M5_LCD_FILLTRIANGLE(x0, y0, x1, y1, x2, y2, color)
}

@[as_macro]
pub fn round_rect(x0 i16, y0 i16, w i16, h i16, radius i16, color u16) {
	C.M5_LCD_DRAWROUNDRECT(x0, y0, w, h, radius, color)
}

@[as_macro]
pub fn fill_round_rect(x0 i16, y0 i16, w i16, h i16, radius i16, color u16) {
	C.M5_LCD_FILLROUNDRECT(x0, y0, w, h, radius, color)
}

@[as_macro]
pub fn bitmap(x i16, y i16, bitmap []u8, w i16, h i16, color u16) {
	C.M5_LCD_DRAWBITMAP(x, y, bitmap, w, h, color)
}

@[as_macro]
pub fn rgb_bitmap(x i16, y i16, bitmap []u16, w i16, h i16) {
	C.M5_LCD_DRAWRGBBITMAP(x, y, bitmap, w, h)
}

@[as_macro]
pub fn char(x u16, y u16, c u8, color u16, bg u16, size u8) {
	C.M5_LCD_DRAWCHAR(x, y, c, color, bg, size)
}

@[as_macro]
pub fn cursor(x0 u16, y0 u16) {
	C.M5_LCD_SETCURSOR(x0, y0)
}

@[as_macro]
pub fn text_color(color u16) {
	C.M5_LCD_SETTEXTCOLOR(color)
}

@[as_macro]
pub fn text_color_bg(color u16, bgcolor u16) {
	C.M5_LCD_SETTEXTCOLORBG(color, bgcolor)
}

@[as_macro]
pub fn text_size(size u8) {
	C.M5_LCD_SETTEXTSIZE(size)
}

@[as_macro]
pub fn text_wrap(w bool) {
	C.M5_LCD_SETTEXTWRAP(w)
}

@[as_macro]
pub fn print(str string) {
	C.M5_LCD_PRINT(str)
}

@[as_macro]
pub fn println(str string) {
	C.M5_LCD_PRINTLN(str)
}

@[as_macro]
pub fn centre_string(str string, dx int, poy int, font int) {
	C.M5_LCD_DRAWCENTRESTRING(str, dx, poy, font)
}

@[as_macro]
pub fn right_string(str string, dx int, poy int, font int) {
	C.M5_LCD_DRAWRIGHTSTRING(str, dx, poy, font)
}

@[as_macro]
pub fn jpg(jpg_data string, jpg_len any, x u16, y u16) {
	C.M5_LCD_DRAWJPG(jpg_data, jpg_len, x, y)
}

@[as_macro]
pub fn jpg_file(fs any, path string, x u16, y u16) {
	C.M5_LCD_DRAWJPGFILE(fs, path, x, y)
}

@[as_macro]
pub fn bmp_file(fs any, path string, x u16, y u16) {
	C.M5_LCD_DRAWBMPFILE(fs, path, x, y)
}

@[as_macro]
pub fn clear(color u16) {
	C.M5_LCD_CLEAR(color)
}