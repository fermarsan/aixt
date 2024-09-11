module pin

@[inline]
pub fn setup(PIN,  MODE) {
	C.gpio_set_mode(PIN, MODE)
}