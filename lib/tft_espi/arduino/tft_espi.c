// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 02/04/2025
// License: MIT
//
// Description: Example of a Library module.
//


#define TFT_FILLSCREEN(COLOR)   tft.fillScreen(COLOR)
#define TFT_SETTEXTCOLOR(COLOR, BKG_COLOR)  tft.setTextColor(COLOR, BKG_COLOR)
#define TFT_SETROTATION(1)  tft.set_rotation(1)
#define TFT_INIT()  setup()
#define TFT_DRAWCENTRESTRING(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)  tft.draw_centre_string(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)


TFT_eSPI tft = TFT_eSPI();
