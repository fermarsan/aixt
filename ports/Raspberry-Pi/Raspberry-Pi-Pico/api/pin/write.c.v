module pin

@[inline]
pub fn pwm.write(PIN_NAME, VALUE) {
	C.digitalWrite(PIN_NAME, VALUE)
}