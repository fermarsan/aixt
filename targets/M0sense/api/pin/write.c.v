module pin

@[inline]
pub fn write(PIN, VALUE) {
	C.gpio_write(PIN, VALUE)
}