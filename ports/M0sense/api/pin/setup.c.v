module pin

@[inline]
pub fn pwm.setup(PIN,  MODE) {
	C.gpio_set_mode(PIN, MODE)
}