// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: LCD module for M5Stack (arduino backend)

module lcd	// M5Stack LCD module

#include "lcd.c"


fn C.M5_LCD_SETBRIGHTNESS(brightness)
fn C.M5_LCD_DRAWPIXEL(x, y, color)
fn C.M5_LCD_DRAWLINE(x0, y0, x1, y1, color)
fn C.M5_LCD_FILLRECT(x, y, w, h, color)
fn C.M5_LCD_FILLSCREEN(color)
fn C.M5_LCD_DRAWCIRCLE(x0, y0, r, color)
fn C.M5_LCD_DRAWCIRCLEHELPER(x0, y0, r, cornername, color)
fn C.M5_LCD_FILLCIRCLE(x0, y0, r, color)
fn C.M5_LCD_FILLCIRCLEHELPER(x0, y0, r, cornername, delta, color)
fn C.M5_LCD_DRAWTRIANGLE(x0, y0, x1, y1, x2, y2, color)
fn C.M5_LCD_FILLTRIANGLE(x0, y0, x1, y1, x2, y2, color)
fn C.M5_LCD_DRAWROUNDRECT(x0, y0, w, h, radius, color)
fn C.M5_LCD_FILLROUNDRECT(x0, y0, w, h, radius, color)
fn C.M5_LCD_DRAWBITMAP(x, y, bitmap, w, h, color)
fn C.M5_LCD_DRAWRGBBITMAP(x, y, bitmap, w, h)
fn C.M5_LCD_DRAWCHAR(x, y, c, color, bg, size)
fn C.M5_LCD_SETCURSOR(x0, y0)
fn C.M5_LCD_SETTEXTCOLOR(color)
fn C.M5_LCD_SETTEXTCOLOR(color, bgcolor)
fn C.M5_LCD_SETTEXTSIZE(size)
fn C.M5_LCD_SETTEXTWRAP(w)
fn C.M5_LCD_PRINT()
fn C.M5_LCD_PRINTLN()
fn C.M5_LCD_DRAWCENTRESTRING(str, dx, poy, font)
fn C.M5_LCD_DRAWRIGHTSTRING(str, dx, poy, font)
fn C.M5_LCD_DRAWJPG(jpg_data, jpg_len, x, y)
fn C.M5_LCD_DRAWJPGFILE(fs, path, x, y)
fn C.M5_LCD_DRAWBMPFILE(fs, path, x, y)


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
pub fn fill_screen(color u16); {
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
pub fn fill_round_rect(x0 i16, y0 i16, w i16, h i16, radius i16, color u16); {
	C.M5_LCD_FILLROUNDRECT(x0, y0, w, h, radius, color)
}

@[as_macro]
pub fn bitmap(x i16, y i16, bitmap u8[], w i16, h i16, color u16) {
	C.M5_LCD_DRAWBITMAP(x, y, bitmap, w, h, color)
}

@[as_macro]
pub fn rgb_bitmap(x i16, y i16, bitmap u16[], w i16, h i16), {
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
	C.M5_LCD_SETTEXTCOLOR(color, bgcolor)
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
pub fn print() {
	C.M5_LCD_PRINT()
}

@[as_macro]
pub fn println() {
	C.M5_LCD_PRINTLN()
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











M5.lcd.setBrightness(brightness u8);
M5.Lcd.drawPixel(x i16, y i16, color u16);
M5.Lcd.drawLine(x0 i16, y0 i16, x1 i16, y1 i16, color u16);
M5.Lcd.fillRect(x i16, y i16, w i16, h i16, color u16);
M5.Lcd.fillScreen(color u16); 
M5.Lcd.drawCircle(x0 i16, y0 i16, r i16, color u16);
M5.Lcd.drawCircleHelper(x0 i16, y0 i16, r i16, cornername u8, color u16);
M5.Lcd.fillCircle(x0 i16, y0 i16, r i16, color u16);
M5.Lcd.fillCircleHelper(x0 i16, y0 i16, r i16, cornername u8, delta i16, color u16);
M5.Lcd.drawTriangle(x0 i16, y0 i16, x1 i16, y1 i16, x2 i16, y2 i16, color u16);
M5.Lcd.fillTriangle(x0 i16, y0 i16, x1 i16, y1 i16, x2 i16, y2 i16, color u16);
M5.Lcd.drawRoundRect(x0 i16, y0 i16, w i16, h i16, radius i16, color u16);
M5.Lcd.fillRoundRect(x0 i16, y0 i16, w i16, h i16, radius i16, color u16); 
M5.Lcd.drawBitmap(x i16, y i16, bitmap u8[], w i16, h i16, color u16);
M5.Lcd.drawRGBBitmap(x i16, y i16, bitmap u16[], w i16, h i16), 
M5.Lcd.drawChar(x u16, y u16, c u8, color u16, bg u16, size u8);
M5.Lcd.setCursor(x0 u16, y0 u16);
M5.Lcd.setTextColor(color u16);
M5.Lcd.setTextColor(color u16, bgcolor u16);
M5.Lcd.setTextSize(size u8);
M5.Lcd.setTextWrap(bool w);
M5.Lcd.print();
M5.Lcd.println();
M5.Lcd.drawCentreString(str string, dx int, poy int, font int);
M5.Lcd.drawRightString(str string, dx int, poy int, font int);
M5.Lcd.drawJpg(jpg_data string, jpg_len any, x u16, y u16);
M5.Lcd.drawJpgFile(fs any, path string, x u16, y u16);
M5.Lcd.drawBmpFile(fs any, path string, x u16, y u16);