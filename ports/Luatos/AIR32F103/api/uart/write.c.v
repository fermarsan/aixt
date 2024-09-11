
module uart
@[inline]
pub fn uart.write(VALUE) {
	C.Serial.write(VALUE)
}