module adc

@[inline]
pub fn adc.read(PIN_NAME) {
C.analogRead(PIN_NAME)
}
