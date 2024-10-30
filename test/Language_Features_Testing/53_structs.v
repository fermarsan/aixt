// struct LEDs {
// 	state 		bool
// 	pin			i64
// 	is_analog	bool
// }

// struct C.GPIO {

// }


// led1 := LEDs {
// 	state:	false
// 	pin:	'PortB_0'
// }

import ttgo
import lv
import time

#include <config.h>

pub struct C.TTGOClass {
}

type ttgo_struct = C.TTGOClass

pub ttgo_get_watch() &ttgo_struct {
	return C.TTGOClass_get_watch()
}

ttgo &ttgo_struct{}
ttgo = ttgo_get_watch()
ttgo.begin()
ttgo.open_bl()
ttgo.lvgl_begin()

text := lv.label_create(lv.scr_act())
text.set_text("T-Watch")
text.align(lv.align_center, 0, 0)


for {
    lv.task_handler()
    time.sleep(5)
}