module ttgo

##include "ttgo.c"


pub init() {
	ttgo.get_watch()
	ttgo.begin()
	ttgo.open_bl()
	ttgo.lvgl_begin()
}