import ttgo
import time
import lv

struct MyStruct {
    x int
    y int
}


// ttgo.start()

// z := MyStruct{3,4}

// text := lv.Obj_t{}
// text := &u8

lv.label_create(lv.scr_act())
lv.label_set_text(text, "T-Watch")
lv.obj_align(text, lv.align_center, 0, 0)

for {
    // lv.task_handler()
    time.sleep(5)
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


// #include "config.h"

// TTGOClass *ttgo;

// void setup()
// {
//     ttgo = TTGOClass::getWatch();
//     ttgo->begin();
//     ttgo->openBL();
//     ttgo->lvgl_begin();

//     lv_obj_t *text = lv_label_create(lv_scr_act(), NULL);
//     lv_label_set_text(text, "T-Watch");
//     lv_obj_align(text, NULL, LV_ALIGN_CENTER, 0, 0);
// }

// void loop()
// {
//     lv_task_handler();
//     delay(5);
// }
