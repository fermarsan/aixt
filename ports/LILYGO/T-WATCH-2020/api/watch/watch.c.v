module watch

#include "watch.c"

fn C.WATCH_GET_WATCH() 
fn C.WATCH_BEGIN()     
fn C.WATCH_OPEN_BL()   
fn C.WATCH_LVGL_BEGIN()

pub fn start() {
	C.WATCH_GET_WATCH() 
	C.WATCH_BEGIN()     
	C.WATCH_OPEN_BL()   
	C.WATCH_LVGL_BEGIN()
}

// fn init() {
// 	C.WATCH_GET_WATCH() 
// 	C.WATCH_BEGIN()     
// 	C.WATCH_OPEN_BL()   
// 	C.WATCH_LVGL_BEGIN()
// }