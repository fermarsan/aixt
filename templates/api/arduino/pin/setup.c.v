module pin

@[inline]
pub fn setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}
