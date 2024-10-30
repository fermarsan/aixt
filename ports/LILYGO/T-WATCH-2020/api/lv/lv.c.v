module lv

struct C.obj_t {
}

type Obj_t = C.obj_t

@[inline]
pub fn scr_act() voidptr {
	return C.lv_scr_act()
}

@[inline]
pub fn label_create(active_scr voidptr) {
	C.lv_label_create(active_scr, C.NULL)
}

@[inline]
pub fn label_set_text(label voidptr, msg string) {
	C.lv_label_set_text(label, msg)
}

@[inline]
pub fn obj_align(obj voidptr, align int, x int, y int) {
	C.lv_obj_align(obj, C.NULL, align, x, y)
}