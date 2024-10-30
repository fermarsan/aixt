module lv

type obj_t = C.lv_obj_t

@[inline]
pub scr_act() &obj_t {
	return C.lv_scr_act()
}

@[inline]
pub label_create(active_scr &obj_t) {
	C.lv_label_create(active_scr, C.NULL)
}

@[inline]
pub label_set_text(label &obj_t, msg string) {
	C.lv_label_set_text(label, msg )
}

@[inline]
pub obj_align(obj &obj_t, align int, x int, y int) {
	C.lv_obj_align(obj, C.NULL, C.LV_ALIGN_CENTER, 0, 0)
}