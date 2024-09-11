module pin

@[inline]
pub fn pin.low(PIN_NAME) {
	C.digitalWrite(PIN_NAME, LOW)
}