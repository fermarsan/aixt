// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 01/04/2025
// License: MIT
//
// Description: Example of a Library module.
//
module tft_espi

#include <SPI.h>
// #include <TFT_eSPI.h>

#include "tft_espi.c"

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
