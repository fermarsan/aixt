module uart

@[inline]
pub fn uart.println(MSG) {
	C.uart.print(MSG);  uart.write('\n');  uart.write('\r')
}