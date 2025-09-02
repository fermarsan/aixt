module uart

@[inline]
pub fn println(MSG) {
	C.uart.print(MSG);  uart.write('\n');  uart.write('\r')
}