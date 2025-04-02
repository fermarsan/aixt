module adc

@[inline]
pub fn read(PIN_NAME) {
C.analogRead(PIN_NAME)
}
