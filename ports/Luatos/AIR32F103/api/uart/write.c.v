
module uart
@[inline]
pub fn write(VALUE) {
	C.Serial.write(VALUE)
}