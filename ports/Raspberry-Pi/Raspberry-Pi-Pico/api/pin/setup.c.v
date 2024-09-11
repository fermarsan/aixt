module pin

@[inline]
pub fn pwm.setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}