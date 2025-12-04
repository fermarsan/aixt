#include "../../clib/TFT_eSPI/TFT_eSPI.h"

#define TFT_FILLSCREEN(COLOR)                                       tft.fillScreen(COLOR)
#define TFT_SETTEXTCOLOR(COLOR, BKG_COLOR)                          tft.setTextColor(COLOR, BKG_COLOR)
#define TFT_SETROTATION(ANGLE)                                      tft.setRotation(ANGLE)
#define TFT_INIT()                                                  tft.init()
#define TFT_DRAWCENTRESTRING(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)   tft.drawCentreString(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)

TFT_eSPI tft = TFT_eSPI();