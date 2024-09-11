module uart2

@[inline]
pub fn uart2.println(MSG) {
C.uart2.print(MSG);  uart2.write('\n');  uart2.write('\r')
}