module uart

@[inline]
pub fn uart.any() {
	C.RCIF
}