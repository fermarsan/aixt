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
#define TFT_SETROTATION(ANGLE)  tft.setRotation(ANGLE)
#define TFT_INIT()  tft.init()
#define TFT_DRAWCENTRESTRING(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)  tft.drawCentreString(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)


TFT_eSPI tft = TFT_eSPI();
