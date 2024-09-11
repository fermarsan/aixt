module pwm

@[inline]
pub fn pwm.map(MODE, VALUE,VALUE1,VALUE2,VALUE3) {
	C.map(MODE, VALUE,VALUE1,VALUE2,VALUE3)
}