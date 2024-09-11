module pwm

@[inline]
pub fn write(PIN, VAL) {
	C.analogWrite(PIN, VAL)
}
