// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 22/05/2025
// License: MIT
//
// Description: LCD module for ESP32-CYD 2.8 inch
//
module lcd

#include <SPI.h>
// #include <TFT_eSPI.h>

#include "lcd.c"

@[as_macro] pub const white = C.TFT_WHITE
@[as_macro] pub const black = C.TFT_BLACK
@[as_macro] pub const temp_text = C.TFT_TEMP_TEXT
@[as_macro] pub const center_x = C.TFT_CENTER_X
@[as_macro] pub const text_y = C.TFT_TEXT_Y
@[as_macro] pub const font_size = C.TFT_FONT_SIZE


fn C.TFT_FILLSCREEN(color any)
fn C.TFT_SETTEXTCOLOR(color any, bkg_color any)
fn C.TFT_DRAWCENTRESTRING(temp_text, center_x, text_y, font_size)
fn C.TFT_SETROTATION(angle any)
fn C.TFT_INIT()

fn init() {
	C.TFT_INIT()
}

@[as_macro]
pub fn text_color(color any, bkg_color any) {
	C.TFT_SETTEXTCOLOR(color, bkg_color)
}

@[as_macro]
pub fn rotation(angle any) {
	C.TFT_SETROTATION(angle)
}

@[as_macro]
pub fn fill_screen(color any) {
	C.TFT_FILLSCREEN(color)
}

@[as_macro]
pub fn draw_centre_string(temp_text any, center_x any, text_y any, font_size any) {
	C.TFT_DRAWCENTRESTRING(temp_text, center_x, text_y, font_size)
}