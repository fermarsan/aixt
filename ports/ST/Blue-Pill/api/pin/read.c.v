
module pin

@[inline]
pub fn pin.read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}