// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: LCD module sfor M5Stack (arduino backend)
module lcd	// M5Stack LCD module

#include "lcd.c"	

@[as_macro] pub const red 		= u32(C.RED)
@[as_macro] pub const green 	= u32(C.GREEN)
@[as_macro] pub const blue 		= u32(C.BLUE)
@[as_macro] pub const yellow 	= u32(C.YELLOW)
@[as_macro] pub const cyan 		= u32(C.CYAN)
@[as_macro] pub const magenta	= u32(C.MAGENTA)
@[as_macro] pub const white 	= u32(C.WHITE)
@[as_macro] pub const black 	= u32(C.BLACK)
@[as_macro] pub const gray		= u32(C.GRAY)


fn C.M5_LCD_SETBRIGHTNESS(brightness u8)
fn C.M5_LCD_DRAWPIXEL(x int, y int, color u32)
fn C.M5_LCD_DRAWLINE(x0 int, y0 int, x1 int, y1 int, color u32)
fn C.M5_LCD_FILLRECT(x int, y int, w int, h int, color u32)
fn C.M5_LCD_FILLSCREEN(color u32)
fn C.M5_LCD_DRAWCIRCLE(x0 int, y0 int, r int, color u32)
fn C.M5_LCD_DRAWCIRCLEHELPER(x0 int, y0 int, r int, cornername u8, color u32)
fn C.M5_LCD_FILLCIRCLE(x0 int, y0 int, r int, color u32)
fn C.M5_LCD_FILLCIRCLEHELPER(x0 int, y0 int, r int, cornername u8, delta int, color u32)
fn C.M5_LCD_DRAWTRIANGLE(x0 int, y0 int, x1 int, y1 int, x2 int, y2 int, color u32)
fn C.M5_LCD_FILLTRIANGLE(x0 int, y0 int, x1 int, y1 int, x2 int, y2 int, color u32)
fn C.M5_LCD_DRAWROUNDRECT(x0 int, y0 int, w int, h int, radius int, color u32)
fn C.M5_LCD_FILLROUNDRECT(x0 int, y0 int, w int, h int, radius int, color u32)
fn C.M5_LCD_DRAWBITMAP(x int, y int, bitmap []u8, w int, h int, color u32)
fn C.M5_LCD_DRAWRGBBITMAP(x int, y int, bitmap []u16, w int, h int)
fn C.M5_LCD_DRAWCHAR(x u32, y u32, c u8, color u32, bg u32, size u8)
fn C.M5_LCD_SETCURSOR(x0 u32, y0 u32)
fn C.M5_LCD_SETTEXTCOLOR(color u32)
fn C.M5_LCD_SETTEXTCOLORBG(color u32, bgcolor u32)
fn C.M5_LCD_SETTEXTSIZE(size u8)
fn C.M5_LCD_SETTEXTWRAP(w bool)
fn C.M5_LCD_PRINT(str string)
fn C.M5_LCD_PRINTLN(str string)
fn C.M5_LCD_DRAWCENTRESTRING(str string, dx int, poy int, font int)
fn C.M5_LCD_DRAWRIGHTSTRING(str string, dx int, poy int, font int)
fn C.M5_LCD_DRAWJPG(jpg_data string, jpg_len any, x u32, y u32)
fn C.M5_LCD_DRAWJPGFILE(fs any, path string, x u32, y u32)
fn C.M5_LCD_DRAWBMPFILE(fs any, path string, x u32, y u32)
fn C.M5_LCD_CLEAR(color u32) 
fn C.M5_LCD_DRAWRECT(x int, y int, w int, h int, color u32)
fn C.M5_LCD_WIDTH() i16
fn C.M5_LCD_HEIGHT() i16

@[as_macro]
pub fn brightness(brightness u8) {
	C.M5_LCD_SETBRIGHTNESS(brightness)
}

@[as_macro]
pub fn draw_pixel(x int, y int, color u32) {
	C.M5_LCD_DRAWPIXEL(x, y, color)
}

