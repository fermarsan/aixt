#define LILYGO_WATCH_2020_V1    //To use T-Watch2020, please uncomment this line
#define LILYGO_WATCH_LVGL       //To use LVGL, you need to enable the macro LVGL

#include <LilyGoWatch.h>


TTGOClass *ttgo;

void ttgo__get_watch(void) {
    ttgo = TTGOClass::getWatch();
}

void ttgo__begin(void) {
    ttgo->begin();
}

void ttgo__open_bl(void) {
    ttgo->openBL();
}

void ttgo__lvgl_begin(void) {
    ttgo->lvgl_begin();
}
