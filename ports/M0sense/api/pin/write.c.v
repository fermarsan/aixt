module pin

@[inline]
pub fn pwm.write(PIN, VALUE) {
	C.gpio_write(PIN, VALUE)
}