@[as_macro]
pub fn draw_line(x0 int, y0 int, x1 int, y1 int, color u32) {
	C.M5_LCD_DRAWLINE(x0, y0, x1, y1, color)
}

@[as_macro]
pub fn fill_rect(x int, y int, w int, h int, color u32) {
	C.M5_LCD_FILLRECT(x, y, w, h, color)
}

@[as_macro]
pub fn fill_screen(color u32) {
	C.M5_LCD_FILLSCREEN(color)
}

@[as_macro]
pub fn circle(x0 int, y0 int, r int, color u32) {
	C.M5_LCD_DRAWCIRCLE(x0, y0, r, color)
}

@[as_macro]
pub fn circle_helper(x0 int, y0 int, r int, cornername u8, color u32) {
	C.M5_LCD_DRAWCIRCLEHELPER(x0, y0, r, cornername, color)
}

@[as_macro]
pub fn fill_circle(x0 int, y0 int, r int, color u32) {
	C.M5_LCD_FILLCIRCLE(x0, y0, r, color)
}

@[as_macro]
pub fn fill_circle_helper(x0 int, y0 int, r int, cornername u8, delta int, color u32) {
	C.M5_LCD_FILLCIRCLEHELPER(x0, y0, r, cornername, delta, color)
}

@[as_macro]
pub fn triangle(x0 int, y0 int, x1 int, y1 int, x2 int, y2 int, color u32) {
	C.M5_LCD_DRAWTRIANGLE(x0, y0, x1, y1, x2, y2, color)
}

@[as_macro]
pub fn fill_triangle(x0 int, y0 int, x1 int, y1 int, x2 int, y2 int, color u32) {
	C.M5_LCD_FILLTRIANGLE(x0, y0, x1, y1, x2, y2, color)
}

@[as_macro]
pub fn round_rect(x0 int, y0 int, w int, h int, radius int, color u32) {
	C.M5_LCD_DRAWROUNDRECT(x0, y0, w, h, radius, color)
}

@[as_macro]
pub fn fill_round_rect(x0 int, y0 int, w int, h int, radius int, color u32) {
	C.M5_LCD_FILLROUNDRECT(x0, y0, w, h, radius, color)
}

@[as_macro]
pub fn bitmap(x int, y int, bitmap []u8, w int, h int, color u32) {
	C.M5_LCD_DRAWBITMAP(x, y, bitmap, w, h, color)
}

@[as_macro]
pub fn rgb_bitmap(x int, y int, bitmap []u16, w int, h int) {
	C.M5_LCD_DRAWRGBBITMAP(x, y, bitmap, w, h)
}

@[as_macro]
pub fn char(x u32, y u32, c u8, color u32, bg u32, size u8) {
	C.M5_LCD_DRAWCHAR(x, y, c, color, bg, size)
}

@[as_macro]
pub fn cursor(x0 u32, y0 u32) {
	C.M5_LCD_SETCURSOR(x0, y0)
}

@[as_macro]
pub fn text_color(color u32) {
	C.M5_LCD_SETTEXTCOLOR(color)
}

@[as_macro]
pub fn text_color_bg(color u32, bgcolor u32) {
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
pub fn jpg(jpg_data string, jpg_len any, x u32, y u32) {
	C.M5_LCD_DRAWJPG(jpg_data, jpg_len, x, y)
}

@[as_macro]
pub fn jpg_file(fs any, path string, x u32, y u32) {
	C.M5_LCD_DRAWJPGFILE(fs, path, x, y)
}

@[as_macro]
pub fn bmp_file(fs any, path string, x u32, y u32) {
	C.M5_LCD_DRAWBMPFILE(fs, path, x, y)
}

@[as_macro]
pub fn clear(color u32) {
	C.M5_LCD_CLEAR(color)
}

@[as_macro]
pub fn rect(x int, y int, w int, h int, color u32) {
	C.M5_LCD_DRAWRECT(x, y, w, h, color)
}

@[as_macro]
pub fn width() i16 {
	return C.M5_LCD_WIDTH() 
}

@[as_macro]
pub fn height() i16 {
	return C.M5_LCD_HEIGHT()
}