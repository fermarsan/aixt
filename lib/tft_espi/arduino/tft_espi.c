// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//		- Jahn Delgado
//		- Fernando M. Santa
// Date: 02/04/2025
// License: MIT
//
// Description: Example of a Library module.
//

// #undef ILI9341_DRIVER
// #define ILI9341_2_DRIVER

// #define TFT_WIDTH  240
// #define TFT_HEIGHT 320

// #define TFT_BL   21
// #define TFT_BACKLIGHT_ON HIGH

// #undef TFT_MISO
// #undef TFT_MOSI
// #undef TFT_SCLK
// #undef TFT_CS
// #undef TFT_DC
// #undef TFT_RST

// #define TFT_MISO 12
// #define TFT_MOSI 13
// #define TFT_SCLK 14
// #define TFT_CS   15  // Chip select control pin
// #define TFT_DC    2  // Data Command control pin
// #define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST
// #define TOUCH_CS 33     // Chip select pin (T_CS) of touch screen

// #undef SPI_FREQUENCY
// #define SPI_FREQUENCY  55000000

// #define USE_HSPI_PORT
//
//

#include "./TFT_eSPI.h"

#define TFT_FILLSCREEN(COLOR)   tft.fillScreen(COLOR)
#define TFT_SETTEXTCOLOR(COLOR, BKG_COLOR)  tft.setTextColor(COLOR, BKG_COLOR)
#define TFT_SETROTATION(ANGLE)  tft.setRotation(ANGLE)
#define TFT_INIT()  tft.init()
#define TFT_DRAWCENTRESTRING(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)  tft.drawCentreString(TEMPTEXT, CENTERX, TEXTY, FONT_ZISE)


TFT_eSPI tft = TFT_eSPI();
