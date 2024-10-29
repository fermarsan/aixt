#include "ex1.c"

C.init()

text := &C.lv_obj_t
text = C.lv_label_create(C.lv_scr_act(), C.NULL)
C.lv_label_set_text(text, "T-Watch")
C.lv_obj_align(text, C.NULL, C.LV_ALIGN_CENTER, 0, 0)

for {
    C.lv_task_handler()
    C.delay(5)
}



//------------------

// import t_watch
// import scr
// import time

// t_watch.init()

// text := scr.label_create()
// scr.label_set_text(text, "T-Watch")

// for {
//     scr.task_handler()
//     time.sleep(5)
// }


#include "config.h"

TTGOClass *ttgo;

void setup()
{
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->lvgl_begin();

    lv_obj_t *text = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(text, "T-Watch");
    lv_obj_align(text, NULL, LV_ALIGN_CENTER, 0, 0);
}

void loop()
{
    lv_task_handler();
    delay(5);
}
