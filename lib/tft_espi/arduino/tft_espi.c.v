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
#include <TFT_eSPI.h>

#include "tft_espi.c"

// @[as_macro] pub const XPT2046_IRQ 36   // T_IRQ
// @[as_macro] pub const XPT2046_MOSI 32  // T_DIN
// @[as_macro] pub const XPT2046_MISO 39  // T_OUT
// @[as_macro] pub const XPT2046_CLK 25   // T_CLK
// @[as_macro] pub const XPT2046_CS 33    // T_CS

// @[as_macro] pub const SCREEN_WIDTH 320
// @[as_macro] pub const SCREEN_HEIGHT 240
// @[as_macro] pub const FONT_SIZE 2


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
