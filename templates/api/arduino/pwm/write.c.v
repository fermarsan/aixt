module pwm

@[inline]
pub fn pwm.write(PIN, VAL) {
	C.analogWrite(PIN, VAL)
}
