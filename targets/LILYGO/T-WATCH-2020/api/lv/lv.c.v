module lv

#include "lv.c"

struct C.lv_obj_t {
}

type Obj_t = C.lv_obj_t

pub const align_center = C.LV_ALIGN_CENTER

fn C.lv_scr_act() voidptr
fn C.lv_label_create(args ...any) &Obj_t
fn C.lv_label_set_text(args ...any)
fn C.lv_obj_align(args ...any)
fn C.lv_task_handler()

@[as_macro]
pub fn scr_act() voidptr {
	return C.lv_scr_act()
}

@[as_macro]
pub fn label_create(active_scr voidptr) &Obj_t{
	return C.lv_label_create(active_scr, C.NULL)
}

@[as_macro]
pub fn label_set_text(label voidptr, msg string) {
	C.lv_label_set_text(label, msg)
}

@[as_macro]
pub fn obj_align(obj voidptr, align int, x int, y int) {
	C.lv_obj_align(obj, C.NULL, align, x, y)
}

@[as_macro]
pub fn task_handler() {
	C.lv_task_handler()
}