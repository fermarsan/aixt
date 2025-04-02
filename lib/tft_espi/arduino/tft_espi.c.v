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

@[as_macro] pub const white = C.TFT_WHITE
@[as_macro] pub const black = C.TFT_BLACK
@[as_macro] pub const red = C.TFT_RED

fn C.TFT_FILLSCREEN(color any)
fn C.TFT_SETTEXTCOLOR(color any, bkg_color any) 