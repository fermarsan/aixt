#define LILYGO_WATCH_2020_V1    //To use T-Watch2020, please uncomment this line
#define LILYGO_WATCH_LVGL       //To use LVGL, you need to enable the macro LVGL

#include <LilyGoWatch.h>


TTGOClass *watch;

#define WATCH_GET_WATCH()    watch = TTGOClass::getWatch()
#define WATCH_BEGIN()        watch->begin()
#define WATCH_OPEN_BL()      watch->openBL()
#define WATCH_LVGL_BEGIN()   watch->lvgl_begin()
