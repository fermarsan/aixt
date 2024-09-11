module pin

@[inline]
pub fn read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}
