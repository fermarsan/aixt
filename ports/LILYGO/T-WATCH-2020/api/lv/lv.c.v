module lv

#include "lv.c"

struct C.lv_obj_t {
}

type Obj_t = C.lv_obj_t

@[inline]
pub fn scr_act() voidptr {
	return C.lv_scr_act()
}

@[inline]
pub fn label_create(active_scr voidptr) &Obj_t{
	return C.lv_label_create(active_scr, C.NULL)
}

@[inline]
pub fn label_set_text(label voidptr, msg string) {
	C.lv_label_set_text(label, msg)
}

@[inline]
pub fn obj_align(obj voidptr, align int, x int, y int) {
	C.lv_obj_align(obj, C.NULL, align, x, y)
}

@[inline]
pub fn task_handler() {
	C.lv_task_handler()
}