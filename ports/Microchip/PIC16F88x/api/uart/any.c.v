module uart

@[inline]
pub fn any() {
	C.RCIF
}