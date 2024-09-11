module pin

@[inline]
pub fn pin.high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}