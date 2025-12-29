module uart2

@[inline]
pub fn println(msg string) {
C.uart2.print(MSG);  uart2.write('\n');  uart2.write('\r')
}
